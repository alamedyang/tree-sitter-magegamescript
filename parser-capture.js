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
	forever: (f, node) => true,
	entity_or_map_identifier: (f, node) => {
		// for 'entity' fields (-> string)
		const typeNode = node.childForFieldName('type');
		return typeNode.text === 'map'
			? '%MAP%'
			: extractEntityName(f, node, typeNode);
	},
	entity_identifier: (f, node) => {
		// for 'entity' fields (-> string)
		const typeNode = node.childForFieldName('type');
		return extractEntityName(f, node, typeNode);
	},
	movable_identifier: (f, node) => {
		// not just for 'entity' fields;
		// result determines which action it is,
		// so result needs to be complex (-> {})
		const ret = {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
		};
		const typeNode = node.childForFieldName('type');
		if (typeNode.text === 'camera') {
			ret.type = 'camera';
			ret.value = 'camera';
		} else {
			const entityName = extractEntityName(f, node, typeNode);
			ret.type = 'entity';
			ret.value = entityName;
		}
		return ret;
	},
	dialog_identifier: (f, node) => {
		let type;
		let value;
		const labelNode = node.childForFieldName('label');
		if (labelNode) {
			type = 'label';
			value = labelNode.text;
		} else {
			const typeNode = node.childForFieldName('type');
			const valueNode = node.childForFieldName('value');
			type = typeNode.text;
			value = valueNode
				? handleCapture(f, valueNode)
				: 'MALFORMED ENTITY IDENTIFIER';
			f.newError({
				locations: [{ node }],
				message: `dialog identifier lacks a value`,
			});
		}
		return {
			mathlang: 'dialog_identifier',
			type,
			value,
			debug: node,
			fileName: f.fileName,
		};
	},
	dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		return {
			mathlang: 'dialog_parameter',
			property: propNode.text,
			value: handleCapture(f, valueNode),
			debug: node,
			fileName: f.fileName,
		};
	},
	serial_dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		return {
			mathlang: 'serial_dialog_parameter',
			property: propNode.text,
			value: handleCapture(f, valueNode),
			debug: node,
			fileName: f.fileName,
		};
	},
	coordinate_identifier: (f, node) => {
		const typeNode = node.childForFieldName('type');
		const type = typeNode.text;
		const ret = {
			mathlang: 'coordinate_identifier',
			debug: node,
			fileName: f.fileName,
		};
		if (type === 'geometry') {
			const geometryNode = node.childForFieldName('geometry');
			const polygonTypeNode = node.childForFieldName('polygon_type');
			ret.type = 'geometry';
			ret.value = extractGeometryName(f, geometryNode);
			ret.polygonType = polygonTypeNode?.text;
		} else {
			const entityName = extractEntityName(f, node, typeNode);
			ret.type = 'entity';
			ret.value = entityName;
		}
		return ret;
	},
	bool_setable: (f, node) => {
		const ret = {
			mathlang: 'bool_setable',
			debug: node,
			fileName: f.fileName,
		};
		const typeNode = node.childForFieldName('type');
		if (!typeNode) {
			const flagNameNode = node.childForFieldName('flag');
			ret.value = handleCapture(f, flagNameNode);
			ret.type = 'save_flag';
			return ret;
		}
		const type = typeNode.text;
		if (type === 'glitched') {
			const entityIdentNode = node.childForFieldName('entity_identifier');
			const entityTypeNode = entityIdentNode.childForFieldName('type');
			ret.value = extractEntityName(f, entityIdentNode, entityTypeNode);
			ret.type = 'entity';
			return ret;
		}
		if (type === 'light') {
			const lightIdentNode = node.childForFieldName('light');
			ret.value = handleCapture(f, lightIdentNode);
			ret.type = 'light';
			return ret;
		}
		ret.type = type;
		return ret;
	},
	bool_or_identifier: (f, node) => {
		const ret = {
			mathlang: 'bool_or_identifier',
			debug: node,
			fileName: f.fileName,
		};
		const capture = handleCapture(f, node);
		ret.value = capture;
		if (typeof capture === 'string') {
			ret.type = 'identifier';
			ret.mathlang = 'setBoolOnFlagName';
			// return mathSequenceFns.setBoolOnFlagName(f, node, spread, boolName);
		} else {
			ret.type = 'boolean'
		}
		return ret;
	},
	int_binary_expression: (f, node) => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		const opNode = node.childForFieldName('binary_operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		const op = opNode.text;
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'number') {
			f.newError({
				locations: [
					{
						node: f.constants[rhs].debug,
						fileName: f.constants[rhs].fileName,
					},
					{ node: rhsNode },
				],
				message: `constant is not a number`
			})
			rhs = NaN;
		}
		if (lhsNode.grammarType === 'CONSTANT' && typeof lhs !== 'number') {
			f.newError({
				locations: [
					{
						node: f.constants[lhsNode.text].debug,
						fileName: f.constants[lhsNode.text].fileName,
					},
					{ node: lhsNode },
				],
				message: `constant is not a number`
			})
			lhs = NaN;
		}
		return {
			mathlang: 'int_binary_expression',
			debug: node,
			fileName: f.fileName,
			lhs,
			rhs,
			op
		};
	},
	entity_int_getable: (f, node) => {
		const propertyNode = node.childForFieldName('property');
		const field = propertyNode.text;
		const entityNode = node.childForFieldName('entity_identifier');
		const entity = handleCapture(f, entityNode);
		return {
			mathlang: 'entity_int_getable',
			debug: node,
			fileName: f.fileName,
			field,
			entity
		}
	},
	int_setable: (f, node) => {
		const propertyNode = node.childForFieldName('property');
		const field = propertyNode.text;
		const entityNode = node.childForFieldName('entity_identifier');
		const entity = handleCapture(f, entityNode);
		return {
			mathlang: 'entity_int_getable',
			debug: node,
			fileName: f.fileName,
			field,
			entity
		}
	},
	int_grouping: (f, node) => handleCapture(f, node.namedChildren[0])
};

const extractEntityName = (f, node, typeNode) => {
	const type = typeNode.text;
	let entity;
	if (type === 'self') entity = '%SELF%'
	if (type === 'player') entity = '%PLAYER%'
	if (type === 'entity') {
		const entityNode = node.childForFieldName('entity');
		if (entityNode) {
			entity = handleCapture(f, entityNode);
		} else {
			entity = 'UNDEFINED ENTITY';
			f.newError({
				locations: [{ node }],
				message: 'undefined entity identifier'
			});
		}
	}
	return entity;
};
const extractGeometryName = (f, geometryNode) => {
	let geometry;
	if (geometryNode) {
		geometry = handleCapture(f, geometryNode);
	} else {
		geometry = 'UNDEFINED GEOMETRY';
		f.newError({
			locations: [{ node }],
			message: 'undefined geometry identifier'
		});
	}
	return geometry;
};

module.exports = handleCapture;
