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
const analyzeLine = (_line: string): LineAnalysis => {
	const line = _line.trim();
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

const calculateRejoins = (lines: string[], registry: Record<string, number>) => {
	const rejoins: Set<number> = new Set();
	lines.forEach((line, i) => {
		const analysis = analyzeLine(line);
		if (analysis.type.startsWith('if-then-goto')) {
			if (lines[i + 1]) {
				rejoins.add(i + 1);
			}
		}
		if (analysis.type.endsWith('goto-index')) {
			rejoins.add(Number(analysis.value));
		} else if (analysis.type.endsWith('goto-label')) {
			rejoins.add(Number(registry[analysis.value]));
			// } else if (analysis.type === 'label') {
			// 	rejoins.add(i);
		}
	});
	return rejoins;
};

type AdventureSegment = {
	from: number;
	tos: number[];
	lines: string[];
	condition?: string;
};

type AdventureCrawlState = {
	lines: string[];
	froms: Record<string, AdventureSegment>;
	tos: Record<string, AdventureSegment[]>;
	seenStarts: Set<number>;
	labelRegistry: Record<string, number>;
	rejoins: Set<number>;
};

const advanceAdventure = (lines: string[], from: number, cs: AdventureCrawlState) => {
	let pos = from;
	const ret: AdventureSegment = {
		from,
		tos: [],
		lines: [],
	};
	const allSegments: AdventureSegment[] = [];
	while (pos < lines.length) {
		// if we hit a rejoin boundary, start new segment
		if (from !== pos && cs.rejoins.has(pos)) {
			ret.tos = [pos];
			// TODO
			break;
		}
		const analysis = analyzeLine(lines[pos]);
		if (analysis.type === 'comment' || analysis.type === 'label') {
			pos += 1;
			continue;
		}
		if (analysis.type === 'line') {
			ret.lines.push(analysis.line);
			pos += 1;
			continue;
		}
		if (analysis.type === 'goto-index') {
			pos = Number(analysis.value);
			continue;
		}
		if (analysis.type === 'goto-label') {
			pos = cs.labelRegistry[analysis.value];
			continue;
		}
		if (analysis.type === 'goto-script') {
			ret.lines.push(analysis.line);
			ret.tos = [lines.length];
			break;
		}
		if (analysis.type === 'load-map') {
			ret.lines.push(analysis.line);
			ret.tos = [lines.length];
			break;
		}
		if (analysis.type === 'if-then-goto-index') {
			const branchTo = Number(analysis.value);
			ret.lines.push(analysis.line);
			ret.tos = [pos + 1, branchTo];
			break;
		}
		if (analysis.type === 'if-then-goto-label') {
			const branchTo = cs.labelRegistry[analysis.value];
			ret.lines.push(analysis.line);
			ret.tos = [pos + 1, branchTo];
			break;
		}
		if (analysis.type === 'if-then-goto-script') {
			const branchTo = lines.length;
			ret.lines.push(analysis.line);
			ret.tos = [pos + 0.5, branchTo];
			cs.seenStarts.add(pos + 0.5);
			allSegments.push({
				from: pos + 0.5,
				tos: [lines.length],
				lines: [String(analysis.value)],
			});
			break;
		}
		console.log('BREAK');
	}
	if (pos >= lines.length) {
		ret.tos.push(lines.length);
	}
	allSegments.push(ret);
	return allSegments;
};

const startAdventure = (text: string) => {
	const lines = text
		.split('\n')
		.map((v) => {
			return v.trim().replace(/[-:]\d+:\d+";$/, '-XX";');
		})
		.filter((v) => !v.startsWith('//'));
	if (lines[lines.length - 1] === '}') {
		lines.shift();
		lines.pop();
	}
	const queue = [0];
	const labelRegistry = getLabelRegistery(lines);
	const cs: AdventureCrawlState = {
		lines,
		froms: {},
		tos: {},
		seenStarts: new Set([0, lines.length]),
		labelRegistry: getLabelRegistery(lines),
		rejoins: calculateRejoins(lines, labelRegistry),
	};
	const segments: AdventureSegment[] = [];
	while (queue.length) {
		const curr = queue.shift();
		if (curr === undefined) throw new Error('TS');
		const newSegments = advanceAdventure(lines, curr, cs);
		newSegments.forEach((segment) => {
			segments.push(segment);
			segment.tos.forEach((to) => {
				if (!cs.seenStarts.has(to)) {
					cs.seenStarts.add(to);
					queue.push(to);
				}
			});
		});
	}
	segments.forEach((segment) => {
		cs.froms[segment.from] = segment;
		segment.tos.forEach((to) => {
			cs.tos[to] = cs.tos[to] || [];
			cs.tos[to].push(segment);
		});
	});
	return cs;
};

const fastForward = (cs: AdventureCrawlState, start: number) => {
	let pos = start;
	const seen: string[] = [];
	while (pos < cs.lines.length) {
		const curr = cs.froms[pos];
		seen.push(...curr.lines);
		if (curr.tos.length === 2) {
			return {
				type: 'branch',
				tos: curr.tos,
				seen,
			};
		} else {
			pos = curr.tos[0];
		}
	}
	return {
		type: 'end',
		tos: [],
		seen,
	};
};

const compareFrom = (
	oldCS: AdventureCrawlState,
	newCS: AdventureCrawlState,
	oldStart: number,
	newStart: number,
	oldCache: Record<string, boolean>,
	newCache: Record<string, boolean>,
	oldSeen: string[],
	newSeen: string[],
	oldBeenTo: Set<number>,
	newBeenTo: Set<number>,
) => {
	if (oldCache[oldStart] === false) return false;
	if (newCache[newStart] === false) return false;

	if (oldCache[oldStart] === true && newCache[newStart]) return true;
	// if (oldCache[oldStart] === true) throw new Error('lopsided true');
	// if (newCache[newStart] === true) throw new Error('lopsided true');

	if (oldBeenTo.has(oldStart) && newBeenTo.has(newStart)) {
		// infinite loop!
		return true;
	}

	oldBeenTo.add(oldStart);
	newBeenTo.add(newStart);

	const result = oldSeen.join('\n') === newSeen.join('\n');
	if (result === false) {
		oldCache[oldStart] = false;
		newCache[newStart] = false;
		return false;
	}

	const oldFF = fastForward(oldCS, oldStart);
	const newFF = fastForward(newCS, newStart);

	if (oldFF.type !== newFF.type) {
		oldCache[oldStart] = false;
		newCache[newStart] = false;
		return false;
	}

	if (oldFF.type === 'end') {
		const result = oldFF.seen.join('\n') === newFF.seen.join('\n');
		oldCache[oldStart] = result;
		newCache[newStart] = result;
		return result;
	}

	const left = compareFrom(
		oldCS,
		newCS,
		oldFF.tos[0],
		newFF.tos[0],
		oldCache,
		newCache,
		oldSeen,
		newSeen,
		oldBeenTo,
		newBeenTo,
	);
	const right = compareFrom(
		oldCS,
		newCS,
		oldFF.tos[1],
		newFF.tos[1],
		oldCache,
		newCache,
		oldSeen,
		newSeen,
		oldBeenTo,
		newBeenTo,
	);
	return left && right;
};

/*
const oldScriptText = `
	"rand" ?= 3;
	if "rand" == 2 then goto label bodyStart_ZIGZAG_4975;
	if "rand" == 1 then goto label bodyStart_ZIGZAG_5020;
	wait 4000ms;
	goto label LABEL_f5055;
	bodyStart_ZIGZAG_4975:
	wait 2000ms;
	goto label LABEL_f5055;
	bodyStart_ZIGZAG_5020:
	wait 3000ms;
	goto label LABEL_f5055;
	LABEL_f5055:
`;

const newScriptText = `
	"rand" ?= 3;
	if "rand" == 2 then goto label if_true_1322;
	if "rand" == 1 then goto label if_true_1323;
	wait 4000ms;
	goto label rendezvous_1321;
	if_true_1323:
	wait 3000ms;
	goto label rendezvous_1321;
	if_true_1322:
	wait 2000ms;
	rendezvous_1321:
	end_of_script_1324:
`;
const newScriptRegistry = {
	if_true_1323: 5,
	if_true_1322: 8,
	rendezvous_1321: 10,
	end_of_script_1324: 11,
};

const newScriptRejoins = new Set([0, 2, 3, 5, 8, 12]);

const newCS = startAdventure(newScriptText.trim().split('\n'));
const oldCS = startAdventure(oldScriptText.trim().split('\n'));
console.log(newCS);
console.log(oldCS);

const compared = compareFrom(oldCS, newCS, 0, 0, {}, {}, [], []);
console.log(compared);
*/
// const newScriptLines = [
// 	/*0*/ `"rand" ?= 3;`,
// 	/*1*/ `if "rand" == 2 then goto label if_true_1322;`,
// 	/*2*/ `if "rand" == 1 then goto label if_true_1323;`,
// 	/*3*/ `wait 4000ms;`,
// 	/*4*/ `goto label rendezvous_1321;`,
// 	/*5*/ `if_true_1323:`,
// 	/*6*/ `wait 3000ms;`,
// 	/*7*/ `goto label rendezvous_1321;`,
// 	/*8*/ `if_true_1322:`,
// 	/*9*/ `wait 2000ms;`,
// 	/*10*/ `rendezvous_1321:`,
// 	/*11*/ `end_of_script_1324:`,
// ];

export const compareNonlinearScripts = (oldText: string, newText: string) => {
	const oldCS = startAdventure(oldText);
	const newCS = startAdventure(newText);
	return compareFrom(oldCS, newCS, 0, 0, {}, {}, [], [], new Set(), new Set());
};
