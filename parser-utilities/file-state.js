const makeFileState = (p, fileName, parser) => {
	const f = {
		p,
		fileName,
		constants: {},
		settings: {
			default: {},
			entity: {},
			label: {},
			serial: {},
		},
		nodes: [],
		errorCount: 0,
		warningCount: 0,
		parser,
		newError: (args) => {
			p.newError({fileName, ...args});
			f.errorCount += 1;
		},
		newWarning: (args) => {
			p.newWarning({fileName, ...args})
			f.warningCount += 1;
		},
		includeFile: (newName) => {
			const newF = p.fileMap[newName].parsed;
			Object.keys(newF.constants).forEach(constantName=>{
				if (f.constants[constantName]) {
					f.newError({
						fileName: newF.fileName,
						node: newF.constants[constantName].node, 
						message: `cannot redefine constant ${constantName} (via 'include')`
					});
				}
				f.constants[constantName] = newF.constants[constantName];
			});
			newF.nodes.forEach(node=>{ f.nodes.push(node) });
			['default', 'serial'].forEach(type=>{
				Object.keys(newF.settings[type]).forEach(param=>{
					f.settings[type][param] = newF.settings[type][param];
				});
			});
			['entity', 'label'].forEach(type=>{
				Object.keys(newF.settings[type]).forEach(target=>{
					const params = Object.keys(newF.settings[type][target]);
					f.settings[type][target] = f.settings[type][target] || {};
					params.forEach(param=>{
						f.settings[type][target][param] = newF.settings[type][target][param];
					});
				});
			});
		},
	};
	return f;
};

module.exports = {
	makeFileState,
};
