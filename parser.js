const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

let verbose = true;
const debugLog = (message) => {
	if (verbose) console.log(message);
}

const cleanFns = {
	BOOL: (f, node) => {
		const text = node.text;
		if (text === 'true') return true;
		if (text === 'false') return false;
		if (text === 'on') return true;
		if (text === 'off') return false;
		if (text === 'open') return true;
		if (text === 'closed') return false;
	},
	BAREWORD: (f, node) => node.text,
	QUOTED_STRING: (f, node) => node.text.slice(1, -1),
	NUMBER: (f, node) => Number(node.text),
	DURATION: (f, node) => {
		let n = parseInt(node.namedChild('NUMBER').text);
		let suffixNode = node.childForFieldName('suffix');
		if (suffixNode?.text === 's') n *= 1000; 
		return n;
	},
	DISTANCE: (f, node) => Number(node.text),
	QUANTITY: (f, node) => {
		if (node.childCount === 0) {
			if (node.text === 'once') return 1;
			if (node.text === 'twice') return 2;
			if (node.text === 'thrice') return 3;
		}
		let n = parseInt(node.namedChild('NUMBER').text);
		let suffixNode = node.childForFieldName('suffix');
		if (suffixNode?.text === 's') n *= 1000; 
		return n;
	},
	COLOR: (f, node) => {
		if (node.childCount === 0) {
			if (node.text === 'white') return '#FFFFFF';
			if (node.text === 'black') return '#000000';
			if (node.text === 'red') return '#FF0000';
			if (node.text === 'green') return '#00FF00';
			if (node.text === 'blue') return '#0000FF';
			if (node.text === 'magenta') return '#FF00FF';
			if (node.text === 'cyan') return '#00FFFF';
			if (node.text === 'yellow') return '#FFFF00';
		}
		if (node.text.length === 4) {
			const a = node.text[1];
			const b = node.text[2];
			const c = node.text[3];
			return `#${a}${a}${b}${b}${c}${c}`;
		}
		return node.text;
	},
	CONSTANT: (f, node) => node.text,
};
const clean = (f, node) => {
	// expansions cannot be recursive, so this is fine
	if (node.grammarType.endsWith('_expansion')) {
		return node.namedChildren.map(v=>clean(f, v));
	}
	if (node.grammarType === 'CONSTANT') {
		const lookup = f.constants[node.text];
		if (lookup === undefined) {
			f.errors.push({
				message: `Constant ${node.text} is undefined`,
				node,
				fileName: f.fileName,
			});
		}
		return lookup?.value || node.text;
	}
	const fn = cleanFns[node.grammarType];
	if (!fn) throw new Error ("No clean function for node type " + node.grammarType);
	return fn(f, node);
};

const handleAction = (f, node) => {
	const genericData = actionData[node.grammarType];
	if (!genericData) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error (`No data or handler function found for ${node.grammarType}`);
		return customFn(f, node);
	}
	let ret = {
		debug: node,
		fileName: f.fileName,
		...genericData?.values,
	};
	const spreadFields = {};
	let spreadSize = -Infinity;
	(genericData.captures||[]).forEach(fieldName=>{
		const fieldNode = node.childForFieldName(fieldName);
		const cleanField = clean(f, fieldNode);
		if (!Array.isArray(cleanField)) {
			ret[fieldName] = cleanField;
		} else {
			spreadFields[fieldName] = cleanField;
			const len = cleanField.length;
			if (spreadSize === -Infinity) spreadSize = len;
			if (spreadSize !== len) {
				f.errors.push({
					message: `spreads must have the same count of items within a given action`,
					node: fieldNode,
					fileName: f.fileName,
				});
				spreadSize = Math.max(spreadSize, len);
			}
		}
	});
	if (spreadSize === -Infinity) {
		return [ret];
	}
	const spreadRet = [];
	for (let i = 0; i < spreadSize; i++) {
		const insert = {
			...ret,
		};
		Object.keys(spreadFields).forEach(fieldName=>{
			const allValues = spreadFields[fieldName];
			const currValue = allValues[i % allValues.length];
			insert[fieldName] = currValue;
		});
		spreadRet.push(insert);
	}
	return spreadRet;
};

