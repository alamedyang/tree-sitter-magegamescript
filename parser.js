const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;
const fileText = `
goatTime {
	rand!(
		return;
		load slot [0, 1];
		goto label [goats, pineapple];
	)
}`;

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
			.map(node=>handleNode(f, node)).flat();
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
		const label = clean(f, labelNode);
		const value = clean(f, valueNode);
		f.constants = f.constants || {};
		if (f.constants[labelNode]) {
			f.errors.push({
				message: `cannot redefine constant ${ret.label}`,
				node,
				fileName: f.fileName,
			})
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
};

// const fileMap = {
// 	"castle.mgs": {
// 		text: `
// 		$trombones = 76;
// 		$hamburgers = "Steamed Hams";
// 		goatTime {
// 			rand!(
// 				wait [1s, 2s, 3s];
// 				wait [1000, 2000];
// 				load map [town, $hamburgers];
// 				return;
// 			)
// 		}`
// 	}
// }


(async () => {
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);
	
	const tree = parser.parse(fileText);
	let document = tree.rootNode;

	const f = {
		fileName: 'testFile',
		constants: {},
		errors: [],
		warnings: [],
	}

	const nodes = document.namedChildren
		.map(node=>handleNode(f, node))
		.flat();

	console.log(nodes);
})();
