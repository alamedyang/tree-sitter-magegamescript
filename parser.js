const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

const fs = require('node:fs');
const path = require('node:path');

const { debugLog } = require('./parser-utilities.js');
const { printScript } = require('./parser-to-json.js');
const { makeProjectState } = require('./parser-project.js');
const { ansiTags } = require('./parser-dialogs.js');
const { composites } = require('./comparisons/exfiltrated_composites.js');
const { idk } = require('./comparisons/exfiltrated_idk.js');

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

	// Make script plaintext readable (pre copy, labels)
	Object.keys(p.scripts).forEach(scriptName=>{
		p.scripts[scriptName].prePrint = printScript(scriptName, p.scripts[scriptName].actions);
	});

	// copyscript - TODO: check for recursion?
	p.copyScriptAll();
	
	// bake all the labels into hard-coded action indices
	p.bakeLabels();

	// Make script plaintext readable
	Object.keys(p.scripts).forEach(scriptName=>{
		p.scripts[scriptName].print = printScript(scriptName, p.scripts[scriptName].actions);
	});
	
	// print fancy squiggly error messages
	p.printProblems();
	
	// done!
	return p;
};

// /*
const inputPath = path.resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

const sanitizeActions = (action) => {
	if (action.action === 'SHOW_DIALOG') {
		action.dialog = action.dialog.replace(/(-|:)\d+:\d+$/, '-XX');
	} else if (action.action === 'SHOW_SERIAL_DIALOG') {
		action.serial_dialog = action.serial_dialog.replace(/(-|:)\d+:\d+$/, '-XX');
	}
	return action;
}

const compareNonGotoActions = (lhsText, rhsText) => {
	const lhs = getNonGotoActions(lhsText);
	const rhs = getNonGotoActions(rhsText);
	const lhsEntries = Object.entries(lhs);
	for (let i = 0; i < lhsEntries.length; i++) {
		const [k, v] = lhsEntries[i];
		if (rhs[k] !== v) {
			return false;
		}
	}
	const rhsEntries = Object.entries(rhs);
	for (let i = 0; i < rhsEntries.length; i++) {
		const [k, v] = rhsEntries[i];
		if (lhs[k] !== v) {
			return false;
		}
	}
	return true;
}
const getNonGotoActions = (text) => {
	const lines = text.split('\n');
	const counts = {};
	lines.forEach(line=>{
		const match = line.match(/((.+) then goto) (index \d+|label .+);/);
		let key = match ? match[1] : line;
		if (/^\s*goto /.test(key)) {
			return;
		} else if (/^\s*.+:$/.test(key)) {
			return;
		} else if (/^\s*\/\//.test(key)) {
			return;
		}
		key = key.replace(/(-|:)\d+:\d+";$/, '-XX";')
		counts[key] = (counts[key] || 0) + 1;
	});
	return counts;
}

parseProject(fileMap).then((p)=>{
	// console.log('PROJECT');
	// console.log(p);
	// const printAll = Object.values(p.scripts)
	// 	.map(v=>v.print)
	// 	.join('\n\n');
	// console.log(printAll);
	const prints = {};
	let tally = 0;
	let badTally = 0;
	let trustTally = 0;
	Object.entries(p.scripts).forEach(([k,v])=>{
		let old = composites[k] || idk[k];
		const oldVersionFiltered = old
			.map(sanitizeActions);
		const newVersionFiltered = v.actions
			.filter(vv=>{
				return vv.mathlang !== 'comment'
					&& vv.mathlang !== 'return_statement'
					&& vv.mathlang !== 'dialog_definition'
					&& vv.mathlang !== 'serial_dialog_definition'
			})
			.map(vv=>{
				delete vv.comment;
				return sanitizeActions(vv)
			});
		const oldVersion = printScript(k, oldVersionFiltered);
		const newVersion = printScript(k, newVersionFiltered);
		if (oldVersion === newVersion) {
			tally += 1;
		} else if (compareNonGotoActions(oldVersion, newVersion)) {
			trustTally += 1;
		} else {
			const newVersionWithLabels = v.prePrint;
			const nonGotoActions = compareNonGotoActions(oldVersion, newVersionWithLabels);
			if (!nonGotoActions) {
				prints[k] = {
					mathlangPre: v.prePrint,
					mathlang: newVersion,
					natlang: oldVersion,
					original: v.debug.text,
				}
				badTally += 1;
			} else {
				trustTally += 1;
			}
		}
	});
	const lhs = Object.values(prints).map(v=>v.natlang).join('\n\n');
	const rhs = Object.values(prints).map(v=>v.mathlang).join('\n\n');
	const rhsPre = Object.values(prints).map(v=>v.mathlangPre).join('\n\n');
	const original = Object.values(prints).map(v=>v.original).join('\n\n');
	console.log(`${tally} scripts were identical (${badTally} were clearly different, and ${trustTally} are probably okay)`)
	fs.writeFileSync(`./comparisons/lhs.mgs`, lhs);
	fs.writeFileSync(`./comparisons/rhs.mgs`, rhs);
	fs.writeFileSync(`./comparisons/rhsPre.mgs`, rhsPre);
	fs.writeFileSync(`./comparisons/rhsOriginal.mgs`, original);

});
// */

module.exports = { parseProject };
