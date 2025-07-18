import {
	makeMessagePrintable,
	flattenGotos,
	newComment,
	ansiTags as ansi,
} from './parser-utilities.js';
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
				} else {
					finalizedActions.push(node);
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
								node: dupe.debug.node.firstNamedChild,
							})),
						});
					}
				});
			});
		},
		copyScriptOne: (scriptName) => {
			const finalActions = [];
			const scriptData = p.scripts[scriptName];
			// one node might produce multiple nodes, so this needs to be .forEach() and not .map()
			scriptData.actions.forEach((action) => {
				// not copy script
				if (action.mathlang !== 'copy_script' && action.action !== 'COPY_SCRIPT') {
					finalActions.push(action);
					return;
				}
				// copy script now:
				if (!p.scripts[action.script]) {
					// named script not found; error
					p.newError({
						locations: [
							{
								fileName: action.fileName,
								node:
									action.debug.node.childForFieldName('script') ||
									action.debug.node,
							},
						],
						message: 'no script found by this name',
					});
					return;
				}
				// if the target script hasn't had its own copyscript pass done yet, do that pass first
				if (!p.scripts[action.script].copyScriptResolved) {
					p.copyScriptOne(action.script);
				}
				// no label? just hand it up, it's fine
				// otherwise alter the copied labels so they don't collide with other copies
				const labelSuffix = 'c' + p.advanceGotoSuffix();
				const copiedActions = p.scripts[action.script].actions.map((copiedAction) => {
					return !copiedAction.mathlang?.includes('label')
						? copiedAction
						: {
								...copiedAction,
								label: copiedAction.label + labelSuffix,
							};
				});
				// simple copies are mathlang's copy_script and the JSON copy_script without search_and_replace
				if (!action.action === 'COPY_SCRIPT' || !action.search_and_replace) {
					finalActions.push(newComment(`Copying: ${action.script} (-${labelSuffix})`));
					finalActions.push(...copiedActions);
				} else {
					// search_and_replace does naive JSON stringifying and straight find-and-replace
					// But thanks to the TreeSitter node stuff, you can't stringify the whole thing
					// Gotta extract the "debug" nodes first so it doesn't try to print recursive things

					// Exctract the debugs for later re-insertion
					const extractedDebugProps = copiedActions.map((copiedAction) => {
						const debug = copiedAction.debug;
						if (copiedAction.debug) {
							delete copiedAction.debug;
						}
						return debug;
					});
					// Do the search-and-replace
					let stringActions = JSON.stringify(copiedActions);
					Object.entries(action.search_and_replace).forEach(([k, v]) => {
						stringActions = stringActions.replaceAll(k, v);
					});
					const objectActions = JSON.parse(stringActions);
					// Put the debugs back
					objectActions.forEach((v, i) => {
						const debug = extractedDebugProps[i];
						if (debug) {
							v.debug = debug;
						}
					});
					finalActions.push(
						newComment(
							`Copying: ${action.script} (-${labelSuffix}) with search_and_replace: ${JSON.stringify(action.search_and_replace)}`,
						),
					);
					finalActions.push(...objectActions);
				}
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
				console.log(`All your project's MGS files parsed with no issues!`);
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
						if (node.text === ';') {
							// semicolons after script definitions or such
							f.newError({
								locations: [{ node }],
								message: `unexpected semicolon`,
							});
						} else {
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
