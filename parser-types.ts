import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';
import { type FileState } from './parser-file.ts';

export type MGSPrimitive = string | boolean | number;
export const isMGSPrimitive = (v: unknown): v is MGSPrimitive => {
	if (typeof v === 'string') return true;
	if (typeof v === 'number') return true;
	if (typeof v === 'boolean') return true;
	return false;
};

export type AnyNode = TYPES.Action | MathlangNode;
export const isActionNode = (v: unknown): v is TYPES.Action => {
	return (v as TYPES.Action).action !== undefined;
};
export const isMathlangNode = (v: unknown): v is MathlangNode => {
	return (v as MathlangNode).mathlang !== undefined;
};
export const isThingNode = (v: unknown): v is AnyNode => {
	return (v as TYPES.Action).action !== undefined || (v as MathlangNode).mathlang !== undefined;
};

export type MGSLocation = {
	node: TreeSitterNode;
	fileName?: string;
};
export type MGSMessage = {
	// error or warning
	locations: MGSLocation[];
	message: string;
	footer?: string;
};

export type MathlangNode =
	// SETTINGS
	| AddDialogSettings
	| AddDialogSettingsTarget
	| AddSerialDialogSettings
	// CONTROL
	| ReturnStatement
	| ContinueStatement
	| BreakStatement
	| GotoLabel
	// DIALOG
	| DialogDefinition
	| Dialog
	| DialogOption
	// SERIAL DIALOG
	| SerialDialogDefinition
	| SerialDialog
	| SerialDialogOption
	// ONE-OFFS
	| IncludeNode
	| ConstantDefinition
	| ScriptDefinition
	| CommentNode
	| LabelDefinition
	| JSONLiteral
	| CopyMacro
	| MathlangSequence
	// EXPRESSIONS
	| BoolBinaryExpression
	| BoolGetable
	| BoolComparison
	| StringCheckable
	| NumberCheckableEquality;

// ------------------------------ SETTINGS ------------------------------ \\

export type AddDialogSettings = {
	mathlang: 'add_dialog_settings';
	debug: TYPES.MGSDebug;
	targets: AddDialogSettingsTarget[];
	parameters?: SerialDialogParameter[];
};
export const isAddDialogSettings = (v: unknown): v is AddDialogSettings => {
	return (v as AddDialogSettings)?.mathlang === 'add_dialog_settings';
};
export const newAddDialogSettings = (
	f: FileState,
	node: TreeSitterNode,
	targets: AddDialogSettingsTarget[],
): AddDialogSettings => {
	return {
		mathlang: 'add_dialog_settings',
		debug: new TYPES.MGSDebug(f, node),
		targets,
	};
};

export type AddDialogSettingsTarget = {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
	target?: string;
	parameters?: DialogParameter[];
};
export const isAddDialogSettingsTarget = (v: unknown): v is AddDialogSettingsTarget => {
	return (v as AddDialogSettingsTarget)?.mathlang === 'add_dialog_settings_target';
};

export type AddSerialDialogSettings = {
	mathlang: 'add_serial_dialog_settings';
	parameters: SerialDialogParameter[];
	debug: TYPES.MGSDebug;
};
export const newAddSerialDialogSettings = (
	f: FileState,
	node: TreeSitterNode,
	parameters: SerialDialogParameter[],
): AddSerialDialogSettings => {
	return {
		mathlang: 'add_serial_dialog_settings',
		debug: new TYPES.MGSDebug(f, node),
		parameters,
	};
};

// ------------------------------ CONTROL ------------------------------ \\

export class ReturnStatement {
	mathlang: 'return_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'return_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
}
export class ContinueStatement {
	mathlang: 'continue_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'continue_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
}
export class BreakStatement {
	mathlang: 'break_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'break_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
}

