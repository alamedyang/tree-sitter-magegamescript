import { Parser } from 'web-tree-sitter';
import {
	makeMessagePrintable,
	flattenGotos,
	newComment,
	ansiTags as ansi,
} from './parser-utilities.ts';
import { type FileState, makeFileState } from './parser-file.ts';
import { handleNode } from './parser-node.ts';
import {
	type AnyNode,
	type DialogDefinition,
	type SerialDialogDefinition,
	type ScriptDefinition,
	type MGSMessage,
	isNodeAction,
	isAnyCopyScript,
	type MathlangNode,
	hasSearchAndReplace,
	isLabelDefinition,
	doesMathlangHaveLabelToChangeToIndex,
} from './parser-types.ts';
import {
	type GOTO_ACTION_INDEX,
	isActionCopyScript,
	type MGSDebug,
} from './parser-bytecode-info.ts';

type FileMapEntry = {
	arrayBuffer: Promise<unknown>;
	fileText: string;
	name: string;
	text: Promise<unknown>;
	type: string;
	parsed?: FileState;
};

export type FileMap = Record<string, FileMapEntry>;
export type ProjectState = {
	parser: Parser;
	fileMap: FileMap;
	gotoSuffixValue: number;
	scripts: Record<string, ScriptDefinition>;
	dialogs: Record<string, DialogDefinition>;
	serialDialogs: Record<string, SerialDialogDefinition>;
	errors: MGSMessage[];
	warnings: MGSMessage[];
	advanceGotoSuffix: () => number;
	getGotoSuffix: () => number;
	newError: (error: MGSMessage) => void;
	newWarning: (warning: MGSMessage) => void;
	addScript: (args: ScriptDefinition) => void;
	addDialog: (args: DialogDefinition) => void;
	addSerialDialog: (args: SerialDialogDefinition) => void;
	detectDuplicates: () => void;
	bakeCopyScriptSingle: (scriptToBake: string) => void;
	copyScriptAll: () => void;
	bakeLabels: () => void;
	printProblems: () => void;
	parseFile: (fileName: string) => FileState;
};

