import { Node as TreeSitterNode } from 'web-tree-sitter';
import { getBoolFieldForAction } from './parser-bytecode-info.ts';
import {
	type AnyNode,
	type MGSLocation,
	type MGSMessage,
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
	newLabelDefinition,
	newGotoLabel,
	newSequence,
	newCheckSaveFlag,
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

const printableLocation = (fileMap: FileMap, location: MGSLocation): string => {
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

export const printableMGSMessage = (fileMap: FileMap, prefix: string, v: MGSMessage): string => {
	let message =
		`${prefix}: ${v.message}\n` +
		v.locations
			.map((location) => {
				return printableLocation(fileMap, location);
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

export const expandBoolExpression = (
	f: FileState,
	node: TreeSitterNode,
	condition: BoolExpression,
	ifLabel: string,
): AnyNode[] => {
	if (condition === true) {
		return [newGotoLabel(f, node, ifLabel)];
	} else if (condition === false) {
		return [];
	}
	if (typeof condition === 'string') {
		return [
			{
				...newCheckSaveFlag(f, node, condition, true),
				label: ifLabel,
			},
		];
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
		return [
			...expandBoolExpression(f, condition.lhsNode, lhs, ifLabel),
			...expandBoolExpression(f, condition.rhsNode, rhs, ifLabel),
		];
	}
	if (op === '&&') {
		// have a separate if-else insert?
		// if first one is false goto a rendezvous at the end of the insert
		// if the second one is false, ditto
		const suffix = f.p.advanceGotoSuffix();
		const innerIfTrueLabel = `if true #${suffix}`;
		const innerRendezvousLabel = `rendezvous #${suffix}`;
		return [
			...expandBoolExpression(f, condition.lhsNode, lhs, innerIfTrueLabel),
			newGotoLabel(f, node, innerRendezvousLabel),
			newLabelDefinition(f, node, innerIfTrueLabel),
			...expandBoolExpression(f, condition.rhsNode, rhs, ifLabel),
			newLabelDefinition(f, node, innerRendezvousLabel),
		];
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
			lhs: invertBoolExpression(f, condition.lhsNode, lhs),
			rhs: invertBoolExpression(f, condition.rhsNode, rhs),
			lhsNode: condition.lhsNode,
			rhsNode: condition.rhsNode,
		},
		lhsNode: condition.lhsNode,
		rhsNode: condition.rhsNode,
	};
	return expandBoolExpression(f, node, expandAs, ifLabel);
};

export const invertBoolExpression = (
	f: FileState,
	node: TreeSitterNode,
	boolExp: BoolExpression,
): BoolExpression => {
	if (typeof boolExp === 'boolean') return !boolExp;
	if (typeof boolExp === 'string') {
		return newCheckSaveFlag(f, node, boolExp, false);
	}
	if (isBoolBinaryExpression(boolExp)) {
		if (boolExp.op === '||' || boolExp.op === '&&') {
			if (typeof boolExp.lhs === 'number' || typeof boolExp.rhs === 'number') {
				throw new Error('|| or && for a number??');
			}
			const invertedLHS = invertBoolExpression(f, node, boolExp.lhs);
			boolExp.lhs = invertedLHS;
			const invertedRHS = invertBoolExpression(f, node, boolExp.rhs);
			boolExp.rhs = invertedRHS;
		}
		boolExp.op = inverseOpMap[boolExp.op];
		return boolExp;
	}
	const param = getBoolFieldForAction(boolExp.action);
	boolExp[param] = !boolExp[param];
	return boolExp;
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
		newGotoLabel(f, node, rendezvousLabel),
		newLabelDefinition(f, node, ifLabel),
		...ifBody,
		newLabelDefinition(f, node, rendezvousLabel),
	];
	return newSequence(f, node, steps, 'simpleBranchMaker');
};

export const simplifyLabelGotos = (actions: AnyNode[]): AnyNode[] => {
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
