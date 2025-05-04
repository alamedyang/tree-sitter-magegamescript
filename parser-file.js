const { ansiTags } = require('./parser-dialogs.js');

const makeFileState = (p, fileName, parser) => {
	const f = { // file
		p, // project
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
		newError: (message) => {
			message.locations.forEach(v=>v.fileName = fileName);
			p.newError(message);
			f.errorCount += 1;
		},
		newWarning: (message) => {
			message.locations.forEach(v=>v.fileName = fileName);
			p.newWarning(message);
			f.warningCount += 1;
		},
		includeFile: (newName) => {
			const newF = p.fileMap[newName].parsed;
			Object.keys(newF.constants).forEach(constantName=>{
				if (f.constants[constantName]) {
					f.newError({
						locations: [{
							fileName: newF.fileName,
							node: newF.constants[constantName].node, 
						}],
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
		printableMessageInformation: () => {
			const { errorCount, warningCount } = f;
			if (errorCount > 0 || warningCount > 0) {
				const errorMessage = errorCount
					? `${ansiTags.r}${errorCount} error${errorCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 errors`;
				const warningMessage = warningCount
					? `${ansiTags.y}${warningCount} warning${warningCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 warnings`;
				if (errorCount > 0 && warningCount > 0) {
					return `(${errorMessage}, ${warningMessage})`;
				} else if (errorCount > 0) {
					return `(${errorMessage})`;
				} else if (warningCount > 0) {
					return `(${warningMessage})`;
				}
			}
			return `(${ansiTags.g}OK${ansiTags.reset})`;
		},
	};
	return f;
};

module.exports = {
	makeFileState,
};
