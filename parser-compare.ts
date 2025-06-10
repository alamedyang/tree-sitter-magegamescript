// Compares old JSON output with new JSON output after being translated to mathlang via regex

import { writeFileSync } from 'node:fs';
import { resolve as _resolve } from 'node:path';

import { composites as oldPost } from './comparisons/exfiltrated_composites.ts';
import { idk as oldPre } from './comparisons/exfiltrated_idk.ts';

import { makeMap, parseProject } from './parser.js';
import * as MATHLANG from './parser-types.ts';
import { printScript } from './parser-to-json.ts';

// Ignoring comments, labels, and other inline jumps, get a count of each action line for a script
const count = (lines: string[]) => {
	const counts = {};
	lines.forEach((line) => {
		counts[line] = (counts[line] || 0) + 1;
	});
	return counts;
};
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
		if (line.startsWith('show')) {
			line = line.replace(/(-|:)\d+:\d+";$/, '-XX";').replace(/-/g, '_');
		}
		ret.push(line);
	});
	return ret;
};

// See if the keys and the counts from two count objects are the same.
const compareCounts = (lhs: Record<string, number>, rhs: Record<string, number>): boolean => {
	const report: string[] = [];
	const lhsEntries = Object.entries(lhs);
	for (let i = 0; i < lhsEntries.length; i++) {
		const [k, lhsCount] = lhsEntries[i];
		const rhsCount = rhs[k] === undefined ? 0 : rhs[k];
		if (lhsCount !== rhsCount) {
			report.push(`Found ${lhsCount} (vs ${rhsCount}) extra line(s): ${k} `);
			// return false;
			continue;
		}
	}
	const rhsEntries = Object.entries(rhs);
	for (let i = 0; i < rhsEntries.length; i++) {
		const [k, rhsCount] = rhsEntries[i];
		const lhsCount = lhs[k] === undefined ? 0 : lhs[k];
		if (lhsCount !== rhsCount) {
			report.push(`Found ${lhsCount} (vs ${rhsCount}) extra line(s): ${k} `);
			// return false;
			continue;
		}
	}
	if (report.length > 0) {
		console.log(report.join('\n'));
		return false;
	}
	return true;
};

