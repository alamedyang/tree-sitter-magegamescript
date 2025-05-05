const fs = require('node:fs');
const path = require('node:path');

const { ansiTags: ansi } = require('./parser-dialogs.js');
const { makeMessagePrintable } = require('./parser-utilities.js');
const { makeFileState } = require('./parser-file.js')
const handleNode = require('./parser-node.js');

// stolen from the other place
const makeMap = path => {
	let map = {};
	for (file of fs.readdirSync(
		path,
		{ withFileTypes: true }
	)) {
		if (file.name === '.DS_Store') continue;
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
		errorCount: 0,
		warningCount: 0,
		newError: (v) => {
			p.errors.push(v);
			p.errorCount += 1;
		},
		newWarning: (v) => {
			p.warnings.push(v);
			p.warningCount += 1;
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
						p.newError({
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
		reportProblems: () => {
			const messages = [];
			const errCount = p.errorCount;
			const warnCount = p.warningCount;
			if (errCount) {
				messages.push(
					`${ansi.r}`
					+ `${errCount} error`
					+ `${errCount !== 1 ? 's' : ''}`
					+ `${ansi.reset}`
				)
			}
			if (warnCount) {
				messages.push(
					`${ansi.y}`
					+ `${warnCount} warning`
					+ `${warnCount !== 1 ? 's' : ''}`
					+ `${ansi.reset}`
				);
			}
			if (messages.length === 0) {
				console.log("No issues found!");
			} else {
				console.log(`Issues found: ${messages.join(', ')}`)
			}
			p.warnings.forEach(v=>{
				const s = ansi.y
					+ makeMessagePrintable(p.fileMap, 'Warning', v)
					+ ansi.reset;
				console.warn(s);
			})
			p.errors.forEach(v=>{
				const s = ansi.r
					+ makeMessagePrintable(p.fileMap, 'Error', v)
					+ ansi.reset;
				console.error(s);
			})
		},
		parseFile: (fileName) => {
			const fileMap = p.fileMap;
			const tree = parser.parse(fileMap[fileName].text);
			let document = tree.rootNode;
			const f = makeFileState(p, fileName, p.parser);
			const nodes = document.namedChildren
				.map(node=>handleNode(f, node))
				.flat();
			f.nodes = nodes;
			fileMap[fileName].parsed = f;
			return f;
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
};

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
