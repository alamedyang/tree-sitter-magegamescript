const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const { debugLog } = require('./parser-utilities.js');
const { makeProjectState } = require('./parser-project.js');
const { ansiTags } = require('./parser-dialogs.js');

const parseProject = async () => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);

	// my the-rest-of-the-owl
	const p = makeProjectState(parser);
	const fileMap = p.fileMap;
	// parse each file
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			p.parseFile(fileName);
		}
	});

	// take scripts/dialogs from each file and make global for the project
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

	// print error messages
	p.printProblems();
	
	// done!
	return p;
};

parseProject().then((p)=>{
	console.log('PROJECT', p);
	console.log("breakpoint me")
});
