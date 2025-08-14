import { Node as TreeSitterNode } from 'web-tree-sitter';
import {
	CHECK_DEBUG_MODE,
	CHECK_DIALOG_OPEN,
	CHECK_ENTITY_CURRENT_ANIMATION,
	CHECK_ENTITY_CURRENT_FRAME,
	CHECK_ENTITY_DIRECTION,
	CHECK_ENTITY_GLITCHED,
	CHECK_ENTITY_INTERACT_SCRIPT,
	CHECK_ENTITY_LOOK_SCRIPT,
	CHECK_ENTITY_NAME,
	CHECK_ENTITY_PATH,
	CHECK_ENTITY_PRIMARY_ID,
	CHECK_ENTITY_PRIMARY_ID_TYPE,
	CHECK_ENTITY_SECONDARY_ID,
	CHECK_ENTITY_TICK_SCRIPT,
	CHECK_ENTITY_TYPE,
	CHECK_ENTITY_X,
	CHECK_ENTITY_Y,
	CHECK_FOR_BUTTON_PRESS,
	CHECK_FOR_BUTTON_STATE,
	CHECK_IF_ENTITY_IS_IN_GEOMETRY,
	CHECK_SAVE_FLAG,
	CHECK_SERIAL_DIALOG_OPEN,
	CHECK_VARIABLE,
	CHECK_VARIABLES,
	CHECK_WARP_STATE,
	BoolGetable,
	StringCheckable,
	NumberCheckableEquality,
} from './parser-bytecode-info.ts';
import {
	MathlangLocation,
	BoolBinaryExpression,
	BoolSetable,
	CoordinateIdentifier,
	DialogIdentifier,
	DialogParameter,
	IntBinaryExpression,
	IntGetable,
	MovableIdentifier,
	SerialDialogParameter,
	type BoolComparison,
	type BoolExpression,
	isBoolExpression,
	type IntExpression,
	isIntExpression,
	type AnyNode,
	DirectionTarget,
} from './parser-types.ts';
import {
	debugLog,
	reportMissingChildNodes,
	reportErrorNodes,
	invertBoolExpression,
	inverseOpMap,
} from './parser-utilities.ts';
import { type FileState } from './parser-file.ts';
import { handleNode } from './parser-node.ts';

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
	if (!node) throw new Error('null node');
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
	if (!fn) throw new Error(`no function found for grammar type ${grammarType}`);
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
		throw new Error('bool capture text not one of the mathlang bools');
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
		const debug = new MathlangLocation(f, node);
		const type = optionalTextForFieldName(f, node, 'type');
		if (type === 'camera') {
			return MovableIdentifier.quick(debug, 'camera', 'camera');
		} else {
			const value = extractEntityName(f, node);
			return MovableIdentifier.quick(debug, 'entity', value);
		}
	},
	dialog_identifier: (f: FileState, node: TreeSitterNode): DialogIdentifier => {
		const debug = new MathlangLocation(f, node);
		const label = optionalTextForFieldName(f, node, 'label');
		if (label) {
			return DialogIdentifier.quick(debug, 'label', label);
		}
		const type = textForFieldName(f, node, 'type');
		if (type !== 'label' && type !== 'entity' && type !== 'name') {
			throw new Error('invalid dialog identifier type: ' + type);
		}
		const value = stringCaptureForFieldName(f, node, 'value');
		return DialogIdentifier.quick(debug, type, value);
	},
	dialog_parameter: (f: FileState, node: TreeSitterNode): DialogParameter => {
		const debug = new MathlangLocation(f, node);
		const property = textForFieldName(f, node, 'property');
		const value = stringOrNumberCaptureForFieldName(f, node, 'value');
		return DialogParameter.quick(debug, property, value);
	},
	serial_dialog_parameter: (f: FileState, node: TreeSitterNode): SerialDialogParameter => {
		const debug = new MathlangLocation(f, node);
		const property = textForFieldName(f, node, 'property');
		const value = stringOrNumberCaptureForFieldName(f, node, 'value');
		return SerialDialogParameter.quick(debug, property, value);
	},
	coordinate_identifier: (f: FileState, node: TreeSitterNode): CoordinateIdentifier => {
		const debug = new MathlangLocation(f, node);
		const type = optionalTextForFieldName(f, node, 'type');
		const polygonType = optionalTextForFieldName(f, node, 'polygon_type');
		if (type === 'entity_path') {
			return CoordinateIdentifier.quick(debug, 'geometry', '%ENTITY_PATH%', polygonType);
		}
		if (type === 'geometry') {
			const value = stringCaptureForFieldName(f, node, 'geometry');
			return CoordinateIdentifier.quick(debug, 'geometry', value, polygonType);
		}
		return CoordinateIdentifier.quick(debug, 'entity', extractEntityName(f, node));
	},
	bool_setable: (f: FileState, node: TreeSitterNode): BoolSetable => {
		const debug = new MathlangLocation(f, node);
		const type = optionalTextForFieldName(f, node, 'type');
		if (!type) {
			const value = stringCaptureForFieldName(f, node, 'flag');
			return BoolSetable.quick(debug, 'save_flag', value);
		}
		if (type === 'glitched') {
			const value = stringCaptureForFieldName(f, node, 'entity_identifier');
			return BoolSetable.quick(debug, 'entity', value);
		}
		if (type === 'light') {
			const value = stringCaptureForFieldName(f, node, 'light');
			return BoolSetable.quick(debug, 'light', value);
		}
		return BoolSetable.quick(debug, type, '');
	},
	int_binary_expression: (f: FileState, node: TreeSitterNode): IntBinaryExpression => {
		const debug = new MathlangLocation(f, node);
		const rhsNode = mandatoryChildForFieldName(f, node, 'rhs');
		const lhsNode = mandatoryChildForFieldName(f, node, 'lhs');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (!isIntExpression(rhs)) throw new Error('RHS not IntBinaryExpression');
		if (!isIntExpression(lhs)) throw new Error('LHS not IntBinaryExpression');
		if (rhsNode.grammarType === 'CONSTANT') {
			rhs = coerceToNumber(f, rhsNode, rhs, 'constant');
		}
		if (lhsNode.grammarType === 'CONSTANT') {
			lhs = coerceToNumber(f, lhsNode, lhs, 'constant');
		}
		return new IntBinaryExpression(debug, { lhs, rhs, op });
	},
	bool_binary_expression: (f: FileState, node: TreeSitterNode): BoolBinaryExpression => {
		const rhsNode = mandatoryChildForFieldName(f, node, 'rhs');
		const lhsNode = mandatoryChildForFieldName(f, node, 'lhs');
		const op = textForFieldName(f, node, 'operator');
		let rhs = handleCapture(f, rhsNode);
		let lhs = handleCapture(f, lhsNode);
		if (rhsNode.grammarType === 'CONSTANT') {
			rhs = coerceAsBool(f, rhsNode, rhs, 'constant');
		}
		if (lhsNode.grammarType === 'CONSTANT') {
			lhs = coerceAsBool(f, lhsNode, lhs, 'constant');
		}
		const debug = new MathlangLocation(f, node);
		if (isBoolExpression(lhs) && isBoolExpression(rhs)) {
			return new BoolBinaryExpression(debug, {
				lhs,
				lhsNode,
				rhs,
				rhsNode,
				op,
			});
		}
		if (
			(lhs instanceof StringCheckable || typeof lhs === 'string') &&
			(rhs instanceof StringCheckable || typeof rhs === 'string')
		) {
			return new BoolBinaryExpression(debug, {
				lhs,
				lhsNode,
				rhs,
				rhsNode,
				op,
			});
		}
		if (
			(lhs instanceof NumberCheckableEquality || typeof lhs === 'number') &&
			(rhs instanceof NumberCheckableEquality || typeof rhs === 'number')
		) {
			return new BoolBinaryExpression(debug, {
				lhs,
				lhsNode,
				rhs,
				rhsNode,
				op,
			});
		}
		throw new Error('invalid LHS and RHS combo for captured bool binary expression');
	},
	bool_grouping: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const capture = captureForFieldName(f, node, 'inner');
		if (isBoolExpression(capture)) return capture;
		throw new Error('bool_grouping capture did not yield BoolExpression');
	},
	bool_unary_expression: (f: FileState, node: TreeSitterNode): BoolExpression => {
		const op = optionalTextForFieldName(f, node, 'operator');
		if (op !== '!') throw new Error('captured unknown unary operator: ' + op);
		const capture = captureForFieldName(f, node, 'operand');
		if (isBoolExpression(capture)) {
			let toInvert = capture;
			if (toInvert instanceof BoolBinaryExpression) {
				toInvert = toInvert.clone();
			}
			return invertBoolExpression(f, node, toInvert);
		}
		throw new Error('bool_unary_expression capture did not yield BoolExpression');
	},
	int_getable: (f: FileState, node: TreeSitterNode) => {
		const debug = new MathlangLocation(f, node);
		// if (textForFieldName(f, node, 'variable')) {
		// 	return captureForFieldName(f, node, 'variable');
		// }
		const entity = stringCaptureForFieldName(f, node, 'entity_identifier');
		const field = textForFieldName(f, node, 'property');
		return IntGetable.quick(debug, entity, field);
	},
	bool_getable: (f: FileState, node: TreeSitterNode): BoolGetable => {
		const type = optionalTextForFieldName(f, node, 'type');
		if (type === 'flag') {
			return CHECK_SAVE_FLAG.quick(stringCaptureForFieldName(f, node, 'value'));
		} else if (type === 'debug_mode') {
			return CHECK_DEBUG_MODE.quick();
		} else if (type === 'glitched') {
			return CHECK_ENTITY_GLITCHED.quick(
				stringCaptureForFieldName(f, node, 'entity_identifier'),
			);
		} else if (type === 'intersects') {
			return CHECK_IF_ENTITY_IS_IN_GEOMETRY.quick(
				stringCaptureForFieldName(f, node, 'entity_identifier'),
				stringCaptureForFieldName(f, node, 'geometry_identifier'),
			);
		} else if (type === 'dialog' || type === 'serial_dialog') {
			const state = optionalTextForFieldName(f, node, 'value');
			if (type === 'dialog') {
				return CHECK_DIALOG_OPEN.quick(state === 'open');
			} else {
				return CHECK_SERIAL_DIALOG_OPEN.quick(state === 'open');
			}
		} else if (type === 'button') {
			const button_id = stringCaptureForFieldName(f, node, 'button');
			const stateNode = mandatoryChildForFieldName(f, node, 'state');
			if (stateNode.text === 'pressed') {
				return CHECK_FOR_BUTTON_PRESS.quick(button_id);
			} else {
				const state = handleCapture(f, stateNode);
				return CHECK_FOR_BUTTON_STATE.quick(
					button_id,
					coerceAsBool(f, node, state, 'button state'),
				);
			}
		}
		throw new Error('failed to capture bool_getable');
	},
	string_checkable: (f: FileState, node: TreeSitterNode): StringCheckable => {
		const entity = optionalStringCaptureForFieldName(f, node, 'entity_identifier');
		if (entity === null) {
			const type = optionalTextForFieldName(f, node, 'type');
			if (type === 'warp_state') {
				return CHECK_WARP_STATE.quick('');
			} else {
				throw new Error(
					`unidentifiable non-entity string_checkable: capturing type ${type}`,
				);
			}
		}
		const property = textForFieldName(f, node, 'property');
		if (property === 'on_tick') {
			return CHECK_ENTITY_TICK_SCRIPT.quick(entity, '');
		} else if (property === 'on_look') {
			return CHECK_ENTITY_LOOK_SCRIPT.quick(entity, '');
		} else if (property === 'on_interact') {
			return CHECK_ENTITY_INTERACT_SCRIPT.quick(entity, '');
		} else if (property === 'name') {
			return CHECK_ENTITY_NAME.quick(entity, '');
		} else if (property === 'path') {
			return CHECK_ENTITY_PATH.quick(entity, '');
		} else if (property === 'type') {
			return CHECK_ENTITY_TYPE.quick(entity, '');
		}
		throw new Error(`could not capture entity string_checkable`);
	},
	number_checkable_equality: (f: FileState, node: TreeSitterNode): NumberCheckableEquality => {
		const entity = stringCaptureForFieldName(f, node, 'entity_identifier');
		const property = textForFieldName(f, node, 'property');
		if (property === 'x') {
			return CHECK_ENTITY_X.quick(entity, NaN);
		} else if (property === 'y') {
			return CHECK_ENTITY_Y.quick(entity, NaN);
		} else if (property === 'primary_id') {
			return CHECK_ENTITY_PRIMARY_ID.quick(entity, NaN);
		} else if (property === 'secondary_id') {
			return CHECK_ENTITY_SECONDARY_ID.quick(entity, NaN);
		} else if (property === 'primary_id_type') {
			return CHECK_ENTITY_PRIMARY_ID_TYPE.quick(entity, NaN);
		} else if (property === 'current_animation') {
			return CHECK_ENTITY_CURRENT_ANIMATION.quick(entity, NaN);
		} else if (property === 'animation_frame') {
			return CHECK_ENTITY_CURRENT_FRAME.quick(entity, NaN);
		} else if (property === 'strafe') {
			const propertyNode = mandatoryChildForFieldName(f, node, 'property');
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
		const lhsNode = mandatoryChildForFieldName(f, node, 'lhs');
		const rhsNode = mandatoryChildForFieldName(f, node, 'rhs');
		const op = textForFieldName(f, node, 'operator');
		// entity Bob direction == north
		if (lhsNode.grammarType === 'entity_direction') {
			return compareNSEW(f, lhsNode, rhsNode, op);
		}
		// north == entity Bob direction
		if (rhsNode.grammarType === 'entity_direction') {
			return compareNSEW(f, rhsNode, lhsNode, op);
		}
		// entity Bob name == "Super Bob"
		if (lhsNode.grammarType === 'string_checkable') {
			return compareString(f, lhsNode, rhsNode, op);
		}
		// "Super Bob" == entity Bob name
		if (rhsNode.grammarType === 'string_checkable') {
			return compareString(f, rhsNode, lhsNode, op);
		}
		// entity Bob x == 7
		if (lhsNode.grammarType === 'number_checkable_equality') {
			return compareNumberCheckableEquality(f, lhsNode, rhsNode, op);
		}
		// 7 == entity Bob x
		if (rhsNode.grammarType === 'number_checkable_equality') {
			return compareNumberCheckableEquality(f, rhsNode, lhsNode, op);
		}
		const lhs = handleCapture(f, lhsNode);
		const rhs = handleCapture(f, rhsNode);
		if (typeof lhs === 'string') {
			if (typeof rhs === 'string') {
				// varName1 > varName2
				return CHECK_VARIABLES.quick(lhs, rhs, op);
			} else if (typeof rhs === 'number') {
				// varName > 255
				return CHECK_VARIABLE.quick(lhs, rhs, op);
			}
		} else if (typeof lhs === 'number') {
			if (typeof rhs === 'string') {
				// 255 > varName
				return CHECK_VARIABLE.quick(rhs, lhs, inverseOpMap[op]);
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
	int_setable: (f: FileState, node: TreeSitterNode) => {
		const debug = new MathlangLocation(f, node);
		const entity = stringCaptureForFieldName(f, node, 'entity_identifier');
		const field = textForFieldName(f, node, 'property');
		return IntGetable.quick(debug, entity, field);
	},
	int_grouping: (f: FileState, node: TreeSitterNode): IntExpression => {
		const capture = handleCapture(f, node.namedChildren[0]);
		if (isIntExpression(capture)) return capture;
		throw new Error('captured int_grouping did not produce IntExpression');
	},
	direction_target: (f: FileState, node: TreeSitterNode) => {
		const debug = new MathlangLocation(f, node);
		const direction = optionalTextForFieldName(f, node, 'nsew');
		if (direction) {
			return DirectionTarget.quick(debug, 'nsew', direction);
		}
		const target_geometry = optionalStringCaptureForFieldName(f, node, 'geometry');
		if (target_geometry) {
			return DirectionTarget.quick(debug, 'geometry', target_geometry);
		}
		const target_entity = optionalStringCaptureForFieldName(f, node, 'entity');
		if (target_entity) {
			return DirectionTarget.quick(debug, 'entity', target_entity);
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
): BoolComparison => {
	if (op !== '==' && op !== '!=') {
		throw new Error('invalid op for bool_comparison compareNSEW: ' + op);
	}
	const entity = stringCaptureForFieldName(f, entityNode, 'entity_identifier');
	return CHECK_ENTITY_DIRECTION.quick(entity, nsewNode.text, op === '==');
};
const compareString = (
	f: FileState,
	checkableNode: TreeSitterNode,
	stringNode: TreeSitterNode,
	op: string,
): StringCheckable => {
	const checkable = handleCapture(f, checkableNode);
	if (!(checkable instanceof StringCheckable)) {
		throw new Error('invalid StringCheckable');
	}
	if (op !== '==' && op !== '!=') {
		throw new Error('invalid op for bool_comparison: ' + op);
	}
	const string = handleCapture(f, stringNode);
	checkable.updateProp(coerceToString(f, stringNode, string, 'compareString'));
	checkable.expected_bool = op === '==';
	return checkable;
};
const compareNumberCheckableEquality = (
	f: FileState,
	checkableNode: TreeSitterNode,
	numberNode: TreeSitterNode,
	op: string,
): NumberCheckableEquality => {
	const checkable = handleCapture(f, checkableNode);
	if (!(checkable instanceof NumberCheckableEquality)) throw new Error('not a thing');
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
	checkable.updateProp(
		coerceToNumber(f, numberNode, number, 'compareNumberCheckableEquality expected number'),
	);
	checkable.expected_bool = op === '==';
	return checkable;
};
const extractEntityName = (f: FileState, node: TreeSitterNode): string => {
	const type = optionalTextForFieldName(f, node, 'type');
	if (type === 'self') return '%SELF%';
	if (type === 'player') return '%PLAYER%';
	if (type !== 'entity') throw new Error('Entity identifier not an entity?');
	return stringCaptureForFieldName(f, node, 'entity');
};

// Very common node handling behaviors

export const handleChildrenForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): AnyNode[] => {
	const children = node.childrenForFieldName(fieldName);
	return children
		.filter((v) => v !== null)
		.map((v) => handleNode(f, v))
		.flat();
};

export const handleNamedChildren = (f: FileState, node: TreeSitterNode): AnyNode[] => {
	return node.namedChildren
		.filter((v) => v !== null)
		.map((v) => handleNode(f, v))
		.flat();
};

export const mandatoryChildForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): TreeSitterNode => {
	const child = node.childForFieldName(fieldName);
	if (child === null) throw new Error('missing child for field name ' + fieldName);
	return child;
};

export const stringCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): string => {
	const captureNode = mandatoryChildForFieldName(f, node, fieldName);
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
	const captureNode = mandatoryChildForFieldName(f, node, fieldName);
	const capture = handleCapture(f, captureNode);
	if (typeof capture === 'string' || typeof capture === 'number') return capture;
	throw new Error(`capture from field ${fieldName} not a string or number`);
};

export const numberCaptureForFieldName = (
	f: FileState,
	node: TreeSitterNode,
	fieldName: string,
): number => {
	const captureNode = mandatoryChildForFieldName(f, node, fieldName);
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
	const captureNode = mandatoryChildForFieldName(f, node, fieldName);
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
