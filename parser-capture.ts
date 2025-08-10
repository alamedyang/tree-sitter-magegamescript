import { Node as TreeSitterNode } from 'web-tree-sitter';
import { type MGSDebug } from './parser-bytecode-info.ts';
import {
	type CoordinateIdentifier,
	type MovableIdentifier,
	type DialogParameter,
	type SerialDialogParameter,
	type StringCheckable,
	isStringCheckable,
	type NumberCheckableEquality,
	isNumberCheckableEquality,
	type BoolGetable,
	type DialogIdentifier,
	type BoolSetable,
	type IntBinaryExpression,
	type BoolBinaryExpression,
	type BoolComparison,
	type BoolExpression,
	isBoolExpression,
	type IntGetable,
	type IntExpression,
	isIntExpression,
	type DirectionTarget,
	newCheckSaveFlag,
} from './parser-types.ts';
import {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	invertBoolExpression,
	inverseOpMap,
} from './parser-utilities.ts';
import { type FileState } from './parser-file.ts';

const opIntoStringMap: Record<string, string> = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

export type Capture =
	| number
	| boolean
	| string
	| MovableIdentifier
	| DialogIdentifier
	| DialogParameter
	| SerialDialogParameter
	| CoordinateIdentifier
	| BoolSetable
	| IntBinaryExpression
	| BoolExpression
	| BoolBinaryExpression
	| BoolExpression
	| IntGetable
	| BoolGetable
	| StringCheckable;

export const handleCapture = (f: FileState, node: TreeSitterNode | null): Capture | Capture[] => {
	if (!node) throw new Error('handleCapture: null node');
	reportErrorNodes(f, node);
	reportMissingChildNodes(f, node);
	// problems handled ^^
	const grammarType = node.grammarType;
	debugLog(`-->> Capturing: ${grammarType}`);
	if (grammarType.endsWith('_expansion')) {
		// fwiw, cannot become recursive according to the grammar (1 level deep only)
		return node.namedChildren.map((v) => handleCapture(f, v)).flat();
	}
	// swap out values of compile-time constants
	if (grammarType === 'CONSTANT') {
		const lookup = f.constants[node.text];
		if (lookup === undefined) {
			f.newError({
				locations: [{ node }],
				message: `Constant ${node.text} is undefined`,
			});
		}
		return lookup?.value !== undefined ? lookup?.value : node.text;
	}
	// do the thing
	const fn = captureFns[grammarType];
	if (!fn) throw new Error(`No capture handler function found for grammar type ${grammarType}`);
	return fn(f, node);
};

