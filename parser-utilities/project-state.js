const { makeMessagePrintable } = require('./general.js');

const makeProjectState = (parser) => {
	const p = { // 'project' :P
		scripts: {},
		dialogs: {},
		serialDialogs: {},
		errors: [],
		warnings: [],
		parser,
		newError: ({location, message, fileName}) => {
			const locations = Array.isArray(location) ? location : [ location ];
			locations.forEach(item=>{
				if (!item.fileName) item.fileName = fileName || 'UNKNOWN FILE';
			})
			p.errors.push({ message, locations });
		},
		newWarning: ({location, message, fileName}) => {
			const locations = Array.isArray(location) ? location : [ location ];
			locations.forEach(item=>{
				if (!item.fileName) item.fileName = fileName || 'UNKNOWN FILE';
			})
			p.warnings.push({ message, locations });
		},
		addScript: (data, fileName) => {
			const scriptName = data.scriptName;
			data.rawActions = data.actions;
			data.actions = finalizeActions(p, data.actions, fileName);
			if (!p.scripts[scriptName]) {
				p.scripts[scriptName] = data;
			} else {
				if (!p.scripts[scriptName].duplicates) {
					p.scripts[scriptName].duplicates = [ p.scripts[scriptName] ];
				}
				p.scripts[scriptName].duplicates.push(data);
			}
		},
		addDialog: (data, fileName) => {
			const dialogName = data.dialogName;
			if (!p.dialogs[dialogName]) {
				p.dialogs[dialogName] = data;
			} else {
				if (!p.dialogs[dialogName].duplicates) {
					p.dialogs[dialogName].duplicates = [ p.dialogs[dialogName] ];
				}
				p.dialogs[dialogName].duplicates.push(data);
			}
		},
		addSerialDialog: (data, fileName) => {
			const serialDialogName = data.serialDialogName;
			if (!p.dialogs[serialDialogName]) {
				p.dialogs[serialDialogName] = data;
			} else {
				if (!p.dialogs[serialDialogName].duplicates) {
					p.dialogs[serialDialogName].duplicates = [ p.dialogs[serialDialogName] ];
				}
				p.dialogs[serialDialogName].duplicates.push(data);
			}
		},
		detectDuplicates: () => {
			[ 'scripts', 'dialogs', 'serialDialogs' ].forEach(category=>{
				const entries = Object.entries(p[category]);
				entries.forEach(([name, entry])=>{
					if (entry.duplicates) {
						p.errors.push({
							locations: entry.duplicates.map(dupe=>({
								fileName: dupe.fileName,
								// TODO: work this part out better
								node: dupe.debug.firstNamedChild,
							})),
							message: `multiple ${category} with name "${name}"`,
						});
					}
				});
			});
		},
		reportProblems: (fileMap) => {
			p.warnings.forEach(v=>{
				const s = makeMessagePrintable(fileMap, 'Warning', v);
				console.warn(s);
			})
			p.errors.forEach(v=>{
				const s = makeMessagePrintable(fileMap, 'Error', v);
				console.error(s);
			})
		},
	};
	return p;
};

const mathSequence = {
	copy_entity_value_to_entity_value: (step) => {
		const variable = '__TEMP';
		return [
			{
				mathlang: 'math_sequence', step,
				action: 'COPY_VARIABLE', inbound: true,
				...step.copyFrom, variable,
			},
			{
				mathlang: 'math_sequence', step,
				action: 'COPY_VARIABLE', inbound: false,
				...step.copyTo, variable,
			}
		];
	}
}

const finalizeActions = (p, rawActions, fileName) => {
	const ret = [];
	rawActions.forEach(node=>{
		if (!node.mathlang) {
			ret.push(node);
		} else if (node.mathlang === 'dialog_definition') {
			p.addDialog(node, fileName);
		} else if (node.mathlang === 'serial_dialog_definition') {
			p.addSerialDialog(node, fileName);
		} else if (node.mathlang === 'math_sequence') {
			node.steps
				.map(step=>mathSequence[step.type](p, step))
				.forEach(v=>ret.push(v));
		}
	})
	return ret;
};

module.exports = {
	makeProjectState,
};
