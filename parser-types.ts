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
	return v instanceof TYPES.Action;
	// return (v as TYPES.Action).action !== undefined;
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
	| TYPES.GotoLabel
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
	| TYPES.BoolGetable
	| TYPES.StringCheckable
	| TYPES.NumberComparison
	| TYPES.NumberCheckableEquality;

// ------------------------------ SETTINGS ------------------------------ \\

export class AddDialogSettings {
	mathlang: 'add_dialog_settings';
	debug: TYPES.MGSDebug;
	targets: AddDialogSettingsTarget[];
	parameters?: SerialDialogParameter[];
	constructor(f: FileState, node: TreeSitterNode, targets: AddDialogSettingsTarget[]) {
		this.mathlang = 'add_dialog_settings';
		this.debug = new TYPES.MGSDebug(f, node);
		this.targets = targets;
	}
	clone(prev: AddDialogSettings) {
		return new AddDialogSettings(prev.debug.f, prev.debug.node, prev.targets);
	}
}

export class AddDialogSettingsTarget {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
	target?: string;
	parameters: DialogParameter[];
	constructor(
		type: string,
		debug: TYPES.MGSDebug,
		parameters: DialogParameter[],
		target?: string,
	) {
		this.mathlang = 'add_dialog_settings_target';
		this.type = type;
		this.debug = debug;
		this.parameters = parameters;
		if (target !== undefined) this.target = target;
	}
	clone(prev: AddDialogSettingsTarget) {
		return new AddDialogSettingsTarget(prev.type, prev.debug, prev.parameters, prev.target);
	}
}

export class AddSerialDialogSettings {
	mathlang: 'add_serial_dialog_settings';
	parameters: SerialDialogParameter[];
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode, parameters: SerialDialogParameter[]) {
		this.mathlang = 'add_serial_dialog_settings';
		this.debug = new TYPES.MGSDebug(f, node);
		this.parameters = parameters;
	}
	clone(prev: AddSerialDialogSettings) {
		return new AddSerialDialogSettings(prev.debug.f, prev.debug.node, prev.parameters);
	}
}

// ------------------------------ CONTROL ------------------------------ \\

