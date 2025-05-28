const { getBoolFieldForAction } = require("./parser-bytecode-info");

let verbose = false;
const debugLog = (message) => { if (verbose) console.log(message); };

// ------------------------ TEMPORARY VARIABLE MANAGEMENT ------------------------ //

const TEMP = '__TEMP_'
const temporaries = [];
const newTemporary = () => {
	temporaries.unshift(TEMP + temporaries.length);
	return temporaries[0];
};
const dropTemporary = () => temporaries.shift();
const quickTemporary = () => {
	newTemporary();
	return dropTemporary();
}
const latestTemporary = () => temporaries[0];

const inverseOpMap = {
	'<': '>=',
	'<=': '>',
	'>=': '<',
	'>': '<=',
	'==': '!=',
	'!=': '==',
	'&&': '||',
	'||': '&&',
};
const reportMissingChildNodes = (f, node) => {
	const missingNodes = node.children
		.filter(child=>child.isMissing);
	missingNodes.forEach(missingChild=>{
		f.newError({
			locations: [{ node: missingChild }],
			message: `missing token: ${missingChild.type}`
		});
	});
	return missingNodes;
};
const reportErrorNodes = (f, node) => {
	const errorNodes = node.namedChildren
		.filter(child=>child.type === 'ERROR');
	errorNodes.forEach(errorNode=>{
		f.newError({
			locations: [{ node: errorNode }],
			message: 'syntax error',
		})
	})
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
	const squigglySize = row === endRow
		? endCol - col
		: allLines[row].length - col;
	const arrow = '~'.repeat(col) + '^'.repeat(squigglySize);
	const message
		= `╓-${fileName} ${row}:${col}\n`
		+ '║ ' + `${line}\n`
		+ '╙~' + arrow;
	return message;
};

const makeMessagePrintable = (fileMap, prefix, item) => {
	let message = `${prefix}: ${item.message}\n`
		+ item.locations.map(location=>{
			return getPrintableLocationData(fileMap, location);
		}).join('\n');
	if (item.footer) {
		message += '\n' + item.footer;
	}
	return message + '\n';
};
const autoIdentifierName = (f, node) => {
	return f.fileName
		+ '-' + node.startPosition.row
		+ ':' + node.startPosition.column;
};
// todo: get rid of 'invert' flag for things with 'expected_bool'! Just use that!
const expandCondition = (f, node, condition, ifLabel) => {
	if (
		condition.mathlang === 'bool_getable'
		|| condition.mathlang === 'bool_comparison'
		|| condition.mathlang === 'string_checkable'
		|| condition.mathlang === 'number_checkable_equality'
	) {
		const action = {
			...condition,
			expected_bool: condition.expected_bool === undefined
				? true
				: condition.expected_bool,
			mathlang: 'if_branch_goto_label',
			label: ifLabel,
		}
		return [ action ];
	}
	if (condition === true) {
		return [ gotoLabel(f, node, ifLabel) ];
	} else if (condition === false) {
		return [];
	}
	if (typeof condition === 'string') {
		const action = checkFlag(f, node, condition, ifLabel, true)
		action.mathlang = 'if_branch_goto_label';
		return [ action ];
	}
	if (condition.mathlang !== 'bool_binary_expression') {
		throw new Error("not yet implemented")
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
		const innerIfTrueLabel = `if true #${f.p.advanceGotoSuffix()}`;
		const innerRendezvousLabel = `rendezvous #${f.p.getGotoSuffix()}`;
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
		throw new Error ("What kind of other thing is this?")
	}
	// todo: if any of these are == bool literal, they can be simplified
	// Cannot directly compare bools. Must branch on if they are both true, or both false
	const expandAs = {
		mathlang: 'bool_binary_expression',
		debug: condition.node,
		fileName: f.fileName,
		op: '||',
		lhs: {
			mathlang: 'bool_binary_expression',
			debug: condition.node,
			fileName: f.fileName,
			op: '&&',
			lhs,
			rhs,
		},
		rhs: {
			mathlang: 'bool_binary_expression',
			debug: condition.node,
			fileName: f.fileName,
			op: '&&',
			lhs: invert(lhs),
			rhs: invert(rhs),
		}
	}
	return expandCondition(f, node, expandAs, ifLabel);
};