export class GotoLabel {
	mathlang: 'goto_label';
	label: string;
	debug: TYPES.MGSDebug;
	comment?: string;
	constructor(f: FileState, node: TreeSitterNode, label: unknown, comment?: string) {
		this.mathlang = 'goto_label';
		this.label = TYPES.breakIfNotString(label, 'GotoLabel label');
		this.debug = new TYPES.MGSDebug(f, node);
		if (comment) this.comment = comment;
	}
}

// ------------------------------ DIALOG ------------------------------ \\

export class DialogDefinition {
	mathlang: 'dialog_definition';
	dialogName: string;
	dialogs: Dialog[];
	debug: TYPES.MGSDebug;
	duplicates?: DialogDefinition[];
	constructor(f: FileState, node: TreeSitterNode, dialogName: string, dialogs: Dialog[]) {
		this.mathlang = 'dialog_definition';
		this.debug = new TYPES.MGSDebug(f, node);
		this.dialogName = dialogName;
		this.dialogs = dialogs;
	}
}
export type DialogSettings = {
	wrap?: number;
	emote?: number;
	entity?: string;
	name?: string;
	portrait?: string;
	alignment?: string;
	border_tileset?: string;
};

export type DialogParameter = {
	mathlang: 'dialog_parameter';
	property: string;
	value: MGSPrimitive;
};
export const isDialogParameter = (v: unknown): v is DialogParameter => {
	return (v as DialogParameter)?.mathlang === 'dialog_parameter';
};

export type Dialog = DialogSettings & {
	mathlang: 'dialog';
	info: DialogInfo;
	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
	debug?: TYPES.MGSDebug;
};
export const isDialog = (v: unknown): v is Dialog => {
	return (v as Dialog)?.mathlang === 'dialog';
};

export type DialogInfo = {
	identifier: DialogIdentifier;
	settings: DialogSettings;
	messages: string[];
	options: DialogOption[];
};

export type DialogIdentifier = {
	mathlang: 'dialog_identifier';
	type: 'label' | 'entity' | 'name';
	value: string;
	debug?: TYPES.MGSDebug;
};
export const isDialogIdentifier = (v: unknown): v is DialogIdentifier => {
	return (v as DialogIdentifier)?.mathlang === 'dialog_identifier';
};