const captureFns = {
	BOOL: (f: FileState, node: TreeSitterNode): boolean => {
		const text = node.text;
		if (text === 'true') return true;
		if (text === 'false') return false;
		if (text === 'on') return true;
		if (text === 'off') return false;
		if (text === 'open') return true;
		if (text === 'closed') return false;
		if (text === 'down') return true;
		if (text === 'up') return false;
		throw new Error('unreachable');
	},
	BAREWORD: (f: FileState, node: TreeSitterNode): string => node.text,
	QUOTED_STRING: (f: FileState, node: TreeSitterNode): string => node.text.slice(1, -1),
	NUMBER: (f: FileState, node: TreeSitterNode): number => Number(node.text),
	DURATION: (f: FileState, node: TreeSitterNode): number => {
		const suffix = optionalTextForFieldName(f, node, 'suffix');
		const int = textForFieldName(f, node, 'NUMBER');
		let n = parseInt(int);
		if (suffix === 's') n *= 1000;
		return n;
	},
	DISTANCE: (f: FileState, node: TreeSitterNode): number => parseInt(node.text),
	QUANTITY: (f: FileState, node: TreeSitterNode): number => {
		if (node.childCount === 0) {
			if (node.text === 'once') return 1;
			if (node.text === 'twice') return 2;
			if (node.text === 'thrice') return 3;
		}
		const int = textForFieldName(f, node, 'NUMBER');
		const n = parseInt(int);
		return n;
	},
	COLOR: (f: FileState, node: TreeSitterNode): string => {
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
	CONSTANT: (f: FileState, node: TreeSitterNode): string => node.text,
	op_equals: (f: FileState, node: TreeSitterNode): string => opIntoStringMap[node.text[0]],
	plus_minus_equals: (f: FileState, node: TreeSitterNode): string => node.text,
	forever: () => true,
	entity_or_map_identifier: (f: FileState, node: TreeSitterNode): string => {
		const type = optionalTextForFieldName(f, node, 'type');
		return type === 'map' ? '%MAP%' : extractEntityName(f, node);
	},
	entity_identifier: (f: FileState, node: TreeSitterNode): string => extractEntityName(f, node),
	movable_identifier: (f: FileState, node: TreeSitterNode): MovableIdentifier => {
		const type = optionalTextForFieldName(f, node, 'type');
		if (type === 'camera') {
			return {
				mathlang: 'movable_identifier',
				type: 'camera',
				value: 'camera',
			};
		} else {
			return {
				mathlang: 'movable_identifier',
				type: 'entity',
				value: extractEntityName(f, node),
			};
		}
	},
	dialog_identifier: (f: FileState, node: TreeSitterNode): DialogIdentifier => {
		const label = optionalTextForFieldName(f, node, 'label');
		if (label) {
			return {
				mathlang: 'dialog_identifier',
				type: 'label',
				value: label,
			};
		}
		const type = textForFieldName(f, node, 'type');
		if (type !== 'label' && type !== 'entity' && type !== 'name') {
			throw new Error('invalid dialog identifier type: ' + type);
		}
		return {
			mathlang: 'dialog_identifier',
			type,
			value: stringCaptureForFieldName(f, node, 'value'),
		};
	},
	dialog_parameter: (f: FileState, node: TreeSitterNode): DialogParameter => {
		return {
			mathlang: 'dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: stringOrNumberCaptureForFieldName(f, node, 'value'),
		};
	},
	serial_dialog_parameter: (f: FileState, node: TreeSitterNode): SerialDialogParameter => {
		return {
			mathlang: 'serial_dialog_parameter',
			property: textForFieldName(f, node, 'property'),
			value: stringOrNumberCaptureForFieldName(f, node, 'value'),
		};
	},
	coordinate_identifier: (f: FileState, node: TreeSitterNode): CoordinateIdentifier => {
		const type = optionalTextForFieldName(f, node, 'type');
		if (type === 'entity_path') {
			return {
				mathlang: 'coordinate_identifier',
				type: 'geometry',
				value: '%ENTITY_PATH%',
				polygonType: optionalTextForFieldName(f, node, 'polygon_type'),
			};
		}
		if (type === 'geometry') {
			return {
				mathlang: 'coordinate_identifier',
				type: 'geometry',
				value: stringCaptureForFieldName(f, node, 'geometry'),
				polygonType: optionalTextForFieldName(f, node, 'polygon_type'),
			};
		}
		return {
			mathlang: 'coordinate_identifier',
			type: 'entity',
			value: extractEntityName(f, node),
		};
	},
	bool_setable: (f: FileState, node: TreeSitterNode): BoolSetable => {
		const type = optionalTextForFieldName(f, node, 'type');
		if (!type) {
			return {
				// action: 'SET_SAVE_FLAG',
				mathlang: 'bool_setable',
				value: stringCaptureForFieldName(f, node, 'flag'),
				type: 'save_flag',
			};
		}
		if (type === 'glitched') {
			return {
				// action: 'SET_ENTITY_GLITCHED',
				mathlang: 'bool_setable',
				value: stringCaptureForFieldName(f, node, 'entity_identifier'),
				type: 'entity',
			};
		}
		if (type === 'light') {
			return {
				// action: 'SET_LIGHTS_STATE',
				mathlang: 'bool_setable',
				value: stringCaptureForFieldName(f, node, 'light'),
				type: 'light',
			};
		}
		return { mathlang: 'bool_setable', type };
	},
	int_binary_expression: (f: FileState, node: TreeSitterNode): IntBinaryExpression => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode in int_binary_expression');
		if (!lhsNode) throw new Error('missing lhsNode in int_binary_expression');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (!isIntExpression(rhs)) throw new Error('RHS not Int Exp');
		if (!isIntExpression(lhs)) throw new Error('LHS not Int Exp');
		if (rhsNode.grammarType === 'CONSTANT') {
			rhs = coerceToNumber(f, rhsNode, rhs, 'constant');
		}
		if (lhsNode.grammarType === 'CONSTANT') {
			lhs = coerceToNumber(f, lhsNode, lhs, 'constant');
		}
		return {
			mathlang: 'int_binary_expression',
			lhs,
			rhs,
			op,
		};
	},
	bool_binary_expression: (f: FileState, node: TreeSitterNode): BoolBinaryExpression => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (rhsNode.grammarType === 'CONSTANT') {
			rhs = coerceAsBool(f, rhsNode, rhs, 'constant');
		}
		if (lhsNode.grammarType === 'CONSTANT') {
			lhs = coerceAsBool(f, lhsNode, lhs, 'constant');
		}
		if (isBoolExpression(lhs) && isBoolExpression(rhs)) {
			return {
				mathlang: 'bool_binary_expression',
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
		}
		if (
			(isStringCheckable(lhs) || typeof lhs === 'string') &&
			(isStringCheckable(rhs) || typeof rhs === 'string')
		) {
			return {
				mathlang: 'bool_binary_expression',
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
		}
		if (
			(isNumberCheckableEquality(lhs) || typeof lhs === 'number') &&
			(isNumberCheckableEquality(rhs) || typeof rhs === 'number')
		) {
			return {
				mathlang: 'bool_binary_expression',
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
		}
		throw new Error('invalid LHS and RHS combo for captured bool binary expression');
	},
	bool_grouping: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const capture = captureForFieldName(f, node, 'inner');
		if (isBoolExpression(capture)) return capture;
		throw new Error('bool_grouping capture did not yield a bool expression');
	},
	bool_unary_expression: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const op = optionalTextForFieldName(f, node, 'operator');
		if (op !== '!') throw new Error('captured unknown unary operator: ' + op);
		const capture = captureForFieldName(f, node, 'operand');
		if (isBoolExpression(capture)) {
			const toInvert = typeof capture === 'object' ? { ...capture } : capture;
			return invertBoolExpression(f, node, toInvert);
		}
		throw new Error('bool_unary_expression capture did not yield a bool expression');
	},
	int_getable: (f: FileState, node: TreeSitterNode): IntGetable => {
		// if (textForFieldName(f, node, 'variable')) {
		// 	return captureForFieldName(f, node, 'variable');
		// }
		return {
			mathlang: 'int_getable',
			field: textForFieldName(f, node, 'property'),
			entity: stringCaptureForFieldName(f, node, 'entity_identifier'),
		};
	},
	bool_getable: (f: FileState, node: TreeSitterNode): BoolGetable => {
		const type = optionalTextForFieldName(f, node, 'type');
		const debug = {
			node,
			fileName: f.fileName,
		};
		if (type === 'flag') {
			return newCheckSaveFlag(f, node, stringCaptureForFieldName(f, node, 'value'), true);
		} else if (type === 'debug_mode') {
			return {
				mathlang: 'bool_getable',
				action: 'CHECK_DEBUG_MODE',
				debug,
				expected_bool: true,
			};
		} else if (type === 'glitched') {
			return {
				mathlang: 'bool_getable',
				action: 'CHECK_ENTITY_GLITCHED',
				debug,
				expected_bool: true,
				entity: stringCaptureForFieldName(f, node, 'entity_identifier'),
			};
		} else if (type === 'intersects') {
			return {
				mathlang: 'bool_getable',
				action: 'CHECK_IF_ENTITY_IS_IN_GEOMETRY',
				debug,
				expected_bool: true,
				entity: stringCaptureForFieldName(f, node, 'entity_identifier'),
				geometry: stringCaptureForFieldName(f, node, 'geometry_identifier'),
			};
		} else if (type === 'dialog' || type === 'serial_dialog') {
			const state = optionalTextForFieldName(f, node, 'value');
			if (type === 'dialog') {
				return {
					mathlang: 'bool_getable',
					action: 'CHECK_DIALOG_OPEN',
					debug,
					expected_bool: state === 'open',
				};
			} else {
				return {
					mathlang: 'bool_getable',
					action: 'CHECK_SERIAL_DIALOG_OPEN',
					debug,
					expected_bool: state === 'open',
				};
			}
		} else if (type === 'button') {
			const button_id = stringCaptureForFieldName(f, node, 'button');
			const stateNode = node.childForFieldName('state');
			if (!stateNode) throw new Error('missing stateNode in bool_getable capture');
			if (stateNode.text === 'pressed') {
				return {
					mathlang: 'bool_getable',
					action: 'CHECK_FOR_BUTTON_PRESS',
					debug,
					expected_bool: true,
					button_id,
				};
			} else {
				const state = handleCapture(f, stateNode);
				return {
					mathlang: 'bool_getable',
					action: 'CHECK_FOR_BUTTON_STATE',
					debug,
					expected_bool: coerceAsBool(f, node, state, 'button state'),
					button_id,
				};
			}
		}
		throw new Error('failed to capture bool_getable');
	},
	string_checkable: (f: FileState, node: TreeSitterNode): StringCheckable => {
		const entity = optionalStringCaptureForFieldName(f, node, 'entity_identifier');
		if (entity === null) {
			const type = optionalTextForFieldName(f, node, 'type');
			if (type === 'warp_state') {
				return {
					mathlang: 'string_checkable',
					action: 'CHECK_WARP_STATE',
					expected_bool: true,
					stringLabel: 'string',
					string: '',
				};
			} else {
				throw new Error(
					`unidentifiable non-entity string_checkable: capturing type ${type}`,
				);
			}
		}
		const property = textForFieldName(f, node, 'property');
		if (property === 'on_tick') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_TICK_SCRIPT',
				expected_bool: true,
				stringLabel: 'expected_script',
				expected_script: '',
			};
		} else if (property === 'on_look') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_LOOK_SCRIPT',
				expected_bool: true,
				stringLabel: 'expected_script',
				expected_script: '',
			};
		} else if (property === 'on_interact') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_INTERACT_SCRIPT',
				expected_bool: true,
				stringLabel: 'expected_script',
				expected_script: '',
			};
		} else if (property === 'name') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_NAME',
				expected_bool: true,
				stringLabel: 'string',
				string: '',
			};
		} else if (property === 'path') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_PATH',
				expected_bool: true,
				stringLabel: 'geometry',
				geometry: '',
			};
		} else if (property === 'type') {
			return {
				mathlang: 'string_checkable',
				entity,
				action: 'CHECK_ENTITY_TYPE',
				expected_bool: true,
				stringLabel: 'entity_type',
				entity_type: '',
			};
		}
		throw new Error(`unidentifiable entity string_checkable, failed to capture`);
	},
	number_checkable_equality: (f: FileState, node: TreeSitterNode): NumberCheckableEquality => {
		const entity = stringCaptureForFieldName(f, node, 'entity_identifier');
		const property = textForFieldName(f, node, 'property');
		if (property === 'x') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_X',
				numberLabel: 'expected_u2',
			};
		} else if (property === 'y') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_Y',
				numberLabel: 'expected_u2',
			};
		} else if (property === 'primary_id') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_PRIMARY_ID',
				numberLabel: 'expected_u2',
			};
		} else if (property === 'secondary_id') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_SECONDARY_ID',
				numberLabel: 'expected_u2',
			};
		} else if (property === 'primary_id_type') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_PRIMARY_ID_TYPE',
				numberLabel: 'expected_byte',
			};
		} else if (property === 'current_animation') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_CURRENT_ANIMATION',
				numberLabel: 'expected_byte',
			};
		} else if (property === 'animation_frame') {
			return {
				mathlang: 'number_checkable_equality',
				entity,
				property,
				action: 'CHECK_ENTITY_CURRENT_FRAME',
				numberLabel: 'expected_byte',
			};
		} else if (property === 'strafe') {
			const propertyNode = node.childForFieldName('property');
			if (!propertyNode) {
				throw new Error('missing property node in capture number_checkable_equality');
			}
			f.newError({
				locations: [{ node: propertyNode }],
				message: `this property is not supported in boolean expressions`,
			});
		}
		throw new Error('could not capture number_checkable_equality');
	},
	geometry_identifier: (f: FileState, node: TreeSitterNode): string => {
		const type = optionalTextForFieldName(f, node, 'type');
		if (type === 'entity_path') {
			return '%ENTITY_PATH%';
		}
		return stringCaptureForFieldName(f, node, 'geometry');
	},
	entity_direction: (f: FileState, node: TreeSitterNode): string => {
		return stringCaptureForFieldName(f, node, 'entity_identifier');
	},
	bool_comparison: (f: FileState, node: TreeSitterNode): BoolComparison | boolean => {
		const lhsNode = node.childForFieldName('lhs');
		const rhsNode = node.childForFieldName('rhs');
		if (!rhsNode) throw new Error('missing rhsNode in bool_comparison capture');
		if (!lhsNode) throw new Error('missing lhsNode in bool_comparison capture');
		const op = textForFieldName(f, node, 'operator');
		const debug = {
			node,
			fileName: f.fileName,
		};
		// entity Bob direction == north
		if (lhsNode.grammarType === 'entity_direction') {
			return compareNSEW(f, lhsNode, rhsNode, op, debug);
		}
		// north == entity Bob direction
		if (rhsNode.grammarType === 'entity_direction') {
			return compareNSEW(f, rhsNode, lhsNode, op, debug);
		}
		// entity Bob name == "Super Bob"
		if (lhsNode.grammarType === 'string_checkable') {
			return compareString(f, lhsNode, rhsNode, op, debug);
		}
		// "Super Bob" == entity Bob name
		if (rhsNode.grammarType === 'string_checkable') {
			return compareString(f, rhsNode, lhsNode, op, debug);
		}
		// entity Bob x == 7
		if (lhsNode.grammarType === 'number_checkable_equality') {
			return compareNumberCheckableEquality(f, lhsNode, rhsNode, op, debug);
		}
		// 7 == entity Bob x
		if (rhsNode.grammarType === 'number_checkable_equality') {
			return compareNumberCheckableEquality(f, rhsNode, lhsNode, op, debug);
		}
		const lhs = handleCapture(f, lhsNode);
		const rhs = handleCapture(f, rhsNode);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				// varName1 > varName2
				return checkVariables(f, lhs, rhs, op, debug);
			} else if (typeof rhs === 'number') {
				// varName > 255
				return checkVariable(f, lhs, rhs, op, debug);
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				// 255 > varName
				return checkVariable(f, rhs, lhs, inverseOpMap[op], debug);
			} else if (typeof rhs === 'number') {
				// 255 > 0
				if (op === '<') return lhs < rhs;
				if (op === '<=') return lhs <= rhs;
				if (op === '>') return lhs > rhs;
				if (op === '>=') return lhs >= rhs;
				if (op === '==') return lhs == rhs;
				if (op === '!=') return lhs != rhs;
				throw new Error(`invalid op in captured bool comparison: ${op}`);
			}
		}
		throw new Error('failed to capture bool_comparison');
	},
	int_setable: (f: FileState, node: TreeSitterNode): IntGetable => {
		return {
			mathlang: 'int_getable',
			field: textForFieldName(f, node, 'property'),
			entity: stringCaptureForFieldName(f, node, 'entity_identifier'),
		};
	},
	int_grouping: (f: FileState, node: TreeSitterNode): IntExpression => {
		const capture = handleCapture(f, node.namedChildren[0]);
		if (isIntExpression(capture)) return capture;
		throw new Error('captured int_grouping did not produce int expression');
	},
	direction_target: (f: FileState, node: TreeSitterNode): DirectionTarget => {
		const direction = optionalTextForFieldName(f, node, 'nsew');
		if (direction) {
			return {
				action: 'SET_ENTITY_DIRECTION',
				direction,
			};
		}
		const target_geometry = optionalStringCaptureForFieldName(f, node, 'geometry');
		if (target_geometry) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY',
				target_geometry,
			};
		}
		const target_entity = optionalStringCaptureForFieldName(f, node, 'entity');
		if (target_entity) {
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY',
				target_entity,
			};
		}
		throw new Error('could not capture direction_target');
	},
	set_entity_string_field: (f: FileState, node: TreeSitterNode): string => node.text,
};

