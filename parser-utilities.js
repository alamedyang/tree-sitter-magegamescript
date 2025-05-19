let verbose = false;
const debugLog = (message) => { if (verbose) console.log(message); };

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
	const allLines = fileMap[fileName].text.split('\n');
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
const expandCondition = (f, node, condition, ifLabel) => {
	if (
		condition.mathlang === 'bool_getable'
		|| condition.mathlang === 'number_checkable_equality'
		|| condition.mathlang === 'string_checkable'
		|| condition.mathlang === 'bool_comparison'
	) {
		const action = {
			...condition,
			expected_bool: condition.expected_bool === undefined
				? true
				: condition.expected_bool,
			mathlang: 'goto_label',
			label: ifLabel,
		}
		if (action.invert) {
			action.expected_bool = !action.expected_bool;
		}
		return [ action ];
	}
	if (condition === true) {
		return [ gotoLabel(f, node, ifLabel) ];
	} else if (condition === false) {
		return [];
	}
	if (condition.mathlang === 'check_save_flag') {
		const expected_bool = !condition.invert;
		return {
			action: "CHECK_SAVE_FLAG",
			expected_bool,
			save_flag: condition.value,
		}
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
		// have a separate if else insert?
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
	if (op === '!=') rhs.invert = !rhs.invert;
	// todo: if any of these are == bool literal, they can be simplified
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
			lhs: typeof lhs === 'boolean'
				? lhs
				: {
					...condition.lhs,
					debug: condition.lhsNode,
					expected_bool: !condition.lhs.invert,
				},
			rhs: typeof rhs === 'boolean'
				? rhs
				: {
					...condition.rhs,
					debug: condition.rhsNode,
					expected_bool: !condition.rhs.invert,
				},
		},
		rhs: {
			mathlang: 'bool_binary_expression',
			debug: condition.node,
			fileName: f.fileName,
			op: '&&',
			lhs: typeof lhs === 'boolean'
				? !lhs
				: {
					...condition.lhs,
					debug: condition.lhsNode,
					expected_bool: !!condition.lhs.invert,
				},
			rhs: typeof rhs === 'boolean'
				? !rhs
				: {
					...condition.rhs,
					debug: condition.rhsNode,
					expected_bool: !!condition.rhs.invert,
				},
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
		{ mathang: 'goto_label', label: rendezvousLabel },
		{ mathang: 'label_definition', label: ifLabel },
		...ifBody,
		{ mathang: 'label_definition', label: rendezvousLabel },
	];
	return newMathSequence(f, node, steps);
};

const label = (f, node, label) => ({
	mathang: 'label_definition',
	label,
	// debug: node,
	// fileName: f.fileName,
});
const gotoLabel = (f, node, label) => ({
	mathang: 'goto_label',
	label,
	// debug: node,
	// fileName: f.fileName,
});

const newMathSequence = (f, node, steps) => ({
	mathlang: 'math_sequence',
	steps,
	debug: node,
	fileName: f.fileName
});
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
const newSerialDialog = (f, node, dialogName, serialDialog) => ({
	mathlang: 'serial_dialog_definition',
	dialogName,
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
	newMathSequence,
	newSerialDialog,
	showSerialDialog,
	newDialog,
	showDialog,
};
