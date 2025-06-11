import { Parser, Language } from 'web-tree-sitter';

import { readdirSync, readFileSync } from 'node:fs';
import { resolve as _resolve } from 'node:path';

import { fileURLToPath } from 'url';
import { dirname } from 'path';
export const __filename = fileURLToPath(import.meta.url);
export const __dirname = dirname(__filename);

import { debugLog, ansiTags } from './parser-utilities.js';
import { printScript } from './parser-to-json.ts';
import { makeProjectState } from './parser-project.js';
import { standardizeAction } from './parser-bytecode-info.ts';

// /*
// stolen from the other place
export const makeMap = (path) => {
	let map = {};
	const files = readdirSync(path, { withFileTypes: true });
	for (let i = 0; i < files.length; i++) {
		const file = files[i];
		if (file.name === '.DS_Store') continue;
		let filePath = `${path}/${file.name}`;
		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath),
			};
		} else {
			let fileBlob = readFileSync(filePath);
			let type = filePath.split('.').pop();
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

export const parseProject = async (fileMap, scenarioData) => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const wasmPath = _resolve(__dirname + '/tree-sitter-magegamescript.wasm');
	const Lang = await Language.load(wasmPath);
	parser.setLanguage(Lang);

	// my the-rest-of-the-owl
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
		f.nodes.forEach((node) => {
			if (node.mathlang === 'script_definition') {
				p.addScript(node, fileName);
			} else if (node.mathlang === 'dialog_definition') {
				p.addDialog(node, fileName);
			} else if (node.mathlang === 'serial_dialog_definition') {
				p.addSerialDialog(node, fileName);
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
					v.mathlang !== 'comment' &&
					v.mathlang !== 'dialog_definition' &&
					v.mathlang !== 'serial_dialog_definition',
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

/*
const inputPath = _resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

parseProject(fileMap).then((p) => {
	console.log('PROJECT');
	console.log(p);
const printAll = Object.values(p.scripts)
	.map(v=>v.print)
	.join('\n\n');
console.log(printAll);
});
*/