actionFns = {};

actionData = {
	action_return_statement: {
		// TODO: everything after is unreachable
		values: { mathlang: 'return_statement' },
	},
	action_close_dialog: {
		values: { action: 'CLOSE_DIALOG' },
	},
	action_close_serial_dialog: {
		values: { action: 'CLOSE_SERIAL_DIALOG' },
	},
	action_save_slot: {
		values: { action: 'SLOT_SAVE' },
	},
	action_load_slot: {
		values: { action: 'SLOT_LOAD' },
		captures: [ 'slot' ],
	},
	action_erase_slot: {
		values: { action: 'SLOT_ERASE' },
		captures: [ 'slot' ],
	},
	action_load_map: {
		values: { action: 'LOAD_MAP' },
		captures: [ 'map' ],
	},
	action_goto_label: {
		values: { mathlang: 'goto_label' },
		captures: [ 'label' ],
	},
	action_goto_index: {
		values: { action: 'GOTO_ACTION_INDEX' },
		captures: [ 'action_index' ],
	},
	action_run_script: {
		values: { action: 'RUN_SCRIPT' },
		captures: [ 'script' ],
	},
	action_non_blocking_delay: {
		values: { action: 'NON_BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
	action_blocking_delay: {
		values: { action: 'BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
};

const handleNode = (f, node) => {
	if (node.grammarType.startsWith('action_')) {
		return handleAction(f, node);
	}
	const nodeFn = nodeFns[node.grammarType];
	if (!nodeFn) {
		throw new Error ('no named node function for '+ node.grammarType);
	}
	return nodeFn(f, node);
}
const nodeFns = {
	line_comment: (f, node) => [],
	block_comment: (f, node) => [],
	ERROR: (f, node) => {
		f.errors.push({
			message: 'tree-sitter parse error (generic)',
			node,
			fileName: f.fileName,
		})
		return [];
	},
	script_definition: (f, node) => {
		// get script_name
		const nameNode = node.childForFieldName('script_name');
		const name = clean(f, nameNode);
		const actions = node.lastChild.namedChildren
			.map(node=>handleNode(f, node))
			.flat();
		return [{
			mathlang: 'script_definition',
			scriptName: name,
			actions,
			debug: node,
			fileName: f.fileName,
		}];
	},
	constant_assignment: (f, node) => {
		const labelNode = node.childForFieldName('label');
		const valueNode = node.childForFieldName('value');
		const label = labelNode.text;
		const value = clean(f, valueNode);
		f.constants = f.constants || {};
		if (f.constants[labelNode]) {
			f.errors.push({
				message: `cannot redefine constant ${ret.label}`,
				node,
				fileName: f.fileName,
			});
		}
		f.constants[label] = {
			value,
			type: valueNode.grammarType,
			debug: node,
			fileName: f.fileName,
		};
		return [{
			mathlang: 'constant_assignment',
			label,
			value,
			debug: node,
			fileName: f.fileName,
		}];
	},
	include_macro: (f, node) => {
		// TODO: handle recursive references
		let includeFileNode = node.childForFieldName('fileName');
		let cleaned = clean(f, includeFileNode);
		const prerequesites = Array.isArray(cleaned) ? cleaned : [ cleaned ];
		prerequesites.forEach(prereq=> {
			if (!fileMap[prereq].parsed) {
				debugLog(`include_macro: must first parse prerequesite "${prereq}"`);
				parseFile(prereq, f.parser)
			} else {
				debugLog(`include_macro: prerequesite "${prereq}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereq} into ${f.fileName}...`);
			f = mergeF(f, fileMap[prereq].parsed);
		});
		return [ // need not include
			// {
			// 	mathlang: 'include_macro',
			// 	value: cleaned,
			// 	debug: node,
			// 	fileName: f.fileName,
			// }
		];
	},
	rand_macro: (f, node) => {
		const horizontal = [];
		let multipleCount = -Infinity;
		node.namedChildren
			.forEach(node=>{
				const handled = handleNode(f, node);
				const len = handled.length;
				if (len === 0) return;
				horizontal.push(handled);
				if (len === 1) return;
				if (multipleCount === -Infinity) multipleCount = len;
				if (multipleCount !== len) {
					f.errors = [{
						message: `spreads inside rand!() must contain same number of items`,
						node,
						fileName: f.fileName,
					}];
				}
			})
		const vertical = [];
		for (let i = 0; i < multipleCount; i++) {
			const insert = horizontal.map(unit=>{
				const len = unit.length;
				return unit[i % len];
			})
			vertical.push(insert);
		}
		return [{
			mathlang: 'rand_macro',
			splits: vertical,
			debug: node,
			fileName: f.fileName,
		}];
	},
	add_serial_dialog_settings: (f, node) => {
		const parameters = node.namedChildren
			.map(child=>handleNode(f, child))
			.flat();
		parameters.forEach(param=>{
			f.settings.serial[param.property] = param.value;
		})
		return [ // might not need to include this
			// {
			// 	mathlang: 'add_serial_dialog_settings',
			// 	parameters,
			// 	debug: node,
			// 	fileName: f.fileName,
			// }
		];
	},
	serial_dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		if (!propNode || !valueNode) {
			f.errors.push({
				message: `malformed serial_dialog parameter`,
				node,
				fileName: f.fileName,
			});
			return [];
		}
		return [{
			mathlang: 'serial_dialog_parameter',
			node,
			fileName: f.fileName,
			property: clean(f, propNode),
			value: clean(f, valueNode),
		}]
	},
};

const fileMap = {
	"header.mgs": {
		text: `
			$trombones = 76;
			add serial_dialog settings {
				wrap 75
			}
		`,
	},
	"castle.mgs": {
		text: `
			include "header.mgs";
			goats { wait $trombones; }
		`,
	},
}

const mergeF = (f1, f2) => {
	Object.keys(f2.constants).forEach(constantName=>{
		if (f1.constants[constantName]) {
			f.errors.push({
				message: `cannot redefine constant ${constantName} (via 'include_macro')`,
				node: f2.constants[constantName].node,
				fileName: f2.fileName,
			})
		}
		f1.constants[constantName] = f2.constants[constantName];
	});
	f2.errors.forEach(error=>{ f1.errors.push(error) });
	f2.warnings.forEach(warning=>{ f1.warnings.push(warning) });
	f2.nodes.forEach(node=>{ f1.nodes.push(node) });
	['default', 'entity', 'label', 'serial'].forEach(type=>{
		const params = Object.keys(f2.settings[type]);
		params.forEach(param=>{
			f1.settings[type][param] = f2.settings[type][param];
		});
	});
	return f1;
}

const parseFile = (fileName, parser) => {
	if (!fileMap[fileName].parsed) {
		const tree = parser.parse(fileMap[fileName].text);
		let document = tree.rootNode;
		const f = {
			fileName,
			constants: {},
			settings: {
				default: {},
				entity: {},
				label: {},
				serial: {},
			},
			errors: [],
			warnings: [],
			nodes: [],
			parser,
		}
		const nodes = document.namedChildren
			.map(node=>handleNode(f, node))
			.flat();
		f.nodes = nodes;
		fileMap[fileName].parsed = f;
		return f;
	}
	return fileMap[fileName].parsed;
};

(async () => {
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);
	
	const fileNames = Object.keys(fileMap);
	fileNames.forEach(fileName=>{
		debugLog(`Parsing file "${fileName}"`);
		parseFile(fileName, parser);
	});
	console.log(fileMap);
})();
