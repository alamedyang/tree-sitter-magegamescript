const { ansiTags: ansi } = require('./parser-dialogs.js');
const { makeMessagePrintable } = require('./parser-utilities.js');
const { makeFileState } = require('./parser-file.js')
const handleNode = require('./parser-node.js');

const makeProjectState = (tsParser, fileMap) => {
	// project crawl state
	const p = {
		parser: tsParser,
		fileMap,

		// auto counter, so that auto-generated gotos do not share labels:
		gotoSuffixValue: 0,

		// the global project things:
		scripts: {},
		dialogs: {},
		serialDialogs: {},

		// for printing fancy messages:
		errors: [],
		warnings: [],
		errorCount: 0,
		warningCount: 0,

		// provides the label suffix, then advances counter:
		gotoSuffix: () => p.gotoSuffixValue++,
		newError: (v) => {
			p.errors.push(v);
			p.errorCount += 1;
		},
		newWarning: (v) => {
			p.warnings.push(v);
			p.warningCount += 1;
		},

		// for adding a file's data to the project's

		addScript: (data, fileName) => {
			const scriptName = data.scriptName;
			data.rawNodes = data.actions;
			// finalize actions
			const finalizedActions = [];
			data.rawNodes.forEach(node=>{
				if (!node.mathlang) {
					finalizedActions.push(node);
				} else if (node.mathlang === 'dialog_definition') {
					// (sometimes these are inside a script body)
					p.addDialog(node, fileName);
				} else if (node.mathlang === 'serial_dialog_definition') {
					// (sometimes these are inside a script body)
					p.addSerialDialog(node, fileName);
				} else if (node.mathlang === 'math_sequence') {
					node.steps.forEach(step=>finalizedActions.push(step));
				} else {
					console.error(node);
					throw new Error ("HANDLE THIS 'MATHLANG' ACTION NODE PLEASE!")
				}
			});
			data.actions = finalizedActions.flat();
			// put it in the project
			if (!p.scripts[scriptName]) {
				// if not registered yet, add it
				p.scripts[scriptName] = data;
			} else {
				// if it's a duplicate, make an array for all the ones we find
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

		// can only be done after all files in a project are parsed
		detectDuplicates: () => {
			[ 'scripts', 'dialogs', 'serialDialogs' ].forEach(category=>{
				const entries = Object.entries(p[category]);
				entries.forEach(([name, entry])=>{
					if (entry.duplicates) {
						// note: one error message, multiple locations
						p.newError({
							message: `multiple ${category} with name "${name}"`,
							locations: entry.duplicates.map(dupe=>({
								fileName: dupe.fileName,
								node: dupe.debug.firstNamedChild,
							})),
						});
					}
				});
			});
		},

		// fancy console location printing for all collected problems
		printProblems: () => {
			const messages = [];
			const errCount = p.errorCount;
			const warnCount = p.warningCount;
			if (errCount) {
				messages.push(
					`${ansi.red}`
					+ `${errCount} error`
					+ `${errCount !== 1 ? 's' : ''}`
					+ `${ansi.reset}`
				)
			}
			if (warnCount) {
				messages.push(
					`${ansi.yellow}`
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
			p.warnings.forEach(message=>{
				const str = ansi.yellow
					+ makeMessagePrintable(p.fileMap, 'Warning', message)
					+ ansi.reset;
				console.warn(str);
			})
			p.errors.forEach(message=>{
				const str = ansi.red
					+ makeMessagePrintable(p.fileMap, 'Error', message)
					+ ansi.reset;
				console.error(str);
			})
		},

		// the actual owl
		parseFile: (fileName) => {
			const fileMap = p.fileMap;
			// tree-sitter things
			const ast = tsParser.parse(fileMap[fileName].text);
			let document = ast.rootNode;
			// file crawl state
			const f = makeFileState(p, fileName);
			const nodes = document.namedChildren
				.map(node=>handleNode(f, node))
				.flat();
			f.nodes = nodes;
			// add parsed file to the pile
			fileMap[fileName].parsed = f;
			return f;
		},
	};

	return p;
};

module.exports = {
	makeProjectState,
};
