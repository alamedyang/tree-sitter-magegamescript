import {
	makeMessagePrintable,
	flattenGotos,
	newComment,
	ansiTags as ansi,
} from './parser-utilities.ts';
import { makeFileState } from './parser-file.js';
import { handleNode } from './parser-node.ts';

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

		// provides the label suffix, then advances counter:
		advanceGotoSuffix: () => ++p.gotoSuffixValue,
		getGotoSuffix: () => p.gotoSuffixValue,

		newError: (v) => p.errors.push(v),
		newWarning: (v) => p.warnings.push(v),

		// for adding a file's data to the project

		addScript: (data, fileName) => {
			const name = data.scriptName;
			data.rawNodes = data.actions; // making a backup of actions
			// finalize actions
			const finalizedActions = [];
			data.rawNodes.forEach((node) => {
				if (node.mathlang === 'dialog_definition') {
					p.addDialog(node, fileName);
				} else if (node.mathlang === 'serial_dialog_definition') {
					p.addSerialDialog(node, fileName);
				} else {
					finalizedActions.push(node);
				}
			});
			data.actions = flattenGotos(finalizedActions.flat());
			// put script in the project
			if (!p.scripts[name]) {
				// if not registered yet, add it
				p.scripts[name] = data;
			} else {
				// if it's a duplicate, make an array for all the ones we find
				if (!p.scripts[name].duplicates) {
					p.scripts[name].duplicates = [p.scripts[name]];
				}
				p.scripts[name].duplicates.push(data);
			}
		},
		addDialog: (data) => {
			const name = data.dialogName;
			if (!p.dialogs[name]) {
				p.dialogs[name] = data;
			} else {
				if (!p.dialogs[name].duplicates) {
					p.dialogs[name].duplicates = [p.dialogs[name]];
				}
				p.dialogs[name].duplicates.push(data);
			}
		},
		addSerialDialog: (data) => {
			const name = data.serialDialogName || data.dialogName; // TODO :|
			if (!p.serialDialogs[name]) {
				p.serialDialogs[name] = data;
			} else {
				if (!p.serialDialogs[name].duplicates) {
					p.serialDialogs[name].duplicates = [p.serialDialogs[name]];
				}
				p.serialDialogs[name].duplicates.push(data);
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
						entry.duplicates.forEach((dupe) => {
							p.fileMap[dupe.fileName].parsed.errorCount += 1;
						});
					}
				});
			});
		},
		copyScriptOne: (scriptName) => {
			const finalActions = [];
			const scriptData = p.scripts[scriptName];
			// one node can become multiple nodes, so this needs to be .forEach() and not .map()
			scriptData.actions.forEach((action) => {
				// not copy script, easy
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
						action[param] = jump_index;
						delete action.label;
						delete action.mathlang;
					}
				});
			});
		},

		// fancy console location printing for all collected problems
		printProblems: () => {
			const messages = [];
			const errCount = p.errors.length;
			const warnCount = p.warnings.length;
			if (errCount) {
				const s = errCount !== 1 ? 's' : '';
				messages.push(ansi.red + `${errCount} error${s}` + ansi.reset);
			}
			if (warnCount) {
				const s = warnCount !== 1 ? 's' : '';
				messages.push(ansi.yellow + `${warnCount} warning${s}` + ansi.reset);
			}
			if (messages.length) {
				console.log(`Issues found: ${messages.join(', ')}`);
			} else {
				console.log(`All your project's MGS files parsed with no issues!`);
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
				.filter((v) => v); // catastrophic errors are undefined
			f.nodes = nodes;
			// add parsed file to the pile
			fileMap[fileName].parsed = f;
			return f;
		},
	};

	return p;
};
