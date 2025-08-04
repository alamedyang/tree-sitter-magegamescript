import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';

export type MGSValue = string | boolean | number;
export const isMGSValue = (v: unknown): v is MGSValue => {
	if (typeof v === 'string') return true;
	if (typeof v === 'number') return true;
	if (typeof v === 'boolean') return true;
	return false;
};

export type Intermediate =
	| BoolBinaryExpression
	| BoolGetable
	| BoolComparison
	| StringCheckable
	| NumberCheckableEquality;

export type MathlangNode =
	| Intermediate
	| MathlangSequence
	| SerialDialog
	| Dialog
	| DialogIdentifier
	| DialogDefinitionNode
	| SerialDialogDefinitionNode
	| ScriptDefinitionNode
	| ConstantDefinitionNode
	| IncludeNode
	| AddDialogSettingsNode
	| AddSerialDialogSettingsNode
	| LabelDefinitionNode
	| AddDialogSettingsTargetNode
	| SerialDialogOption
	| DialogOption
	| JSONNode
	| CommentNode
	| ReturnStatement
	| ContinueStatement
	| BreakStatement
	| GotoLabel
	| CopyMacro;

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
	debug?: TYPES.MGSDebug;
};
export const isDialogIdentifier = (v: unknown): v is DialogIdentifier => {
	return (v as DialogIdentifier).mathlang === 'dialog_identifier';
};
export type SerialDialogInfo = {
	settings: SerialDialogSettings;
	messages: string[];
	options: SerialDialogOption[];
};
export type SerialDialogSettings = {
	wrap?: number;
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
export type DialogParameter = {
	mathlang: 'dialog_parameter';
	property: string;
	value: MGSValue;
};
export const isDialogParameter = (v: unknown): v is DialogParameter => {
	if (typeof v !== 'object') return false;
	return (v as DialogParameter).mathlang === 'dialog_parameter';
};
export type SerialDialogParameter = {
	mathlang: 'serial_dialog_parameter';
	property: string;
	value: MGSValue;
};
export const isSerialDialogParameter = (v: unknown): v is SerialDialogParameter => {
	if (typeof v !== 'object') return false;
	return (v as SerialDialogParameter).mathlang === 'serial_dialog_parameter';
};
export type MovableIdentifier = {
	mathlang: 'movable_identifier';
	type: string;
	value: string;
};
export type BoolSetable = {
	mathlang: 'bool_setable';
	type: string;
	value?: string;
};
export type CoordinateIdentifier = {
	mathlang: 'coordinate_identifier';
	type: string;
	value: string;
	polygonType: string | undefined;
};
export type IntGetable = {
	mathlang: 'int_getable';
	field: string;
	entity: string;
};
export const isIntGetable = (data: unknown): data is IntGetable => {
	if (typeof data !== 'object') return false;
	return (data as IntGetable).mathlang === 'int_getable';
};
export type IntBinaryExpression = {
	mathlang: 'int_binary_expression';
	lhs: IntUnit;
	rhs: IntUnit;
	op: string;
};
export type IntUnit = IntBinaryExpression | IntGetable | number | string;
export const isIntUnit = (data: unknown): data is IntUnit => {
	if (data === null) return false;
	if (typeof data === 'number') return true;
	if (typeof data === 'string') return true;
	if (isIntGetable(data)) return true;
	return (data as IntBinaryExpression).mathlang === 'int_binary_expression';
};
export type BoolUnit = BoolBinaryExpression | boolean | string;
export type BoolBinaryExpression = {
	mathlang: 'bool_binary_expression';
	debug: TYPES.MGSDebug;
	op: string;
	lhs: BoolUnit | number | IntUnit;
	rhs: BoolUnit | number | IntUnit;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
};
export type MathlangCondition =
	| BoolBinaryExpression
	| BoolGetable
	| BoolComparison
	| StringCheckable
	| NumberCheckableEquality
	| TYPES.CHECK_SAVE_FLAG
	| boolean
	| string;
export const isCondition = (v: unknown): v is MathlangCondition => {
	if (typeof v === 'string') return true;
	if (typeof v === 'boolean') return true;
	if ((v as TYPES.CHECK_SAVE_FLAG).action === 'CHECK_SAVE_FLAG') return true;
	if ((v as BoolBinaryExpression).mathlang === 'bool_binary_expression') return true;
	if ((v as BoolGetable).mathlang === 'bool_getable') return true;
	if ((v as BoolComparison).mathlang === 'bool_comparison') return true;
	if ((v as BoolComparison).mathlang === 'number_checkable_equality') return true;
	if ((v as StringCheckable).mathlang === 'string_checkable') return true;
	if ((v as NumberCheckableEquality).mathlang === 'number_checkable_equality') {
		return true;
	}
	return false;
};

export type StringCheckable = {
	mathlang: 'string_checkable' | 'bool_comparison'; // todo fix
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

// icky
export const isStringCheckable = (v: unknown): v is StringCheckable => {
	if (typeof v !== 'object') return false;
	const hasEntity = typeof (v as StringCheckable).entity == 'string';
	const hasProperty = typeof (v as StringCheckable).property == 'string';
	return (
		(v as MathlangNode).mathlang === 'string_checkable' ||
		((v as MathlangNode).mathlang === 'string_checkable' && hasEntity && hasProperty)
	);
};

export type NumberCheckableEquality = {
	mathlang: 'number_checkable_equality' | 'bool_comparison'; // todo fix
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
export type BoolGetable = {
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

export type ConstantDefinitionNode = {
	mathlang: 'constant_assignment';
	label: string;
	value: string | boolean | number;
	debug: TYPES.MGSDebug;
};

export type IncludeNode = {
	mathlang: 'include_macro';
	value: string;
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

export type AddDialogSettingsNode = {
	mathlang: 'add_dialog_settings';
	debug: TYPES.MGSDebug;
	targets: AddDialogSettingsTargetNode[];
	parameters?: SerialDialogParameter[];
};
export const isAddDialogSettingsNode = (node: AnyNode): node is AddDialogSettingsNode => {
	return (node as AddDialogSettingsNode).mathlang === 'add_dialog_settings';
};
export type AddDialogSettingsTargetNode = {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
	target?: string;
	parameters?: DialogParameter[];
};
export const isAddDialogSettingsTargetNode = (
	node: AnyNode,
): node is AddDialogSettingsTargetNode => {
	return (node as AddDialogSettingsTargetNode).mathlang === 'add_dialog_settings_target';
};
// todo: not used?
export type AddSerialDialogSettingsNode = {
	mathlang: 'add_serial_dialog_settings';
	parameters: SerialDialogParameter[];
	debug: TYPES.MGSDebug;
};
export type SerialOptionType = 'text_options' | 'options';
export type SerialDialogOption = {
	mathlang: 'serial_dialog_option';
	optionType: SerialOptionType;
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export const isSerialDialogOption = (node: AnyNode): node is SerialDialogOption => {
	return (node as SerialDialogOption).mathlang === 'serial_dialog_option';
};
export type DialogOption = {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export const isDialogOption = (node: AnyNode): node is DialogOption => {
	return (node as DialogOption).mathlang === 'dialog_option';
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

export type DirectionTarget =
	| {
			action: 'SET_ENTITY_DIRECTION';
			direction: string;
	  }
	| {
			action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
			target_geometry: string;
	  }
	| {
			action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
			target_entity: string;
	  };

export type Dialog = DialogSettings & {
	mathlang: 'dialog';
	info: DialogInfo; // for debugging(?)
	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
	debug?: TYPES.MGSDebug;
};
export const isDialog = (v: AnyNode): v is Dialog => {
	return (v as Dialog).mathlang === 'dialog';
};
export type SerialDialog = {
	// TODO fix all of these
	mathlang: 'serial_dialog';
	info: SerialDialogInfo; // for debugging
	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	debug?: TYPES.MGSDebug;
};
export const isSerialDialog = (v: AnyNode): v is SerialDialog => {
	return (v as SerialDialog).mathlang === 'serial_dialog';
};

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
export type GotoLabel = {
	mathlang: 'goto_label';
	label: string;
	debug?: TYPES.MGSDebug;
	comment?: string;
};
export type Constant = {
	value: MGSValue;
	debug: TYPES.MGSDebug;
};
export type CopyMacro = {
	mathlang: 'copy_script';
	script: string;
	debug: TYPES.MGSDebug;
};
type CopyScript = CopyMacro | TYPES.COPY_SCRIPT;

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
	| GotoLabel
	| BoolGetable
	| BoolComparison
	| StringCheckable
	| NumberCheckableEquality;

export const doesMathlangHaveLabelToChangeToIndex = (
	node: AnyNode,
): node is MathlangNodeWithLabel => {
	if (isNodeAction(node)) return false;
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
