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

const simpleBranchMaker = (f, _branchAction, _ifBody, _elseBody) => {
	const ifBody = Array.isArray(_ifBody) ? _ifBody : [ _ifBody ];
	const elseBody = Array.isArray(_elseBody) ? _elseBody : [ _elseBody ];

	const gotoLabel = f.p.gotoSuffix();
	const ifLabel = `if #${gotoLabel}`;
	const rendezvousLabel = `rendezvous #${gotoLabel}`;

	const branchAction = structuredClone(_branchAction);
	branchAction.label = ifLabel;

	const steps = [
		branchAction,
		...elseBody,
		{ mathang: 'goto_label', label: rendezvousLabel, },
		{ mathang: 'label_definition', label: ifLabel, },
		...ifBody,
		{ mathang: 'label_definition', label: rendezvousLabel, },
	];
	return {
		mathlang: 'math_sequence',
		steps: steps.map(v=>({ ...v, node, fileName: f.fileName })),
	};
};

module.exports = {
	verbose,
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	makeMessagePrintable,
	autoIdentifierName,
	simpleBranchMaker,
};
