import { Node as TreeSitterNode } from 'web-tree-sitter';
import {
	getBoolFieldForAction,
	type SHOW_SERIAL_DIALOG,
	type SHOW_DIALOG,
	type CHECK_SAVE_FLAG,
} from './parser-bytecode-info.ts';
import {
	type AnyNode,
	type MGSLocation,
	type MGSMessage,
	type CommentNode,
	type Dialog,
	type DialogDefinition,
	type SerialDialog,
	type SerialDialogDefinition,
	type LabelDefinition,
	type GotoLabel,
	type MathlangSequence,
	type BoolExpression,
	type BoolBinaryExpression,
	isMathlangNode,
	isGotoLabel,
	isBoolGetable,
	isBoolComparison,
	isStringCheckable,
	isNumberCheckableEquality,
	isBoolBinaryExpression,
	isLabelDefinition,
	isMathlangSequence,
} from './parser-types.ts';
import { type FileState } from './parser-file.ts';
import { type FileMap } from './parser-project.ts';

export const verbose = false;
export const debugLog = (message: string) => {
	if (verbose) console.log(message);
};
export const ansiTags: Record<string, string> = {
	// styles
	bold: '\u001B[1m', // aka bright
	dim: '\u001B[2m', // aka dim
	'/': '\u001B[0m',
	reset: '\u001B[0m', // reset all styles
	// fg colors
	k: '\u001B[30m',
	black: '\u001B[30m',
	r: '\u001B[31m',
	red: '\u001B[31m',
	g: '\u001B[32m',
	green: '\u001B[32m',
	y: '\u001B[33m',
	yellow: '\u001B[33m',
	b: '\u001B[34m',
	blue: '\u001B[34m',
	m: '\u001B[35m',
	magenta: '\u001B[35m',
	c: '\u001B[36m',
	cyan: '\u001B[36m',
	w: '\u001B[37m',
	white: '\u001B[37m',
	// bg colors
	'bg-k': '\u001B[40m',
	'bg-black': '\u001B[40m',
	'bg-r': '\u001B[41m',
	'bg-red': '\u001B[41m',
	'bg-g': '\u001B[42m',
	'bg-green': '\u001B[42m',
	'bg-y': '\u001B[43m',
	'bg-yellow': '\u001B[43m',
	'bg-b': '\u001B[44m',
	'bg-blue': '\u001B[44m',
	'bg-m': '\u001B[45m',
	'bg-magenta': '\u001B[45m',
	'bg-c': '\u001B[46m',
	'bg-cyan': '\u001B[46m',
	'bg-w': '\u001B[47m',
	'bg-white': '\u001B[47m',
	// non-color-related
	bell: '',
};

// ------------------------ TEMPORARY VARIABLE MANAGEMENT ------------------------ //

const TEMP = '__TEMP_';
const temporaries: string[] = [];
let temporaryStep = 0;
export const newTemporary = (value?: string): string => {
	if (temporaries.length === 0 && value !== undefined) {
		temporaries.unshift(value);
	} else {
		temporaries.unshift(TEMP + temporaryStep);
		temporaryStep += 1;
	}
	return temporaries[0] || '';
};
export const dropTemporary = (): string => {
	temporaryStep -= 1;
	temporaryStep = temporaryStep < 0 ? 0 : temporaryStep;
	return temporaries.shift() || '';
};
export const quickTemporary = (): string => {
	newTemporary();
	return dropTemporary();
};
export const latestTemporary = (): string => temporaries[0];

// ------------------------ GENERIC ------------------------ //

