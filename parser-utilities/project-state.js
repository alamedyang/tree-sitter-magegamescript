const fs = require('node:fs');
const path = require('node:path');

const { makeMessagePrintable } = require('./general.js');

// stolen from the other place
const makeMap = path => {
	let map = {};
	for (file of fs.readdirSync(
		path,
		{ withFileTypes: true }
	)) {
		let filePath = `${path}/${file.name}`

		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath)
			};
		} else {
			let text = fs.readFileSync(filePath, 'utf-8')
			let type = filePath.split('.').pop()
			map[file.name] = {
				fileName: file.name,
				type,
				text,
			}
		}
	}
	return map;
}

const makeProjectState = (parser) => {
	const inputPath = path.resolve('./scenario_source_files');
	const fileMap = makeMap(inputPath);
	const p = { // 'project' :P
		fileMap,
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
			data.actions = finalizeActions(p, data.actions, fileName).flat();
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
						// TODO: use new error paradigm instead
						p.errors.push({
							locations: entry.duplicates.map(dupe=>({
								fileName: dupe.fileName,
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

// TODO: move these out of here
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
				.map(step=>mathSequence[step.type](step))
				.forEach(v=>ret.push(v));
		}
	})
	return ret;
};

module.exports = {
	makeProjectState,
};
