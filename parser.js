const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

let verbose = true;
const debugLog = (message) => {
	if (verbose) console.log(message);
}

const captureFns = {
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
const handleCapture = (f, node) => {
	// expansions cannot be recursive, so this is fine
	if (node.grammarType.endsWith('_expansion')) {
		return node.namedChildren.map(v=>handleCapture(f, v));
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
	const fn = captureFns[node.grammarType];
	if (!fn) throw new Error (`No handler function found for token ${node.grammarType}`);
	return fn(f, node);
};

const handleAction = (f, node) => {
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error (`No action data nor handler function found for action ${node.grammarType}`);
		return customFn(f, node);
	}
	let ret = {
		debug: node,
		fileName: f.fileName,
		...data.values,
	};
	const spreadFields = {};
	let spreadSize = -Infinity;
	(data.captures||[]).forEach(fieldName=>{
		const fieldNode = node.childForFieldName(fieldName);
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			ret[fieldName] = capture;
		} else {
			spreadFields[fieldName] = capture;
			const len = capture.length;
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
	if (spreadSize === -Infinity) return [ret];
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
		// Ditto some other actions, too
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
		const nameNode = node.childForFieldName('script_name');
		const name = handleCapture(f, nameNode);
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
		const value = handleCapture(f, valueNode);
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
		// TODO: ~~handle~~ prevent recursive references
		let includeFileNode = node.childForFieldName('fileName');
		let capture = handleCapture(f, includeFileNode);
		const prerequesites = Array.isArray(capture) ? capture : [ capture ];
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
		return [{
			mathlang: 'include_macro',
			value: capture,
			debug: node,
			fileName: f.fileName,
		}];
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
				return unit[i % unit.length];
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
	add_dialog_settings: (f, node) => {
		const targets = node.namedChildren
			.map(child=>handleNode(f, child))
			.flat();
		return [{
			mathlang: 'add_dialog_settings',
			targets,
			debug: node,
			fileName: f.fileName,
		}]
	},
	add_dialog_settings_target: (f, node) => {
		let bucket;
		const type = node.firstChild.type;
		const targetNode = node.childForFieldName('target');
		if (type === 'target_default') {
			bucket = f.settings.default;
		} else if (type === 'target_label') {
			if (!targetNode) {
				f.errors.push({
					message: `dialog_settings_target: malformed label definition`,
					node,
					fileName: f.fileName,
				})
			}
			const target = targetNode.text || 'UNDEFINED LABEL';
			f.settings.label[target] = f.settings.label[target] || {};
			bucket = f.settings.label[target];
		} else if (type === 'target_entity') {
			if (!targetNode) {
				f.errors.push({
					message: `dialog_settings_target: malformed entity definition`,
					node,
					fileName: f.fileName,
				})
			}
			const target = targetNode.text || 'UNDEFINED ENTITY';
			f.settings.label[target] = f.settings.label[target] || {};
			bucket = f.settings.entity[target];
		} else {
			throw new Error("This shouldn't happen, I think");
		}
		const parameters = node.childrenForFieldName('dialog_parameter')
			.map(innerChild=>handleNode(f, innerChild))
			.flat();
		parameters.forEach(param=>{
			bucket[param.property] = param.value;
		});
		return [{
			mathlang: 'add_dialog_settings_target',
			parameters,
			debug: node,
			fileName: f.fileName,
		}];
	},
	dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		if (!propNode || !valueNode) {
			f.errors.push({
				message: `malformed dialog parameter`,
				node,
				fileName: f.fileName,
			});
			return [];
		}
		return [{
			mathlang: 'dialog_parameter',
			property: handleCapture(f, propNode),
			value: handleCapture(f, valueNode),
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
		return [{
			mathlang: 'add_serial_dialog_settings',
			parameters,
			debug: node,
			fileName: f.fileName,
		}];
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
			property: handleCapture(f, propNode),
			value: handleCapture(f, valueNode),
			debug: node,
			fileName: f.fileName,
		}]
	},
	serial_dialog_option: (f, node) => {
		const optionNode = node.childForFieldName('option_type');
		const labelNode = node.childForFieldName('label');
		const scriptNode = node.childForFieldName('script');
		if (!optionNode || !labelNode || !scriptNode) {
			f.errors.push({
				message: `malformed serial_dialog option`,
				debug: node,
				fileName: f.fileName,
			});
			return [];
		}
		let optionType = null;
		if (optionNode.text === '_') optionType = 'text_options';
		else if (optionNode.text === '#') optionType = 'options';
		return [{
			mathlang: 'serial_dialog_option',
			optionType,
			label: handleCapture(f, labelNode),
			script: handleCapture(f, scriptNode),
			debug: node,
			fileName: f.fileName,
		}]
	},
	serial_dialog_definition: (f, node) => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const serialDialogNode = node.childForFieldName('serial_dialog');
		const name = handleCapture(f, nameNode);
		const dialog = handleNode(f, serialDialogNode);
		return [{
			mathlang: 'serial_dialog_definition',
			serialDialogName: name,
			serialDialog: dialog[0],
			debug: node,
			fileName: f.fileName,
		}];
	},
	serial_dialog: (f, node) => {
		const paramNodes = node.childrenForFieldName('serial_dialog_parameter');
		const messageNodes = node.childrenForFieldName('serial_message');
		const optionNodes = node.childrenForFieldName('serial_dialog_option');
		const params = paramNodes.map(v=>handleNode(f, v)).flat();
		const options = optionNodes.map(v=>handleNode(f, v)).flat();
		// TODO: make options more closely resemble final form?
		const settings = {};
		params.forEach(param=>{
			settings[param.property] = param.value;
		});
		const messages = messageNodes.map(v=>handleCapture(f, v));
		return [{
			mathlang: 'serial_dialog',
			settings,
			messages,
			options,
			debug: node,
			fileName: f.fileName,
		}];
	},
	json_literal: (f, node) => {
		// TODO: do it more by hand so that errors can be reported more accurately
		const jsonNode = node.namedChildren[0];
		const text = jsonNode.text;
		let parsed = [];
		try {
			parsed = JSON.parse(text);
		} catch {
			f.errors.push({
				message: `JSON syntax error`,
				node,
				fileName: f.fileName,
			})
		}
		return [{
			mathlang: 'json_literal',
			json: parsed,
			debug: node,
			fileName: f.fileName,
		}]
	},
};

const fileMap = {
	"header.mgs": {
		text: `
			$trombones = 76;
			add dialog settings {
				default {
					alignment BL
				}
				label PLAYER {
					wrap 75
					alignment BR
				}
			}
		`,
	},
	"castle.mgs": {
		text: `
			serial_dialog goatTimes {
				wrap 99
				wrap 69
				"Serial Message! AHOY!"
				_ "what?" = goatScript
			}
			include "header.mgs";
			goats {
				wait $trombones;
				json [
					{"action":true}
				]
			}
		`,
	},
};

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
	// actually, errors etc. shouldn't show up multiple times; the fact that the included file
	// got parsed meant that its errors already happened once
	// f2.errors.forEach(error=>{ f1.errors.push(error) });
	// f2.warnings.forEach(warning=>{ f1.warnings.push(warning) });
	// unsure whether we need this one though; might help debug if included
	f2.nodes.forEach(node=>{ f1.nodes.push(node) });
	['default', 'serial'].forEach(type=>{
		const params = Object.keys(f2.settings[type]);
		params.forEach(param=>{
			f1.settings[type][param] = f2.settings[type][param];
		});
	});
	['entity', 'label'].forEach(type=>{
		const targets = Object.keys(f2.settings[type]);
		targets.forEach(target=>{
			const params = Object.keys(f2.settings[type][target]);
			f1.settings[type][target] = f1.settings[type][target] || {};
			params.forEach(param=>{
				f1.settings[type][target][param] = f2.settings[type][target][param];
			});
		});
	});
	return f1;
};

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