export const inverseOpMap: Record<string, string> = {
	'<': '>=',
	'<=': '>',
	'>=': '<',
	'>': '<=',
	'==': '!=',
	'!=': '==',
	'&&': '||',
	'||': '&&',
};
export const reportMissingChildNodes = (
	f: FileState,
	node: TreeSitterNode,
): (TreeSitterNode | null)[] => {
	const missingNodes = node.children
		.filter((v) => v !== null)
		.filter((child) => child?.isMissing);
	missingNodes.forEach((missingChild) => {
		f.newError({
			locations: [{ node: missingChild }],
			message: `missing token: ${missingChild.type}`,
		});
	});
	return missingNodes;
};
export const reportErrorNodes = (f: FileState, node: TreeSitterNode): (TreeSitterNode | null)[] => {
	const errorNodes = node.children
		.filter((v) => v !== null)
		.filter((child) => child.type === 'ERROR');
	errorNodes.forEach((errorNode) => {
		f.newError({
			locations: [{ node: errorNode }],
			message: 'syntax error',
		});
	});
	return errorNodes;
};

const getPrintableLocationData = (fileMap: FileMap, location: MGSLocation): string => {
	const fileName = location.fileName || '';
	const fileText = fileMap[fileName].fileText;
	const allLines = fileText.split('\n');
	const row = location.node.startPosition.row;
	const col = location.node.startPosition.column;
	const endRow = location.node.endPosition.row;
	const endCol = location.node.endPosition.column;
	const line = allLines[row].replace(/\t/g, ' ');
	const squigglySize = row === endRow ? endCol - col : allLines[row].length - col;
	const arrow = '~'.repeat(col) + '^'.repeat(squigglySize);
	const message = `╓-${fileName} ${row}:${col}\n` + '║ ' + `${line}\n` + '╙~' + arrow;
	return message;
};

export const printableMessage = (fileMap: FileMap, prefix: string, v: MGSMessage): string => {
	let message =
		`${prefix}: ${v.message}\n` +
		v.locations
			.map((location) => {
				return getPrintableLocationData(fileMap, location);
			})
			.join('\n');
	if (v.footer) {
		message += '\n' + v.footer;
	}
	return message + '\n';
};

export const autoIdentifierName = (f: FileState, node: TreeSitterNode): string => {
	return f.fileName + '-' + node.startPosition.row + ':' + node.startPosition.column;
};

// ------------------------ CONDITIONS ------------------------ //

// todo: get rid of 'invert' flag for things with 'expected_bool'! Just use that!
export const expandCondition = (
	f: FileState,
	node: TreeSitterNode,
	condition: BoolExpression,
	ifLabel: string,
): AnyNode[] => {
	if (condition === true) {
		return [makeGotoLabel(f, node, ifLabel)];
	} else if (condition === false) {
		return [];
	}
	if (typeof condition === 'string') {
		const action = checkFlag(f, node, condition, ifLabel, true);
		return [action];
	}
	if (
		isBoolGetable(condition) ||
		isBoolComparison(condition) ||
		isStringCheckable(condition) ||
		isNumberCheckableEquality(condition)
	) {
		const action = {
			...condition,
			expected_bool: condition.expected_bool === undefined ? true : condition.expected_bool,
			label: ifLabel,
		};
		return [action];
	}
	if (!isBoolBinaryExpression(condition)) {
		throw new Error('expansion for condition not yet implemented');
	}
	const op = condition.op;
	const lhs = condition.lhs;
	const rhs = condition.rhs;
	if (typeof lhs === 'number' || typeof rhs === 'number') {
		throw new Error('LHS or RHS not a number');
	}
	if (op === '||') {
		const expanded = [
			expandCondition(f, condition.lhsNode, lhs, ifLabel),
			expandCondition(f, condition.rhsNode, rhs, ifLabel),
		];
		return expanded.flat();
	}
	if (op === '&&') {
		// have a separate if-else insert?
		// if first one is false goto a rendezvous at the end of the insert
		// if the second one is false, ditto
		const suffix = f.p.advanceGotoSuffix();
		const innerIfTrueLabel = `if true #${suffix}`;
		const innerRendezvousLabel = `rendezvous #${suffix}`;
		const inner = [
			expandCondition(f, condition.lhsNode, lhs, innerIfTrueLabel),
			makeGotoLabel(f, node, innerRendezvousLabel),
			makeLabelDefinition(f, node, innerIfTrueLabel),
			expandCondition(f, condition.rhsNode, rhs, ifLabel),
			makeLabelDefinition(f, node, innerRendezvousLabel),
		];
		return inner.flat();
	}
	if (op !== '==' && op !== '!=') {
		throw new Error('Expected == or !==, found ' + op);
	}
	// todo: if any of these are == bool literal, they can be simplified
	// Cannot directly compare bools. Must branch on if they are both true, or both false
	const expandAs: BoolBinaryExpression = {
		mathlang: 'bool_binary_expression',
		debug: {
			node: condition.debug?.node || node,
			fileName: f.fileName,
		},
		op: '||',
		lhs: {
			mathlang: 'bool_binary_expression',
			debug: {
				node: condition.debug?.node || node,
				fileName: f.fileName,
			},
			op: '&&',
			lhs,
			rhs,
			lhsNode: condition.lhsNode,
			rhsNode: condition.rhsNode,
		},
		rhs: {
			mathlang: 'bool_binary_expression',
			debug: {
				node: condition.debug?.node || node,
				fileName: f.fileName,
			},
			op: '&&',
			lhs: invert(f, condition.lhsNode, lhs),
			rhs: invert(f, condition.rhsNode, rhs),
			lhsNode: condition.lhsNode,
			rhsNode: condition.rhsNode,
		},
		lhsNode: condition.lhsNode,
		rhsNode: condition.rhsNode,
	};
	return expandCondition(f, node, expandAs, ifLabel);
};