// These are separated so that the LHS and RHS can be swapped easily
const compareNSEW = (
	f: FileState,
	entityNode: TreeSitterNode,
	nsewNode: TreeSitterNode,
	op: string,
	debug: MGSDebug,
): BoolComparison => {
	if (op !== '==' && op !== '!=') {
		throw new Error('invalid op for bool_comparison compareNSEW: ' + op);
	}
	return {
		mathlang: 'bool_comparison',
		debug,
		action: 'CHECK_ENTITY_DIRECTION',
		expected_bool: op === '==',
		direction: nsewNode.text,
		entity: stringCaptureForFieldName(f, entityNode, 'entity_identifier'),
	};
};
const compareString = (
	f: FileState,
	checkableNode: TreeSitterNode,
	stringNode: TreeSitterNode,
	op: string,
	debug: MGSDebug,
): StringCheckable => {
	const checkable = handleCapture(f, checkableNode);
	if (!isStringCheckable(checkable)) {
		throw new Error('invalid string checkable');
	}
	if (op !== '==' && op !== '!=') {
		throw new Error('invalid op for bool_comparison compareString: ' + op);
	}
	const string = handleCapture(f, stringNode);
	const prop = checkable.stringLabel;
	if (prop === undefined) throw new Error('undefined prop');
	if (
		prop !== 'string' &&
		prop !== 'expected_script' &&
		prop !== 'geometry' &&
		prop !== 'entity_type'
	) {
		throw new Error('string checkable with invalid prop ' + prop);
	}
	return {
		...checkable,
		debug,
		expected_bool: op === '==',
		[prop]: string,
	};
};
const compareNumberCheckableEquality = (
	f: FileState,
	checkableNode: TreeSitterNode,
	numberNode: TreeSitterNode,
	op: string,
	debug: MGSDebug,
): NumberCheckableEquality => {
	const checkable = handleCapture(f, checkableNode);
	if (!isNumberCheckableEquality(checkable)) throw new Error('not a thing');
	if (op !== '==' && op !== '!=') {
		throw new Error('invalid op for bool_comparison compareNumberCheckableEquality: ' + op);
	}
	const number = handleCapture(f, numberNode);
	if (typeof number !== 'number') {
		f.newError({
			message: `This action can only compare to number literals`,
			locations: [
				{
					node: numberNode,
				},
			],
		});
	}
	if (checkable.numberLabel !== 'expected_u2' && checkable.numberLabel !== 'expected_byte') {
		throw new Error('invalid prop');
	}
	return {
		...checkable,
		expected_bool: op === '==',
		debug,
		[checkable.numberLabel]: number,
	};
};
const checkVariables = (
	f: FileState,
	variable: string,
	source: string,
	comparison: string,
	debug: MGSDebug,
): BoolComparison => {
	return {
		mathlang: 'bool_comparison',
		debug,
		action: 'CHECK_VARIABLES',
		variable,
		source,
		comparison,
		expected_bool: true,
	};
};
const checkVariable = (
	f: FileState,
	variable: string,
	value: number,
	comparison: string,
	debug: MGSDebug,
): BoolComparison => ({
	mathlang: 'bool_comparison',
	debug,
	action: 'CHECK_VARIABLE',
	variable,
	value,
	comparison,
	expected_bool: true,
});
const extractEntityName = (f: FileState, node: TreeSitterNode): string => {
	const type = optionalTextForFieldName(f, node, 'type');
	if (type === 'self') return '%SELF%';
	if (type === 'player') return '%PLAYER%';
	if (type !== 'entity') throw new Error('Entity identifier not an entity?');
	return stringCaptureForFieldName(f, node, 'entity');
};

