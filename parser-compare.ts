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
		if (line.includes('show')) {
			line = line.replace(/(-|:)\d+:\d+";$/, '-XX";').replace(/-/g, '_');
		}
		ret.push(line);
	});
	return ret;
};
const splitSanitizeAndRecoverLabels = (text: string): string[] => {
	const ret: string[] = [];
	text.split('\n').forEach((origLine) => {
		let line = origLine.trim();
		// // split script jumps in case they're separate some times and not others
		// // (this is actually happening)
		// // we're taking away the word script apparently
		// const gotoScriptSplit = line.match(/^(if (.+) then) (goto script (".+");)/);
		// if (gotoScriptSplit) {
		// 	ret.push(gotoScriptSplit[1]);
		// 	ret.push(gotoScriptSplit[3]);
		// 	return;
		// }
		const hiddenLabel = line.match(/^\/\/ '(.+)':/);
		if (hiddenLabel) {
			const label: string = (hiddenLabel[1] || '')
				.replace(/ /g, '_')
				.replace(/-/g, '_')
				.replace(/#/g, '');
			ret.push(`${label}:`);
			return;
		}
		// genericize dialog identifiers that squeaked through
		line = line.replace(/(-|:)\d+:\d+";$/, '-XX";');
		ret.push(line);
	});
	return ret;
};

// // Takes two script strings and sees if their non-goto-line counts are the same.
// // If-else logic aside, this means these scripts are the same and do not have syntax/translation nerrors.
// const compareNonGotoActions = (lhsText: string, rhsText: string) => {
// 	const lhs = count(lhsText);
// 	const rhs = count(rhsText);
// 	return compareCounts(lhs, rhs);
// };

// See if the keys and the counts from two count objects are the same.
const compareCounts = (lhs: Record<string, number>, rhs: Record<string, number>): boolean => {
	const lhsEntries = Object.entries(lhs);
	for (let i = 0; i < lhsEntries.length; i++) {
		const [k, v] = lhsEntries[i];
		if (rhs[k] !== v) {
			return false;
		}
	}
	const rhsEntries = Object.entries(rhs);
	for (let i = 0; i < rhsEntries.length; i++) {
		const [k, v] = rhsEntries[i];
		if (lhs[k] !== v) {
			return false;
		}
	}
	return true;
};
const compareCounted = (lhs: Record<string, number>, rhs: Record<string, number>): boolean => {
	const lhsEntries = Object.entries(lhs);
	for (let i = 0; i < lhsEntries.length; i++) {
		const k = lhsEntries[i][0];
		if (rhs[k] === undefined) {
			return false;
		}
	}
	const rhsEntries = Object.entries(rhs);
	for (let i = 0; i < rhsEntries.length; i++) {
		const k = rhsEntries[i][0];
		if (lhs[k] === undefined) {
			return false;
		}
	}
	return true;
};

type AdventureCS = {
	pos: number;
	seen: string[];
	from: number;
	fromTos: string[];
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
	return {
		type: 'line',
		line: line,
		value: line,
	};
};
const advanceAdventureCS = (cs: AdventureCS, n?: number) => {
	const oldPos = cs.pos;
	const newPos = n === undefined ? cs.pos + 1 : n;
	cs.pos = newPos;
	cs.from = oldPos;
	return oldPos + '->' + newPos;
};
const chooseYourOwnAdventure = (text: string): string[][] => {
	let lines = splitSanitizeAndRecoverLabels(text)
		.filter((s) => !/\/\/.+$/.test(s))
		.slice(1, -1);
	const labelRegistry: Record<string, number> = getLabelRegistery(lines);
	if (text.includes('goto index')) {
		lines = lines.filter((v) => !/^[_a-zA-Z0-9]+:$/.test(v));
	}
	const ifs = lines.filter((v) => v.startsWith('if '));

	const permutations = 2 ** ifs.length;
	if (permutations > 100_000_000) {
		console.warn(`danger! ${permutations} permutations ahead! Skipping for your safety`);
		return [[String(Math.random())], [String(Math.random())]];
	}

	const doneQueue: AdventureCS[] = [];
	const queue: AdventureCS[] = [
		{
			pos: 0,
			seen: [],
			from: -1,
			fromTos: [],
		},
	];
	// const fromTos: Set<string> = new Set();
	while (queue.length) {
		const cs = queue.pop();
		if (!cs) throw new Error('TS I swear');
		const line = lines[cs.pos];
		// Ran out of bounds? We win!
		if (line === undefined) {
			doneQueue.push(cs);
			continue;
		}
		const analysis = analyzeLine(line);
		// Just plain leaving the script
		if (analysis.type === 'load-map' || analysis.type === 'goto-script') {
			// we're done
			if (analysis.type === 'load-map') {
				cs.seen.push(analysis.line);
			}
			doneQueue.push(cs);
			continue;
		}
		// Normal line
		if (
			analysis.type === 'line' ||
			analysis.type === 'if-then-goto-script' ||
			analysis.type === 'comment' ||
			analysis.type === 'label'
		) {
			// (the out-of-script jump is ignored; just fall through)
			const fromTo = advanceAdventureCS(cs);
			cs.seen.push(analysis.line);
			// check for loop
			if (cs.fromTos.includes(fromTo)) {
				doneQueue.push(cs);
			} else {
				cs.fromTos.push(fromTo);
				queue.unshift(cs);
			}
			if (analysis.type === 'comment' || analysis.type === 'label') {
				cs.seen.pop(); // don't track that you saw a comment or a label
			}
			// if (analysis.type === 'if-then-goto-script') {
			// 	if (typeof analysis.value !== 'string') throw new Error('TS');
			// 	cs.seen.push(analysis.value);
			// }
			continue;
		}
		// Non-conditional jumping within the script
		if (analysis.type === 'goto-label' || analysis.type === 'goto-index') {
			const index =
				analysis.type === 'goto-label' ? labelRegistry[analysis.value] : analysis.value;
			if (typeof index !== 'number') throw new Error("TS you're smarter than this");
			const fromTo = advanceAdventureCS(cs, index);
			// don't have "seen" these!
			// check for loop
			if (cs.fromTos.includes(fromTo)) {
				doneQueue.push(cs);
			} else {
				cs.fromTos.push(fromTo);
				queue.unshift(cs);
			}
			continue;
		}
		// Conditional jumping within the script
		if (analysis.type === 'if-then-goto-label' || analysis.type === 'if-then-goto-index') {
			cs.seen.push(analysis.line);
			// fall through half
			const fallThroughCS: AdventureCS = {
				pos: cs.pos,
				seen: cs.seen.slice(),
				from: cs.from,
				fromTos: cs.fromTos.slice(),
			};
			// const fallThroughCS: AdventureCS = JSON.stringify(JSON.parse(cs)) as AdventureCS;
			const fallThroughFromTo = advanceAdventureCS(fallThroughCS);
			// check for loop
			if (cs.fromTos.includes(fallThroughFromTo)) {
				doneQueue.push(fallThroughCS);
			} else {
				fallThroughCS.fromTos.push(fallThroughFromTo);
				queue.unshift(fallThroughCS);
			}
			// jump half
			const index =
				analysis.type === 'if-then-goto-label'
					? labelRegistry[analysis.value]
					: analysis.value;
			if (typeof index !== 'number') throw new Error("TS you're smarter than this");
			const fromTo = advanceAdventureCS(cs, index);
			// check for loop
			if (cs.fromTos.includes(fromTo)) {
				doneQueue.push(cs);
			} else {
				cs.fromTos.push(fromTo);
				queue.unshift(cs);
			}
			continue;
		}
	}
	const flat = doneQueue.map((v) => {
		return v.seen;
	});
	return flat;
};

type PrintComparison = { old: string; new: string };
const inputPath = _resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);
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
		let oldBaked = oldPost[scriptName];
		let newBaked = p.scripts[scriptName].print;
		// if (!oldBaked) {
		oldBaked = oldPre[scriptName];
		newBaked = p.scripts[scriptName].prePrint;
		// }
		const oldPrint = printScript(scriptName, oldBaked);
		const newPrint = newBaked;
		const oldPrintLines = splitAndStripNonGotoActions(oldPrint);
		const newPrintLines = splitAndStripNonGotoActions(newPrint);

		if (oldPrintLines.join('\n') === newPrintLines.join('\n')) {
			tally += 1;
			identical[scriptName] = {
				old: oldPrint,
				new: newPrint,
			};
			return;
		}
		const countAndTrust = compareCounts(count(oldPrintLines), count(newPrintLines));
		if (countAndTrust) {
			trustTally += 1;
			trusted[scriptName] = {
				old: oldPrint,
				new: newPrint,
			};
			return;
		}
		const oldAdventure = chooseYourOwnAdventure(oldPrint);
		const newAdventure = chooseYourOwnAdventure(newPrint);
		const oldAdventureCounts = count(oldAdventure.map((s) => s.join('\n')));
		const newAdventureCounts = count(newAdventure.map((s) => s.join('\n')));
		// don't check counts, just check journeys
		const compareAdventures = compareCounted(oldAdventureCounts, newAdventureCounts);
		if (compareAdventures) {
			functionalTally += 1;
			functional[scriptName] = {
				old: oldPrint,
				new: newPrint,
			};
			return;
		}
		badTally += 1;
		bad[scriptName] = {
			old: oldPrint,
			new: newPrint,
		};
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
