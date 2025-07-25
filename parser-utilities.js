import { getBoolFieldForAction } from './parser-bytecode-info.ts';

export let verbose = false;
export const debugLog = (message) => {
	if (verbose) console.log(message);
};
export const ansiTags = {
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
const temporaries = [];
let temporaryStep = 0;
export const newTemporary = (value) => {
	if (temporaries.length === 0 && value !== undefined) {
		temporaries.unshift(value);
	} else {
		temporaries.unshift(TEMP + temporaryStep);
		temporaryStep += 1;
	}
	return temporaries[0];
};
export const dropTemporary = () => {
	temporaryStep -= 1;
	temporaryStep = temporaryStep < 0 ? 0 : temporaryStep;
	return temporaries.shift();
};
export const quickTemporary = () => {
	newTemporary();
	return dropTemporary();
};
export const latestTemporary = () => temporaries[0];

export const inverseOpMap = {
	'<': '>=',
	'<=': '>',
	'>=': '<',
	'>': '<=',
	'==': '!=',
	'!=': '==',
	'&&': '||',
	'||': '&&',
};
export const reportMissingChildNodes = (f, node) => {
	const missingNodes = node.children.filter((child) => child.isMissing);
	missingNodes.forEach((missingChild) => {
		f.newError({
			locations: [{ node: missingChild }],
			message: `missing token: ${missingChild.type}`,
		});
	});
	return missingNodes;
};
export const reportErrorNodes = (f, node) => {
	const errorNodes = node.namedChildren.filter((child) => child.type === 'ERROR');
	errorNodes.forEach((errorNode) => {
		f.newError({
			locations: [{ node: errorNode }],
			message: 'syntax error',
		});
	});
	return errorNodes;
};

const getPrintableLocationData = (fileMap, location) => {
	const fileName = location.fileName;
	const allLines = fileMap[fileName].fileText.split('\n');
	let row = location.node.startPosition.row;
	let col = location.node.startPosition.column;
	let endRow = location.node.endPosition.row;
	let endCol = location.node.endPosition.column;
	const line = allLines[row].replaceAll('\t', ' ');
	const squigglySize = row === endRow ? endCol - col : allLines[row].length - col;
	const arrow = '~'.repeat(col) + '^'.repeat(squigglySize);
	const message = `╓-${fileName} ${row}:${col}\n` + '║ ' + `${line}\n` + '╙~' + arrow;
	return message;
};

export const makeMessagePrintable = (fileMap, prefix, item) => {
	let message =
		`${prefix}: ${item.message}\n` +
		item.locations
			.map((location) => {
				return getPrintableLocationData(fileMap, location);
			})
			.join('\n');
	if (item.footer) {
		message += '\n' + item.footer;
	}
	return message + '\n';
};
export const autoIdentifierName = (f, node) => {
	return f.fileName + '-' + node.startPosition.row + ':' + node.startPosition.column;
};
// todo: get rid of 'invert' flag for things with 'expected_bool'! Just use that!
export const expandCondition = (f, node, condition, ifLabel) => {
	if (
		condition.mathlang === 'bool_getable' ||
		condition.mathlang === 'bool_comparison' ||
		condition.mathlang === 'string_checkable' ||
		condition.mathlang === 'number_checkable_equality'
	) {
		const action = {
			...condition,
			expected_bool: condition.expected_bool === undefined ? true : condition.expected_bool,
			mathlang: 'if_branch_goto_label',
			label: ifLabel,
		};
		return [action];
	}
	if (condition === true) {
		return [gotoLabel(f, node, ifLabel)];
	} else if (condition === false) {
		return [];
	}
	if (typeof condition === 'string') {
		const action = checkFlag(f, node, condition, ifLabel, true);
		action.mathlang = 'if_branch_goto_label';
		return [action];
	}
	if (condition.mathlang !== 'bool_binary_expression') {
		throw new Error('not yet implemented');
	}
	const op = condition.op;
	const lhs = condition.lhs;
	const rhs = condition.rhs;
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
			gotoLabel(f, node, innerRendezvousLabel),
			label(f, node, innerIfTrueLabel),
			expandCondition(f, condition.rhsNode, rhs, ifLabel),
			label(f, node, innerRendezvousLabel),
		];
		return inner.flat();
	}
	if (op !== '==' && op !== '!=') {
		throw new Error('What kind of other thing is this?');
	}
	// todo: if any of these are == bool literal, they can be simplified
	// Cannot directly compare bools. Must branch on if they are both true, or both false
	const expandAs = {
		mathlang: 'bool_binary_expression',
		debug: {
			node: condition.node,
			fileName: f.fileName,
		},
		op: '||',
		lhs: {
			mathlang: 'bool_binary_expression',
			debug: {
				node: condition.node,
				fileName: f.fileName,
			},
			op: '&&',
			lhs,
			rhs,
		},
		rhs: {
			mathlang: 'bool_binary_expression',
			debug: {
				node: condition.node,
				fileName: f.fileName,
			},
			op: '&&',
			lhs: invert(lhs),
			rhs: invert(rhs),
		},
	};
	return expandCondition(f, node, expandAs, ifLabel);
};

