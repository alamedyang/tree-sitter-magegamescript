const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;
const fileText = `
$test = #ABC;
$trombones = 76;
$hamburgers = "Steamed Hams";
goatTime {
	rand!(
		wait [1s, 2s, 3s];
		wait [1000, 2000];
		load map [town, $hamburgers];
		return;
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

const handleNode = (f, node) => {
	const genericFn = nodeFns[node.grammarType];
	if (!genericFn) {
		throw new Error ('no named node function for '+ node.grammarType);
	}
	return genericFn(f, node);
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
	action_non_blocking_delay: (f, node) => {
		const durationNode = node.childForFieldName('duration');
		const duration = clean(f, durationNode);
		if (Array.isArray(duration)) {
			return duration.map(v=>({
				action: "NON_BLOCKING_DELAY",
				duration: v,
				debug: node,
				fileName: f.fileName,
			}));
		}
		return [{
			action: "NON_BLOCKING_DELAY",
			duration: duration,
			debug: node,
			fileName: f.fileName,
		}];
	},
	return_statement: (f, node) => [{
		// TODO: everything after is unreachable
		mathlang: 'return_statement',
		debug: node,
		fileName: f.fileName,
	}],
	action_close_dialog: (f, node) => [{
		action: 'CLOSE_DIALOG',
		debug: node,
		fileName: f.fileName,
	}],
	action_close_serial_dialog: (f, node) => [{
		action: 'CLOSE_SERIAL_DIALOG',
		debug: node,
		fileName: f.fileName,
	}],
	action_load_map: (f, node) => {
		const mapNode = node.childForFieldName('map');
		const map = clean(f, mapNode);
		if (Array.isArray(map)) {
			return map.map(v=>({
				action: "LOAD_MAP",
				map: v,
				debug: node,
				fileName: f.fileName,
			}));
		}
		return [{
			action: "LOAD_MAP",
			map: map,
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
		const splits = node.namedChildren
			.map(node=>handleNode(f, node))
			.filter(item => item.length>0);
		const ret = {
			mathlang: 'rand_macro',
			splits,
			debug: node,
			fileName: f.fileName,
		};
		const lengths = {};
		let max = 0;
		splits.forEach(split=>{
			const len = split.length;
			lengths[len] = (lengths[len] || 0) + 1;
			max = Math.max(max, len);
		});
		Object.keys(lengths).forEach(n=>{
			if (n!==1 && n!==max) {
				f.errors = [{
					message: `spread items inside rand!() must have same number of members`,
					node,
					fileName: f.fileName,
				}];
			}
		})
		return [ret];
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
