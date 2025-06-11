import { ansiTags as ansi } from './parser-dialogs.js';
import { makeMessagePrintable, flattenGotos, newComment } from './parser-utilities.js';
import { makeFileState } from './parser-file.js';
import { handleNode } from './parser-node.js';

export const makeProjectState = (tsParser, fileMap, scenarioData) => {
	// project crawl state
	const p = {
		...(scenarioData || {}),
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
		advanceGotoSuffix: () => ++p.gotoSuffixValue,
		getGotoSuffix: () => p.gotoSuffixValue,
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
			data.rawNodes.forEach((node) => {
				if (!node.mathlang) {
					finalizedActions.push(node);
				} else if (node.mathlang === 'dialog_definition') {
					// (sometimes these are inside a script body)
					p.addDialog(node, fileName);
				} else if (node.mathlang === 'serial_dialog_definition') {
					// (sometimes these are inside a script body)
					p.addSerialDialog(node, fileName);
				} else if (node.mathlang === 'copy_script') {
					finalizedActions.push(node);
					// done as a separate layer
				} else if (node.mathlang.includes('label')) {
					finalizedActions.push(node);
				} else if (node.mathlang === 'comment') {
					finalizedActions.push(node);
				} else {
					console.error(node);
					throw new Error("HANDLE THIS 'MATHLANG' ACTION NODE PLEASE! " + node.mathlang);
				}
			});
			data.actions = flattenGotos(finalizedActions.flat());
			// put it in the project
			if (!p.scripts[scriptName]) {
				// if not registered yet, add it
				p.scripts[scriptName] = data;
			} else {
				// if it's a duplicate, make an array for all the ones we find
				if (!p.scripts[scriptName].duplicates) {
					p.scripts[scriptName].duplicates = [p.scripts[scriptName]];
				}
				p.scripts[scriptName].duplicates.push(data);
			}
		},
		addDialog: (data) => {
			const dialogName = data.dialogName;
			if (!p.dialogs[dialogName]) {
				p.dialogs[dialogName] = data;
			} else {
				if (!p.dialogs[dialogName].duplicates) {
					p.dialogs[dialogName].duplicates = [p.dialogs[dialogName]];
				}
				p.dialogs[dialogName].duplicates.push(data);
			}
		},
		addSerialDialog: (data) => {
			const serialDialogName = data.serialDialogName;
			if (!p.serialDialogs[serialDialogName]) {
				p.serialDialogs[serialDialogName] = data;
			} else {
				if (!p.serialDialogs[serialDialogName].duplicates) {
					p.serialDialogs[serialDialogName].duplicates = [
						p.serialDialogs[serialDialogName],
					];
				}
				p.serialDialogs[serialDialogName].duplicates.push(data);
			}
		},

		// can only be done after all files in a project are parsed
		detectDuplicates: () => {
			['scripts', 'dialogs', 'serialDialogs'].forEach((category) => {
				const entries = Object.entries(p[category]);
				entries.forEach(([name, entry]) => {
					if (entry.duplicates) {
						// note: one error message, multiple locations
						p.newError({
							message: `multiple ${category} with name "${name}"`,
							locations: entry.duplicates.map((dupe) => ({
								fileName: dupe.fileName,
								node: dupe.debug.firstNamedChild,
							})),
						});
					}
				});
			});
		},
		copyScriptOne: (scriptName) => {
			const finalActions = [];
			const scriptData = p.scripts[scriptName];
			scriptData.actions.forEach((action) => {
				if (action.mathlang !== 'copy_script') {
					finalActions.push(action);
					return;
				}
				if (!p.scripts[action.script]) {
					p.newError({
						locations: [
							{
								fileName: action.fileName,
								node: action.debug.childForFieldName('script') || action.debug,
							},
						],
						message: 'no script found by this name',
					});
					return;
				}
				if (!p.scripts[action.script].copyScriptResolved) {
					p.copyScriptOne(action.script);
				}
				const labelSuffix = 'c' + p.advanceGotoSuffix();
				const copiedInsert = p.scripts[action.script].actions;
				finalActions.push(newComment(`Copying: ${action.script} (-${labelSuffix})`));
				finalActions.push(
					...copiedInsert.map((insert) => {
						if (insert.mathlang?.includes('label')) {
							const newInsert = {};
							Object.entries(insert).forEach(([k, v]) => {
								newInsert[k] = v;
							});
							newInsert.label += labelSuffix;
							return newInsert;
						}
						return insert;
					}),
				);
			});
			p.scripts[scriptName].copyScriptResolved = true;
			p.scripts[scriptName].actions = finalActions;
		},
		copyScriptAll: () => {
			Object.keys(p.scripts).forEach((scriptName) => {
				if (!p.scripts[scriptName].copyScriptDone) {
					p.copyScriptOne(scriptName);
				}
			});
		},
		bakeLabels: () => {
			Object.keys(p.scripts).forEach((scriptName) => {
				const scriptData = p.scripts[scriptName];
				const registry = {};
				const actions = scriptData.actions;
				let commentlessIndex = 0;
				for (let i = 0; i < actions.length; i++) {
					const currAction = actions[i];
					if (
						currAction.mathlang === 'comment' ||
						currAction.mathlang === 'dialog_definition' ||
						currAction.mathlang === 'serial_dialog_definition'
					) {
						continue;
					} else if (currAction.mathlang === 'label_definition') {
						registry[currAction.label] = commentlessIndex;
						actions[i] = newComment(`'${currAction.label}':`);
						// commentlessIndex -= 1;
					} else {
						commentlessIndex += 1;
					}
				}
				actions.forEach((action) => {
					if (
						action.mathlang?.includes('label') ||
						action.mathlang === 'bool_getable' ||
						action.mathlang === 'bool_comparison' ||
						action.mathlang === 'string_checkable' ||
						action.mathlang === 'number_checkable_equality'
					) {
						const jump_index = registry[action.label];
						if (jump_index === undefined) {
							throw new Error('NOT REGISTERED?');
						}
						let param = 'jump_index';
						if (action.mathlang === 'goto_label') {
							action.action = 'GOTO_ACTION_INDEX';
							param = 'action_index';
						}
						action.comment = `goto label '${action.label}'`;
						delete action.label;
						delete action.mathlang;
						action[param] = jump_index;
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
					`${ansi.red}` +
						`${errCount} error` +
						`${errCount !== 1 ? 's' : ''}` +
						`${ansi.reset}`,
				);
			}
			if (warnCount) {
				messages.push(
					`${ansi.yellow}` +
						`${warnCount} warning` +
						`${warnCount !== 1 ? 's' : ''}` +
						`${ansi.reset}`,
				);
			}
			if (messages.length === 0) {
				console.log('No issues found!');
			} else {
				console.log(`Issues found: ${messages.join(', ')}`);
			}
			p.warnings.forEach((message) => {
				const str =
					ansi.yellow + makeMessagePrintable(p.fileMap, 'Warning', message) + ansi.reset;
				console.warn(str);
			});
			p.errors.forEach((message) => {
				const str =
					ansi.red + makeMessagePrintable(p.fileMap, 'Error', message) + ansi.reset;
				console.error(str);
			});
		},

		// the actual owl
		parseFile: (fileName) => {
			const fileMap = p.fileMap;
			// tree-sitter things
			const text = fileMap[fileName].fileText;
			const ast = tsParser.parse(text);
			let document = ast.rootNode;
			// file crawl state
			const f = makeFileState(p, fileName);
			if (document.isError) {
			}
			let catastrophicErrorReported = false;
			const nodes = document.namedChildren
				.map((node) => {
					if (catastrophicErrorReported) {
						// Nuke the map()!
						return;
					} else if (!node.isError) {
						// Normal
						return handleNode(f, node);
					} else if (!catastrophicErrorReported) {
						// The first catastrophic error should be the last!
						// Every node underneath is just wrecked. Nuke it all!
						f.newError({
							locations: [{ node }],
							message: `catastrophic syntax error (naive guess: invalid script name)`,
							footer:
								`Avoid keywords for bare script names in definitions, or wrap the script name in quotes\n` +
								`   add { ... } // INVALID\n` +
								`   include { ... } // INVALID\n` +
								`   script add { ... } // fix with keyword\n` +
								`   "include" { ... } // fix with quotes\n`,
						});
						catastrophicErrorReported = true;
					}
				})
				.flat()
				.filter((v) => v); // catastrophic errors are undefined nodes
			f.nodes = nodes;
			// add parsed file to the pile
			fileMap[fileName].parsed = f;
			return f;
		},
	};

	return p;
};
