import { Parser } from 'web-tree-sitter';
import { flattenGotos, newComment } from './parser-utilities.ts';
import { type FileState, makeFileState } from './parser-file.ts';
import { handleNode } from './parser-node.ts';
import {
	type AnyNode,
	type DialogDefinition,
	type SerialDialogDefinition,
	type ScriptDefinition,
	type MGSMessage,
	isNodeMathlang,
	isLabelDefinition,
	doesMathlangHaveLabelToChangeToIndex,
	isAnyCopyScript,
	hasSearchAndReplace,
} from './parser-types.ts';
import { type MGSDebug } from './parser-bytecode-info.ts';

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
	scripts: Record<string, ScriptDefinition>;
	dialogs: Record<string, DialogDefinition>;
	serialDialogs: Record<string, SerialDialogDefinition>;
	errors: MGSMessage[];
	warnings: MGSMessage[];
	newError: (error: MGSMessage) => void;
	newWarning: (warning: MGSMessage) => void;
	gotoSuffixValue: number;
	advanceGotoSuffix: () => number;
	getGotoSuffix: () => number;
	addScript: (args: ScriptDefinition) => void;
	addDialog: (args: DialogDefinition) => void;
	addSerialDialog: (args: SerialDialogDefinition) => void;
	bakeCopyScriptSingle: (scriptToBake: string) => void;
	parseFile: (fileName: string) => FileState;
};

const copyRecursion: string[] = [];

// PROJECT CRAWL STATE
export const makeProjectState = (
	tsParser: Parser,
	fileMap: FileMap,
	scenarioData: Record<string, unknown>,
): ProjectState => {
	const p: ProjectState = {
		// stuff needed to be handed around
		...(scenarioData || {}),
		parser: tsParser,
		fileMap,

		// global project things
		scripts: {},
		dialogs: {},
		serialDialogs: {},

		// error/warning messages
		errors: [],
		warnings: [],
		newError: (v) => p.errors.push(v),
		newWarning: (v) => p.warnings.push(v),

		// auto counter, so that auto-generated gotos don't share labels:
		gotoSuffixValue: 0,
		advanceGotoSuffix: () => ++p.gotoSuffixValue,
		getGotoSuffix: () => p.gotoSuffixValue,

		// for adding a file's data to the project
		addScript: (data: ScriptDefinition) => {
			const name = data.scriptName;
			data.rawNodes = data.actions; // making a backup of actions
			// finalize actions
			const finalizedActions: AnyNode[] = [];
			data.rawNodes.forEach((node) => {
				if (isNodeMathlang(node) && node.mathlang === 'dialog_definition') {
					p.addDialog(node);
				} else if (isNodeMathlang(node) && node.mathlang === 'serial_dialog_definition') {
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

		// do a COPY_SCRIPT
		// needs to be here because it can call itself
		bakeCopyScriptSingle: (scriptName: string) => {
			// Recursion detection
			if (copyRecursion.includes(scriptName)) {
				copyRecursion.push(scriptName);
				throw new Error(
					`copy_macro recursion\n       ${copyRecursion.join('\n       -> ')}`,
				);
			}
			copyRecursion.push(scriptName);

			const finalActions: AnyNode[] = [];
			const scriptData = p.scripts[scriptName];

			// one node can become multiple nodes, so this needs to be .forEach() and not .map()
			scriptData.actions.forEach((action: AnyNode) => {
				// not copy script, easy, hand it in
				if (!isAnyCopyScript(action)) {
					finalActions.push(action);
					return;
				}
				// copy script now:
				const targetScript: string = action.script;
				if (!p.scripts[targetScript]) {
					// named script not found; error
					if (!action.debug) {
						throw new Error(
							"plain COPY_SCRIPT with missing TreeSitterNode; this shouldn't happen",
						);
					}
					p.newError({
						locations: [
							{
								fileName: scriptData.debug.fileName,
								node:
									action.debug.node.childForFieldName('script') ||
									action.debug.node,
							},
						],
						message: 'no script found by the name ' + targetScript,
					});
					return;
				}
				// if the target script hasn't had its own copy_script pass done yet, do that pass first
				if (!p.scripts[action.script].copyScriptResolved) {
					p.bakeCopyScriptSingle(action.script);
				}
				// add suffix to labels so they don't collide with other copies
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
				// search-and-replace
				if (!hasSearchAndReplace(action)) {
					// plain version
					finalActions.push(newComment(`Copying: ${action.script} (-${labelSuffix})`));
					finalActions.push(...copiedActions);
				} else {
					// search-and-replace does naive JSON stringifying and straight find-and-replace.
					// But thanks to the TreeSitter node stuff, you can't stringify the whole thing in this intermediate state.
					// Gotta extract the "debug" nodes first so it doesn't try to print recursive things.

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
					const searchAndReplace: Record<string, string> =
						action.search_and_replace || {};
					Object.entries(searchAndReplace).forEach(([k, v]) => {
						stringActions = stringActions.replace(new RegExp(k, 'g'), v);
					});
					const objectActions: AnyNode[] = JSON.parse(stringActions);
					// Put the debugs back
					objectActions.forEach((v, i) => {
						const debug: MGSDebug | undefined = extractedDebugProps[i];
						if (debug) {
							v.debug = debug;
						}
					});
					const comment = `Copying: ${action.script} (-${labelSuffix}) with search_and_replace: ${JSON.stringify(action.search_and_replace)}`;
					finalActions.push(newComment(comment));
					finalActions.push(...objectActions);
				}
			});
			p.scripts[scriptName].copyScriptResolved = true;
			p.scripts[scriptName].actions = finalActions;
			copyRecursion.pop();
		},

		// the actual owl
		parseFile: (fileName) => {
			const fileMap = p.fileMap;
			// tree-sitter things
			const text = fileMap[fileName].fileText;
			const ast = tsParser.parse(text);
			if (!ast) throw new Error('tree-sitter parser failed to produce AST');
			const document = ast.rootNode;
			// file crawl state
			const f = makeFileState(p, fileName);
			let catastrophicErrorReported = false;
			const nodes = document.namedChildren
				.map((node) => {
					if (catastrophicErrorReported) {
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
							if (!node) {
								throw new Error('No node found for catastrophic error case');
							}
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
			f.nodes = nodes.filter((v) => v !== undefined);
			// add parsed file to the pile
			fileMap[fileName].parsed = f;
			return f;
		},
	};

	return p;
};
