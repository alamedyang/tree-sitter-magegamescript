import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';

export type MGSValue = string | boolean | number;

export type Intermediate =
	| IfBranchGotoLabel
	| BoolBinaryExpression
	| MathlangBoolGetable
	| MathlangBoolComparison
	| MathlangStringCheckable
	| MathlangNumberCheckableEquality
	| MathlangDialogOption
	| MathlangSerialDialogOption
	| MathlangDialog
	| MathlangSerialDialog;

export type MathlangNode =
	| Intermediate
	| MathlangSequence
	| DialogDefinitionNode
	| SerialDialogDefinitionNode
	| ScriptDefinitionNode
	| ConstantDefinitionNode
	| IncludeNode
	| AddDialogSettingsNode
	| AddSerialDialogSettingsNode
	| LabelDefinitionNode
	| JSONNode
	| CommentNode
	| ReturnStatement
	| ContinueStatement
	| BreakStatement
	| MathlangGotoLabel
	| MathlangCopyMacro;

export type GenericActionish = Record<
	string,
	boolean | number | string | TYPES.MGSDebug | Record<string, unknown>
>;
export type AnyNode = TYPES.Action | MathlangNode;
export const isNodeAction = (node: TYPES.Action | MathlangNode): node is TYPES.Action => {
	return (node as TYPES.Action).action !== undefined;
};

// --------------------- intermediates, used to make final nodes --------------------- \\