export type DialogOption = {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export const isDialogOption = (v: unknown): v is DialogOption => {
	return (v as DialogOption)?.mathlang === 'dialog_option';
};

// ------------------------------ SERIAL DIALOG ------------------------------ \\

export class SerialDialogDefinition {
	mathlang: 'serial_dialog_definition';
	dialogName: string;
	serialDialog: SerialDialog;
	debug: TYPES.MGSDebug;
	duplicates?: SerialDialogDefinition[];
	constructor(
		f: FileState,
		node: TreeSitterNode,
		dialogName: string,
		serialDialog: SerialDialog,
	) {
		this.mathlang = 'serial_dialog_definition';
		this.debug = new TYPES.MGSDebug(f, node);
		this.dialogName = dialogName;
		this.serialDialog = serialDialog;
	}
}

export type SerialDialogSettings = {
	wrap?: number;
};

export class SerialDialogParameter {
	mathlang: 'serial_dialog_parameter';
	property: string;
	value: MGSPrimitive;
	constructor(property: string, value: MGSPrimitive) {
		this.mathlang = 'serial_dialog_parameter';
		this.property = property;
		this.value = value;
	}
}

export type SerialDialogConstructorArgs = {
	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	debug?: TYPES.MGSDebug;
};
export class SerialDialog {
	mathlang: 'serial_dialog';
	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	debug?: TYPES.MGSDebug;
	constructor(args: SerialDialogConstructorArgs) {
		this.mathlang = 'serial_dialog';
		this.messages = args.messages;
		if (args.options) this.options = args.options;
		if (args.text_options) this.text_options = args.text_options;
		if (args.debug) this.debug = args.debug;
	}
}

export type SerialDialogInfo = {
	settings: SerialDialogSettings;
	messages: string[];
	options: SerialDialogOption[];
};

export type SerialOptionType = 'text_options' | 'options';
export class SerialDialogOption {
	mathlang: 'serial_dialog_option';
	optionType: SerialOptionType;
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
	constructor(
		optionType: SerialOptionType,
		label: string,
		script: string,
		debug: TYPES.MGSDebug,
	) {
		this.mathlang = 'serial_dialog_option';
		this.optionType = optionType;
		this.label = label;
		this.script = script;
		this.debug = debug;
	}
}
// ------------------------------ ONE-OFFS ------------------------------ \\

export class IncludeNode {
	mathlang: 'include_macro';
	debug: TYPES.MGSDebug;
	value: string;
	constructor(f: FileState, node: TreeSitterNode, value: string) {
		this.mathlang = 'include_macro';
		this.debug = new TYPES.MGSDebug(f, node);
		this.value = value;
	}
}

export class ConstantDefinition {
	mathlang: 'constant_assignment';
	debug: TYPES.MGSDebug;
	label: string;
	value: string | boolean | number;
	constructor(f: FileState, node: TreeSitterNode, label: string, value: MGSPrimitive) {
		this.mathlang = 'constant_assignment';
		this.debug = new TYPES.MGSDebug(f, node);
		this.label = label;
		this.value = value;
	}
}

export class ScriptDefinition {
	mathlang: 'script_definition';
	scriptName: string;
	prePrint?: string;
	testPrint?: string;
	print?: string;
	rawNodes?: AnyNode[];
	actions: AnyNode[];
	debug: TYPES.MGSDebug;
	preActions?: AnyNode[];
	duplicates?: ScriptDefinition[];
	copyScriptResolved?: boolean;
	constructor(f: FileState, node: TreeSitterNode, scriptName: string, actions: AnyNode[]) {
		this.mathlang = 'script_definition';
		this.debug = new TYPES.MGSDebug(f, node);
		this.scriptName = scriptName;
		this.actions = actions;
	}
}

export class CommentNode {
	mathlang: 'comment';
	comment: string;
	debug?: TYPES.MGSDebug;
	constructor(comment: string) {
		this.mathlang = 'comment';
		this.comment = comment;
	}
}

export class LabelDefinition {
	mathlang: 'label_definition';
	label: string;
	debug?: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode, label: string) {
		this.mathlang = 'label_definition';
		this.debug = new TYPES.MGSDebug(f, node);
		this.label = label;
	}
}

export class JSONLiteral {
	mathlang: 'json_literal';
	json: [JSON];
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode, json: [JSON]) {
		this.mathlang = 'json_literal';
		this.debug = new TYPES.MGSDebug(f, node);
		this.json = json;
	}
}

type CopyScript = CopyMacro | TYPES.COPY_SCRIPT;
export const isAnyCopyScript = (v: unknown): v is CopyScript => {
	return v instanceof TYPES.COPY_SCRIPT || v instanceof CopyMacro;
};

export class CopyMacro {
	mathlang: 'copy_script';
	script: string;
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode, script: string) {
		this.mathlang = 'copy_script';
		this.debug = new TYPES.MGSDebug(f, node);
		this.script = script;
	}
}

// needs to be one unit of thing for reasons, but still contain than one thing
export class MathlangSequence {
	mathlang: 'sequence';
	type: string;
	steps: AnyNode[];
	debug: TYPES.MGSDebug;
	constructor(
		f: FileState,
		node: TreeSitterNode,
		steps: AnyNode[],
		type: string = 'generic_sequence',
	) {
		this.mathlang = 'sequence';
		this.debug = new TYPES.MGSDebug(f, node);
		this.type = type;
		const comment = node.text.replace(/[\n\s\t]+/g, ' ');
		const mathlangComment = new CommentNode(`${type}: ${comment}`);
		steps.unshift(mathlangComment);
		const flatSteps: AnyNode[] = [];
		steps.forEach((v) => {
			if (v instanceof MathlangSequence) {
				flatSteps.push(...v.steps);
			} else {
				flatSteps.push(v);
			}
		});
		this.steps = flatSteps;
	}
}