export class ReturnStatement {
	mathlang: 'return_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'return_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
	clone(prev: ReturnStatement) {
		return new ReturnStatement(prev.debug.f, prev.debug.node);
	}
}
export class ContinueStatement {
	mathlang: 'continue_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'continue_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
	clone(prev: ContinueStatement) {
		return new ContinueStatement(prev.debug.f, prev.debug.node);
	}
}
export class BreakStatement {
	mathlang: 'break_statement';
	debug: TYPES.MGSDebug;
	constructor(f: FileState, node: TreeSitterNode) {
		this.mathlang = 'break_statement';
		this.debug = new TYPES.MGSDebug(f, node);
	}
	clone(prev: BreakStatement) {
		return new BreakStatement(prev.debug.f, prev.debug.node);
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
	clone(prev: DialogDefinition) {
		return new DialogDefinition(prev.debug.f, prev.debug.node, prev.dialogName, prev.dialogs);
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

export class DialogParameter {
	mathlang: 'dialog_parameter';
	property: string;
	value: MGSPrimitive;
	constructor(property: string, value: MGSPrimitive) {
		this.mathlang = 'dialog_parameter';
		this.property = property;
		this.value = value;
	}
	clone(prev: DialogParameter) {
		return new DialogParameter(prev.property, prev.value);
	}
}

export class Dialog {
	wrap?: number;
	emote?: number;
	entity?: string;
	name?: string;
	portrait?: string;
	alignment?: string;
	border_tileset?: string;

	args: DialogSettings;
	options?: DialogOption[];
	mathlang: 'dialog';
	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	debug?: TYPES.MGSDebug;
	constructor(
		messages: string[],
		options: DialogOption[],
		args: DialogSettings,
		debug?: TYPES.MGSDebug,
	) {
		this.mathlang = 'dialog';
		this.messages = messages;
		if (options.length) {
			this.options = options;
			this.response_type = 'SELECT_FROM_SHORT_LIST';
		}
		if (debug) this.debug = debug;
		Object.entries(args).forEach(([k, v]) => {
			this[k] = v;
		});
		this.args = args;
	}
	clone(prev: Dialog) {
		return new Dialog(prev.messages, prev.options || [], prev.args || {}, prev.debug);
	}
}

export type DialogInfo = {
	identifier: DialogIdentifier;
	settings: DialogSettings;
	messages: string[];
	options: DialogOption[];
};

export class DialogIdentifier {
	mathlang: 'dialog_identifier';
	type: DialogIdentifierType;
	value: string;
	debug?: TYPES.MGSDebug;
	constructor(type: DialogIdentifierType, value: string, debug?: TYPES.MGSDebug) {
		this.mathlang = 'dialog_identifier';
		this.type = type;
		this.value = value;
		if (debug) this.debug = debug;
	}
	clone(prev: DialogIdentifier) {
		return new DialogIdentifier(prev.type, prev.value, prev.debug);
	}
}
type DialogIdentifierType = 'label' | 'entity' | 'name';

export class DialogOption {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
	constructor(label: string, script: string, debug: TYPES.MGSDebug) {
		this.mathlang = 'dialog_option';
		this.label = label;
		this.script = script;
		this.debug = debug;
	}
	clone(prev: DialogOption) {
		return new DialogOption(prev.label, prev.script, prev.debug);
	}
}

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
	clone(prev: SerialDialogDefinition) {
		return new SerialDialogDefinition(
			prev.debug.f,
			prev.debug.node,
			prev.dialogName,
			prev.serialDialog,
		);
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
	clone(prev: SerialDialogParameter) {
		return new SerialDialogParameter(prev.property, prev.value);
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
	args: SerialDialogConstructorArgs;
	constructor(args: SerialDialogConstructorArgs) {
		this.mathlang = 'serial_dialog';
		this.messages = args.messages;
		if (args.options) this.options = args.options;
		if (args.text_options) this.text_options = args.text_options;
		if (args.debug) this.debug = args.debug;
		this.args = args;
	}
	clone(prev: SerialDialog) {
		return new SerialDialog(prev.args);
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
	clone(prev: SerialDialogOption) {
		return new SerialDialogOption(prev.optionType, prev.label, prev.script, prev.debug);
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
	clone(prev: IncludeNode) {
		return new IncludeNode(prev.debug.f, prev.debug.node, prev.value);
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
	clone(prev: ConstantDefinition) {
		return new ConstantDefinition(prev.debug.f, prev.debug.node, prev.label, prev.value);
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
	clone(prev: ScriptDefinition) {
		return new ScriptDefinition(prev.debug.f, prev.debug.node, prev.scriptName, prev.actions);
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
	clone(prev: CommentNode) {
		return new CommentNode(prev.comment);
	}
}

export class LabelDefinition {
	mathlang: 'label_definition';
	label: string;
	debug?: TYPES.MGSDebug;
	constructor(label: string) {
		this.mathlang = 'label_definition';
		this.label = label;
	}
	clone(prev: LabelDefinition) {
		return new LabelDefinition(prev.label);
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
	clone(prev: JSONLiteral) {
		return new JSONLiteral(prev.debug.f, prev.debug.node, prev.json);
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
	clone(prev: CopyMacro) {
		return new CopyMacro(prev.debug.f, prev.debug.node, prev.script);
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
	clone(prev: MathlangSequence) {
		return new MathlangSequence(prev.debug.f, prev.debug.node, prev.steps, prev.type);
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
	clone(prev: IntGetable) {
		return new IntGetable(prev.entity, prev.field);
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
	clone(prev: IntBinaryExpression) {
		return new IntBinaryExpression(prev.lhs, prev.rhs, prev.op);
	}
}

// ------------------------------ BOOL EXPRESSIONS ------------------------------ \\

export type BoolExpression = BoolComparison | BoolBinaryExpression | BoolUnit;
export const isBoolExpression = (v: unknown): v is BoolExpression => {
	return isBoolComparison(v) || v instanceof BoolBinaryExpression || isBoolUnit(v);
};

export type BoolUnit = boolean | string | TYPES.BoolGetable;
export const isBoolUnit = (v: unknown): v is BoolUnit => {
	if (typeof v === 'string') return true;
	if (typeof v === 'boolean') return true;
	return (v as TYPES.BoolGetable)?.mathlang === 'bool_getable';
};

export type BoolComparison =
	| TYPES.NumberCheckableEquality
	| TYPES.StringCheckable
	| TYPES.NumberComparison;
export const isBoolComparison = (v: unknown): v is BoolComparison => {
	if (v instanceof TYPES.NumberCheckableEquality) return true;
	if (v instanceof TYPES.StringCheckable) return true;
	if (v instanceof TYPES.NumberComparison) return true;
	return false;
};

export type BoolBinaryExpressionArgs = {
	lhs: TYPES.StringCheckable | string | number | BoolExpression | TYPES.NumberCheckableEquality;
	rhs: TYPES.StringCheckable | string | number | BoolExpression | TYPES.NumberCheckableEquality;
	op: string;
	debug?: TYPES.MGSDebug;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
};

export class BoolBinaryExpression {
	mathlang: 'bool_binary_expression';
	lhs: TYPES.StringCheckable | string | number | BoolExpression | TYPES.NumberCheckableEquality;
	rhs: TYPES.StringCheckable | string | number | BoolExpression | TYPES.NumberCheckableEquality;
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
	clone(args: BoolBinaryExpressionArgs) {
		return new BoolBinaryExpression(args);
	}
}

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
	mathlang: 'direction_target';
	type: string;
	value: string;
	constructor(type: string, value: string) {
		this.mathlang = 'direction_target';
		this.type = type;
		this.value = value;
	}
}
// --------------------- Mathlang Nodes with labels --------------------- \\

export type MathlangNodeWithLabel =
	| TYPES.GotoLabel
	| TYPES.BoolGetable
	| TYPES.StringCheckable
	| TYPES.NumberComparison
	| TYPES.NumberCheckableEquality;

export const doesMathlangHaveLabelToChangeToIndex = (v: unknown): v is MathlangNodeWithLabel => {
	if (!isMathlangNode(v)) return false; // load bearing??
	if (v instanceof TYPES.GotoLabel) return true;
	if (v instanceof TYPES.BoolGetable) return true;
	if (v instanceof TYPES.StringCheckable) return true;
	if (v instanceof TYPES.NumberComparison) return true;
	if (v instanceof TYPES.NumberCheckableEquality) return true;
	return false;
};
