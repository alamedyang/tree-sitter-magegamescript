const {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	invert,
} = require('./parser-utilities.js');
const {
	getBoolFieldForAction,
} = require('./parser-bytecode-info.js');

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

// TODO: auto apply fileName and debug:node at the end of the function lookup
// no need to add it individually each time
// (be sure it can be overridden though)
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
		const suffixNode = textForFieldName(f, node, 'suffix');
		let n = parseInt(node.namedChild('NUMBER').text);
		if (suffixNode === 's') n *= 1000; 
		return n;
	},
	DISTANCE: (f, node) => parseInt(node.text),
	QUANTITY: (f, node) => {
		if (node.childCount === 0) {
			if (node.text === 'once') return 1;
			if (node.text === 'twice') return 2;
			if (node.text === 'thrice') return 3;
		}
		const suffixNode = textForFieldName(f, node, 'suffix');
		let n = parseInt(node.namedChild('NUMBER').text);
		if (suffixNode === 's') n *= 1000; 
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
	entity_or_map_identifier: (f, node) => { // for 'entity' fields (-> string)
		return textForFieldName(f, node, 'type') === 'map'
			? '%MAP%'
			: extractEntityName(f, node);
	},
	entity_identifier: (f, node) => extractEntityName(f, node), // for 'entity' fields (-> string)
	movable_identifier: (f, node) => {
		// not just for 'entity' fields;
		// result determines which action it is,
		// so result needs to be complex (-> {})
		const ret = {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
		};
		const type = textForFieldName(f, node, 'type');
		if (type === 'camera') {
			ret.type = 'camera';
			ret.value = 'camera';
		} else {
			const entityName = extractEntityName(f, node);
			ret.type = 'entity';
			ret.value = entityName;
		}
		return ret;
	},
	dialog_identifier: (f, node) => {
		let type;
		let value;
		const label = textForFieldName(f, node, 'label');
		if (!label) {
			type = 'label';
			value = label;
		} else {
			type = textForFieldName(f, node, 'type');
			value = captureForFieldName(f, node, 'value');
			if (!value) {
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
		return {
			mathlang: 'dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: captureForFieldName(f, node, 'value'),
			debug: node,
			fileName: f.fileName,
		};
	},
	serial_dialog_parameter: (f, node) => {
		return {
			mathlang: 'serial_dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: captureForFieldName(f, node, 'value'),
			debug: node,
			fileName: f.fileName,
		};
	},
	coordinate_identifier: (f, node) => {
		const type = textForFieldName(f, node, 'type');
		const ret = {
			mathlang: 'coordinate_identifier',
			debug: node,
			fileName: f.fileName,
		};
		if (type === 'geometry') {
			ret.type = 'geometry';
			ret.value = captureForFieldName(f, node, 'geometry');
			ret.polygonType = textForFieldName(f, node, 'polygon_type');
		} else {
			ret.type = 'entity';
			ret.value = extractEntityName(f, node);
		}
		return ret;
	},
	bool_setable: (f, node) => {
		const ret = {
			mathlang: 'bool_setable',
			debug: node,
			fileName: f.fileName,
		};
		const type = textForFieldName(f, node, 'type');
		if (!type) {
			// ret.action = 'SET_SAVE_FLAG';
			ret.value = captureForFieldName(f, node, 'flag');
			ret.type = 'save_flag';
			return ret;
		}
		if (type === 'glitched') {
			// ret.action = 'SET_ENTITY_GLITCHED';
			ret.value = captureForFieldName(f, node, 'entity_identifier');
			ret.type = 'entity';
			return ret;
		}
		if (type === 'light') {
			// ret.action = 'SET_LIGHTS_STATE';
			ret.value = captureForFieldName(f, node, 'light');
			ret.type = 'light';
			return ret;
		}
		ret.type = type;
		return ret;
	},
	int_binary_expression: (f, node) => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
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
	bool_binary_expression: (f, node) => { // PART OF BOOL EXPRESSIONS
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
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
	bool_grouping: (f, node) => captureForFieldName(f, node, 'inner'),
	bool_unary_expression: (f, node) => { // PART OF BOOL EXPRESSIONS
		const op = textForFieldName(f, node, 'operator');
		if (op !== '!') throw new Error ("what kind of unary is '" + op + "'?");
		const capture = captureForFieldName(f, node, 'operand');
		const toInvert = typeof capture === 'object'  ? {...capture} : capture;
		const inverted = invert(f, node, toInvert);
		inverted.debug = node;
		return inverted;
	},
	int_getable: (f, node) => {
		return {
			mathlang: 'int_getable',
			debug: node,
			fileName: f.fileName,
			field: textForFieldName(f, node, 'property'),
			entity: captureForFieldName(f, node, 'entity_identifier'),
		}
	},
	bool_getable: (f, node) => { // PART OF BOOL EXPRESSIONS
		const type = textForFieldName(f, node, 'type');
		const ret = {
			mathlang: 'bool_getable',
			debug: node,
			fileName: f.fileName,
		};
		if (type === 'debug_mode') {
			ret.action = 'CHECK_DEBUG_MODE';
		} else if (type === 'glitched') {
			ret.action = 'CHECK_ENTITY_GLITCHED';
			ret.entity = captureForFieldName(f, node, 'entity_identifier');
		} else if (type === 'intersects') {
			ret.action = 'CHECK_IF_ENTITY_IS_IN_GEOMETRY';
			ret.entity = captureForFieldName(f, node, 'entity_identifier');
			ret.geometry = captureForFieldName(f, node, 'geometry_identifier');
		} else if (type === 'dialog' || type === 'serial_dialog') {
			ret.action = type === 'dialog'
				? 'CHECK_DIALOG_OPEN'
				: 'CHECK_SERIAL_DIALOG_OPEN';
			const param = getBoolFieldForAction(ret.action);
			const state = textForFieldName(f, node, 'value');
			if (state === 'open') ret[param] = true;
			if (state === 'closed') ret[param] = false;
		} else if (type === 'button') {
			ret.value = textForFieldName(f, node, 'button');
			const stateNode = node.childForFieldName('state');
			if (stateNode.text === 'pressed') {
				ret.action = 'CHECK_FOR_BUTTON_PRESS';
				ret.state = 'pressed';
			} else {
				ret.action = 'CHECK_FOR_BUTTON_STATE';
				const state = handleCapture(f, stateNode);
				const param = getBoolFieldForAction(ret.action);
				ret[param] = state;
			}
		}
		const param = getBoolFieldForAction(ret.action);
		ret[param] = ret[param] === undefined ? true : ret[param];
		return ret;
	},
	string_checkable: (f, node) => {
		const ret = {
			mathlang: 'string_checkable',
			debug: node,
			fileName: f.fileName,
		};
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			ret.entity = entity;
			ret.property = textForFieldName(f, node, 'property');
			if (ret.property === 'on_tick') {
				ret.action = 'CHECK_ENTITY_TICK_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (ret.property === 'on_look') {
				ret.action = 'CHECK_ENTITY_LOOK_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (ret.property === 'on_interact') {
				ret.action = 'CHECK_ENTITY_INTERACT_SCRIPT';
				ret.stringLabel = 'expected_script';
			} else if (ret.property === 'name') {
				ret.action = 'CHECK_ENTITY_NAME';
				ret.stringLabel = 'string';
			} else if (ret.property === 'path') {
				ret.action = 'CHECK_ENTITY_PATH';
				ret.stringLabel = 'geometry';
			} else if (ret.property === 'type') {
				ret.action = 'CHECK_ENTITY_TYPE';
				ret.stringLabel = 'entity_type';
			}
		} else {
			const type = textForFieldName(f, node, 'type');
			if (type === 'warp_state') {
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
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			ret.entity = entity;
			ret.property = textForFieldName(f, node, 'property');
			if (ret.property === 'x') {
				ret.action = 'CHECK_ENTITY_X';
				ret.numberLabel = 'expected_u2';
			} else if (ret.property === 'y') {
				ret.action = 'CHECK_ENTITY_Y';
				ret.numberLabel = 'expected_u2';
			} else if (ret.property === 'primary_id') {
				ret.action = 'CHECK_ENTITY_PRIMARY_ID';
				ret.numberLabel = 'expected_u2';
			} else if (ret.property === 'secondary_id') {
				ret.action = 'CHECK_ENTITY_SECONDARY_ID';
				ret.numberLabel = 'expected_u2';
			} else if (ret.property === 'primary_id_type') {
				ret.action = 'CHECK_ENTITY_PRIMARY_ID_TYPE';
				ret.numberLabel = 'expected_byte';
			} else if (ret.property === 'current_animation') {
				ret.action = 'CHECK_ENTITY_CURRENT_ANIMATION';
				ret.numberLabel = 'expected_byte';
			} else if (ret.property === 'animation_frame') {
				ret.action = 'CHECK_ENTITY_CURRENT_FRAME';
				ret.numberLabel = 'expected_byte';
			} else if (ret.property === 'strafe') {
				f.newError({
					location: [{ node: propertyNode }],
					message: `This property is not supported in boolean expressions`
				});
			}
		}
		return ret;
	},
	geometry_identifier: (f, node) => captureForFieldName(f, node, 'geometry'),
	nsew: (f, node) => node.text, // not used but maybe good for error'd nodes
	entity_direction: (f, node) => captureForFieldName(f, node, 'entity_identifier'),
	towards: (f, node) => {
		const direction = textForFieldName(f, node, 'nsew');
		if (direction) {
			return {
				action: 'SET_ENTITY_DIRECTION',
				direction,
			};
		}
		const target_geometry = captureForFieldName(f, node, 'geometry');
		if (target_geometry) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY',
				target_geometry,
			};
		}
		const target_entity = captureForFieldName(f, node, 'entity_identifier');
		if (target_entity) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY',
				target_entity,
			};
		}
	},
	bool_comparison: (f, node) => { // PART OF BOOL EXPRESSIONS
		const lhsNode = node.childForFieldName('lhs');
		const rhsNode = node.childForFieldName('rhs');
		const op = textForFieldName(f, node, 'operator');
		if (lhsNode.grammarType === 'entity_direction') {
			return {
				mathlang: 'bool_comparison',
				...compareNSEW(f, lhsNode, rhsNode),
				expected_bool: op === '==',
			}
		} 
		if (rhsNode.grammarType === 'entity_direction') {
			return {
				mathlang: 'bool_comparison',
				...compareNSEW(f, rhsNode, lhsNode),
				expected_bool: op === '==',
			}
		}
		if (lhsNode.grammarType === 'string_checkable') {
			return {
				mathlang: 'bool_comparison',
				expected_bool: op === '==',
				...compareString(f, lhsNode, rhsNode),
			}
		}
		if (rhsNode.grammarType === 'string_checkable') {
			return {
				mathlang: 'bool_comparison',
				expected_bool: op === '==',
				...compareString(f, rhsNode, lhsNode),
			}
		}
		if (lhsNode.grammarType === 'number_checkable_equality') {
			return {
				mathlang: 'bool_comparison',
				...compareNumberCheckableEquality(f, lhsNode, rhsNode),
				expected_bool: op === '==',
			}
		}
		if (rhsNode.grammarType === 'number_checkable_equality') {
			return {
				mathlang: 'bool_comparison',
				...compareNumberCheckableEquality(f, rhsNode, lhsNode),
				expected_bool: op === '==',
			}
		}
		const lhs = handleCapture(f, lhsNode);
		const rhs = handleCapture(f, rhsNode);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLES',
					variable: lhs,
					source: rhs,
					comparison: op,
					expected_bool: true,
					debug: node,
					fileName: f.fileName,
				}
			} else if (typeof rhs === 'number') {
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLE',
					variable: lhs,
					value: rhs,
					comparison: op,
					expected_bool: true,
					debug: node,
					fileName: f.fileName,
				}
			} else {
				throw new Error ('not yet implemented');
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				const comparison = op;
				return {
					mathlang: 'bool_comparison',
					action: 'CHECK_VARIABLE',
					variable: rhs,
					value: lhs,
					comparison: inverseOpMap[comparison],
					expected_bool: true,
					debug: node,
					fileName: f.fileName,
				}
			} else {
				throw new Error ('not yet implemented');
			}
		} else {
			throw new Error ('not yet implemented');
		}
	},
	int_setable: (f, node) => {
		return {
			mathlang: 'int_getable',
			debug: node,
			fileName: f.fileName,
			field: textForFieldName(f, node, 'property'),
			entity: captureForFieldName(f, node, 'entity_identifier')
		}
	},
	int_grouping: (f, node) => handleCapture(f, node.namedChildren[0]),
	bool_grouping: (f, node) => handleCapture(f, node.namedChildren[0]),
	direction_target: (f, node) => {
		const direction = textForFieldName(f, node, 'nsew');
		if (direction) {
			return {
				action: 'SET_ENTITY_DIRECTION',
				direction,
			};
		}
		const target_geometry = captureForFieldName(f, node, 'geometry');
		if (target_geometry) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY',
				target_geometry,
			};
		}
		const target_entity = captureForFieldName(f, node, 'entity');
		if (target_entity) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY',
				target_entity,
			};
		}
	},
	set_entity_string_field: (f, node) => node.text,
};

