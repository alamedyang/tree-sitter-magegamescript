const reportAnyMissingChildren = (f, node) => {
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
const reportAnyErrors = (f, node) => {
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

module.exports = {
	reportAnyMissingChildren,
	reportAnyErrors,
};
