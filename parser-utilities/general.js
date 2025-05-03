const reportMissingChildNodes = (f, node) => {
	const missingNodes = node.children
		.filter(child=>child.isMissing);
	missingNodes.forEach(missingChild=>{
		f.newError(
			{ node: missingChild },
			`missing token: ${missingChild.type}`,
		);
	});
	return missingNodes;
};
const reportErrorNodes = (f, node) => {
	const errorNodes = node.namedChildren
		.filter(child=>child.type === 'ERROR');
	errorNodes.forEach(errorNode=>{
		f.newError(
			{ node: errorNode },
			'syntax error'
		)
	})
	return errorNodes;
};

const getPrintableLocationData = (fileMap, location) => {
	const fileName = location.fileName;
	const allLines = fileMap[fileName].text.split('\n');
	let row = location.node.startPosition.row;
	let col = location.node.startPosition.column;
	const line = allLines[row].replaceAll('\t', ' ');
	const arrow = '~'.repeat(col) + '^';
	const message
		= `╓-${fileName} ${row}:${col}\n`
		+ '║ ' + `${line}\n`
		+ '╙~' + arrow;
	return message;
};

const makeMessagePrintable = (fileMap, prefix, item) => {
	return `\n${prefix}: ${item.message}\n`
		+ item.locations.map(location=>{
			return getPrintableLocationData(fileMap, location);
		}).join('\n');
};

module.exports = {
	reportMissingChildNodes,
	reportErrorNodes,
	makeMessagePrintable,
};
