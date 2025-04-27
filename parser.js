const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;
console.log("What is TreeSitter?", TreeSitter);
const fileText = `goatTime {
	wait [2s, 2000];
	wait 1000;
	wait 1000ms;
	wait 1s;
}`;

const nodeReport = (node) => {
	return {
		isError: node.isError,
		hasError: node.hasError,
		isExtra: node.isExtra,
		isMissing: node.isMissing,
		isNamed: node.isNamed,
		// parseState: node.parseState,
		hasChanges: node.hasChanges,
		grammarType: node.grammarType,
		// grammarId: node.grammarId,
		// startIndex: node.endPosition,
		startPosition: node.startPosition,
		endPosition: node.endPosition,
		children: node.children,
		}
};

const cleanFns = {
	BAREWORD: (node) => node.text,
	QUOTED_STRING: (node) => node.text.slice(1, -1),
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
	if (!fn) throw new Error ("DERP");
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
			scriptName: cleanedName,
			actions,
		};
	},
	'action_non_blocking_delay': (node) => {
		const durationNode = node.namedChildren[0];
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
		};
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
