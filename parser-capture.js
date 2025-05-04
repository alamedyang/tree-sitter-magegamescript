const {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
} = require('./parser-utilities.js');

const handleCapture = (f, node) => {
	debugLog(`-->> Capturing: ${node.grammarType}`);
	reportErrorNodes(f, node);
	reportMissingChildNodes(f, node);
	const parseAs = node.grammarType;
	// expansions cannot be recursive, so this is fine
	if (node.grammarType.endsWith('_expansion')) {
		return node.namedChildren.map(v=>handleCapture(f, v));
	}
	if (parseAs === 'CONSTANT') {
		const lookup = f.constants[node.text];
		if (lookup === undefined) {
			f.newError({
				locations: [{ node }],
				message: `Constant ${node.text} is undefined`,
			});
		}
		return lookup?.value || node.text;
	}
	const fn = captureFns[parseAs];
	if (!fn) throw new Error (`No handler function found for token ${parseAs}`);
	return fn(f, node);
};
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
	entity_or_map_identifier: (f, node) => {
		const targetNode = node.childForFieldName('target');
		const target = targetNode.text;
		let entity = '';
		if (target === 'map') entity = '%MAP%'
		if (target === 'self') entity = '%SELF%'
		if (target === 'player') entity = '%PLAYER%'
		if (target === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return entity;
	},
	entity_identifier: (f, node) => {
		const typeNode = node.childForFieldName('entity_type');
		const type = typeNode.text;
		let entity = '';
		if (type === 'self') entity = '%SELF%'
		if (type === 'player') entity = '%PLAYER%'
		if (type === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return entity;
	},
	movable_identifier: (f, node) => {
		const targetNode = node.childForFieldName('type');
		const target = targetNode.text;
		let entity = '';
		if (target === 'camera') {
			return {
				mathlang: 'movable_identifier',
				debug: node,
				fileName: f.fileName,
				type: 'camera',
				value: 'camera',
			}
		}
		if (target === 'self') entity = '%SELF%'
		if (target === 'player') entity = '%PLAYER%'
		if (target === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
			type: 'entity',
			value: entity,
		};
	},
	coordinate_identifier: (f, node) => {
		const typeNode = node.childForFieldName('type');
		const type = typeNode.text;
		let entity = '';
		if (type === 'geometry') {
			const geometryNode = node.childForFieldName('geometry');
			const geometry = geometryNode
				? handleCapture(f, geometryNode)
				: 'UNDEFINED GEOMETRY';
			return {
				mathlang: 'movable_identifier',
				debug: node,
				fileName: f.fileName,
				type: 'geometry',
				value: geometry,
			}
		}
 		if (type === 'self') entity = '%SELF%'
		if (type === 'player') entity = '%PLAYER%'
		if (type === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
			type: 'entity',
			value: entity,
		};
	},
	polygon_and_duration: (f, node) => {
		const polygonTypeNode = node.childForFieldName('polygon_type');
		const polygonType = polygonTypeNode.text;
		const durationNode = node.childForFieldName('duration');
		const duration = handleCapture(f, durationNode);
		const forever = !!node.childForFieldName('forever');
		return {
			mathlang: 'polygon_and_duration',
			debug: node,
			fileName: f.fileName,
			polygonType,
			duration,
			forever,
		};
	},
};

module.exports = handleCapture;
