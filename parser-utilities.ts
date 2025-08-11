import { Node as TreeSitterNode } from 'web-tree-sitter';
import { getBoolFieldForAction, type MGSDebug } from './parser-bytecode-info.ts';
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
	isBoolExpression,
	type BoolComparison,
	type BoolGetable,
} from './parser-types.ts';
import { type FileState } from './parser-file.ts';
import { type FileMap } from './parser-project.ts';
import {
	handleCapture,
	handleNamedChildren,
	mandatoryChildForFieldName,
} from './parser-capture.ts';

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

export const autoDebug = (f: FileState, node: TreeSitterNode): MGSDebug => {
	return {
		node,
		fileName: f.fileName,
	};
};
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
		// basically nesting the ifs
		const suffix = f.p.advanceGotoSuffix();
		const secondIfTrueLabel = `if true #${suffix}`;
		const secondRendezvousLabel = `rendezvous #${suffix}`;
		return [
			...expandBoolExpression(f, condition.lhsNode, lhs, secondIfTrueLabel),
			newGotoLabel(f, node, secondRendezvousLabel),
			newLabelDefinition(f, node, secondIfTrueLabel),
			...expandBoolExpression(f, condition.rhsNode, rhs, ifLabel),
			newLabelDefinition(f, node, secondRendezvousLabel),
		];
	}
	if (op !== '==' && op !== '!=') {
		throw new Error('expected == or !==, found ' + op);
	}
	// Cannot directly compare bools. Must branch on if they are both true, or both false
	const expandAs: BoolBinaryExpression = {
		mathlang: 'bool_binary_expression',
		debug: autoDebug(f, condition.debug?.node || node),
		op: '||',
		lhs: {
			mathlang: 'bool_binary_expression',
			debug: autoDebug(f, condition.debug?.node || node),
			op: '&&',
			lhs,
			rhs,
			lhsNode: condition.lhsNode,
			rhsNode: condition.rhsNode,
		},
		rhs: {
			mathlang: 'bool_binary_expression',
			debug: autoDebug(f, condition.debug?.node || node),
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
	condition: BoolGetable | BoolComparison | BoolBinaryExpression,
	trueBlock: AnyNode[],
	falseBlock: AnyNode[],
): MathlangSequence => {
	const n = f.p.advanceGotoSuffix();
	const ifLabel = `if true #${n}`;
	const rendezvousLabel = `rendezvous #${n}`;

	let top: AnyNode[] = [];
	if (isBoolComparison(condition) || isBoolGetable(condition)) {
		top = [
			{
				...condition,
				label: ifLabel,
			},
		];
	} else if (isBoolBinaryExpression(condition)) {
		top = expandBoolExpression(f, node, condition, ifLabel);
	}

	const steps = [
		...top,
		...falseBlock,
		newGotoLabel(f, node, rendezvousLabel),
		newLabelDefinition(f, node, ifLabel),
		...trueBlock,
		newLabelDefinition(f, node, rendezvousLabel),
	];
	return newSequence(f, node, steps, 'longerBranchMaker');
};

export type ConditionalBlock = {
	condition: BoolExpression;
	conditionNode?: TreeSitterNode;
	body: AnyNode[];
	bodyNode?: TreeSitterNode;
	debug: MGSDebug;
};
export const newConditionalBlock = (
	f: FileState,
	node: TreeSitterNode,
	type: string,
): ConditionalBlock => {
	const conditionNode = mandatoryChildForFieldName(f, node, 'condition');
	const condition = handleCapture(f, conditionNode);
	if (!isBoolExpression(condition)) {
		throw new Error(type + ' condition not BoolExpression');
	}
	const bodyNode = node.childForFieldName('body');
	if (!bodyNode) throw new Error(type + ' lacks a body');
	const body = handleNamedChildren(f, bodyNode);
	return {
		condition,
		conditionNode,
		body,
		bodyNode,
		debug: autoDebug(f, node),
	};
};
export const newElse = (f: FileState, elseNode: TreeSitterNode | null): AnyNode[] => {
	let elseBody: AnyNode[] = [];
	if (elseNode && elseNode.lastChild) {
		elseBody = handleNamedChildren(f, elseNode.lastChild);
	}
	return elseBody;
};

export const ifChainMaker = (
	f: FileState,
	node: TreeSitterNode,
	iffs: ConditionalBlock[],
	elseBody: AnyNode[],
	label: string,
): MathlangSequence => {
	const rendezvousL: string = label + ` rendezvous #${f.p.advanceGotoSuffix()}`;
	const steps: AnyNode[] = [];
	let bottomSteps: AnyNode[] = [];

	iffs.forEach((iff) => {
		const ifL = `if true #${f.p.advanceGotoSuffix()}`;
		// add top half
		steps.push(
			...expandBoolExpression(f, iff.conditionNode || iff.debug.node, iff.condition, ifL),
		);
		// add bottom half
		const bottomInsert: AnyNode[] = [
			newLabelDefinition(f, iff.bodyNode || iff.debug.node, ifL),
			...iff.body,
			newGotoLabel(f, iff.bodyNode || iff.debug.node, rendezvousL),
		];
		bottomSteps = bottomInsert.concat(bottomSteps);
	});

	steps.push(...elseBody);
	steps.push(newGotoLabel(f, node, rendezvousL));
	const combined = steps.concat(bottomSteps);
	combined.push(newLabelDefinition(f, node, rendezvousL));
	return newSequence(f, node, combined, 'parser-node: ' + label);
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