// ------------------------------ INT EXPRESSIONS ------------------------------ \\

export type IntExpression = IntUnit | IntBinaryExpression;
export const isIntExpression = (v: unknown): v is IntExpression => {
	return isIntUnit(v) || v instanceof IntBinaryExpression;
};

export type IntUnit = IntGetable | number | string;
export const isIntUnit = (v: unknown): v is IntUnit => {
	if (v === null) return false;
	if (v === undefined) return false;
	if (typeof v === 'number') return true;
	if (typeof v === 'string') return true;
	if (v instanceof IntGetable) return true;
	return false;
};

export class IntGetable {
	mathlang: 'int_getable';
	field: string;
	entity: string;
	constructor(entity: string, field: string) {
		this.mathlang = 'int_getable';
		this.field = field;
		this.entity = entity;
	}
}

export class IntBinaryExpression {
	mathlang: 'int_binary_expression';
	lhs: IntExpression;
	rhs: IntExpression;
	op: string;
	constructor(lhs: IntExpression, rhs: IntExpression, op: string) {
		this.mathlang = 'int_binary_expression';
		this.lhs = lhs;
		this.rhs = rhs;
		this.op = op;
	}
}

// ------------------------------ BOOL EXPRESSIONS ------------------------------ \\

export type BoolExpression = BoolComparison | BoolBinaryExpression | BoolUnit;
export const isBoolExpression = (v: unknown): v is BoolExpression => {
	return isBoolComparison(v) || v instanceof BoolBinaryExpression || isBoolUnit(v);
};

export type BoolUnit = boolean | string | BoolGetable;
export const isBoolUnit = (v: unknown): v is BoolUnit => {
	if (typeof v === 'string') return true;
	if (typeof v === 'boolean') return true;
	return (v as BoolGetable)?.mathlang === 'bool_getable';
};

export type BoolComparison =
	| NumberCheckableEquality
	| StringCheckable
	| ((TYPES.CHECK_VARIABLES | TYPES.CHECK_VARIABLE | TYPES.CHECK_ENTITY_DIRECTION) & {
			mathlang: 'bool_comparison';
			label?: string;
			debug?: TYPES.MGSDebug;
			comment?: string;
	  });
export const isBoolComparison = (v: unknown): v is BoolComparison => {
	if ((v as NumberCheckableEquality)?.mathlang === 'number_checkable_equality') return true;
	if (isStringCheckable(v)) return true;
	if ((v as BoolComparison)?.mathlang === 'bool_comparison') return true;
	return false;
};

export type StringCheckable = (
	| TYPES.CHECK_ENTITY_TICK_SCRIPT
	| TYPES.CHECK_ENTITY_LOOK_SCRIPT
	| TYPES.CHECK_ENTITY_INTERACT_SCRIPT
	| TYPES.CHECK_ENTITY_NAME
	| TYPES.CHECK_ENTITY_PATH
	| TYPES.CHECK_ENTITY_TYPE
	| TYPES.CHECK_WARP_STATE
) & {
	mathlang: 'string_checkable';
	debug?: TYPES.MGSDebug;
	comment?: string;
};

export const isStringCheckable = (v: unknown): v is StringCheckable => {
	return (v as MathlangNode)?.mathlang === 'string_checkable';
};

export type BoolBinaryExpressionArgs = {
	lhs: StringCheckable | string | number | BoolExpression | NumberCheckableEquality;
	rhs: StringCheckable | string | number | BoolExpression | NumberCheckableEquality;
	op: string;
	debug?: TYPES.MGSDebug;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
};

