// Compares old JSON output with new JSON output after being translated to mathlang via regex.
// Capable of following branches of if-else structures even when their output's line ordering is different.

import { writeFileSync } from 'node:fs';
import { resolve as _resolve } from 'node:path';

// The original JSON output as intercepted manually from the original encoder.
// Lacks some scripts for some reason.
import { composites as oldPost } from './comparisons/exfiltrated_composites.ts';
import {
	compareDialogs,
	type EncoderDialog,
	dialogs as origDialogs,
} from './comparisons/exfiltrated_dialogs.ts';

// The original JSON output at an earlier stage, also intercepted manually from the original encoder.
// Has scripts the other lacks.
import { idk as oldPre } from './comparisons/exfiltrated_idk.ts';

import { makeMap, parseProject } from './parser.js';
import * as MATHLANG from './parser-types.ts';
import { printScript } from './parser-to-json.ts';
import * as TYPES from './parser-bytecode-info.ts';

const splitAndStripNonGotoActions = (text: string): string[] => {
	const ret: string[] = [];
	text.split('\n').forEach((origLine) => {
		let line = origLine.trim();
		// strip label/index goto definitions (keep script jumps)
		const match = line.match(/((.+) then) goto (index \d+|label .+);/);
		line = match ? match[1] : line;
		// ignore bare label/index gotos
		if (/^\s*goto (index \d+|label .+)/.test(line)) {
			return;
		}
		// split script jumps in case they're separate some times and not others
		// (this is actually happening)
		// we're taking away the word script apparently
		const gotoScriptSplit = line.match(/^(if (.+) then) (goto script (".+");)/);
		if (gotoScriptSplit) {
			ret.push(gotoScriptSplit[1]);
			ret.push(gotoScriptSplit[3]);
			return;
		}
		if (/^\s*\/\//.test(line)) {
			// ignore comments
			return;
		}
		if (/^\s*.+:$/.test(line)) {
			// ignore labels
			return;
		}
		// take off any RHS comments (idk if there are any tbh)
		const comments = line.match(/(\s*[^\s]+\s*)\/\/.+$/);
		line = comments ? comments[1].trim() : line;
		// genericize dialog identifiers that squeaked through
		if (line.startsWith('show') || line.startsWith('concat')) {
			line = line.replace(/(-|:)\d+:\d+";$/, '-XX";').replace(/-/g, '_');
		}
		ret.push(line);
	});
	return ret;
};

const getLabelRegistery = (lines: string[]) => {
	const registry: Record<string, number> = {};
	lines.forEach((line, i) => {
		const labelMatch = line.trim().match(/^([^/]+):$/);
		if (labelMatch) {
			const label = labelMatch[1];
			if (registry[label] !== undefined) {
				throw new Error('label already registered: ' + label);
			}
			registry[label] = i;
		}
	});
	return registry;
};

type LineAnalysis = {
	type: LineAnalysisTypes;
	line: string;
	value: number | string;
};
type LineAnalysisTypes =
	| 'if-then-goto-script'
	| 'if-then-goto-label'
	| 'if-then-goto-index'
	| 'goto-script'
	| 'goto-label'
	| 'goto-index'
	| 'comment'
	| 'load-map'
	| 'label'
	| 'line';
const analyzeLine = (line: string): LineAnalysis => {
	// take off RHS comments
	const ifGotoScript = line.match(/(if.+then) goto( script)? "(.+)";$/);
	if (ifGotoScript) {
		return {
			type: 'if-then-goto-script',
			line: ifGotoScript[1],
			value: `goto script "${ifGotoScript[3]}";`,
		};
	}
	const ifGotoLabel = line.match(/(if.+then) goto label (.+);$/);
	if (ifGotoLabel) {
		return {
			type: 'if-then-goto-label',
			line: ifGotoLabel[1],
			value: ifGotoLabel[2],
		};
	}
	const ifGotoIndex = line.match(/(if.+then) goto index (\d+);$/);
	if (ifGotoIndex) {
		return {
			type: 'if-then-goto-index',
			line: ifGotoIndex[1],
			value: Number(ifGotoIndex[2]),
		};
	}
	const gotoScript = line.match(/goto script "(.+)";$/);
	if (gotoScript) {
		return {
			type: 'goto-script',
			line: 'goto script',
			value: gotoScript[1],
		};
	}
	const gotoLabel = line.match(/^goto label (.+);$/);
	if (gotoLabel) {
		return {
			type: 'goto-label',
			line: line,
			value: gotoLabel[1],
		};
	}
	const gotoIndex = line.match(/^goto index (\d+);$/);
	if (gotoIndex) {
		return {
			type: 'goto-index',
			line: 'goto',
			value: Number(gotoIndex[1]),
		};
	}
	const comment = line.match(/^\/\/\s*(.+)$/);
	if (comment) {
		return {
			type: 'comment',
			line: line,
			value: comment[1],
		};
	}
	const label = line.match(/^(.+?):$/);
	if (label) {
		return {
			type: 'label',
			line: line,
			value: label[1],
		};
	}
	const load = line.match(/^load map (.+);$/);
	if (load) {
		return {
			type: 'load-map',
			line: line,
			value: load[1],
		};
	}
	const sanitizedLine = line.replace(/(-|:)\d+:\d+";/, '-XX";');
	return {
		type: 'line',
		line: line,
		value: sanitizedLine,
	};
};
// const advanceAdventureCS = (cs: AdventureCS, n?: number) => {
// 	// ユウキリンリン　ゲンキハツラツ :P
// 	const oldPos = cs.pos;
// 	const newPos = n === undefined ? cs.pos + 1 : n;
// 	cs.pos = newPos;
// 	cs.from = oldPos;
// 	return oldPos + '->' + newPos;
// };

const calculateRejoins = (lines: string[], registry: Record<string, number>) => {
	const rejoins: Set<number> = new Set();
	lines.forEach((line, i) => {
		const analysis = analyzeLine(line);
		if (analysis.type.endsWith('goto-index')) {
			rejoins.add(Number(analysis.value));
		} else if (analysis.type.endsWith('goto-label')) {
			rejoins.add(Number(registry[analysis.value]));
		} else if (analysis.type === 'label') {
			rejoins.add(i);
		}
	});
	return rejoins;
};

const startAdventure = (_lines: string[], actions: TYPES.Action[]) => {
	let lines = _lines[_lines.length - 1] === '}' ? _lines.slice(1, -1) : _lines.slice();
	lines = lines.map((v) =>
		v
			.trim()
			.replace(/(-|:)\d+:\d+";$/, '-XX";')
			.replace(/-/g, '_'),
	);
	lines = lines.join('\n').includes('goto index') ? lines.filter((v) => !/^\/\//.test(v)) : lines;
	const registry = getLabelRegistery(lines);
	const rejoins = calculateRejoins(lines, registry);
	const cs: AdventureCrawlState = {
		actions,
		lines,
		OOB: lines.length,
		rejoins,
		registry,
		exploredBranchPoints: new Set(),
		fromIndicies: {},
		toIndicies: {},
	};
	chooseYourOwnAdventure(cs, 0);
	const allFroms: Set<number> = new Set();
	const allTos: Set<number> = new Set();
	Object.values(cs.toIndicies).forEach((toIndexEntry) => {
		toIndexEntry.forEach((toIndex) => {
			allFroms.add(toIndex.from);
			toIndex.jumpTos.forEach((jumpTo) => allTos.add(jumpTo));
		});
	});
	return cs;
};
const compareAdventures = (
	lhCS: AdventureCrawlState,
	rhCS: AdventureCrawlState,
	cachedLhIndices: Record<string, boolean> = {},
	cachedRhIndices: Record<string, boolean> = {},
	_lhPos: number = 0,
	_rhPos: number = 0,
	lhString: string[] = [],
	rhString: string[] = [],
): boolean => {
	const lhPos = _lhPos;
	const rhPos = _rhPos;
	if (cachedLhIndices[lhPos] !== undefined && cachedRhIndices[rhPos] !== undefined) {
		// We have a cache for both of their match results? We win! We've been here before. Pass back the combo of the cached values.
		return cachedLhIndices[lhPos] && cachedRhIndices[rhPos];
	}
	let lhEntry = lhCS.fromIndicies[lhPos];
	let rhEntry = rhCS.fromIndicies[rhPos];
	if (!rhEntry && !lhEntry) {
		// End of the line for both sides? We win! Pass back the comparison result.
		const lhTest = lhString
			.flat()
			.filter((v) => v !== undefined)
			.join(' /* ----- */ ');
		const rhTest = rhString
			.flat()
			.filter((v) => v !== undefined)
			.join(' /* ----- */ ');
		if (lhTest === rhTest) {
			return true;
		} else {
			return false;
		}
	}
	// For times the closing } didn't quite make it in one of them,
	// make a dummy entry so the other can catch up.
	if (!rhEntry) {
		rhEntry = {
			from: rhCS.OOB,
			jumpTos: [rhCS.OOB],
			sequence: [],
		};
	}
	if (!lhEntry) {
		lhEntry = {
			from: lhCS.OOB,
			jumpTos: [lhCS.OOB],
			sequence: [],
		};
	}
	// sometimes no jumpTo?
	if (lhEntry.jumpTos.length === 0) {
		lhEntry.jumpTos = [lhEntry.from];
	}
	if (rhEntry.jumpTos.length === 0) {
		rhEntry.jumpTos = [rhEntry.from];
	}
	// Branches have the same count. Compare all sets of paired branches.
	if (lhEntry.jumpTos.length === rhEntry.jumpTos.length) {
		lhString.push(...lhEntry.sequence);
		rhString.push(...rhEntry.sequence);
		const compares = lhEntry.jumpTos.map((lhTryPos, i) => {
			const rhTryPos = rhEntry.jumpTos[i];
			if (lhTryPos === lhEntry.from && rhTryPos === rhEntry.from) {
				// They're both looping? That's a match.
				const loopResult = false;
				cachedLhIndices[lhEntry.from] = loopResult;
				cachedRhIndices[rhEntry.from] = loopResult;
				return loopResult;
			}
			// We have caches for these particular matches? Hand that back.
			if (
				cachedLhIndices[lhTryPos] !== undefined &&
				cachedRhIndices[rhTryPos] !== undefined
			) {
				const allMatched = cachedLhIndices[lhTryPos] && cachedRhIndices[rhTryPos];
				cachedLhIndices[lhEntry.from] = allMatched;
				cachedRhIndices[rhEntry.from] = allMatched;
				return allMatched;
			}
			// We're here? Guess we need to try it for real:
			const manualMatch = compareAdventures(
				lhCS,
				rhCS,
				cachedLhIndices,
				cachedRhIndices,
				lhTryPos,
				rhTryPos,
				lhString.slice(),
				rhString.slice(),
			);
			// Add result to cache, then hand it to the list of results.
			cachedLhIndices[lhEntry.from] = manualMatch;
			cachedRhIndices[rhEntry.from] = manualMatch;
			return manualMatch;
		});
		// Check if every branch pair matched
		const every = compares.every((v) => v);
		cachedLhIndices[lhEntry.from] = every;
		cachedRhIndices[rhEntry.from] = every;
		return every;
	}
	// If the jumpto lengths are different:
	// Skip ahead on the one with nothing in it
	// (but don't push the sequence to the chain yet or it'll double up)
	if (
		// LH is boring version
		lhEntry.jumpTos.length === 1 && // only one place to go (other side has a split tho)
		lhEntry.sequence.length == 0 && // its sequence is empty
		lhEntry.jumpTos[0] !== lhEntry.from // and it's not a deadend
	) {
		const deeperMatch = compareAdventures(
			lhCS,
			rhCS,
			cachedLhIndices,
			cachedRhIndices,
			lhEntry.jumpTos[0],
			rhEntry.from,
			lhString.slice(),
			rhString.slice(),
		);
		cachedLhIndices[lhEntry.from] = deeperMatch;
		cachedRhIndices[rhEntry.from] = deeperMatch;
		return deeperMatch;
	} else if (
		// RH is boring version
		rhEntry.jumpTos.length === 1 && // only one place to go (other side has a split tho)
		rhEntry.sequence.length == 0 && // its sequence is empty
		rhEntry.jumpTos[0] !== rhEntry.from // and it's not a deadend
	) {
		const deeperMatch = compareAdventures(
			lhCS,
			rhCS,
			cachedLhIndices,
			cachedRhIndices,
			lhEntry.from,
			rhEntry.jumpTos[0],
			lhString.slice(),
			rhString.slice(),
		);
		cachedLhIndices[lhEntry.from] = deeperMatch;
		cachedRhIndices[rhEntry.from] = deeperMatch;
		return deeperMatch;
	}
	return false;
};
type AdventureCrawlState = {
	actions: TYPES.Action[];
	// gotten in advance
	lines: string[];
	OOB: number;
	rejoins: Set<number>;
	registry: Record<string, number>;
	// while crawling
	exploredBranchPoints: Set<number>;
	fromIndicies: Record<string, AdventureSequence>;
	toIndicies: Record<string, AdventureSequence[]>;
};
let deepness = 0;
const chooseYourOwnAdventure = (cs: AdventureCrawlState, _pos: number) => {
	deepness += 1;
	if (deepness > 1_000) {
		throw new Error('Call stack size limit is like 2k or something?');
	}
	const { lines, exploredBranchPoints, fromIndicies, toIndicies } = cs;
	let topPos = _pos;
	let pos = _pos;
	// chunks that
	let jumpTos: number[] = [];
	const sequence: string[] = [];
	while (!exploredBranchPoints.has(pos)) {
		while (pos < cs.OOB + 1) {
			const line = lines[pos];
			if (line === undefined) {
				// console.log('NO MORE LINES!');
				jumpTos = [cs.OOB];
				break;
			}
			// console.log(`Looking at line [${pos}]: ${line}`);
			if (cs.rejoins.has(pos) && pos !== topPos) {
				jumpTos = [pos];
				break;
			}
			const analysis = analyzeLine(line);
			// console.log(`   > TYPE: ${analysis.type}`);
			if (analysis.type === 'line') {
				// console.log(`   > DO: push to seen lines`);
				sequence.push(analysis.line);
				pos += 1;
				continue;
			}
			if (analysis.type === 'comment') {
				// console.log(`   > DO: ignore`);
				pos += 1;
				continue;
			}
			if (analysis.type === 'label') {
				// console.log(`   > DO: break the sequence`);
				pos += 1;
				jumpTos = [pos];
				break;
			}
			if (analysis.type === 'load-map') {
				// console.log(`   > DO: jump to OOB (${cs.OOB})`);
				pos += 1;
				sequence.push(analysis.line);
				jumpTos = [cs.OOB];
				break;
			}
			if (analysis.type === 'goto-script') {
				// console.log(`   > DO: jump to OOB (${cs.OOB})`);
				sequence.push(`goto script "${analysis.value}"`);
				jumpTos = [cs.OOB];
				break;
			}
			if (analysis.type === 'goto-index') {
				if (typeof analysis.value !== 'number') throw new Error('TS broke it');
				pos = analysis.value;
				// console.log(`   > DO: jump to new pos (${pos})`);
				jumpTos = [pos];
				break;
			}
			if (analysis.type === 'goto-label') {
				if (typeof analysis.value !== 'string') throw new Error('TS broke it');
				pos = cs.registry[analysis.value];
				// console.log(`   > DO: jump to new pos (${pos}, via label ${analysis.value})`);
				if (pos === undefined)
					throw new Error('No registered index for label ' + analysis.value);
				jumpTos = [pos];
				break;
			}
			if (analysis.type === 'if-then-goto-script') {
				// must do both cases separately, as sometimes the goto is split from the check
				// Let's just get rid of the deadend early?
				// console.log(`   > DO: PROBABLY SOMETHING FANCY (TODO)`);
				const deadendFrom = cs.OOB + Math.random(); // oh dear
				if (typeof analysis.value !== 'string') throw new Error('unreachable');
				lines[deadendFrom] = analysis.value; // !! is this gonna work??
				sequence.push(analysis.line);
				pos += 1;
				jumpTos = [pos, deadendFrom];
				break;
			}
			if (analysis.type === 'if-then-goto-label') {
				sequence.push(analysis.line);
				if (typeof analysis.value !== 'string') throw new Error('TS broke it');
				pos += 1;
				const jumpPos = cs.registry[analysis.value];
				jumpTos = [pos, jumpPos];
				// console.log(
				// 	`   > DO: split to next line (${pos}) and jump point (${jumpPos}, via label ${analysis.value})`,
				// );
				break;
			}
			if (analysis.type === 'if-then-goto-index') {
				sequence.push(analysis.line);
				if (typeof analysis.value !== 'number') throw new Error('TS broke it');
				pos += 1;
				const jumpPos = analysis.value;
				jumpTos = [pos, jumpPos];
				// console.log(`   > DO: split to next line (${pos}) and jump point (${jumpPos})`);
				break;
			}
		}
		exploredBranchPoints.add(topPos);
		const insert = {
			from: topPos,
			jumpTos,
			sequence: sequence.slice(),
		};
		if (fromIndicies[insert.from]) {
			throw new Error('already something starting from index ' + insert.from);
		}
		fromIndicies[insert.from] = insert;
		jumpTos.forEach((to) => {
			toIndicies[to] = toIndicies[to] || [];
			toIndicies[to].push(insert);
			return insert;
		});
		if (jumpTos.length > 1) {
			jumpTos.forEach((to) => {
				if (to !== cs.OOB && !exploredBranchPoints.has(to)) {
					exploredBranchPoints.add(to);
					chooseYourOwnAdventure(cs, to);
				}
			});
			break;
		}
		if (jumpTos.length === 1) {
			pos = jumpTos[0];
			topPos = pos;
		}
	}
	deepness -= 1;
	return cs;
};
type AdventureSequence = {
	from: number;
	jumpTos: number[];
	sequence: string[];
};

type PrintComparison = { old: string; new: string };
const inputPath = _resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

const compareScripts = (p: MATHLANG.ProjectState, scriptName: string) => {
	let oldActions = oldPost[scriptName];
	let newActions = p.scripts[scriptName].actions;
	if (!oldActions) {
		oldActions = oldPre[scriptName];
		newActions = p.scripts[scriptName].preActions;
	}
	const oldPrint = printScript(scriptName, oldActions);
	const newPrint = printScript(scriptName, newActions);
	if (
		(!oldPrint.includes('goto label') || !oldPrint.includes('goto index')) &&
		(!newPrint.includes('goto label') || !newPrint.includes('goto index'))
	) {
		const oldPrintLines = splitAndStripNonGotoActions(oldPrint);
		const newPrintLines = splitAndStripNonGotoActions(newPrint);
		if (oldPrintLines.join('\n') === newPrintLines.join('\n')) {
			// Literal exact copies.
			return {
				type: 'tally',
				old: oldPrint,
				new: newPrint,
			};
		}
	}
	const oldAdventure = startAdventure(oldPrint.split('\n').slice(1, -1), oldActions);
	const newAdventure = startAdventure(newPrint.split('\n').slice(1, -1), newActions);
	const compared = compareAdventures(oldAdventure, newAdventure);
	if (compared) {
		// Exact copies when you follow their if-else branches.
		// (Line ordering might be different.)
		return {
			type: 'functional',
			old: oldPrint,
			new: newPrint,
		};
	}
	// They did not match.
	return {
		type: 'bad',
		old: oldPrint,
		new: newPrint,
	};
};

const sortDialogs = (dialogs: Record<string, (EncoderDialog | MATHLANG.Dialog)[]>) => {
	const ret = {
		NAMED: {},
	};
	Object.entries(dialogs).forEach(([name, values]) => {
		const splits = name.split('.mgs');
		if (splits.length === 1) {
			ret.NAMED[name] = values;
		} else {
			const useName = splits[0];
			ret[useName] = ret[useName] || [];
			ret[useName].push(values);
		}
	});
	return ret;
};

const identical: Record<string, PrintComparison> = {};
const functional: Record<string, PrintComparison> = {};
const bad: Record<string, PrintComparison> = {};
parseProject(fileMap, {}).then((p: MATHLANG.ProjectState) => {
	console.log('PROJECT');
	console.log(p);

	// Comparing dialogs
	const foundDialogs = p.dialogs;
	const expectedDialogs: Record<string, EncoderDialog[]> = origDialogs;
	const expectedDialogsSorted = sortDialogs(expectedDialogs);
	const foundDialogsSorted = sortDialogs(foundDialogs);

	const dialogNames = new Set([
		...Object.keys(expectedDialogsSorted.NAMED),
		...Object.keys(foundDialogsSorted.NAMED),
	]);
	const dialogFileNames = new Set([
		...Object.keys(expectedDialogsSorted),
		...Object.keys(foundDialogsSorted),
	]);
	dialogFileNames.delete('NAMED');

	// Comparing named dialogs
	const namedDialogDiffs: string[] = [];
	[...dialogNames].forEach((name) => {
		const found = foundDialogsSorted.NAMED[name];
		const expected = expectedDialogsSorted.NAMED[name];
		if (!found) {
			namedDialogDiffs.push(`Did not find expected dialog named "${name}"`);
			return;
		}
		if (!expected) {
			namedDialogDiffs.push(`Found unexpected dialog named "${name}"`);
			return;
		}
		if (found.dialogs.length !== expected.length) {
			namedDialogDiffs.push(
				`"${name}": found ${found.dialogs.length} dialogs, expected ${expected.length}`,
			);
			return;
		}
		found.dialogs.forEach((foundItem, i) => {
			const expectedItem = expected[i];
			const diffs = compareDialogs(expectedItem, foundItem);
			if (diffs.length) {
				namedDialogDiffs.push(`Named dialog "${name}" has the following issue(s):`);
				namedDialogDiffs.push(...diffs.map((v) => '\t' + v));
			}
		});
		// TODO: compare the dialog contents
	});
	if (namedDialogDiffs.length) {
		console.error(`Named dialogs: found ${namedDialogDiffs.length} differences`);
		console.error(namedDialogDiffs.join('\n'));
	} else {
		console.log(`Named dialogs: all ${dialogNames.size} are identical!`);
	}

	// const expectedCounts = {};
	// Object.entries(expectedDialogsSorted).forEach(([name, data]) => {
	// 	if (!Array.isArray(data)) return;
	// 	expectedCounts[name] = data.length;
	// });
	// const foundCounts = {};
	// Object.entries(foundDialogsSorted).forEach(([name, data]) => {
	// 	if (!Array.isArray(data)) return;
	// 	foundCounts[name] = data.length;
	// });
	// Object.entries(expectedCounts).forEach(([name, expectedCount]) => {
	// 	const foundCount = foundCounts[name];
	// 	if (foundCount !== expectedCount) {
	// 		countDiffs.push(`${name}: found ${foundCount} dialogs, expected ${expectedCount}`);
	// 	}
	// });
	// const foundSolos = Object.keys(foundDialogsSorted.NAMED);
	// const expectedSolos = Object.keys(expectedDialogsSorted.NAMED);
	// foundSolos.forEach((foundSolo) => {
	// 	if (!expectedSolos.includes(foundSolo)) {
	// 		countDiffs.push(`Found "${foundSolo}" and was not expecting it`);
	// 	}
	// });
	// expectedSolos.forEach((expectedSolo) => {
	// 	if (!foundSolos.includes(expectedSolo)) {
	// 		countDiffs.push(`Did not find expected "${expectedSolo}"`);
	// 	}
	// });

	// Comparing scripts
	const scriptNames = Object.keys(p.scripts);
	let tally = 0;
	let functionalTally = 0;
	let badTally = 0;
	scriptNames.forEach((scriptName) => {
		const result = compareScripts(p, scriptName);
		if (result.type === 'tally') {
			tally += 1;
			identical[scriptName] = {
				old: result.old,
				new: result.new,
			};
			return;
		}
		if (result.type === 'functional') {
			functionalTally += 1;
			functional[scriptName] = {
				old: result.old,
				new: result.new,
			};
			return;
		}
		if (result.type === 'bad') {
			badTally += 1;
			bad[scriptName] = {
				old: result.old,
				new: result.new,
			};
			return;
		}
	});

	const olds = Object.values(bad)
		.sort((a, b) => a.old.length - b.old.length)
		.map((v: PrintComparison) => v.old)
		.join('\n\n');
	const news = Object.values(bad)
		.sort((a, b) => a.old.length - b.old.length)
		.map((v: PrintComparison) => v.new)
		.join('\n\n');
	console.log(
		`${tally} scripts were identical, ${functionalTally} were functionally identical, and ${badTally} were clearly different`,
	);
	writeFileSync(`./comparisons/olds.mgs`, olds);
	writeFileSync(`./comparisons/news.mgs`, news);
});
