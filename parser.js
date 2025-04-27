const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;
const fileText = `
$trombones = 76;
$hamburgers = "Steamed Hams";
goatTime {
	rand!(
		wait [1s, 2s, 3s];
		wait [1000, 2000];
		load map [town, egpplant];
		return;
	)
}`;

const cleanFns = {
	BAREWORD: (node) => node.text,
	QUOTED_STRING: (node) => node.text.slice(1, -1),
	CONSTANT: (node) => node.text,
	NUMBER: (node) => Number(node.text),
	DURATION: (node) => {
		let v = parseInt(node.text);
		const suffix = node.text.match(/(m?s)$/);
		if (suffix?.[1] === 's') {
			v *= 1000; 
		}
		return v;
	},
};
const clean = (node) => {
	if (node.grammarType.endsWith('_expansion')) {
		return node.namedChildren.map(clean);
	}
	const fn = cleanFns[node.grammarType];
	if (!fn) throw new Error ("No clean function for node type " + node.grammarType);
	return fn(node);
};
const namedNodeFunctions = {
	'script_definition': (node) => {
		// get script_name
		const nameNode = node.childForFieldName('script_name');
		const cleanedName = clean(nameNode);
		const actions = node.lastChild.namedChildren.map(node=>{
			return namedNodeFunctions[node.grammarType](node);
		}).flat();
		return {
			mathlang: 'script_definition',
			scriptName: cleanedName,
			actions,
			debug: node,
		};
	},
	'action_non_blocking_delay': (node, spreadIndex) => {
		const durationNode = node.childForFieldName('duration');
		const duration = clean(durationNode);
		if (Array.isArray(duration)) {
			return duration.map(v=>({
				action: "NON_BLOCKING_DELAY",
				duration: v,
			}));
		}
		return {
			action: "NON_BLOCKING_DELAY",
			duration: duration,
			debug: node,
		};
	},
	'return_statement': () => ({ mathlang: 'return_statement' }),
	'action_load_map': (node) => {
		const mapNode = node.childForFieldName('map');
		const map = clean(mapNode);
		if (Array.isArray(map)) {
			return map.map(v=>({
				action: "LOAD_MAP",
				map: v,
			}));
		}
		return {
			action: "LOAD_MAP",
			map: map,
			debug: node,
		};
	},
	'constant_assignment': (node) => {
		const label = node.childForFieldName('label');
		const value = node.childForFieldName('value');
		return {
			mathlang: 'constant_assignment',
			label: clean(label),
			value: clean(value),
			debug: node
		}

	},
	'rand_macro': (node) => {
		let count = 0;
		const splits = node.namedChildren.map(node=>{
			const fn = namedNodeFunctions[node.grammarType];
			if (!fn) throw new Error ('no named node function for '+ node.grammarType);
			const result = namedNodeFunctions[node.grammarType](node, count);
			return Array.isArray(result) ? result : [result];
		});
		const ret = {
			mathlang: 'rand_macro',
			splits,
			debug: node,
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
				ret.errors = [{
					message: `spread actions inside rand!() must have same number of members`
				}];
			}
		})
		return ret;
	},
	// 'include_macro': (node) => {},
};

(async () => {
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);
	
	const tree = parser.parse(fileText);
	let source_file = tree.rootNode;

	const nodes = source_file.namedChildren.map(node=>{
	return namedNodeFunctions[node.grammarType](node);
	})

	console.log(nodes);
})();