export type DialogInfo = {
	identifier: DialogIdentifier;
	settings: DialogSettings;
	messages: string[];
	options: DialogOption[];
};
export type DialogSettings = {
	wrap?: number;
	emote?: number;
	entity?: string;
	name?: string;
	portrait?: string;
	alignment?: string;
	border_tileset?: string;
};
export type DialogIdentifier = {
	mathlang: 'dialog_identifier';
	type: 'label' | 'entity' | 'name';
	value: string;
};
export type DialogOption = {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TreeSitterNode;
	fileName: string;
};
export type SerialDialogInfo = {
	settings: SerialDialogSettings;
	messages: string[];
	options: SerialDialogOption[];
};
export type SerialDialogSettings = {
	wrap?: number;
};
export type SerialDialogOption = {
	mathlang: 'serial_dialog_option';
	optionType: 'text_options' | 'options';
	label: string;
	script: string;
	debug: TreeSitterNode;
	fileName: string;
};
export type MathlangBoolComparison = {
	mathlang: 'bool_comparison';
	action: 'CHECK_VARIABLE';
	variable: string;
	value: number;
	comparison: '==';
	expected_bool: boolean;
	label: string;
	debug: TYPES.MGSDebug;
	comment?: string;
};
export type MathlangSerialDialogParameter = {
	mathlang: 'serial_dialog_parameter';
	property: string;
	value: MGSValue;
};
export type MathlangDialogOption = {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export type MathlangSerialDialogOption = {
	mathlang: 'serial_dialog_option';
	optionType: string;
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export type MathlangDialog = {
	mathlang: 'dialog';
	info: DialogInfo;
	dialogs: Dialog[];
	debug: TYPES.MGSDebug;
};
export type MathlangSerialDialog = {
	mathlang: 'serial_dialog';
	serialDialog: SerialDialog;
	debug: TYPES.MGSDebug;
};
export type MovableIdentifier = {
	mathlang: 'movable_identifier';
	type: string;
	value: string;
};
export type CoordinateIdentifier = {
	mathlang: 'coordinate_identifier';
	type: string;
	value: string;
	polygonType: string;
};
export type IntGetable = {
	mathlang: 'int_getable';
	field: string;
	entity: string;
};
export const isIntGetable = (data: Record<string, unknown>): data is IntGetable => {
	return (data as IntGetable).mathlang === 'int_getable';
};
export type IntBinaryExpression = {
	mathlang: 'int_binary_expression';
	lhs: unknown;
	rhs: unknown;
	op: string;
};
export type BoolBinaryExpression = {
	mathlang: 'bool_binary_expression';
	debug: TYPES.MGSDebug;
	op: string;
	lhs: MathlangCondition;
	rhs: MathlangCondition;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
};
export type MathlangCondition =
	| BoolBinaryExpression
	| MathlangBoolGetable
	| MathlangBoolComparison
	| MathlangStringCheckable
	| MathlangNumberCheckableEquality
	| TYPES.CHECK_SAVE_FLAG
	| boolean
	| string;

export type IfBranchGotoLabel = {
	expected_bool: boolean;
	mathlang: 'if_branch_goto_label';
	label?: string;
	debug: TYPES.MGSDebug;
	action?: string;
	entity: string;
	geometry?: string;
	value?: string;
	state?: string;
	button_id?: string;
	save_flag?: string;
	property?: string;
	stringLabel?: string;
	variable?: string;
	comparison?: string;
	numberLabel?: string;
	comment?: string;
};
export type MathlangStringCheckable = {
	mathlang: 'string_checkable';
	debug?: TYPES.MGSDebug;
	entity: string;
	property: string;
	expected_bool?: boolean;
	label?: string;
	action?:
		| 'CHECK_ENTITY_TICK_SCRIPT'
		| 'CHECK_ENTITY_LOOK_SCRIPT'
		| 'CHECK_ENTITY_INTERACT_SCRIPT'
		| 'CHECK_ENTITY_NAME'
		| 'CHECK_ENTITY_PATH'
		| 'CHECK_ENTITY_TYPE'
		| 'CHECK_WARP_STATE';
	stringLabel?: 'expected_script' | 'string' | 'geometry' | 'entity_type';
	comment?: string;
};
export type MathlangNumberCheckableEquality = {
	mathlang: 'number_checkable_equality';
	debug?: TYPES.MGSDebug;
	entity: string;
	property: string;
	expected_bool?: boolean;
	label?: string;
	action?:
		| 'CHECK_ENTITY_X'
		| 'CHECK_ENTITY_Y'
		| 'CHECK_ENTITY_PRIMARY_ID'
		| 'CHECK_ENTITY_SECONDARY_ID'
		| 'CHECK_ENTITY_PRIMARY_ID_TYPE'
		| 'CHECK_ENTITY_CURRENT_ANIMATION'
		| 'CHECK_ENTITY_CURRENT_FRAME';
	numberLabel?: 'expected_u2' | 'expected_byte';
	comment?: string;
};
export type MathlangBoolGetable = {
	mathlang: 'bool_getable';
	debug: TYPES.MGSDebug;
	action: string;
	entity: string;
	geometry: string;
	value: string;
	state: string;
	button_id: string;
	expected_bool?: boolean;
	label?: string;
	save_flag: string;
	comment?: string;
};

// --------------------- final nodes that aren't actions --------------------- \\

// needs to be one unit of thing for reasons, but still contain than one thing
export type MathlangSequence = {
	mathlang: 'sequence';
	type: string;
	steps: AnyNode[];
	debug: TYPES.MGSDebug;
};
export type AddDialogSettingsNode = {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
	target?: string;
	parameters?: Record<string, MGSValue>;
};
// todo: not used?
export type AddSerialDialogSettingsNode = {
	mathlang: 'add_serial_dialog_settings_target';
	parameters: Record<string, MGSValue>;
	debug: TYPES.MGSDebug;
};

export type FileCategory = 'scripts' | 'dialogs' | 'serialDialogs';
export type DialogDefinitionNode = {
	mathlang: 'dialog_definition';
	fileName: string;
	dialogName: string;
	dialogs: Dialog[];
	debug: TYPES.MGSDebug;
	duplicates?: DialogDefinitionNode[];
};
export const isDialogDefinitionNode = (node: AnyNode): node is DialogDefinitionNode => {
	return (node as MathlangNode).mathlang === 'dialog_definition';
};
export type SerialDialogDefinitionNode = {
	mathlang: 'serial_dialog_definition';
	fileName: string;
	dialogName: string;
	serialDialog: SerialDialog;
	debug: TYPES.MGSDebug;
	duplicates?: SerialDialogDefinitionNode[];
};
export const isSerialDialogDefinitionNode = (node: AnyNode): node is SerialDialogDefinitionNode => {
	return (node as MathlangNode).mathlang === 'serial_dialog_definition';
};
export type ScriptDefinitionNode = {
	mathlang: 'script_definition';
	fileName: string;
	scriptName: string;
	prePrint?: string;
	testPrint?: string;
	print?: string;
	rawNodes?: AnyNode[];
	actions: AnyNode[];
	debug: TYPES.MGSDebug;
	preActions?: AnyNode[];
	duplicates?: ScriptDefinitionNode[];
	copyScriptResolved?: boolean;
};
export const isScriptDefinitionNode = (node: AnyNode): node is ScriptDefinitionNode => {
	return (node as MathlangNode).mathlang === 'script_definition';
};
//todo: not used?
export type ConstantDefinitionNode = {
	mathlang: 'constant_assignment';
	label: string;
	value: string | boolean | number;
	debug: TYPES.MGSDebug;
};
export type LabelDefinitionNode = {
	mathlang: 'label_definition';
	label: string;
	debug?: TYPES.MGSDebug;
};
export const isLabelDefinition = (node: AnyNode): node is LabelDefinitionNode => {
	if (isNodeAction(node)) return false;
	return node.mathlang === 'label_definition';
};

//todo: not used?
export type IncludeNode = {
	mathlang: 'include_macro';
	value: string;
	debug: TYPES.MGSDebug;
};
export type Dialog = DialogSettings & {
	mathlang: 'dialog';
	info: DialogInfo; // for debugging(?)
	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
};
export type SerialDialog = {
	// TODO fix all of these
	mathlang: 'serial_dialog';
	info: SerialDialogInfo; // for debugging
	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
};

// todo: not used?
export type JSONNode = {
	mathlang: 'json_literal';
	json: JSON;
	debug: TYPES.MGSDebug;
};
export type CommentNode = {
	mathlang: 'comment';
	comment: string;
	debug?: TYPES.MGSDebug;
};
export type ReturnStatement = {
	mathlang: 'return_statement';
	debug: TYPES.MGSDebug;
};
export type ContinueStatement = {
	mathlang: 'continue_statement';
	debug: TYPES.MGSDebug;
};
export type BreakStatement = {
	mathlang: 'break_statement';
	debug: TYPES.MGSDebug;
};
export type MathlangGotoLabel = {
	mathlang: 'goto_label';
	label: string;
	debug?: TYPES.MGSDebug;
	comment?: string;
};
export type Constant = {
	value: MGSValue;
	debug: TYPES.MGSDebug;
};
export type MathlangCopyMacro = {
	mathlang: 'copy_script';
	script: string;
	debug: TYPES.MGSDebug;
};
type CopyScript = MathlangCopyMacro | TYPES.COPY_SCRIPT;

export const isAnyCopyScript = (node: TYPES.Action | MathlangNode): node is CopyScript => {
	return (
		(node as TYPES.Action).action === 'COPY_SCRIPT' ||
		(node as MathlangNode).mathlang === 'copy_script'
	);
};
export const hasSearchAndReplace = (node: AnyNode): boolean => {
	if (TYPES.isActionCopyScript(node) && node.search_and_replace) return true;
	return false;
};

// --------------------- Mathlang Nodes with labels --------------------- \\

export type MathlangNodeWithLabel =
	| IfBranchGotoLabel
	| MathlangGotoLabel
	| MathlangBoolGetable
	| MathlangBoolComparison
	| MathlangStringCheckable
	| MathlangNumberCheckableEquality;

export const doesMathlangHaveLabelToChangeToIndex = (
	node: AnyNode,
): node is MathlangNodeWithLabel => {
	if (isNodeAction(node)) return false;
	if (node.mathlang === 'if_branch_goto_label') return true;
	if (node.mathlang === 'goto_label') return true;
	if (node.mathlang === 'bool_getable') return true;
	if (node.mathlang === 'bool_comparison') return true;
	if (node.mathlang === 'string_checkable') return true;
	if (node.mathlang === 'number_checkable_equality') return true;
	return false;
};

// --------------------- idk --------------------- \\

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
