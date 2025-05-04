const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const {
	verbose,
	debugLog,
} = require('./parser-utilities/general.js');

const { makeProjectState } = require('./parser-utilities/project-state.js');
const { makeFileState } = require('./parser-utilities/file-state.js');
const handleNode = require('./parser-node.js');

const {
	ansiTags,
} = require('./parser-utilities/dialog-handling.js');

const parseFile = (p, fileName) => {
	const fileMap = p.fileMap;
	const tree = p.parser.parse(fileMap[fileName].text);
	let document = tree.rootNode;
	const f = makeFileState(p, fileName, p.parser);
	const nodes = document.namedChildren
		.map(node=>handleNode(f, node))
		.flat();
	f.nodes = nodes;
	fileMap[fileName].parsed = f;
	return f;
};

const parseProject = async () => {
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);
	
	const p = makeProjectState(parser);
	const fileMap = p.fileMap;
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			parseFile(p, fileName);
		}
	});
	Object.keys(fileMap).forEach(fileName=>{
		fileMap[fileName].parsed.nodes.forEach(node=>{
			if (node.mathlang === 'script_definition') {
				p.addScript(node, fileName);
			} else if (node.mathlang === 'dialog_definition') {
				p.addDialog(node, fileName);
			} else if (node.mathlang === 'serial_dialog_definition') {
				p.addSerialDialog(node, fileName);
			}
		})
		if (verbose) {
			const { errorCount, warningCount } = f;
			let message = `${ansiTags.g}File ${fileName} complete!${ansiTags.reset}`;
			if (errorCount > 0 || warningCount > 0) {
				const errorMessage = errorCount
					? `${ansiTags.r}${errorCount} error${errorCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 errors`;
				const warningMessage = warningCount
					? `${ansiTags.y}${warningCount} warning${warningCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 warnings`;
				if (errorCount > 0 && warningCount > 0) {
					message += ` (${errorMessage}, ${warningMessage})`;
				} else if (errorCount > 0) {
					message += ` (${errorMessage})`;
				} else if (warningCount > 0) {
					message += ` (${warningMessage})`;
				}
			}
			console.log(message);
		}
	})
	// finalize
	p.detectDuplicates();
	p.reportProblems(fileMap);
	console.log("DONE");
	return p;
};

parseProject().then((p)=>{
	console.log('PROJECT', p);
	console.log("breakpoint me")
});