// Very common node handling behaviors

export const stringCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) throw new Error('no TS node found for fieldName ' + fieldName);
	const capture = handleCapture(f, captureNode);
	if (typeof capture === 'string') return capture;
	throw new Error(`capture from field ${fieldName} not a string`);
};

export const optionalStringCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string | null => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return null;
	const capture = handleCapture(f, captureNode);
	if (typeof capture === 'string') return capture;
	throw new Error(`capture from field ${fieldName} not a string`);
};

export const stringOrNumberCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string | number => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) throw new Error('no TS node found for fieldName ' + fieldName);
	const capture = handleCapture(f, captureNode);
	if (typeof capture === 'string' || typeof capture === 'number') return capture;
	throw new Error(`capture from field ${fieldName} not a string or number`);
};

export const numberCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): number => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) throw new Error('no TS node found for fieldName ' + fieldName);
	const capture = handleCapture(f, captureNode);
	if (typeof capture === 'number') return capture;
	throw new Error(`capture from field ${fieldName} not a number`);
};

export const captureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): Capture | Capture[] | undefined => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return handleCapture(f, captureNode);
};
export const capturesForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): Capture[] => {
	return (node.childrenForFieldName(fieldName) || []).map((v) => handleCapture(f, v)).flat();
};
// TODO: change to not return undefined? Better to return ''?
export const optionalTextForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string | undefined => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.text;
};
export const textForFieldName = (f: FileState, node: TreeSitterNode, fieldName: string): string => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) throw new Error('missing text for field name ' + fieldName);
	return captureNode.text;
};

export const coerceToString = (
	f: FileState,
	node: TreeSitterNode,
	v: unknown,
	label: string,
): string => {
	if (typeof v !== 'string') {
		f.newError({
			locations: [
				{
					node: f.constants[node.text].debug.node,
					fileName: f.constants[node.text].debug.fileName,
				},
				{ node },
			],
			message: `${label} is not a string`,
		});
		return '';
	}
	return v;
};
export const coerceToNumber = (
	f: FileState,
	node: TreeSitterNode,
	v: unknown,
	label: string,
): number => {
	if (typeof v !== 'number') {
		f.newError({
			locations: [
				{
					node: f.constants[node.text].debug.node,
					fileName: f.constants[node.text].debug.fileName,
				},
				{ node },
			],
			message: `${label} is not a number`,
		});
		return NaN;
	}
	return v;
};

export const coerceAsBool = (
	f: FileState,
	node: TreeSitterNode,
	v: unknown,
	label: string,
): boolean => {
	if (typeof v !== 'boolean') {
		f.newError({
			locations: [
				{
					node: f.constants[node.text].debug.node,
					fileName: f.constants[node.text].debug.fileName,
				},
				{ node },
			],
			message: `${label} is not a boolean`,
		});
		return false;
	}
	return v;
};
