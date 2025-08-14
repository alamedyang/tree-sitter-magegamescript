import { Parser, Language } from 'web-tree-sitter';
import { readdirSync, readFileSync } from 'node:fs';
import { resolve as _resolve } from 'node:path';
import { fileURLToPath } from 'url';
import { dirname } from 'path';
export const __filename = fileURLToPath(import.meta.url);
export const __dirname = dirname(__filename);

import { debugLog, printableMessage, ansiTags as ansi, printScript } from './parser-utilities.ts';

import { type FileMap, ProjectState } from './parser-project.ts';
import { GOTO_ACTION_INDEX, standardizeNode } from './parser-bytecode-info.ts';

import {
	DialogDefinition,
	ScriptDefinition,
	SerialDialogDefinition,
	LabelDefinition,
	doesMathlangHaveLabelToChangeToIndex,
	CommentNode,
	GotoLabel,
} from './parser-types.ts';

type FileCategory = 'scripts' | 'dialogs' | 'serialDialogs';
type Definition = ScriptDefinition | DialogDefinition | SerialDialogDefinition;

// /*
// stolen from the other place
export const makeMap = (path: string) => {
	let map = {};
	const files = readdirSync(path, { withFileTypes: true });
	for (let i = 0; i < files.length; i++) {
		const file = files[i];
		if (file.name === '.DS_Store') continue;
		const filePath = `${path}/${file.name}`;
		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath),
			};
		} else {
			const fileBlob = readFileSync(filePath);
			const type = filePath.split('.').pop();
			map[file.name] = {
				name: file.name,
				type,
				arrayBuffer: () => {
					return new Promise((resolve) => {
						resolve(fileBlob);
					});
				},
				text: () => {
					return new Promise((resolve) => {
						resolve(fileBlob.toString('utf8'));
					});
				},
				get fileText() {
					return fileBlob.toString('utf8');
				},
			};
		}
	}
	return map;
};
// */

