const {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
} = require('./parser-utilities.js');

const inverseOpMap = {
	'<': '>=',
	'<=': '>',
	'>=': '<',
	'>': '<=',
	'==': '!=',
	'!==': '==',
	'&&': '||',
	'||': '&&',
};

const opIntoStringMap = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

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
		if (text === 'down') return true;
		if (text === 'up') return false;
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
	op_equals: (f, node) => opIntoStringMap[node.text[0]],
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
			if (!valueNode) {
				f.newError({
					locations: [{ node }],
					message: `dialog identifier lacks a value`,
				});
			}
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
			// ret.action = 'SET_SAVE_FLAG';
			const flagNameNode = node.childForFieldName('flag');
			ret.value = handleCapture(f, flagNameNode);
			ret.type = 'save_flag';
			return ret;
		}
		const type = typeNode.text;
		if (type === 'glitched') {
			// ret.action = 'SET_ENTITY_GLITCHED';
			const entityIdentNode = node.childForFieldName('entity_identifier');
			const entityTypeNode = entityIdentNode.childForFieldName('type');
			ret.value = extractEntityName(f, entityIdentNode, entityTypeNode);
			ret.type = 'entity';
			return ret;
		}
		if (type === 'light') {
			// ret.action = 'SET_LIGHTS_STATE';
			const lightIdentNode = node.childForFieldName('light');
			ret.value = handleCapture(f, lightIdentNode);
			ret.type = 'light';
			return ret;
		}
		ret.type = type;
		return ret;
	},
	int_binary_expression: (f, node) => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		const opNode = node.childForFieldName('operator');
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
	bool_binary_expression: (f, node) => {
		// const inner = node.namedChildren[0];
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		const opNode = node.childForFieldName('operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		const op = opNode.text;
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'boolean') {
			f.newError({
				locations: [
					{
						node: f.constants[rhs].debug,
						fileName: f.constants[rhs].fileName,
					},
					{ node: rhsNode },
				],
				message: `constant is not a boolean`
			})
			rhs = null;
		}
		if (lhsNode.grammarType === 'CONSTANT' && typeof lhs !== 'boolean') {
			f.newError({
				locations: [
					{
						node: f.constants[lhsNode.text].debug,
						fileName: f.constants[lhsNode.text].fileName,
					},
					{ node: lhsNode },
				],
				message: `constant is not a boolean`
			})
			lhs = null;
		}
		return {
			mathlang: node.grammarType,
			debug: node,
			fileName: f.fileName,
			lhs,
			lhsNode,
			rhs,
			rhsNode,
			op,
		};
	},
	bool_grouping: (f, node) => {
		const inner = node.childForFieldName('inner');
		return handleCapture(f, inner);
	},
	bool_unary_expression: (f, node) => {
		const opNode = node.childForFieldName('operator');
		const op = opNode.text;
		if (op !== '!') throw new Error ("what kind of unary is " + op + '?');
		const valueNode = node.childForFieldName('operand');
		const value = handleCapture(f, valueNode);
		if (typeof value === 'boolean') return !value;
		if (typeof value === 'string') {
			return {
				mathlang: 'check_save_flag',
				invert: true,
				value,
			}
		}
		value.invert = !value.invert;
		if (value.mathlang === 'bool_binary_expression' && value.invert) {
			value.invert = !value.invert;
			value.op = inverseOpMap[value.op];
			value.lhs.invert = !value.lhs.invert;
			value.rhs.invert = !value.rhs.invert;
		}
		return value;
	},
	int_getable: (f, node) => {
		const propertyNode = node.childForFieldName('property');
		const field = propertyNode.text;
		const entityNode = node.childForFieldName('entity_identifier');
		const entity = handleCapture(f, entityNode);
		return {
			mathlang: 'int_getable',
			debug: node,
			fileName: f.fileName,
			field,
			entity
		}
	},
	bool_getable: (f, node) => {
		const ret = {
			mathlang: 'bool_getable',
			debug: node,
			fileName: f.fileName,
			boolParamName: 'expected_bool',
		};
		const typeNode = node.childForFieldName('type');
		const type = typeNode.text;
		ret.type = type;
		if (type === 'debug_mode') {
			ret.action = 'CHECK_DEBUG_MODE';
		} else if (type === 'glitched') {
			ret.action = 'CHECK_ENTITY_GLITCHED';
			const entityIdentNode = node.childForFieldName('entity_identifier');
			const entityTypeNode = entityIdentNode.childForFieldName('type');
			ret.entity = extractEntityName(f, entityIdentNode, entityTypeNode);
		} else if (type === 'intersects') {
			ret.action = 'CHECK_IF_ENTITY_IS_IN_GEOMETRY';
			const entityIdentNode = node.childForFieldName('entity_identifier');
			const entityTypeNode = entityIdentNode.childForFieldName('type');
			ret.entity = extractEntityName(f, entityIdentNode, entityTypeNode);
			const geometryIdentNode = node.childForFieldName('geometry_identifier');
			ret.geometry = handleCapture(f, geometryIdentNode);
		} else if (type === 'dialog' || type === 'serial_dialog') {
			ret.action = type === 'dialog'
				? 'CHECK_DIALOG_OPEN'
				: 'CHECK_SERIAL_DIALOG_OPEN';
			const valueNode = node.childForFieldName('value')
			ret.value = valueNode.text;
		} else if (type === 'button') {
			ret.value = node.childForFieldName('button').text;
			const stateNode = node.childForFieldName('state');
			if (stateNode.text === 'pressed') {
				ret.action = 'CHECK_FOR_BUTTON_PRESS';
				ret.state = 'pressed';
			} else {
				ret.action = 'CHECK_FOR_BUTTON_STATE';
				ret.state = handleCapture(f, stateNode);
			}
		}
		return ret;
	},
	string_checkable: (f, node) => {
		const ret = {
			mathlang: 'string_checkable',
			debug: node,
			fileName: f.fileName,
			boolParamName: 'expected_bool',
		};
		const entityIdentNode = node.childForFieldName('entity_identifier');
		if (entityIdentNode) {
			ret.entity = extractEntityName(f, entityIdentNode);
			const property = node.childForFieldName('property')?.text;
			ret.property = property;
			if (property === 'on_tick') {
				ret.action = 'CHECK_ENTITY_TICK_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (property === 'on_look') {
				ret.action = 'CHECK_ENTITY_LOOK_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (property === 'on_interact') {
				ret.action = 'CHECK_ENTITY_INTERACT_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (property === 'on_interact') {
				ret.action = 'CHECK_ENTITY_NAME';
				ret.stringLabel = 'string';
			} else if (property === 'path') {
				ret.action = 'CHECK_ENTITY_PATH';
				ret.stringLabel = 'geometry';
			} else if (property === 'type') {
				ret.action = 'CHECK_ENTITY_TYPE';
				ret.stringLabel = 'entity_type';
			}
		} else {
			const type = node.childForFieldName('type');
			if (type.text === 'warp_state') {
				ret.action = 'CHECK_WARP_STATE';
				ret.stringLabel = 'string';
			} else {
				throw new Error (`this shouldn't happen`)
			}
		}
		return ret;
	},
	number_checkable_equality: (f, node) => {
		const ret = {
			mathlang: 'number_checkable_equality',
			debug: node,
			fileName: f.fileName,
		};
		const entityIdentNode = node.childForFieldName('entity_identifier');
		if (entityIdentNode) {
			ret.entity = extractEntityName(f, entityIdentNode);
			const propertyNode = node.childForFieldName('property');
			const property = propertyNode.text;
			ret.property = property;
			if (property === 'x') {
				ret.action = 'CHECK_ENTITY_X';
				ret.numberLabel = 'expected_u2';
			} else if (property === 'y') {
				ret.action = 'CHECK_ENTITY_Y';
				ret.numberLabel = 'expected_u2';
			} else if (property === 'primary_id') {
				ret.action = 'CHECK_ENTITY_PRIMARY_ID';
				ret.numberLabel = 'expected_u2';
			} else if (property === 'secondary_id') {
				ret.action = 'CHECK_ENTITY_SECONDARY_ID';
				ret.numberLabel = 'expected_u2';
			} else if (property === 'primary_id_type') {
				ret.action = 'CHECK_ENTITY_PRIMARY_ID_TYPE';
				ret.numberLabel = 'expected_byte';
			} else if (property === 'current_animation') {
				ret.action = 'CHECK_ENTITY_CURRENT_ANIMATION';
				ret.numberLabel = 'expected_byte';
			} else if (property === 'animation_frame') {
				ret.action = 'CHECK_ENTITY_CURRENT_FRAME';
				ret.numberLabel = 'expected_byte';
			} else if (property === 'strafe') {
				f.newError({
					location: [{ node: propertyNode }],
					message: `This property is not supported in boolean expressions`
				});
			}
		}
		return ret;
	},
	geometry_identifier: (f, node) => {
		const v = node.childForFieldName('geometry');
		return handleCapture(f, v);
	},
	nsew: (f, node) => node.text,
	nsew_checkable: (f, node) => {
		const entityIdentNode = node.childForFieldName('entity_identifier');
		return extractEntityName(f, entityIdentNode);
	},
	bool_comparison: (f, node) => {
		const lhsN = node.childForFieldName('lhs');
		const rhsN = node.childForFieldName('rhs');
		if (lhsN.grammarType === 'nsew_checkable') {
			return {
				mathlang: 'bool_comparison',
				...compareNSEW(f, lhsN, rhsN),
				expected_bool: node.childForFieldName('operator').text === '==',
			}
		} 
		if (rhsN.grammarType === 'nsew_checkable') {
			return {
				mathlang: 'bool_comparison',
				...compareNSEW(f, rhsN, lhsN),
				expected_bool: node.childForFieldName('operator').text === '==',
			}
		}
		if (lhsN.grammarType === 'string_checkable') {
			return {
				mathlang: 'bool_comparison',
				expected_bool: node.childForFieldName('operator').text === '==',
				...compareString(f, lhsN, rhsN),
			}
		}
		if (rhsN.grammarType === 'string_checkable') {
			return {
				mathlang: 'bool_comparison',
				expected_bool: node.childForFieldName('operator').text === '==',
				...compareString(f, rhsN, lhsN),
			}
		}
		if (lhsN.grammarType === 'number_checkable_equality') {
			return {
				mathlang: 'bool_comparison',
				...compareNumberCheckableEquality(f, lhsN, rhsN),
				expected_bool: node.childForFieldName('operator').text === '==',
			}
		}
		if (rhsN.grammarType === 'number_checkable_equality') {
			return {
				mathlang: 'bool_comparison',
				...compareNumberCheckableEquality(f, rhsN, lhsN),
				expected_bool: node.childForFieldName('operator').text === '==',
			}
		}
		const lhs = handleCapture(f, lhsN);
		const rhs = handleCapture(f, rhsN);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLES',
					variable: lhs,
					source: rhs,
					comparison: node.childForFieldName('operator').text,
					expected_bool: true,
				}
			} else if (typeof rhs === 'number') {
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLE',
					variable: lhs,
					value: rhs,
					comparison: node.childForFieldName('operator').text,
					expected_bool: true,
				}
			} else {
				throw new Error ('not yet implemented');
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				const comparison = node.childForFieldName('operator').text;
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLE',
					variable: rhs,
					value: lhs,
					comparison: inverseOpMap[comparison],
					expected_bool: true,
				}
			} else {
				throw new Error ('not yet implemented');
			}
		} else {
			throw new Error ('not yet implemented');
		}
	},
	int_setable: (f, node) => {
		const propertyNode = node.childForFieldName('property');
		const field = propertyNode.text;
		const entityNode = node.childForFieldName('entity_identifier');
		const entity = handleCapture(f, entityNode);
		return {
			mathlang: 'int_getable',
			debug: node,
			fileName: f.fileName,
			field,
			entity
		}
	},
	int_grouping: (f, node) => handleCapture(f, node.namedChildren[0]),
	bool_grouping: (f, node) => handleCapture(f, node.namedChildren[0]),
	direction_target: (f, node) => {
		const nsewNode = node.childForFieldName('nsew');
		if (nsewNode) {
			return {
				action: 'SET_ENTITY_DIRECTION',
				direction: nsewNode.text,
			};
		}
		const geometryNode = node.childForFieldName('geometry');
		if (geometryNode) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY',
				target_geometry: handleCapture(f, geometryNode),
			};
		}
		const entityNode = node.childForFieldName('entity');
		if (entityNode) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY',
				target_entity: handleCapture(f, entityNode),
			};
		}
	},
};
const compareNSEW = (f, node, nsewNode) => ({
	action: "CHECK_ENTITY_DIRECTION",
	direction: nsewNode.text,
	entity: extractEntityName(f, node.childForFieldName('entity_identifier')),
});

const compareString = (f, checkableNode, stringNode) => {
	const checkable = handleCapture(f, checkableNode);
	const string = handleCapture(f, stringNode);
	return {
		...checkable,
		[checkable.stringLabel]: string,
	}
};
const compareNumberCheckableEquality = (f, checkableNode, numberNode) => {
	const checkable = handleCapture(f, checkableNode);
	const number = handleCapture(f, numberNode);
	return {
		...checkable,
		[checkable.numberLabel]: number,
	}
};

const extractEntityName = (f, node, _typeNode) => {
	const typeNode = _typeNode || node.childForFieldName('type');
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