export const simpleBranchMaker = (
	f: FileState,
	node: TreeSitterNode,
	_branchAction: AnyNode,
	ifBody: AnyNode[],
	elseBody: AnyNode[],
): MathlangSequence => {
	const gotoLabel = f.p.advanceGotoSuffix();
	const ifLabel = `if #${gotoLabel}`;
	const rendezvousLabel = `rendezvous #${gotoLabel}`;
	const branchAction = {
		..._branchAction,
		label: ifLabel,
	};
	const steps: AnyNode[] = [
		branchAction,
		...elseBody,
		{ mathlang: 'goto_label', label: rendezvousLabel },
		{ mathlang: 'label_definition', label: ifLabel },
		...ifBody,
		{ mathlang: 'label_definition', label: rendezvousLabel },
	];
	return newSequence(f, node, steps, 'simple branch on');
};

export const invert = (
	f: FileState,
	node: TreeSitterNode,
	boolExp: BoolExpression,
): BoolExpression => {
	// TODO: typeof `boolExp`
	if (typeof boolExp === 'boolean') return !boolExp;
	if (typeof boolExp === 'string') {
		return { ...checkFlag(f, node, boolExp, '', false), mathlang: 'bool_getable' };
	}
	if (isBoolBinaryExpression(boolExp)) {
		if (boolExp.op === '||' || boolExp.op === '&&') {
			if (typeof boolExp.lhs === 'number' || typeof boolExp.rhs === 'number') {
				throw new Error('|| or && for a number??');
			}
			const invertedLHS = invert(f, node, boolExp.lhs);
			boolExp.lhs = invertedLHS;
			const invertedRHS = invert(f, node, boolExp.rhs);
			boolExp.rhs = invertedRHS;
		}
		boolExp.op = inverseOpMap[boolExp.op];
		return boolExp;
	}
	if (!boolExp.action) throw new Error('should be string');
	const param = getBoolFieldForAction(boolExp.action);
	boolExp[param] = !boolExp[param];
	return boolExp;
};