export const parseProject = async (fileMap: FileMap, scenarioData: Record<string, unknown>) => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const wasmPath = _resolve(__dirname + '/tree-sitter-magegamescript.wasm');
	const Lang = await Language.load(wasmPath);
	parser.setLanguage(Lang);

	const p = new ProjectState(parser, fileMap, scenarioData);
	// PARSE EACH FILE
	Object.keys(fileMap).forEach((fileName) => {
		if (fileName.endsWith('.mgs') && !fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansi.c}"${fileName}"${ansi.reset}`);
			p.parseFile(fileName);
		}
	});

	// MAKE FILE SCRIPTS/DIALOGS GLOBAL FOR PROJECT
	// Q. why do these one at a time? so a single file can be parsed on its own, and added/removed on its own (later)
	// TODO: could they not be added to an object for that file rather than being left in sequence?
	// That way we don't have to filter out those nodes anymore when script parsing?
	Object.keys(fileMap).forEach((fileName) => {
		if (!fileName.endsWith('.mgs')) return;
		const f = fileMap[fileName].parsed;
		if (!f) throw new Error(`File "${fileName}" failed to parse in time (?)`);
		f.nodes.forEach((node) => {
			if (node instanceof ScriptDefinition) {
				p.addScript(node);
			} else if (node instanceof DialogDefinition) {
				p.addDialog(node);
			} else if (node instanceof SerialDialogDefinition) {
				p.addSerialDialog(node);
			}
		});
		debugLog(
			`File ${ansi.c}"${fileName}"${ansi.reset} complete! ` + f.printableMessageInformation(),
		);
	});

	// CHECK FOR DUPLICATES
	const cats: FileCategory[] = ['scripts', 'dialogs', 'serialDialogs'];
	cats.forEach((category) => {
		const entries = Object.entries(p.duplicates[category]);
		entries.forEach(([name, dupes]: [string, Definition[]]) => {
			// One error message, multiple locations
			p.newError({
				message: `multiple ${category} with name "${name}"`,
				locations: dupes.map((dupe: Definition) => ({
					fileName: dupe.debug.fileName,
					node: dupe.debug.node.firstNamedChild || dupe.debug.node,
				})),
			});
			// Increment error count for that file
			dupes.forEach((dupe: Definition) => {
				const file = p.fileMap[dupe.debug.fileName].parsed;
				if (!file) {
					throw new Error(`No parsed file found by name "${dupe.debug.fileName}"`);
				}
				file.errorCount += 1;
			});
		});
	});

	// STANDARDIZE ACTIONS
	Object.keys(p.scripts).forEach((scriptName) => {
		const standardizedActions = p.scripts[scriptName].actions
			.filter(
				(v) =>
					!(v instanceof CommentNode) &&
					!(v instanceof DialogDefinition) &&
					!(v instanceof SerialDialogDefinition),
			)
			.map((v, i, arr) => standardizeNode(v, arr.length));
		p.scripts[scriptName].preActions = standardizedActions.map((v) => ({ ...v })); // shallow clone
		// Snapshot current action state (pre copy_script, pre label baking)
		p.scripts[scriptName].prePrint = printScript(scriptName, standardizedActions);
	});

	// DO COPY_SCRIPT
	Object.keys(p.scripts).forEach((scriptName) => {
		if (!p.scripts[scriptName].copyScriptResolved) {
			const fileName = p.scripts[scriptName].debug.fileName;
			const f = p.fileMap[fileName].parsed || p.scripts[scriptName].debug.f;
			if (!f) throw new Error(`file ${fileName} not parsed`);
			const node = p.scripts[scriptName].debug.node;
			// todo: better sources of f, node?
			p.bakeCopyScriptSingle(f, node, scriptName);
		}
	});

	// Snapshot current action state (post copy_script, pre label baking)
	Object.keys(p.scripts).forEach((scriptName) => {
		p.scripts[scriptName].testPrint = printScript(scriptName, p.scripts[scriptName].actions);
	});

	// BAKE LABELS
	Object.keys(p.scripts).forEach((scriptName) => {
		const scriptData = p.scripts[scriptName];
		const registry: Record<string, number> = {};
		const actions = scriptData.actions;
		let gaplessIndex = 0;
		for (let i = 0; i < actions.length; i++) {
			const currAction = actions[i];
			if (
				currAction instanceof CommentNode ||
				currAction instanceof DialogDefinition ||
				currAction instanceof SerialDialogDefinition
			) {
				continue;
			} else if (currAction instanceof LabelDefinition) {
				registry[currAction.label] = gaplessIndex;
				const comment = `'${currAction.label}':`;
				actions[i] = CommentNode.quick(currAction.debug, comment);
			} else {
				gaplessIndex += 1;
			}
		}
		actions.forEach((action, i) => {
			if (doesMathlangHaveLabelToChangeToIndex(action)) {
				if (!action.label) throw new Error(`action should have a label and doesn't`);
				const jumpToIndex = registry[action.label];
				if (jumpToIndex === undefined) {
					throw new Error(
						`Jump index not registered for label "${action.label}" in script "${scriptName}"`,
					);
				}
				if (action instanceof GotoLabel) {
					actions[i] = GOTO_ACTION_INDEX.quick(jumpToIndex);
				} else {
					action.comment = `goto label '${action.label}'`;
					action.jump_index = jumpToIndex;
					delete action.label;
				}
			}
		});
	});

	// Snapshot current action state (post copy_script, post label baking)
	Object.keys(p.scripts).forEach((scriptName) => {
		p.scripts[scriptName].printed = printScript(scriptName, p.scripts[scriptName].actions);
	});

	// PRINT ERRORS
	const messages: string[] = [];
	const errCount = p.errors.length;
	const warnCount = p.warnings.length;
	if (errCount) {
		messages.push(ansi.red + `${errCount} error${plural(errCount)}` + ansi.reset);
	}
	if (warnCount) {
		messages.push(ansi.yellow + `${warnCount} warning${plural(warnCount)}` + ansi.reset);
	}
	if (messages.length) {
		console.log(`Issues found: ${messages.join(', ')}`);
	} else {
		console.log(`All your project's MGS files parsed with no issues!`);
	}
	p.warnings.forEach((message) => {
		const str = ansi.yellow + printableMessage(p.fileMap, 'Warning', message) + ansi.reset;
		console.warn(str);
	});
	p.errors.forEach((message) => {
		const str = ansi.red + printableMessage(p.fileMap, 'Error', message) + ansi.reset;
		console.error(str);
	});

	// DONE
	return p;
};

const plural = (n: number): string => (n !== 1 ? 's' : '');

/*
const inputPath = _resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

parseProject(fileMap).then((p) => {
	console.log('PROJECT');
	console.log(p);
const printAll = Object.values(p.scripts)
	.map(v=>v.printed)
	.join('\n\n');
console.log(printAll);
});
*/