const compareNSEW = (f, node, nsewNode) => ({
	action: "CHECK_ENTITY_DIRECTION",
	direction: nsewNode.text,
	entity: captureForFieldName(f, node, 'entity_identifier'),
	fileName: f.fileName,
	debug: node,
});
const compareString = (f, checkableNode, stringNode) => {
	const checkable = handleCapture(f, checkableNode);
	const string = handleCapture(f, stringNode);
	return {
		...checkable,
		[checkable.stringLabel]: string,
	};
};
const compareNumberCheckableEquality = (f, checkableNode, numberNode) => {
	const checkable = handleCapture(f, checkableNode);
	const number = handleCapture(f, numberNode);
	return {
		...checkable,
		[checkable.numberLabel]: number,
	};
};
const extractEntityName = (f, node) => {
	const type = textForFieldName(f, node, 'type');
	if (type === 'self') return '%SELF%'
	if (type === 'player') return '%PLAYER%'
	if (type !== 'entity') throw new Error ('Entity identifier not an entity?');
	return captureForFieldName(f, node, 'entity');
};

const captureForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return handleCapture(f, captureNode);
};
const capturesForFieldName = (f, node, fieldName) => {
	return (node.childrenForFieldName(fieldName) || [])
		.map(v=>handleCapture(f, v))
		.flat();
};
const textForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.text;
};
const grammarTypeForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.grammarType;
};

module.exports = {
	handleCapture,
	captureForFieldName,
	capturesForFieldName,
	textForFieldName,
	grammarTypeForFieldName,
};
