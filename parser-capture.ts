import { Node as TreeSitterNode } from 'web-tree-sitter';
import { getBoolFieldForAction } from './parser-bytecode-info.ts';
import * as TYPES from './parser-types.ts';
import {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	invert,
	inverseOpMap,
} from './parser-utilities.js';

const opIntoStringMap: Record<string, string> = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

export const handleCapture = (f: TYPES.FileState, node: TreeSitterNode | null) => {
	if (!node) throw new Error('TS FRFR');
	reportErrorNodes(f, node);
	reportMissingChildNodes(f, node);
	const grammarType = node.grammarType;
	debugLog(`-->> Capturing: ${grammarType}`);
	// expansions cannot be recursive, so this is fine
	if (grammarType.endsWith('_expansion')) {
		return node.namedChildren.map((v) => handleCapture(f, v));
	}
	if (grammarType === 'CONSTANT') {
		const lookup = f.constants[node.text];
		if (lookup === undefined) {
			f.newError({
				locations: [{ node }],
				message: `Constant ${node.text} is undefined`,
			});
		}
		return lookup?.value || node.text;
	}
	const fn = captureFns[grammarType];
	if (!fn) throw new Error(`No handler function found for token ${grammarType}`);
	const ret = fn(f, node);
	// todo: Maybe I don't need this? Errors are reported as they are discovered, not ascertained after the fact (bereft of context), right?
	if (typeof ret === 'object') {
		ret.debug = {
			node,
			fileName: f.fileName,
		};
	}
	return ret;
};
const captureFns = {
	BOOL: (f: TYPES.FileState, node: TreeSitterNode) => {
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
	BAREWORD: (f: TYPES.FileState, node: TreeSitterNode) => node.text,
	QUOTED_STRING: (f: TYPES.FileState, node: TreeSitterNode) => node.text.slice(1, -1),
	NUMBER: (f: TYPES.FileState, node: TreeSitterNode) => Number(node.text),
	DURATION: (f: TYPES.FileState, node: TreeSitterNode) => {
		const suffix = textForFieldName(f, node, 'suffix');
		const int = textForFieldName(f, node, 'NUMBER');
		let n = parseInt(int);
		if (suffix === 's') n *= 1000;
		return n;
	},
	DISTANCE: (f: TYPES.FileState, node: TreeSitterNode) => parseInt(node.text),
	QUANTITY: (f: TYPES.FileState, node: TreeSitterNode) => {
		if (node.childCount === 0) {
			if (node.text === 'once') return 1;
			if (node.text === 'twice') return 2;
			if (node.text === 'thrice') return 3;
		}
		const suffix = textForFieldName(f, node, 'suffix');
		const int = textForFieldName(f, node, 'NUMBER');
		let n = parseInt(int);
		if (suffix === 's') n *= 1000;
		return n;
	},
	COLOR: (f: TYPES.FileState, node: TreeSitterNode) => {
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
	CONSTANT: (f: TYPES.FileState, node: TreeSitterNode) => node.text,
	op_equals: (f: TYPES.FileState, node: TreeSitterNode) => opIntoStringMap[node.text[0]],
	plus_minus_equals: (f: TYPES.FileState, node: TreeSitterNode) => node.text,
	forever: () => true,
	entity_or_map_identifier: (f: TYPES.FileState, node: TreeSitterNode) => {
		// -> string
		return textForFieldName(f, node, 'type') === 'map' ? '%MAP%' : extractEntityName(f, node);
	},
	entity_identifier: (f: TYPES.FileState, node: TreeSitterNode) => extractEntityName(f, node), // -> string
	movable_identifier: (f: TYPES.FileState, node: TreeSitterNode) => {
		// -> {}
		const ret: TYPES.MovableIdentifier = {
			mathlang: 'movable_identifier',
			type: '',
			value: '',
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
	dialog_identifier: (f: TYPES.FileState, node: TreeSitterNode) => {
		const label = textForFieldName(f, node, 'label');
		const ret = { mathlang: 'dialog_identifier' };
		if (label) {
			return {
				...ret,
				type: 'label',
				value: label,
			};
		}
		return {
			...ret,
			type: textForFieldName(f, node, 'type'),
			value: captureForFieldName(f, node, 'value'),
		};
	},
	dialog_parameter: (f: TYPES.FileState, node: TreeSitterNode) => {
		return {
			mathlang: 'dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: captureForFieldName(f, node, 'value'),
		};
	},
	serial_dialog_parameter: (f: TYPES.FileState, node: TreeSitterNode) => {
		return {
			mathlang: 'serial_dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: captureForFieldName(f, node, 'value'),
		};
	},
	coordinate_identifier: (f: TYPES.FileState, node: TreeSitterNode) => {
		const type = textForFieldName(f, node, 'type');
		const ret: TYPES.CoordinateIdentifier = {
			mathlang: 'coordinate_identifier',
			type: '',
			value: '',
			polygonType: '',
		};
		if (type === 'geometry') {
			return {
				...ret,
				type: 'geometry',
				value: captureForFieldName(f, node, 'geometry'),
				polygonType: textForFieldName(f, node, 'polygon_type'),
			};
		}
		return {
			...ret,
			type: 'entity',
			value: extractEntityName(f, node),
		};
	},
	bool_setable: (f: TYPES.FileState, node: TreeSitterNode) => {
		const ret = { mathlang: 'bool_setable' };
		const type = textForFieldName(f, node, 'type');
		if (!type) {
			return {
				...ret,
				// action: 'SET_SAVE_FLAG',
				value: captureForFieldName(f, node, 'flag'),
				type: 'save_flag',
			};
		}
		if (type === 'glitched') {
			return {
				// action: 'SET_ENTITY_GLITCHED',
				value: captureForFieldName(f, node, 'entity_identifier'),
				type: 'entity',
			};
		}
		if (type === 'light') {
			return {
				...ret,
				// action: 'SET_LIGHTS_STATE',
				value: captureForFieldName(f, node, 'light'),
				type: 'light',
			};
		}
		return { ...ret, type };
	},
	int_binary_expression: (f: TYPES.FileState, node: TreeSitterNode) => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'number') {
			f.newError({
				locations: [
					{
						node: f.constants[rhs].debug.node,
						fileName: f.constants[rhs].debug.fileName,
					},
					{ node: rhsNode },
				],
				message: `constant is not a number`,
			});
			rhs = NaN;
		}
		if (lhsNode.grammarType === 'CONSTANT' && typeof lhs !== 'number') {
			f.newError({
				locations: [
					{
						node: f.constants[lhsNode.text].debug.node,
						fileName: f.constants[lhsNode.text].debug.fileName,
					},
					{ node: lhsNode },
				],
				message: `constant is not a number`,
			});
			lhs = NaN;
		}
		return {
			mathlang: 'int_binary_expression',
			lhs,
			rhs,
			op,
		};
	},
	bool_binary_expression: (f: TYPES.FileState, node: TreeSitterNode) => {
		// PART OF BOOL EXPRESSIONS
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'boolean') {
			f.newError({
				locations: [
					{
						node: f.constants[rhs].debug.node,
						fileName: f.constants[rhs].debug.fileName,
					},
					{ node: rhsNode },
				],
				message: `constant is not a boolean`,
			});
			rhs = null;
		}
		if (lhsNode.grammarType === 'CONSTANT' && typeof lhs !== 'boolean') {
			f.newError({
				locations: [
					{
						node: f.constants[lhsNode.text].debug.node,
						fileName: f.constants[lhsNode.text].debug.fileName,
					},
					{ node: lhsNode },
				],
				message: `constant is not a boolean`,
			});
			lhs = null;
		}
		return {
			mathlang: node.grammarType,
			debug: {
				node,
				fileName: f.fileName,
			},
			lhs,
			lhsNode,
			rhs,
			rhsNode,
			op,
		};
	},
	bool_grouping: (f: TYPES.FileState, node: TreeSitterNode) =>
		captureForFieldName(f, node, 'inner'),
	bool_unary_expression: (f: TYPES.FileState, node: TreeSitterNode) => {
		// PART OF BOOL EXPRESSIONS
		const op = textForFieldName(f, node, 'operator');
		if (op !== '!') throw new Error("what kind of unary is '" + op + "'?");
		const capture = captureForFieldName(f, node, 'operand');
		const toInvert = typeof capture === 'object' ? { ...capture } : capture;
		const inverted = invert(f, node, toInvert);
		return inverted;
	},
	int_getable: (f: TYPES.FileState, node: TreeSitterNode) => {
		return {
			mathlang: 'int_getable',
			field: textForFieldName(f, node, 'property'),
			entity: captureForFieldName(f, node, 'entity_identifier'),
		};
	},
	bool_getable: (f: TYPES.FileState, node: TreeSitterNode) => {
		// PART OF BOOL EXPRESSIONS
		const type = textForFieldName(f, node, 'type');
		const ret = {
			mathlang: 'bool_getable',
			debug: {
				node,
				fileName: f.fileName,
			},
			action: '',
			entity: '',
			geometry: '',
			value: '',
			state: '',
			button_id: '',
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
			ret.action = type === 'dialog' ? 'CHECK_DIALOG_OPEN' : 'CHECK_SERIAL_DIALOG_OPEN';
			const param = getBoolFieldForAction(ret.action);
			if (!param) throw new Error('Missing param');
			const state = textForFieldName(f, node, 'value');
			if (state === 'open') ret[param] = true;
			if (state === 'closed') ret[param] = false;
		} else if (type === 'button') {
			ret.value = captureForFieldName(f, node, 'button');
			const stateNode = node.childForFieldName('state');
			if (!stateNode) throw new Error('Missing stateNode');
			if (stateNode.text === 'pressed') {
				ret.action = 'CHECK_FOR_BUTTON_PRESS';
				ret.state = 'pressed';
				ret.button_id = ret.value;
			} else {
				ret.action = 'CHECK_FOR_BUTTON_STATE';
				const state = handleCapture(f, stateNode);
				const param = getBoolFieldForAction(ret.action);
				if (!param) throw new Error('Missing param');
				ret.button_id = ret.value;
				ret[param] = state;
			}
		}
		const param = getBoolFieldForAction(ret.action);
		if (!param) throw new Error('Missing param');
		ret[param] = ret[param] === undefined ? true : ret[param];
		return ret;
	},
	string_checkable: (f: TYPES.FileState, node: TreeSitterNode) => {
		const ret = {
			mathlang: 'string_checkable',
			entity: '',
			property: '',
		};
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			ret.entity = entity;
			ret.property = textForFieldName(f, node, 'property');
			if (ret.property === 'on_tick') {
				return {
					...ret,
					action: 'CHECK_ENTITY_TICK_SCRIPT',
					stringLabel: 'expected_script',
				};
			} else if (ret.property === 'on_look') {
				return {
					...ret,
					action: 'CHECK_ENTITY_LOOK_SCRIPT',
					stringLabel: 'expected_script',
				};
			} else if (ret.property === 'on_interact') {
				return {
					...ret,
					action: 'CHECK_ENTITY_INTERACT_SCRIPT',
					stringLabel: 'expected_script',
				};
			} else if (ret.property === 'name') {
				return {
					...ret,
					action: 'CHECK_ENTITY_NAME',
					stringLabel: 'string',
				};
			} else if (ret.property === 'path') {
				return {
					...ret,
					action: 'CHECK_ENTITY_PATH',
					stringLabel: 'geometry',
				};
			} else if (ret.property === 'type') {
				return {
					...ret,
					action: 'CHECK_ENTITY_TYPE',
					stringLabel: 'entity_type',
				};
			}
		} else {
			const type = textForFieldName(f, node, 'type');
			if (type === 'warp_state') {
				return {
					...ret,
					action: 'CHECK_WARP_STATE',
					stringLabel: 'string',
				};
			} else {
				throw new Error(`this shouldn't happen`);
			}
		}
	},
	number_checkable_equality: (f: TYPES.FileState, node: TreeSitterNode) => {
		const ret = {
			mathlang: 'number_checkable_equality',
			entity: '',
			property: '',
		};
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			ret.entity = entity;
			ret.property = textForFieldName(f, node, 'property');
			if (ret.property === 'x') {
				return {
					...ret,
					action: 'CHECK_ENTITY_X',
					numberLabel: 'expected_u2',
				};
			} else if (ret.property === 'y') {
				return {
					...ret,
					action: 'CHECK_ENTITY_Y',
					numberLabel: 'expected_u2',
				};
			} else if (ret.property === 'primary_id') {
				return {
					...ret,
					action: 'CHECK_ENTITY_PRIMARY_ID',
					numberLabel: 'expected_u2',
				};
			} else if (ret.property === 'secondary_id') {
				return {
					...ret,
					action: 'CHECK_ENTITY_SECONDARY_ID',
					numberLabel: 'expected_u2',
				};
			} else if (ret.property === 'primary_id_type') {
				return {
					...ret,
					action: 'CHECK_ENTITY_PRIMARY_ID_TYPE',
					numberLabel: 'expected_byte',
				};
			} else if (ret.property === 'current_animation') {
				return {
					...ret,
					action: 'CHECK_ENTITY_CURRENT_ANIMATION',
					numberLabel: 'expected_byte',
				};
			} else if (ret.property === 'animation_frame') {
				return {
					...ret,
					action: 'CHECK_ENTITY_CURRENT_FRAME',
					numberLabel: 'expected_byte',
				};
			} else if (ret.property === 'strafe') {
				const propertyNode = node.childForFieldName('property');
				if (!propertyNode) throw new Error('Missing property node');
				f.newError({
					locations: [{ node: propertyNode }],
					message: `This property is not supported in boolean expressions`,
				});
			}
		}
		return ret;
	},
	geometry_identifier: (f: TYPES.FileState, node: TreeSitterNode) =>
		captureForFieldName(f, node, 'geometry'),
	nsew: (f: TYPES.FileState, node: TreeSitterNode) => node.text, // not used but maybe good for error'd nodes?
	entity_direction: (f: TYPES.FileState, node: TreeSitterNode) =>
		captureForFieldName(f, node, 'entity_identifier'),
	towards: (f: TYPES.FileState, node: TreeSitterNode) => {
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
	bool_comparison: (f: TYPES.FileState, node: TreeSitterNode) => {
		// PART OF BOOL EXPRESSIONS
		const lhsNode = node.childForFieldName('lhs');
		const rhsNode = node.childForFieldName('rhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = textForFieldName(f, node, 'operator');
		const ret = {
			mathlang: 'bool_comparison',
			debug: {
				node,
				fileName: f.fileName,
			},
		};
		if (lhsNode.grammarType === 'entity_direction') {
			return {
				...ret,
				...compareNSEW(f, lhsNode, rhsNode),
				expected_bool: op === '==',
			};
		}
		if (rhsNode.grammarType === 'entity_direction') {
			return {
				...ret,
				expected_bool: op === '==',
				...compareNSEW(f, rhsNode, lhsNode),
			};
		}
		if (lhsNode.grammarType === 'string_checkable') {
			return {
				...ret,
				expected_bool: op === '==',
				...compareString(f, lhsNode, rhsNode),
			};
		}
		if (rhsNode.grammarType === 'string_checkable') {
			return {
				...ret,
				expected_bool: op === '==',
				...compareString(f, rhsNode, lhsNode),
			};
		}
		if (lhsNode.grammarType === 'number_checkable_equality') {
			return {
				...ret,
				expected_bool: op === '==',
				...compareNumberCheckableEquality(f, lhsNode, rhsNode),
			};
		}
		if (rhsNode.grammarType === 'number_checkable_equality') {
			return {
				...ret,
				expected_bool: op === '==',
				...compareNumberCheckableEquality(f, rhsNode, lhsNode),
			};
		}
		const lhs = handleCapture(f, lhsNode);
		const rhs = handleCapture(f, rhsNode);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				return {
					...ret,
					...checkVariables(f, lhs, rhs, op),
				};
			} else if (typeof rhs === 'number') {
				return {
					...ret,
					...checkVariable(f, lhs, rhs, op),
				};
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				return checkVariable(f, rhs, lhs, inverseOpMap[op]);
			} else if (typeof rhs === 'number') {
				// Why would you do this? T.T
				return eval(`${lhs} ${op} ${rhs}`);
			}
		}
	},
	int_setable: (f: TYPES.FileState, node: TreeSitterNode) => {
		return {
			mathlang: 'int_getable',
			field: textForFieldName(f, node, 'property'),
			entity: captureForFieldName(f, node, 'entity_identifier'),
		};
	},
	int_grouping: (f: TYPES.FileState, node: TreeSitterNode) =>
		handleCapture(f, node.namedChildren[0]),
	direction_target: (f: TYPES.FileState, node: TreeSitterNode) => {
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
	set_entity_string_field: (f: TYPES.FileState, node: TreeSitterNode) => node.text,
};