export class BoolBinaryExpression {
	mathlang: 'bool_binary_expression';
	lhs: StringCheckable | string | number | BoolExpression | NumberCheckableEquality;
	rhs: StringCheckable | string | number | BoolExpression | NumberCheckableEquality;
	op: string;
	debug?: TYPES.MGSDebug;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
	constructor(args: BoolBinaryExpressionArgs) {
		this.mathlang = 'bool_binary_expression';
		this.lhs = args.lhs;
		this.rhs = args.rhs;
		this.op = args.op;
		this.lhsNode = args.lhsNode;
		this.rhsNode = args.rhsNode;
		if (args.debug) this.debug = args.debug;
	}
}

export type BoolGetableCommon = {
	mathlang: 'bool_getable';
	label?: string;
	debug?: TYPES.MGSDebug;
	comment?: string;
};
export type BoolGetable = BoolGetableCommon &
	(
		| TYPES.CHECK_DEBUG_MODE
		| TYPES.CHECK_ENTITY_GLITCHED
		| TYPES.CHECK_IF_ENTITY_IS_IN_GEOMETRY
		| TYPES.CHECK_SAVE_FLAG
		| TYPES.CHECK_DIALOG_OPEN
		| TYPES.CHECK_SERIAL_DIALOG_OPEN
		| TYPES.CHECK_FOR_BUTTON_PRESS
		| TYPES.CHECK_FOR_BUTTON_STATE
	);

export const isBoolGetable = (v: unknown): v is BoolGetable => {
	return (v as BoolGetable)?.mathlang === 'bool_getable';
};

// ------------------------------ INTERMEDIATES ------------------------------ \\

export class BoolSetable {
	mathlang: 'bool_setable';
	type: string;
	value: string;
	constructor(type: string, value: string) {
		this.mathlang = 'bool_setable';
		this.value = value;
		this.type = type;
	}
}
export class MovableIdentifier {
	mathlang: 'movable_identifier';
	type: string;
	value: string;
	constructor(type: string, value: string) {
		this.mathlang = 'movable_identifier';
		this.type = type;
		this.value = value;
	}
}
export class CoordinateIdentifier {
	mathlang: 'coordinate_identifier';
	type: string;
	value: string;
	polygonType?: string;
	constructor(type: string, value: string, polygonType?: string) {
		this.mathlang = 'coordinate_identifier';
		this.type = type;
		this.value = value;
		if (polygonType) this.polygonType = polygonType;
	}
}
export class DirectionTarget {
	type: string;
	value: string;
	constructor(type: string, value: string) {
		this.type = type;
		this.value = value;
	}
}
export type NumberCheckableEquality =
	| TYPES.CHECK_ENTITY_X
	| TYPES.CHECK_ENTITY_Y
	| TYPES.CHECK_ENTITY_PRIMARY_ID
	| TYPES.CHECK_ENTITY_SECONDARY_ID
	| TYPES.CHECK_ENTITY_PRIMARY_ID_TYPE
	| TYPES.CHECK_ENTITY_CURRENT_ANIMATION
	| TYPES.CHECK_ENTITY_CURRENT_FRAME;

export const isNumberCheckableEquality = (v: unknown): v is NumberCheckableEquality => {
	return (v as NumberCheckableEquality)?.mathlang === 'number_checkable_equality';
};

// --------------------- Mathlang Nodes with labels --------------------- \\

export type MathlangNodeWithLabel =
	| GotoLabel
	| BoolGetable
	| BoolComparison
	| StringCheckable
	| NumberCheckableEquality;

export const doesMathlangHaveLabelToChangeToIndex = (v: unknown): v is MathlangNodeWithLabel => {
	if (typeof v !== 'object') return false;
	if (!isMathlangNode(v)) return false;
	if (isActionNode(v)) return false; // load bearing??
	if (v instanceof GotoLabel) return true;
	if (isBoolGetable(v)) return true;
	if (isBoolComparison(v)) return true;
	if (isStringCheckable(v)) return true;
	if (isNumberCheckableEquality(v)) return true;
	return false;
};
