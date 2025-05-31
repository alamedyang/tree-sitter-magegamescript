const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const fs = require('node:fs');
const path = require('node:path');

const { debugLog } = require('./parser-utilities.js');
const { printScript } = require('./parser-to-json.js');
const { makeProjectState } = require('./parser-project.js');
const { ansiTags } = require('./parser-dialogs.js');

// /*
// stolen from the other place
const makeMap = path => {
	let map = {};
	for (file of fs.readdirSync(
		path,
		{ withFileTypes: true }
	)) {
		if (file.name === '.DS_Store') continue;
		let filePath = `${path}/${file.name}`;
		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath)
			};
		} else {
			let fileBlob = fs.readFileSync(filePath);
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
					return new Promise(resolve => {
						resolve(fileBlob.toString('utf8'));
					});
				},
				get fileText () {
					return fileBlob.toString('utf8');
				}
			};
		}
	}
	return map;
};
// */

const parseProject = async (fileMap, scenarioData) => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const wasmPath = path.resolve(__dirname + '/tree-sitter-magegamescript.wasm');
	const Lang = await Language.load(wasmPath);
	parser.setLanguage(Lang);
	
	// my the-rest-of-the-owl
	const p = makeProjectState(parser, fileMap, scenarioData);
	// parse each file
	Object.keys(fileMap).forEach(fileName=>{
		if (fileName.endsWith('.mgs') && !fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			p.parseFile(fileName);
		}
	});

	// take scripts/dialogs from each file and make global for the project
	// why do these one at a time? so a single file can be parsed on its own, and added/removed on its own (later)
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileName.endsWith('.mgs')) return;
		const f = fileMap[fileName].parsed;
		f.nodes.forEach(node=>{
			if (node.mathlang === 'script_definition') {
				p.addScript(node, fileName);
			} else if (node.mathlang === 'dialog_definition') {
				p.addDialog(node, fileName);
			} else if (node.mathlang === 'serial_dialog_definition') {
				p.addSerialDialog(node, fileName);
			}
		})
		debugLog(
			`File ${ansiTags.c}"${fileName}"${ansiTags.reset} complete! `
			+ f.printableMessageInformation()
		);
	})

	// check whether multiple registrations have been made for anything global
	p.detectDuplicates();

	// copyscript - TODO: check for recursion?
	p.copyScriptAll();

	// Make script plaintext readable
	Object.keys(p.scripts).forEach(scriptName=>{
		p.scripts[scriptName].print = printScript(scriptName, p.scripts[scriptName].actions);
	})
	
	// bake all the labels into hard-coded action indices
	p.bakeLabels();
	
	// print fancy squiggly error messages
	p.printProblems();
	
	// done!
	return p;
};

// /*
const inputPath = path.resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

parseProject(fileMap).then((p)=>{
	// console.log('PROJECT');
	// console.log(p);
	const printAll = Object.values(p.scripts)
		.map(v=>v.print)
		.join('\n\n');
	// console.log(printAll);
	console.log("BREAK")
});
// */

module.exports = { parseProject };