const simpleBranchMaker = (f, node, _branchAction, _ifBody, _elseBody) => {
	const ifBody = Array.isArray(_ifBody) ? _ifBody : [ _ifBody ];
	const elseBody = Array.isArray(_elseBody) ? _elseBody : [ _elseBody ];
	const gotoLabel = f.p.getGotoSuffix();
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

const invert = (f, node, boolExp) => {
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

const label = (f, node, label) => ({
	mathlang: 'label_definition',
	label,
	// debug: node,
	// fileName: f.fileName,
});
const gotoLabel = (f, node, label) => ({
	mathlang: 'goto_label',
	label,
	// debug: node,
	// fileName: f.fileName,
});
const newComment = (comment) => ({ mathlang: 'comment', comment });
const newSequence = (f, node, steps, _type) => {
	const type = _type || 'generic_sequence';
	const comment = node.text.replace(/[\n\s\t]+/g, ' ');
	steps.unshift(newComment(`${type}: ${comment}`));
	return {
		mathlang: 'sequence',
		type,
		steps,
		debug: node,
		fileName: f.fileName
	};
};
const newDialog = (f, node, dialogName, dialogs) => ({
	mathlang: 'dialog_definition',
	dialogName,
	dialogs,
	debug: node,
	fileName: f.fileName,
});
const showDialog = (f, node, name) => ({
	action: 'SHOW_DIALOG',
	dialog: name,
	debug: node,
	fileName: f.fileName
});
const newSerialDialog = (f, node, serialDialogName, serialDialog) => ({
	mathlang: 'serial_dialog_definition',
	serialDialogName,
	serialDialog,
	debug: node,
	fileName: f.fileName,
});
const showSerialDialog = (f, node, name, isConcat) => ({
	action: 'SHOW_SERIAL_DIALOG',
	disable_newline: !isConcat,
	serial_dialog: name,
	debug: node,
	fileName: f.fileName
});
const checkFlag = (f, node, save_flag, gotoLabel, expected_bool) => {
	return {
		mathlang: 'bool_getable',
		action: "CHECK_SAVE_FLAG",
		save_flag,
		value: save_flag,
		expected_bool: expected_bool !== undefined ? expected_bool : true,
		label: gotoLabel || 'UNDEFINED LABEL',
		fileName: f.fileName,
		debug: node,
	}
};

const flattenGotos = (actions) => {
	// replace labels of k with v; remove label definitions for k
	const labelDefThenGotoLabel = {}; // Record<string, string>
	// Index of label definition where there's a goto for that k immediately before
	const gotoLabelThenLabelDef = {}; // Record<string, number>
	actions.forEach((action, i)=>{
		if (action.mathlang === 'label_definition') {
			const next = actions[i+1];
			if (next?.mathlang === 'goto_label') {
				labelDefThenGotoLabel[action.label] = next.label;
			}
		} else if (action.mathlang === 'goto_label') {
			const next = actions[i+1];
			if (next.mathlang === 'label_definition' && next.label === action.label) {
				gotoLabelThenLabelDef[action.label] = i;
			}
		}
	});
	let queue = actions;
	let processed = [];
	Object.keys(gotoLabelThenLabelDef).reverse().forEach(k=>{
		const uses = actions.filter(v=>v.mathlang === "goto_label" && v.label === k);
		if (uses.length === 1) {
			const index = gotoLabelThenLabelDef[k];
			const cut = queue.splice(index, 2);
			debugLog('reduced goto: ', JSON.stringify(cut));
		} else {
			const index = gotoLabelThenLabelDef[k];
			const cut = queue.splice(index, 1);
			debugLog('reduced goto: ', JSON.stringify(cut));
		}
	});
	Object.entries(labelDefThenGotoLabel).forEach(([k, v])=>{
		for (let i = 0; i < queue.length; i++) {
			const action = queue[i];
			if (action.label === k) {
				if (action.mathlang === 'label_definition') {
					// do nothing (it dies)
				} else if (action.mathlang === 'goto_label') {
					action.label = v;
					processed.push(action);
				}
			} else if (
				action.label === v
				&& action.mathlang === 'goto_label'
			) {
				// do nothing (it dies)
			} else {
				processed.push(action);
			}
		}
		queue = processed;
		processed = [];
	});
	return queue;
};

module.exports = {
	verbose,
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	makeMessagePrintable,
	autoIdentifierName,
	expandCondition,
	label,
	gotoLabel,
	simpleBranchMaker,
	newSequence,
	newComment,
	newSerialDialog,
	showSerialDialog,
	newDialog,
	showDialog,
	flattenGotos,
	invert,
	inverseOpMap,
	newTemporary,
	dropTemporary,
	quickTemporary,
	latestTemporary,
};