const getLabelRegistery = (lines: string[]) => {
	const registry: Record<string, number> = {};
	lines.forEach((line, i) => {
		const label = line.trim().match(/^([^/]+):$/);
		if (label) {
			registry[label[1]] = i;
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
	const sanitizedLine = line.startsWith('show') ? line.replace(/(-|:)\d+:\d+";/, '-XX";') : line;
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

const calculateRejoins = (lines: string[]) => {
	const rejoins: Set<number> = new Set();
	const registry = getLabelRegistery(lines);
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

const startAdventure = (_lines: string[]) => {
	const lines = _lines.join('\n').includes('goto index')
		? _lines.slice(1, -1).filter((v) => !/^\/\//.test(v))
		: _lines.slice(1, -1);
	const rejoins = calculateRejoins(lines);
	const registry = getLabelRegistery(lines);
	const cs: AdventureCrawlState = {
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
		// We have a cache for both of them? We win! We've been here before. Pass back the result.
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
	// For times the closing } didn't quite make it in one of them.
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
	lhString.push(...lhEntry.sequence);
	rhString.push(...rhEntry.sequence);
	if (lhEntry.jumpTos.length === rhEntry.jumpTos.length) {
		// Both paths are branching now.
		const compares = lhEntry.jumpTos.map((lhTryPos, i) => {
			const rhTryPos = rhEntry.jumpTos[i];
			if (lhTryPos === lhEntry.from && rhTryPos === rhEntry.from) {
				console.log('INFINITE LOOP!');
				cachedLhIndices[lhEntry.from] = false;
				cachedRhIndices[rhEntry.from] = false;
				return false;
			}
			if (
				cachedLhIndices[lhTryPos] !== undefined &&
				cachedRhIndices[rhTryPos] !== undefined
			) {
				const allMatched = cachedLhIndices[lhTryPos] && cachedRhIndices[rhTryPos];
				cachedLhIndices[lhEntry.from] = allMatched;
				cachedRhIndices[rhEntry.from] = allMatched;
				return allMatched;
			}
			// Do each of their splits separately
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
			cachedLhIndices[lhEntry.from] = manualMatch;
			cachedRhIndices[rhEntry.from] = manualMatch;
			return manualMatch;
		});
		// Check if every branch matched
		const every = compares.every((v) => v);
		cachedLhIndices[lhEntry.from] = every;
		cachedRhIndices[rhEntry.from] = every;
		return every;
	}
	// The jumpto lengths are different:
	if (
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
	// console.log('Then what?');
	// const lhTest = lhString
	// 	.flat()
	// 	.filter((v) => v !== undefined)
	// 	.join(' /* ----- */ ');
	// const rhTest = rhString
	// 	.flat()
	// 	.filter((v) => v !== undefined)
	// 	.join(' /* ----- */ ');
	// if (lhTest === rhTest) {
	// 	return true;
	// } else {
	// 	return false;
	// }
};
type AdventureCrawlState = {
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
const chooseYourOwnAdventure = (cs: AdventureCrawlState, _pos: number) => {
	const { lines, exploredBranchPoints, fromIndicies, toIndicies } = cs;
	let pos = _pos;
	// chunks that
	let jumpTos: number[] = [];
	const sequence: string[] = [];
	while (pos < cs.OOB + 1) {
		const line = lines[pos];
		if (line === undefined) {
			console.log('NO MORE LINES!');
			jumpTos = [cs.OOB];
			break;
		}
		console.log(`Looking at line [${pos}]: ${line}`);
		if (cs.rejoins.has(pos) && pos !== _pos) {
			jumpTos = [pos];
			break;
		}
		const analysis = analyzeLine(line);
		console.log(`   > TYPE: ${analysis.type}`);
		if (analysis.type === 'line') {
			console.log(`   > DO: push to seen lines`);
			sequence.push(analysis.line);
			pos += 1;
			continue;
		}
		if (analysis.type === 'comment') {
			console.log(`   > DO: ignore`);
			pos += 1;
			continue;
		}
		if (analysis.type === 'label') {
			console.log(`   > DO: break the sequence`);
			pos += 1;
			jumpTos = [pos];
			break;
		}
		if (analysis.type === 'load-map') {
			console.log(`   > DO: jump to OOB (${cs.OOB})`);
			pos += 1;
			sequence.push(analysis.line);
			jumpTos = [cs.OOB];
			break;
		}
		if (analysis.type === 'goto-script') {
			console.log(`   > DO: jump to OOB (${cs.OOB})`);
			sequence.push(`goto script "${analysis.value}"`);
			jumpTos = [cs.OOB];
			break;
		}
		if (analysis.type === 'goto-index') {
			if (typeof analysis.value !== 'number') throw new Error('TS broke it');
			pos = analysis.value;
			console.log(`   > DO: jump to new pos (${pos})`);
			jumpTos = [pos];
			break;
		}
		if (analysis.type === 'goto-label') {
			if (typeof analysis.value !== 'string') throw new Error('TS broke it');
			pos = cs.registry[analysis.value];
			console.log(`   > DO: jump to new pos (${pos}, via label ${analysis.value})`);
			if (pos === undefined) throw new Error('something else broke');
			jumpTos = [pos];
			break;
		}
		if (analysis.type === 'if-then-goto-script') {
			// must do both cases separately, as sometimes the goto is split from the check
			// Let's just get rid of the deadend early?
			console.log(`   > DO: PROBABLY SOMETHING FANCY (TODO)`);
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
			jumpTos = [pos, cs.registry[analysis.value]];
			console.log(
				`   > DO: split to next line (${pos}) and jump point (${jumpPos}, via label ${analysis.value})`,
			);
			break;
		}
		if (analysis.type === 'if-then-goto-index') {
			sequence.push(analysis.line);
			if (typeof analysis.value !== 'number') throw new Error('TS broke it');
			pos += 1;
			const jumpPos = analysis.value;
			jumpTos = [pos, jumpPos];
			console.log(`   > DO: split to next line (${pos}) and jump point (${jumpPos})`);
			break;
		}
	}
	exploredBranchPoints.add(_pos);
	const insert = {
		from: _pos,
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
	jumpTos.forEach((to) => {
		if (to !== cs.OOB && !exploredBranchPoints.has(to)) {
			exploredBranchPoints.add(to);
			chooseYourOwnAdventure(cs, to);
		}
	});
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
	let oldBaked = oldPost[scriptName];
	let newBaked = p.scripts[scriptName].actions;
	// let newBaked = p.scripts[scriptName].print;
	if (!oldBaked) {
		oldBaked = oldPre[scriptName];
		newBaked = p.scripts[scriptName].preActions;
		// newBaked = p.scripts[scriptName].prePrint;
	}
	const oldPrint = printScript(scriptName, oldBaked);
	const newPrint = printScript(scriptName, newBaked);
	const oldPrintLines = splitAndStripNonGotoActions(oldPrint);
	const newPrintLines = splitAndStripNonGotoActions(newPrint);

	if (oldPrintLines.join('\n') === newPrintLines.join('\n')) {
		// Literal exact copies
		return {
			type: 'tally',
			old: oldPrint,
			new: newPrint,
		};
	}
	const countAndTrust = compareCounts(count(oldPrintLines), count(newPrintLines));
	// Ignoring control logic, the count of each kind of line is equal
	// (No typos; if-else logic not tested at all! Hence trust)
	if (countAndTrust) {
		return {
			type: 'trust',
			old: oldPrint,
			new: newPrint,
		};
	}
	const oldAdventureLines = oldPrint
		.split('\n')
		.map((v) => v.trim())
		.slice(1, -1);
	const newPostConstantsLines = printScript(scriptName, p.scripts[scriptName].actions);
	let newAdventureLines = newPostConstantsLines.split('\n').map((v) => v.trim());
	newAdventureLines = newAdventureLines.join('\n').includes('goto index')
		? newAdventureLines.slice(1, -1).filter((v) => !/^\/\//.test(v))
		: newAdventureLines.slice(1, -1);
	const oldAdventure = startAdventure(oldAdventureLines);
	const newAdventure = startAdventure(newAdventureLines);
	const compared = compareAdventures(oldAdventure, newAdventure);
	// NAIVE VERSION
	// const counts: Record<string, AdventureSequence[]> = {};
	// const oldAdventure = chooseYourOwnAdventure(oldPrint);
	// const newAdventure = chooseYourOwnAdventure(newPrint);
	// const oldAdventureCounts = count(oldAdventure.map((s) => s.join('\n')));
	// const newAdventureCounts = count(newAdventure.map((s) => s.join('\n')));
	// // don't check counts, just check journeys
	if (compared) {
		return {
			type: 'functional',
			old: oldPrint,
			new: newPrint,
		};
	}
	return {
		type: 'bad',
		old: oldPrint,
		new: newPrint,
	};
};

const identical: Record<string, PrintComparison> = {};
const trusted: Record<string, PrintComparison> = {};
const functional: Record<string, PrintComparison> = {};
const bad: Record<string, PrintComparison> = {};
parseProject(fileMap, {}).then((p: MATHLANG.ProjectState) => {
	console.log('PROJECT');
	console.log(p);
	const scriptNames = Object.keys(p.scripts);
	let tally = 0;
	let trustTally = 0;
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
		if (result.type === 'trust') {
			trustTally += 1;
			trusted[scriptName] = {
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
		`${tally} scripts were identical, ${functionalTally} were functionally identical, and ${trustTally} are probably okay (${badTally} were clearly different)`,
	);
	writeFileSync(`./comparisons/olds.mgs`, olds);
	writeFileSync(`./comparisons/news.mgs`, news);
});

// 1606 scripts were identical, 2 were functionally identical, and 126 are probably okay (79 were clearly different)
// 1618 scripts were identical, 0 were functionally identical, and 125 are probably okay (68 were clearly different)
// 1618 scripts were identical, 56 were functionally identical, and 125 are probably okay (68 were clearly different)
// 1618 scripts were identical, 1 were functionally identical, and 125 are probably okay (67 were clearly different)
// 1669 scripts were identical, 1 were functionally identical, and 116 are probably okay (25 were clearly different)
// 1629 scripts were identical, 6 were functionally identical, and 159 are probably okay (17 were clearly different)
// 1636 scripts were identical, 0 were functionally identical, and 160 are probably okay (15 were clearly different)
// 1639 scripts were identical, 0 were functionally identical, and 166 are probably okay (6 were clearly different)