// TODO: real constructors
export const makeLabelDefinition = (
	f: FileState,
	node: TreeSitterNode,
	label: string,
): LabelDefinition => ({
	mathlang: 'label_definition',
	label,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const makeGotoLabel = (f: FileState, node: TreeSitterNode, label: string): GotoLabel => ({
	mathlang: 'goto_label',
	label,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const newComment = (comment: string): CommentNode => ({ mathlang: 'comment', comment });
export const newSequence = (
	f: FileState,
	node: TreeSitterNode,
	steps: AnyNode[],
	type: string = 'generic_sequence',
): MathlangSequence => {
	const comment = node.text.replace(/[\n\s\t]+/g, ' ');
	const mathlangComment: CommentNode = newComment(`${type}: ${comment}`);
	steps.unshift(mathlangComment);
	const flatSteps: AnyNode[] = [];
	steps
		.filter((v) => v !== null) // might not need this anymore
		.forEach((v) => {
			if (isMathlangSequence(v)) {
				flatSteps.push(...v.steps);
			} else {
				flatSteps.push(v);
			}
		});
	return {
		mathlang: 'sequence',
		type,
		steps: flatSteps,
		debug: {
			node,
			fileName: f.fileName,
		},
	};
};
export const newDialog = (
	f: FileState,
	node: TreeSitterNode,
	dialogName: string,
	dialogs: Dialog[],
): DialogDefinition => ({
	mathlang: 'dialog_definition',
	fileName: f.fileName,
	dialogName,
	dialogs,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const showDialog = (f: FileState, node: TreeSitterNode, name: string): SHOW_DIALOG => ({
	action: 'SHOW_DIALOG',
	dialog: name,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const newSerialDialog = (
	f: FileState,
	node: TreeSitterNode,
	dialogName: string,
	serialDialog: SerialDialog,
): SerialDialogDefinition => ({
	mathlang: 'serial_dialog_definition',
	fileName: f.fileName,
	dialogName,
	serialDialog,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const showSerialDialog = (
	f: FileState,
	node: TreeSitterNode,
	name: string,
	isConcat?: boolean,
): SHOW_SERIAL_DIALOG => ({
	action: 'SHOW_SERIAL_DIALOG',
	disable_newline: isConcat,
	serial_dialog: name,
	debug: {
		node,
		fileName: f.fileName,
	},
});
const checkFlag = (
	f: FileState,
	node: TreeSitterNode,
	save_flag: string,
	gotoLabel: string,
	expected_bool: boolean = true,
): CHECK_SAVE_FLAG => {
	return {
		mathlang: 'bool_getable',
		action: 'CHECK_SAVE_FLAG',
		save_flag,
		value: save_flag,
		expected_bool,
		label: gotoLabel || 'UNDEFINED LABEL',
		debug: {
			node,
			fileName: f.fileName,
		},
	};
};

export const flattenGotos = (actions: AnyNode[]): AnyNode[] => {
	// const before = printScript('_', actions).split('\n');
	// A goto label followed by the same label definition can be removed
	for (let i = 0; i < actions.length; i++) {
		const action = actions[i];
		const next = actions[i + 1];
		if (
			isMathlangNode(action) &&
			isGotoLabel(action) &&
			next &&
			isMathlangNode(next) &&
			isLabelDefinition(next) &&
			next.label === action.label
		) {
			actions.splice(i, 1);
			// can jump over the next one (no need to i--) because it's not being handled now
			// You don't need to do remove the label, even for those with zero uses,
			// because labels are going to be removed anyway
		}
	}

	// If a label definition is followed by a goto for a different label,
	// then the previous label registration can be replaced with following goto value
	const labelDefThenDifferentGotoLabel = {}; // Record<string, string>
	actions.forEach((action: AnyNode, i: number) => {
		if (isLabelDefinition(action)) {
			const next = actions[i + 1];
			if (isGotoLabel(next)) {
				labelDefThenDifferentGotoLabel[action.label] = next.label;
			}
		}
	});
	actions.forEach((action: AnyNode) => {
		if (isGotoLabel(action)) {
			const alias = labelDefThenDifferentGotoLabel[action.label];
			if (alias) {
				action.label = alias;
			}
		}
	});
	return actions;
};
