const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const { debugLog } = require('./parser-utilities.js');
const { makeProjectState } = require('./parser-project.js');
const { ansiTags } = require('./parser-dialogs.js');

const fileMap = {
	binaryOperations: {
		fileName: 'binaryOperations.mgs',
		type: 'mgs',
		text: ``
			+ `\n simple { a = 1; player x = 1; }`
			// + `\n add { a = 1+2; player x = 1+2; }`
			// + `\n order1 { a = 1+2*3; player x = 1+2*3; }`
			// + `\n order2 { a = 1*2+3; player x = 1*2+3; }`
	}
};

const runTests = async () => {
	// tree-sitter
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);

	const p = makeProjectState(parser, fileMap);
	// parse each file
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			p.parseFile(fileName);
		}
	});
	// files have not been finalized yet

}


runTests().then((p)=>{
	console.log('TESTS', p);




	console.log("breakpoint me")
});

