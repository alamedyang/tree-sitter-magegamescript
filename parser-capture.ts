import { Node as TreeSitterNode } from 'web-tree-sitter';
import { type CHECK_VARIABLE, type CHECK_VARIABLES } from './parser-bytecode-info.ts';
import {
	type CoordinateIdentifier,
	type MovableIdentifier,
	type DialogParameter,
	type SerialDialogParameter,
	type StringCheckable,
	type NumberCheckableEquality,
	type BoolGetable,
	type DialogIdentifier,
	type BoolSetable,
	type IntBinaryExpression,
	type BoolBinaryExpression,
	type BoolComparison,
	type BoolExpression,
	type IntGetable,
	type DirectionTarget,
	isStringCheckable,
	isBoolExpression,
	isIntExpression,
	type IntExpression,
	isNumberCheckableEquality,
} from './parser-types.ts';
import {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	invert,
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
	| SerialDialogParameter
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
	if (!node) throw new Error('TS FRFR');
	reportErrorNodes(f, node);
	reportMissingChildNodes(f, node);
	const grammarType = node.grammarType;
	debugLog(`-->> Capturing: ${grammarType}`);
	// expansions cannot be recursive, so this is fine
	if (grammarType.endsWith('_expansion')) {
		return node.namedChildren.map((v) => handleCapture(f, v)).flat();
	}
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
		const suffix = textForFieldName(f, node, 'suffix');
		const int = mandatoryTextForFieldName(f, node, 'NUMBER');
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
		const suffix = textForFieldName(f, node, 'suffix');
		const int = mandatoryTextForFieldName(f, node, 'NUMBER');
		let n = parseInt(int);
		if (suffix === 's') n *= 1000;
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
		return textForFieldName(f, node, 'type') === 'map' ? '%MAP%' : extractEntityName(f, node);
	},
	entity_identifier: (f: FileState, node: TreeSitterNode): string => extractEntityName(f, node),
	movable_identifier: (f: FileState, node: TreeSitterNode): MovableIdentifier => {
		const ret: MovableIdentifier = {
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
	dialog_identifier: (f: FileState, node: TreeSitterNode): DialogIdentifier => {
		const label = textForFieldName(f, node, 'label');
		if (label) {
			return {
				mathlang: 'dialog_identifier',
				type: 'label',
				value: label,
			};
		}
		const type = mandatoryTextForFieldName(f, node, 'type');
		if (type !== 'label' && type !== 'entity' && type !== 'name') {
			throw new Error('invalid type');
		}
		const value = captureForFieldName(f, node, 'value');
		if (typeof value !== 'string') throw new Error('value not a string');
		return {
			mathlang: 'dialog_identifier',
			type,
			value,
		};
	},
	dialog_parameter: (f: FileState, node: TreeSitterNode): DialogParameter => {
		const property = mandatoryTextForFieldName(f, node, 'property');
		const value = captureForFieldName(f, node, 'value');
		if (typeof value !== 'string' && typeof value !== 'number') throw new Error('ts');
		return {
			mathlang: 'dialog_parameter',
			property,
			value,
		};
	},
	serial_dialog_parameter: (f: FileState, node: TreeSitterNode): SerialDialogParameter => {
		const property = mandatoryTextForFieldName(f, node, 'property');
		const value = captureForFieldName(f, node, 'value');
		if (typeof value !== 'string' && typeof value !== 'number') throw new Error('ts');
		return {
			mathlang: 'serial_dialog_parameter',
			property,
			value,
		};
	},
	coordinate_identifier: (f: FileState, node: TreeSitterNode): CoordinateIdentifier => {
		const type = textForFieldName(f, node, 'type');
		const ret: CoordinateIdentifier = {
			mathlang: 'coordinate_identifier',
			type: '',
			value: '',
			polygonType: '',
		};
		if (type === 'entity_path') {
			return {
				...ret,
				type: 'geometry',
				value: '%ENTITY_PATH%',
				polygonType: textForFieldName(f, node, 'polygon_type'),
			};
		}
		if (type === 'geometry') {
			const value = captureForFieldName(f, node, 'geometry');
			if (typeof value !== 'string') throw new Error('value not a string');
			return {
				...ret,
				type: 'geometry',
				value,
				polygonType: textForFieldName(f, node, 'polygon_type'),
			};
		}
		return {
			...ret,
			type: 'entity',
			value: extractEntityName(f, node),
		};
	},
	bool_setable: (f: FileState, node: TreeSitterNode): BoolSetable => {
		const type = textForFieldName(f, node, 'type');
		if (!type) {
			const value = captureForFieldName(f, node, 'flag');
			if (typeof value !== 'string') throw new Error('value not a string');
			return {
				mathlang: 'bool_setable',
				// action: 'SET_SAVE_FLAG',
				value,
				type: 'save_flag',
			};
		}
		if (type === 'glitched') {
			const value = captureForFieldName(f, node, 'entity_identifier');
			if (typeof value !== 'string') throw new Error('value not a string');
			return {
				mathlang: 'bool_setable',
				// action: 'SET_ENTITY_GLITCHED',
				value,
				type: 'entity',
			};
		}
		if (type === 'light') {
			const value = captureForFieldName(f, node, 'light');
			if (typeof value !== 'string') throw new Error('value not a string');
			return {
				mathlang: 'bool_setable',
				// action: 'SET_LIGHTS_STATE',
				value,
				type: 'light',
			};
		}
		return { mathlang: 'bool_setable', type };
	},
	int_binary_expression: (f: FileState, node: TreeSitterNode): IntBinaryExpression => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = mandatoryTextForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (!isIntExpression(rhs)) throw new Error('RHS not Int Exp');
		if (!isIntExpression(lhs)) throw new Error('LHS not Int Exp');
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'number') {
			f.newError({
				locations: [
					{
						node: f.constants[rhsNode.text].debug.node,
						fileName: f.constants[rhsNode.text].debug.fileName,
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
	bool_binary_expression: (f: FileState, node: TreeSitterNode): BoolBinaryExpression => {
		const rhsNode = node.childForFieldName('rhs');
		const lhsNode = node.childForFieldName('lhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = mandatoryTextForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (rhsNode.grammarType === 'CONSTANT' && typeof rhs !== 'boolean') {
			f.newError({
				locations: [
					{
						node: f.constants[rhsNode.text].debug.node,
						fileName: f.constants[rhsNode.text].debug.fileName,
					},
					{ node: rhsNode },
				],
				message: `constant is not a boolean`,
			});
			rhs = false;
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
			lhs = false;
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
		throw new Error('unreachable');
	},
	bool_grouping: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const capture = captureForFieldName(f, node, 'inner');
		if (!isBoolExpression(capture)) throw new Error('lulul');
		return capture;
	},
	bool_unary_expression: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const op = textForFieldName(f, node, 'operator');
		if (op !== '!') throw new Error("what kind of unary is '" + op + "'?");
		const capture = captureForFieldName(f, node, 'operand');
		if (!isBoolExpression(capture)) throw new Error(':/');
		const toInvert = typeof capture === 'object' ? { ...capture } : capture;
		const inverted = invert(f, node, toInvert);
		return inverted;
	},
	int_getable: (f: FileState, node: TreeSitterNode): IntGetable => {
		// if (textForFieldName(f, node, 'variable')) {
		// 	return captureForFieldName(f, node, 'variable');
		// }
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (typeof entity !== 'string') throw new Error('entity not a string');
		return {
			mathlang: 'int_getable',
			field: mandatoryTextForFieldName(f, node, 'property'),
			entity,
		};
	},
	bool_getable: (f: FileState, node: TreeSitterNode): BoolGetable => {
		const type = textForFieldName(f, node, 'type');
		const debug = {
			node,
			fileName: f.fileName,
		};
		if (type === 'flag') {
			const save_flag = captureForFieldName(f, node, 'value');
			if (typeof save_flag !== 'string') throw new Error('flag not a string');
			return {
				action: 'CHECK_SAVE_FLAG',
				debug,
				mathlang: 'bool_getable',
				expected_bool: true,
				save_flag: save_flag,
			};
		} else if (type === 'debug_mode') {
			return {
				action: 'CHECK_DEBUG_MODE',
				debug,
				mathlang: 'bool_getable',
				expected_bool: true,
			};
		} else if (type === 'glitched') {
			const entity = captureForFieldName(f, node, 'entity_identifier');
			if (typeof entity !== 'string') throw new Error('entity not a string');
			return {
				action: 'CHECK_ENTITY_GLITCHED',
				debug,
				mathlang: 'bool_getable',
				expected_bool: true,
				entity,
			};
		} else if (type === 'intersects') {
			const entity = captureForFieldName(f, node, 'entity_identifier');
			if (typeof entity !== 'string') throw new Error('entity not a string');
			const geometry = captureForFieldName(f, node, 'geometry_identifier');
			if (typeof geometry !== 'string') throw new Error('geometry not a string');
			return {
				action: 'CHECK_IF_ENTITY_IS_IN_GEOMETRY',
				debug,
				mathlang: 'bool_getable',
				expected_bool: true,
				entity,
				geometry,
			};
		} else if (type === 'dialog' || type === 'serial_dialog') {
			const state = textForFieldName(f, node, 'value');
			if (type === 'dialog') {
				return {
					action: 'CHECK_DIALOG_OPEN',
					debug,
					mathlang: 'bool_getable',
					expected_bool: state === 'open',
				};
			} else {
				return {
					action: 'CHECK_SERIAL_DIALOG_OPEN',
					debug,
					mathlang: 'bool_getable',
					expected_bool: state === 'open',
				};
			}
		} else if (type === 'button') {
			const value = captureForFieldName(f, node, 'button');
			if (typeof value !== 'string') throw new Error('button not a string');
			const stateNode = node.childForFieldName('state');
			if (!stateNode) throw new Error('Missing stateNode');
			if (stateNode.text === 'pressed') {
				return {
					action: 'CHECK_FOR_BUTTON_PRESS',
					debug,
					mathlang: 'bool_getable',
					expected_bool: true,
					button_id: value,
				};
			} else {
				const state = handleCapture(f, stateNode);
				if (typeof state !== 'boolean') throw new Error('bool');
				return {
					action: 'CHECK_FOR_BUTTON_STATE',
					debug,
					mathlang: 'bool_getable',
					expected_bool: state,
					button_id: value,
				};
			}
		}
		throw new Error('unreachable');
	},
	string_checkable: (f: FileState, node: TreeSitterNode): StringCheckable => {
		const ret: StringCheckable = {
			mathlang: 'string_checkable',
			entity: '',
			property: '',
		};
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			if (typeof entity !== 'string') throw new Error('entity not a string');
			ret.entity = entity;
			ret.property = mandatoryTextForFieldName(f, node, 'property');
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
			}
		}
		throw new Error(`unreachable`);
	},
	number_checkable_equality: (f: FileState, node: TreeSitterNode): NumberCheckableEquality => {
		const ret: NumberCheckableEquality = {
			mathlang: 'number_checkable_equality',
			entity: '',
			property: '',
		};
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (entity) {
			if (typeof entity !== 'string') throw new Error('entity not a string');
			ret.entity = entity;
			ret.property = textForFieldName(f, node, 'property') || '';
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
	geometry_identifier: (f: FileState, node: TreeSitterNode): string => {
		const type = textForFieldName(f, node, 'type');
		if (type === 'entity_path') {
			return '%ENTITY_PATH%';
		}
		const geometry = captureForFieldName(f, node, 'geometry');
		if (typeof geometry !== 'string') throw new Error('geometry not a string');
		return geometry;
	},
	entity_direction: (f: FileState, node: TreeSitterNode): string => {
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (typeof entity !== 'string') throw new Error('entity not a string');
		return entity;
	},
	bool_comparison: (f: FileState, node: TreeSitterNode): BoolComparison | boolean => {
		const lhsNode = node.childForFieldName('lhs');
		const rhsNode = node.childForFieldName('rhs');
		if (!rhsNode) throw new Error('missing rhsNode');
		if (!lhsNode) throw new Error('missing lhsNode');
		const op = mandatoryTextForFieldName(f, node, 'operator');
		const debug = {
			node,
			fileName: f.fileName,
		};
		if (lhsNode.grammarType === 'entity_direction') {
			const checkEntityDirection: BoolComparison = {
				...compareNSEW(f, lhsNode, rhsNode),
				debug,
				expected_bool: op === '==',
			};
			return checkEntityDirection;
		}
		if (rhsNode.grammarType === 'entity_direction') {
			const checkEntityDirection: BoolComparison = {
				...compareNSEW(f, rhsNode, lhsNode),
				debug,
				expected_bool: op === '==',
			};
			return checkEntityDirection;
		}
		if (lhsNode.grammarType === 'string_checkable') {
			const stringCheckable: StringCheckable = {
				...compareString(f, lhsNode, rhsNode),
				debug,
				expected_bool: op === '==',
			};
			return stringCheckable;
		}
		if (rhsNode.grammarType === 'string_checkable') {
			const stringCheckable: StringCheckable = {
				...compareString(f, rhsNode, lhsNode),
				debug,
				expected_bool: op === '==',
			};
			return stringCheckable;
		}
		if (lhsNode.grammarType === 'number_checkable_equality') {
			const numberCheckableEquality: NumberCheckableEquality = {
				...compareNumberCheckableEquality(f, lhsNode, rhsNode),
				debug,
				expected_bool: op === '==',
			};
			return numberCheckableEquality;
		}
		if (rhsNode.grammarType === 'number_checkable_equality') {
			const numberCheckableEquality: NumberCheckableEquality = {
				...compareNumberCheckableEquality(f, rhsNode, lhsNode),
				debug,
				expected_bool: op === '==',
			};
			return numberCheckableEquality;
		}
		const lhs = handleCapture(f, lhsNode);
		const rhs = handleCapture(f, rhsNode);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				const checkVariablesAction: BoolComparison = {
					...checkVariables(f, lhs, rhs, op),
					mathlang: 'bool_comparison',
					debug,
				};
				return checkVariablesAction;
			} else if (typeof rhs === 'number') {
				const checkVariableAction: BoolComparison = {
					...checkVariable(f, lhs, rhs, op),
					mathlang: 'bool_comparison',
					debug,
				};
				return checkVariableAction;
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				return {
					...checkVariable(f, rhs, lhs, inverseOpMap[op]),
					mathlang: 'bool_comparison',
					debug,
				};
			} else if (typeof rhs === 'number') {
				// I decided I don't want eval in here, lul
				if (op === '<') return lhs < rhs;
				if (op === '<=') return lhs <= rhs;
				if (op === '>') return lhs > rhs;
				if (op === '>=') return lhs >= rhs;
				if (op === '==') return lhs == rhs;
				if (op === '!=') return lhs != rhs;
				throw new Error(`invalid op in bool comparison (${op})`);
			}
		}
		throw new Error("unreachable; seriously, anything else wouldn't have matched this");
	},
	int_setable: (f: FileState, node: TreeSitterNode): IntGetable => {
		const entity = captureForFieldName(f, node, 'entity_identifier');
		if (typeof entity !== 'string') throw new Error('entity not a string');
		return {
			mathlang: 'int_getable',
			field: mandatoryTextForFieldName(f, node, 'property'),
			entity,
		};
	},
	int_grouping: (f: FileState, node: TreeSitterNode): IntExpression => {
		const capture = handleCapture(f, node.namedChildren[0]);
		if (!isIntExpression(capture)) {
			throw new Error();
		}
		return capture;
	},
	direction_target: (f: FileState, node: TreeSitterNode): DirectionTarget => {
		const direction = textForFieldName(f, node, 'nsew');
		if (direction) {
			return {
				action: 'SET_ENTITY_DIRECTION',
				direction,
			};
		}
		const target_geometry = captureForFieldName(f, node, 'geometry');
		if (target_geometry) {
			if (typeof target_geometry !== 'string') throw new Error('geometry not a string');
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY',
				target_geometry,
			};
		}
		const target_entity = captureForFieldName(f, node, 'entity');
		if (target_entity) {
			if (typeof target_entity !== 'string') throw new Error('entity not a string');
			return {
				action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY',
				target_entity,
			};
		}
		throw new Error('unreachable');
	},
	set_entity_string_field: (f: FileState, node: TreeSitterNode): string => node.text,
};

// These are separated so that the LHS and RHS can be swapped easily
const compareNSEW = (
	f: FileState,
	entityNode: TreeSitterNode,
	nsewNode: TreeSitterNode,
): BoolComparison => {
	const entity = captureForFieldName(f, entityNode, 'entity_identifier');
	if (typeof entity !== 'string') throw new Error('entity not a string');
	return {
		mathlang: 'bool_comparison',
		action: 'CHECK_ENTITY_DIRECTION',
		expected_bool: true,
		direction: nsewNode.text,
		entity,
	};
};
const compareString = (
	f: FileState,
	checkableNode: TreeSitterNode,
	stringNode: TreeSitterNode,
): StringCheckable => {
	const checkable = handleCapture(f, checkableNode);
	if (!isStringCheckable(checkable)) {
		throw new Error('invalid string checkable');
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
		[prop]: string,
	};
};
const compareNumberCheckableEquality = (
	f: FileState,
	checkableNode: TreeSitterNode,
	numberNode: TreeSitterNode,
): NumberCheckableEquality => {
	const checkable = handleCapture(f, checkableNode);
	if (!isNumberCheckableEquality(checkable)) throw new Error('not a thing');
	const number = handleCapture(f, numberNode);
	if (checkable.numberLabel !== 'expected_u2' && checkable.numberLabel !== 'expected_byte') {
		throw new Error('invalid prop');
	}
	return {
		...checkable,
		[checkable.numberLabel]: number,
	};
};
const checkVariables = (
	f: FileState,
	variable: string,
	source: string,
	comparison: string,
): CHECK_VARIABLES => {
	return {
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
): CHECK_VARIABLE => ({
	action: 'CHECK_VARIABLE',
	variable,
	value,
	comparison,
	expected_bool: true,
});
const extractEntityName = (f: FileState, node: TreeSitterNode): string => {
	const type = textForFieldName(f, node, 'type');
	if (type === 'self') return '%SELF%';
	if (type === 'player') return '%PLAYER%';
	if (type !== 'entity') throw new Error('Entity identifier not an entity?');
	const entity = captureForFieldName(f, node, 'entity');
	if (typeof entity !== 'string') throw new Error('entity not a string');
	return entity;
};

// Very common node handling behaviors
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
export const textForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string | undefined => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.text;
};
export const mandatoryTextForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) throw new Error('missing text for field name ' + fieldName);
	return captureNode.text;
};
// ditto?
export const grammarTypeForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string | undefined => {
	const captureNode = node.childForFieldName(fieldName);
	if (!captureNode) return undefined;
	return captureNode.grammarType;
};
