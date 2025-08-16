import initTreeSitter from './parser-init-tree-sitter.ts';
import { debugLog, ansiTags } from './parser-utilities.ts';
import { printScript } from './parser-to-json.ts';
import { type FileMap, makeProjectState } from './parser-project.ts';
import { standardizeAction } from './parser-bytecode-info.ts';
import {
	isDialogDefinitionNode,
	isScriptDefinitionNode,
	isSerialDialogDefinitionNode,
	type MathlangNode,
} from './parser-types.ts';

export const parseProject = async (fileMap: FileMap, scenarioData: Record<string, unknown>) => {
	const parser = await initTreeSitter();
	const p = makeProjectState(parser, fileMap, scenarioData);
	// parse each file
	Object.keys(fileMap).forEach((fileName) => {
		if (fileName.endsWith('.mgs') && !fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			p.parseFile(fileName);
		}
	});

	// take scripts/dialogs from each file and make global for the project
	// why do these one at a time? so a single file can be parsed on its own, and added/removed on its own (later)
	// TODO: could they not be added to an object for that file rather than being left in sequence?
	// That way we don't have to filter out those nodes anymore when script parsing
	Object.keys(fileMap).forEach((fileName) => {
		if (!fileName.endsWith('.mgs')) return;
		const f = fileMap[fileName].parsed;
		if (!f) throw new Error(`File ${fileName} failed to parse in time (?)`);
		f.nodes.forEach((node) => {
			if (isScriptDefinitionNode(node)) {
				p.addScript(node);
			} else if (isDialogDefinitionNode(node)) {
				p.addDialog(node);
			} else if (isSerialDialogDefinitionNode(node)) {
				p.addSerialDialog(node);
			}
		});
		debugLog(
			`File ${ansiTags.c}"${fileName}"${ansiTags.reset} complete! ` +
				f.printableMessageInformation(),
		);
	});

	// check whether multiple registrations have been made for anything global
	p.detectDuplicates();

	// Make script plaintext readable (pre copy, labels)
	Object.keys(p.scripts).forEach((scriptName) => {
		const standardizedActions = p.scripts[scriptName].actions
			.filter(
				(v) =>
					(v as MathlangNode).mathlang !== 'comment' &&
					(v as MathlangNode).mathlang !== 'dialog_definition' &&
					(v as MathlangNode).mathlang !== 'serial_dialog_definition',
			)
			.map((v, i, arr) => standardizeAction(v, arr.length));
		p.scripts[scriptName].prePrint = printScript(scriptName, standardizedActions);
		p.scripts[scriptName].preActions = standardizedActions.map((v) => ({ ...v })); // shallow clone
	});

	// copyscript - TODO: check for recursion?
	p.copyScriptAll();

	// This is where unit tests want to pull from?
	Object.keys(p.scripts).forEach((scriptName) => {
		p.scripts[scriptName].testPrint = printScript(scriptName, p.scripts[scriptName].actions);
	});

	// bake all the labels into hard-coded action indices
	p.bakeLabels();

	// Make script plaintext readable
	Object.keys(p.scripts).forEach((scriptName) => {
		p.scripts[scriptName].print = printScript(scriptName, p.scripts[scriptName].actions);
	});

	// print fancy squiggly error messages
	p.printProblems();

	// done!
	return p;
};
