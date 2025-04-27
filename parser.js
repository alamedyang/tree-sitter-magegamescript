const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;
const fileText = `
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
	BAREWORD: (f, node) => node.text,
	QUOTED_STRING: (f, node) => node.text.slice(1, -1),
	CONSTANT: (f, node) => node.text,
	NUMBER: (f, node) => Number(node.text),
	DURATION: (f, node) => {
		let v = parseInt(node.text);
		const suffix = node.text.match(/(m?s)$/);
		// TODO: make it an immediate pattern? is that for this?
		if (suffix?.[1] === 's') {
			v *= 1000; 
		}
		return v;
	},
};
const clean = (f, node) => {
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
			})
		}
		return lookup?.value || node.text;
	}
	const fn = cleanFns[node.grammarType];
	if (!fn) throw new Error ("No clean function for node type " + node.grammarType);
	return fn(f, node);
};
const namedNodeFunctions = {
	'script_definition': (f, node) => {
		// get script_name
		const nameNode = node.childForFieldName('script_name');
		const name = clean(f, nameNode);
		const actions = node.lastChild.namedChildren.map(node=>{
			return namedNodeFunctions[node.grammarType](f, node);
		}).flat();
		return {
			mathlang: 'script_definition',
			scriptName: name,
			actions,
			debug: node,
			fileName: f.fileName,
		};
	},
	'action_non_blocking_delay': (f, node) => {
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
		return {
			action: "NON_BLOCKING_DELAY",
			duration: duration,
			debug: node,
			fileName: f.fileName,
		};
	},
	'return_statement': (f, node) => ({
		// TODO: everything after is unreachable
		mathlang: 'return_statement',
		debug: node,
		fileName: f.fileName,
	}),
	'action_close_dialog': (f, node) => ({
		action: 'CLOSE_DIALOG',
		debug: node,
		fileName: f.fileName,
	}),
	'action_close_serial_dialog': (f, node) => ({
		action: 'CLOSE_SERIAL_DIALOG',
		debug: node,
		fileName: f.fileName,
	}),
	'action_load_map': (f, node) => {
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
		return {
			action: "LOAD_MAP",
			map: map,
			debug: node,
			fileName: f.fileName,
		};
	},
	'constant_assignment': (f, node) => {
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
		return {
			mathlang: 'constant_assignment',
			label,
			value,
			debug: node,
			fileName: f.fileName,
		};
	},
	'rand_macro': (f, node) => {
		const splits = node.namedChildren.map(node=>{
			const fn = namedNodeFunctions[node.grammarType];
			if (!fn) throw new Error ('no named node function for '+ node.grammarType);
			const result = namedNodeFunctions[node.grammarType](f, node);
			return Array.isArray(result) ? result : [result];
		});
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
		return ret;
	},
	// 'include_macro': (f, node) => {},
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
	let source_file = tree.rootNode;

	const f = {
		fileName: 'testFile',
		constants: {},
		errors: [],
		warnings: [],
	}

	const nodes = source_file.namedChildren.map(node=>{
	return namedNodeFunctions[node.grammarType](f, node);
	})

	console.log(nodes);
})();
