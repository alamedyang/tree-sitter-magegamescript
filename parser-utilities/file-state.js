
const makeFileState = (fileName, parser) => {
	const f = {
		fileName,
		constants: {},
		settings: {
			default: {},
			entity: {},
			label: {},
			serial: {},
		},
		errors: [],
		warnings: [],
		nodes: [],
		parser,
	};
	const newWarningOrError = (location, message, type) => {
		const locations = Array.isArray(location)
			? location
			: [ location ];
		locations.forEach(item=>{
			if (!item.fileName) item.fileName = f.fileName;
		})
		f[type].push({ message, locations });
	}
	f.newWarning = (location, message) => newWarningOrError(location, message, 'warnings');
	f.newError = (location, message) => newWarningOrError(location, message, 'errors');
	f.mergeF = (newF) => {
		Object.keys(newF.constants).forEach(constantName=>{
			if (f.constants[constantName]) {
				f.newError(
					{
						node: newF.constants[constantName].node, 
						fileName: newF.fileName,
					},
					`cannot redefine constant ${constantName} (via 'include_macro')`
				);
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
	}
	return f;
};

module.exports = {
	makeFileState,
};