type FileCategory = 'scripts' | 'dialogs' | 'serialDialogs';
export const makeProjectState = (
	tsParser: Parser,
	fileMap: FileMap,
	scenarioData: Record<string, unknown>,
): ProjectState => {
	// project crawl state
	const p: ProjectState = {
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

		addScript: (data: ScriptDefinition) => {
			const name = data.scriptName;
			data.rawNodes = data.actions; // making a backup of actions
			// finalize actions
			const finalizedActions: AnyNode[] = [];
			data.rawNodes.forEach((node) => {
				if (!isNodeAction(node) && node.mathlang === 'dialog_definition') {
					p.addDialog(node);
				} else if (!isNodeAction(node) && node.mathlang === 'serial_dialog_definition') {
					p.addSerialDialog(node);
				} else {
					finalizedActions.push(node);
				}
			});
			data.actions = flattenGotos(finalizedActions.flat());
			// put script in the project
			if (!p.scripts[name]) {
				// if not registered yet, add it
				p.scripts[name] = { ...data, preActions: [] };
			} else {
				// if it's a duplicate, make an array for all the ones we find
				if (!p.scripts[name].duplicates) {
					p.scripts[name].duplicates = [p.scripts[name]];
				}
				p.scripts[name].duplicates.push(data);
			}
		},
		addDialog: (data: DialogDefinition) => {
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
		addSerialDialog: (data: SerialDialogDefinition) => {
			const name = data.dialogName;
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
			const cats: FileCategory[] = ['scripts', 'dialogs', 'serialDialogs'];
			cats.forEach((category) => {
				const entries = Object.entries(p[category]);
				entries.forEach(([name, entry]) => {
					const dupes: (DialogDefinition | SerialDialogDefinition | ScriptDefinition)[] =
						entry.duplicates;
					if (dupes) {
						// note: one error message, multiple locations
						p.newError({
							message: `multiple ${category} with name "${name}"`,
							locations: entry.duplicates.map((dupe) => ({
								fileName: dupe.fileName,
								node: dupe.debug.node.firstNamedChild,
							})),
						});
						dupes.forEach((dupe) => {
							const file = p.fileMap[dupe.fileName].parsed;
							if (!file) throw new Error('ts');
							file.errorCount += 1;
						});
					}
				});
			});
		},
		bakeCopyScriptSingle: (scriptName: string) => {
			const finalActions: AnyNode[] = [];
			const scriptData = p.scripts[scriptName];
			// one node can become multiple nodes, so this needs to be .forEach() and not .map()
			scriptData.actions.forEach((action: AnyNode) => {
				// not copy script, easy
				if (!isAnyCopyScript(action)) {
					finalActions.push(action);
					return;
				}
				// copy script now:
				const targetScript: string = action.script;
				if (!p.scripts[targetScript]) {
					// named script not found; error
					if (!action.debug)
						throw new Error(
							"plain COPY_SCRIPT with missing TreeSitterNode; this shouldn't happen",
						);
					p.newError({
						locations: [
							{
								fileName: scriptData.fileName,
								node:
									action.debug.node.childForFieldName('script') ||
									action.debug.node,
							},
						],
						message: 'no script found by the name ' + targetScript,
					});
					return;
				}
				// if the target script hasn't had its own copyscript pass done yet, do that pass first
				if (!p.scripts[action.script].copyScriptResolved) {
					p.bakeCopyScriptSingle(action.script);
				}
				// no label? just hand it up, it's fine
				// otherwise alter the copied labels so they don't collide with other copies
				const labelSuffix = 'c' + p.advanceGotoSuffix();
				const copiedActions: AnyNode[] = p.scripts[action.script].actions.map(
					(copiedAction) => {
						if (
							(doesMathlangHaveLabelToChangeToIndex(copiedAction) &&
								copiedAction.label) ||
							isLabelDefinition(copiedAction)
						) {
							return {
								...copiedAction,
								label: copiedAction.label + labelSuffix,
							};
						} else {
							return copiedAction;
						}
					},
				);
				// simple copies are mathlang's copy_script and the JSON copy_script without search_and_replace
				if (!isAnyCopyScript(action) || !hasSearchAndReplace(action)) {
					finalActions.push(newComment(`Copying: ${action.script} (-${labelSuffix})`));
					finalActions.push(...copiedActions);
				} else {
					// search_and_replace does naive JSON stringifying and straight find-and-replace
					// But thanks to the TreeSitter node stuff, you can't stringify the whole thing
					// Gotta extract the "debug" nodes first so it doesn't try to print recursive things

					// Exctract the debugs for later re-insertion
					const extractedDebugProps = copiedActions.map((copiedAction) => {
						const debug: MGSDebug | undefined = copiedAction.debug;
						if (copiedAction.debug) {
							delete copiedAction.debug;
						}
						return debug;
					});
					// Do the search-and-replace
					let stringActions: string = JSON.stringify(copiedActions);
					const doSearchAndReplace =
						isActionCopyScript(action) && hasSearchAndReplace(action);
					if (doSearchAndReplace) {
						const searchAndReplace: Record<string, string> =
							action.search_and_replace || {};
						Object.entries(searchAndReplace).forEach(([k, v]) => {
							stringActions = stringActions.replace(new RegExp(k, 'g'), v);
						});
					}
					const objectActions: AnyNode[] = JSON.parse(stringActions);
					// Put the debugs back
					objectActions.forEach((v, i) => {
						const debug: MGSDebug | undefined = extractedDebugProps[i];
						if (debug) {
							v.debug = debug;
						}
					});
					const comment = doSearchAndReplace
						? `Copying: ${action.script} (-${labelSuffix}) with search_and_replace: ${JSON.stringify(action.search_and_replace)}`
						: `Copying: ${action.script} (-${labelSuffix})`;
					finalActions.push(newComment(comment));
					finalActions.push(...objectActions);
				}
			});
			p.scripts[scriptName].copyScriptResolved = true;
			p.scripts[scriptName].actions = finalActions;
		},
		copyScriptAll: () => {
			Object.keys(p.scripts).forEach((scriptName) => {
				if (!p.scripts[scriptName].copyScriptResolved) {
					p.bakeCopyScriptSingle(scriptName);
				}
			});
		},
		bakeLabels: () => {
			// standardizeAction() has happened by now;
			// no more mathlang: 'copy_script', 'label_definition', 'goto_label', or 'return_statement'
			Object.keys(p.scripts).forEach((scriptName) => {
				const scriptData = p.scripts[scriptName];
				const registry: Record<string, number> = {};
				const actions = scriptData.actions;
				let commentlessIndex = 0;
				for (let i = 0; i < actions.length; i++) {
					const currAction = actions[i];
					if (
						(currAction as MathlangNode).mathlang === 'comment' ||
						(currAction as MathlangNode).mathlang === 'dialog_definition' ||
						(currAction as MathlangNode).mathlang === 'serial_dialog_definition'
					) {
						continue;
					} else if (isLabelDefinition(currAction)) {
						registry[currAction.label] = commentlessIndex;
						actions[i] = newComment(`'${currAction.label}':`);
					} else {
						commentlessIndex += 1;
					}
				}
				actions.forEach((action, i) => {
					if (doesMathlangHaveLabelToChangeToIndex(action)) {
						if (!action.label) throw new Error("should have a label and doesn't");
						const jump_index = registry[action.label];
						if (jump_index === undefined) {
							throw new Error(
								`Jump index not registered for label ${action.label} (in script ${scriptName})`,
							);
						}
						const param = 'jump_index';
						if (action.mathlang === 'goto_label') {
							const replacement: GOTO_ACTION_INDEX = {
								action: 'GOTO_ACTION_INDEX',
								action_index: jump_index,
							};
							actions[i] = replacement;
						} else {
							action.comment = `goto label '${action.label}'`;
							action[param] = jump_index;
							delete action.label;
						}
					}
				});
			});
		},

		// fancy console location printing for all collected problems
		printProblems: () => {
			const messages: string[] = [];
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
			if (!ast) throw new Error('HAHAHA SOMETHING WENT WRONG BOOOO');
			const document = ast.rootNode;
			// file crawl state
			const f = makeFileState(p, fileName);
			let catastrophicErrorReported = false;
			const nodes = document.namedChildren
				.map((node) => {
					if (catastrophicErrorReported) {
						// Nuke the map()!
						return;
					} else if (node && !node.isError) {
						// Normal
						return handleNode(f, node);
					} else if (!catastrophicErrorReported) {
						if (node?.text === ';') {
							// semicolons after script definitions or such
							f.newError({
								locations: [{ node }],
								message: `unexpected semicolon`,
							});
						} else {
							// The first catastrophic error should be the last!
							// Every node underneath is just wrecked. Nuke it all!
							if (!node) throw new Error('ts');
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