// These are separated so that the LHS and RHS can be swapped easily
const compareNSEW = (f, entityNode, nsewNode) => ({
	action: 'CHECK_ENTITY_DIRECTION',
	direction: nsewNode.text,
	entity: captureForFieldName(f, entityNode, 'entity_identifier'),
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
const checkVariables = (f, variable, source, comparison) => {
	return {
		action: 'CHECK_VARIABLES',
		variable,
		source,
		comparison,
		expected_bool: true,
	};
};
const checkVariable = (f, variable, value, comparison) => ({
	action: 'CHECK_VARIABLE',
	variable,
	value,
	comparison,
	expected_bool: true,
});
const extractEntityName = (f, node) => {
	const type = textForFieldName(f, node, 'type');
	if (type === 'self') return '%SELF%';
	if (type === 'player') return '%PLAYER%';
	if (type !== 'entity') throw new Error('Entity identifier not an entity?');
	return captureForFieldName(f, node, 'entity');
};

// Very common node handling behaviors
export const captureForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return handleCapture(f, captureNode);
};
export const capturesForFieldName = (f, node, fieldName) => {
	return (node.childrenForFieldName(fieldName) || []).map((v) => handleCapture(f, v)).flat();
};
export const textForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.text;
};
export const grammarTypeForFieldName = (f, node, fieldName) => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.grammarType;
};
