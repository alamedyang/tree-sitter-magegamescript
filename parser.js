const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const fs = require('node:fs');
const path = require('node:path');

const { debugLog } = require('./parser-utilities.js');
const { translateScript } = require('./parser-to-json.js');
const { makeProjectState } = require('./parser-project.js');
const { ansiTags } = require('./parser-dialogs.js');

// stolen from the other place
const makeMap = path => {
	let map = {};
	for (file of fs.readdirSync(
		path,
		{ withFileTypes: true }
	)) {
		if (file.name === '.DS_Store') continue;
		let filePath = `${path}/${file.name}`
		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath)
			};
		} else {
			let text = fs.readFileSync(filePath, 'utf-8')
			let type = filePath.split('.').pop()
			map[file.name] = {
				fileName: file.name,
				type,
				text,
			}
		}
	}
	return map;
};

const parseProject = async () => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);

	const inputPath = path.resolve('./scenario_source_files');
	const fileMap = makeMap(inputPath);
	
	// my the-rest-of-the-owl
	const p = makeProjectState(parser, fileMap);
	// parse each file
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			p.parseFile(fileName);
		}
	});

	// take scripts/dialogs from each file and make global for the project
	// why do these one at a time? so a single file can be parsed on its own, and added/removed on its own (later)
	Object.keys(fileMap).forEach(fileName=>{
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

	// print error messages
	p.printProblems();
	
	// done!
	return p;
};

parseProject().then((p)=>{
	console.log('PROJECT', p);
	console.log('\nSCRIPTS');
	const entries = Object.entries(p.scripts);
	const printable = entries.map(([scriptName, values])=>{
		const translated = translateScript(scriptName, values.actions);
		console.log(translated);
	}).join('\n\n')
	console.log(printable);
});

// Strips debug info from items so JSON.stringify() isn't monstrously long
const cleanseDebug = (obj) => {
	const keys = Object.keys(obj);
	keys.forEach(key=>{
		if (key === 'debug') {
			delete obj.debug;
		} else if (key === 'fileName') {
			delete obj.fileName;
		} else if (typeof obj[key] === 'object') {
			cleanseDebug(obj[key]);
		}
	});
	return obj;
};

module.exports = { parseProject };