export const simpleBranchMaker = (f, node, _branchAction, _ifBody, _elseBody) => {
	const ifBody = Array.isArray(_ifBody) ? _ifBody : [_ifBody];
	const elseBody = Array.isArray(_elseBody) ? _elseBody : [_elseBody];
	const gotoLabel = f.p.advanceGotoSuffix();
	const ifLabel = `if #${gotoLabel}`;
	const rendezvousLabel = `rendezvous #${gotoLabel}`;
	const branchAction = {
		..._branchAction,
		label: ifLabel,
	};
	const steps = [
		branchAction,
		...elseBody,
		{ mathlang: 'goto_label', label: rendezvousLabel },
		{ mathlang: 'label_definition', label: ifLabel },
		...ifBody,
		{ mathlang: 'label_definition', label: rendezvousLabel },
	];
	return newSequence(f, node, steps, 'simple branch on');
};

export const invert = (f, node, boolExp) => {
	if (typeof boolExp === 'boolean') return !boolExp;
	if (typeof boolExp === 'string') {
		return checkFlag(f, node, boolExp, '', false);
	}
	if (boolExp.mathlang === 'bool_binary_expression') {
		if (boolExp.op === '||' || boolExp.op === '&&') {
			boolExp.lhs = invert(f, node, boolExp.lhs);
			boolExp.rhs = invert(f, node, boolExp.rhs);
		}
		boolExp.op = inverseOpMap[boolExp.op];
		return boolExp;
	}
	const param = getBoolFieldForAction(boolExp.action);
	boolExp[param] = !boolExp[param];
	return boolExp;
};

export const label = (f, node, label) => ({
	mathlang: 'label_definition',
	label,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const gotoLabel = (f, node, label) => ({
	mathlang: 'goto_label',
	label,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const newComment = (comment) => ({ mathlang: 'comment', comment });
export const newSequence = (f, node, steps, _type) => {
	const type = _type || 'generic_sequence';
	const comment = node.text.replace(/[\n\s\t]+/g, ' ');
	steps.unshift(newComment(`${type}: ${comment}`));
	const flatSteps = [];
	steps
		.filter((v) => v !== null) // might not need this anymore
		.forEach((v) => {
			if (v.mathlang === 'sequence') {
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
export const newDialog = (f, node, dialogName, dialogs) => ({
	mathlang: 'dialog_definition',
	dialogName,
	dialogs,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const showDialog = (f, node, name) => ({
	action: 'SHOW_DIALOG',
	dialog: name,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const newSerialDialog = (f, node, serialDialogName, serialDialog) => ({
	mathlang: 'serial_dialog_definition',
	serialDialogName,
	serialDialog,
	debug: {
		node,
		fileName: f.fileName,
	},
});
export const showSerialDialog = (f, node, name, isConcat) => ({
	action: 'SHOW_SERIAL_DIALOG',
	disable_newline: isConcat,
	serial_dialog: name,
	debug: {
		node,
		fileName: f.fileName,
	},
});
const checkFlag = (f, node, save_flag, gotoLabel, expected_bool) => {
	return {
		mathlang: 'bool_getable',
		action: 'CHECK_SAVE_FLAG',
		save_flag,
		value: save_flag,
		expected_bool: expected_bool !== undefined ? expected_bool : true,
		label: gotoLabel || 'UNDEFINED LABEL',
		debug: {
			node,
			fileName: f.fileName,
		},
	};
};

export const flattenGotos = (actions) => {
	// const before = printScript('_', actions).split('\n');
	// A goto label followed by the same label definition can be removed
	for (let i = 0; i < actions.length; i++) {
		const action = actions[i];
		const next = actions[i + 1];
		if (
			action.mathlang === 'goto_label' &&
			next?.mathlang === 'label_definition' &&
			next?.label === action.label
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
	actions.forEach((action, i) => {
		if (action.mathlang === 'label_definition') {
			const next = actions[i + 1];
			if (next?.mathlang === 'goto_label') {
				if (!next.label) {
					throw new Error('NO LABEL');
				}
				labelDefThenDifferentGotoLabel[action.label] = next.label;
			}
		}
	});
	actions.forEach((action) => {
		if (action.mathlang?.includes('label') && action.mathlang !== 'label_definition') {
			if (!action.label) {
				throw new Error('NO LABEL');
			}
			const alias = labelDefThenDifferentGotoLabel[action.label];
			if (alias) {
				action.label = alias;
			}
		}
	});
	// const after = printScript('_', actions).split('\n');
	// console.log(before, after);
	return actions;
};
