import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';

export type MGSPrimitive = string | boolean | number;
export const isMGSPrimitive = (v: unknown): v is MGSPrimitive => {
	if (typeof v === 'string') return true;
	if (typeof v === 'number') return true;
	if (typeof v === 'boolean') return true;
	return false;
};

export type AnyNode = TYPES.Action | MathlangNode;
export const isNodeAction = (v: unknown): v is TYPES.Action => {
	return (v as TYPES.Action).action !== undefined;
};
export const isNodeMathlang = (v: unknown): v is MathlangNode => {
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
	| JSONNode
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
	if (typeof v !== 'object') return false;
	return (v as AddDialogSettings).mathlang === 'add_dialog_settings';
};

export type AddDialogSettingsTarget = {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
	target?: string;
	parameters?: DialogParameter[];
};
export const isAddDialogSettingsTarget = (v: unknown): v is AddDialogSettingsTarget => {
	if (typeof v !== 'object') return false;
	return (v as AddDialogSettingsTarget).mathlang === 'add_dialog_settings_target';
};

export type AddSerialDialogSettings = {
	mathlang: 'add_serial_dialog_settings';
	parameters: SerialDialogParameter[];
	debug: TYPES.MGSDebug;
};

// ------------------------------ CONTROL ------------------------------ \\

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
export const isGotoLabel = (v: unknown): v is GotoLabel => {
	if (typeof v !== 'object') return false;
	return (v as GotoLabel).mathlang === 'goto_label';
};

// ------------------------------ DIALOG ------------------------------ \\

export type DialogDefinition = {
	mathlang: 'dialog_definition';
	fileName: string;
	dialogName: string;
	dialogs: Dialog[];
	debug: TYPES.MGSDebug;
	duplicates?: DialogDefinition[];
};
export const isDialogDefinition = (v: unknown): v is DialogDefinition => {
	if (typeof v !== 'object') return false;
	return (v as MathlangNode).mathlang === 'dialog_definition';
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

export type DialogParameter = {
	mathlang: 'dialog_parameter';
	property: string;
	value: MGSPrimitive;
};
export const isDialogParameter = (v: unknown): v is DialogParameter => {
	if (typeof v !== 'object') return false;
	return (v as DialogParameter).mathlang === 'dialog_parameter';
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
	if (typeof v !== 'object') return false;
	return (v as Dialog).mathlang === 'dialog';
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
	if (typeof v !== 'object') return false;
	return (v as DialogIdentifier).mathlang === 'dialog_identifier';
};

export type DialogOption = {
	mathlang: 'dialog_option';
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export const isDialogOption = (v: unknown): v is DialogOption => {
	if (typeof v !== 'object') return false;
	return (v as DialogOption).mathlang === 'dialog_option';
};

// ------------------------------ SERIAL DIALOG ------------------------------ \\

export type SerialDialogDefinition = {
	mathlang: 'serial_dialog_definition';
	fileName: string;
	dialogName: string;
	serialDialog: SerialDialog;
	debug: TYPES.MGSDebug;
	duplicates?: SerialDialogDefinition[];
};
export const isSerialDialogDefinition = (v: unknown): v is SerialDialogDefinition => {
	if (typeof v !== 'object') return false;
	return (v as MathlangNode).mathlang === 'serial_dialog_definition';
};

export type SerialDialogSettings = {
	wrap?: number;
};

export type SerialDialogParameter = {
	mathlang: 'serial_dialog_parameter';
	property: string;
	value: MGSPrimitive;
};
export const isSerialDialogParameter = (v: unknown): v is SerialDialogParameter => {
	if (typeof v !== 'object') return false;
	return (v as SerialDialogParameter).mathlang === 'serial_dialog_parameter';
};

export type SerialDialog = {
	mathlang: 'serial_dialog';
	info: SerialDialogInfo;
	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	debug?: TYPES.MGSDebug;
};
export const isSerialDialog = (v: unknown): v is SerialDialog => {
	if (typeof v !== 'object') return false;
	return (v as SerialDialog).mathlang === 'serial_dialog';
};

export type SerialDialogInfo = {
	settings: SerialDialogSettings;
	messages: string[];
	options: SerialDialogOption[];
};

export type SerialOptionType = 'text_options' | 'options';
export type SerialDialogOption = {
	mathlang: 'serial_dialog_option';
	optionType: SerialOptionType;
	label: string;
	script: string;
	debug: TYPES.MGSDebug;
};
export const isSerialDialogOption = (v: unknown): v is SerialDialogOption => {
	if (typeof v !== 'object') return false;
	return (v as SerialDialogOption).mathlang === 'serial_dialog_option';
};

// ------------------------------ ONE-OFFS ------------------------------ \\

export type IncludeNode = {
	mathlang: 'include_macro';
	value: string;
	debug: TYPES.MGSDebug;
};

export type ConstantDefinition = {
	mathlang: 'constant_assignment';
	label: string;
	value: string | boolean | number;
	debug: TYPES.MGSDebug;
};

export type ScriptDefinition = {
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
};
export const isScriptDefinition = (v: unknown): v is ScriptDefinition => {
	if (typeof v !== 'object') return false;
	return (v as MathlangNode).mathlang === 'script_definition';
};

export type CommentNode = {
	mathlang: 'comment';
	comment: string;
	debug?: TYPES.MGSDebug;
};

export type LabelDefinition = {
	mathlang: 'label_definition';
	label: string;
	debug?: TYPES.MGSDebug;
};
export const isLabelDefinition = (v: unknown): v is LabelDefinition => {
	if (typeof v !== 'object') return false;
	if (!isNodeMathlang(v)) return false;
	return v.mathlang === 'label_definition';
};

export type JSONNode = {
	mathlang: 'json_literal';
	json: JSON;
	debug: TYPES.MGSDebug;
};

export type CopyMacro = {
	mathlang: 'copy_script';
	script: string;
	debug: TYPES.MGSDebug;
};
type CopyScript = CopyMacro | TYPES.COPY_SCRIPT;
export const isAnyCopyScript = (v: unknown): v is CopyScript => {
	if (typeof v !== 'object') return false;
	return (
		(v as TYPES.Action).action === 'COPY_SCRIPT' ||
		(v as MathlangNode).mathlang === 'copy_script'
	);
};
export const hasSearchAndReplace = (v: unknown): v is TYPES.COPY_SCRIPT_SEARCH_AND_REPLACE => {
	if (!v) return false;
	return (
		typeof v === 'object' &&
		isNodeAction(v) &&
		TYPES.isActionCopyScript(v) &&
		!!(v as TYPES.COPY_SCRIPT_SEARCH_AND_REPLACE).search_and_replace
	);
};

// needs to be one unit of thing for reasons, but still contain than one thing
export type MathlangSequence = {
	mathlang: 'sequence';
	type: string;
	steps: AnyNode[];
	debug: TYPES.MGSDebug;
};
export const isMathlangSequence = (v: unknown): v is MathlangSequence => {
	if (typeof v !== 'object') return false;
	return (v as MathlangSequence).mathlang === 'sequence';
};

// ------------------------------ INT EXPRESSIONS ------------------------------ \\

export type IntExpression = IntUnit | IntBinaryExpression;
export const isIntExpression = (v: unknown): v is IntExpression => {
	return isIntUnit(v) || isIntBinaryExpression(v);
};

export type IntUnit = IntGetable | number | string;
export const isIntUnit = (v: unknown): v is IntUnit => {
	if (v === null) return false;
	if (typeof v === 'number') return true;
	if (typeof v === 'string') return true;
	if (isIntGetable(v)) return true;
	return false;
};

export type IntGetable = {
	mathlang: 'int_getable';
	field: string;
	entity: string;
};
export const isIntGetable = (v: unknown): v is IntGetable => {
	if (typeof v !== 'object') return false;
	return (v as IntGetable).mathlang === 'int_getable';
};

export type IntBinaryExpression = {
	mathlang: 'int_binary_expression';
	lhs: IntExpression;
	rhs: IntExpression;
	op: string;
};
export const isIntBinaryExpression = (v: unknown): v is IntBinaryExpression => {
	if (typeof v !== 'object') return false;
	return (v as IntBinaryExpression).mathlang === 'int_binary_expression';
};

// ------------------------------ BOOL EXPRESSIONS ------------------------------ \\

export type BoolExpression = BoolComparison | BoolBinaryExpression | BoolUnit;
export const isBoolExpression = (v: unknown): v is BoolExpression => {
	return isBoolComparison(v) || isBoolBinaryExpression(v) || isBoolUnit(v);
};

export type BoolUnit = boolean | string | BoolGetable;
export const isBoolUnit = (v: unknown): v is BoolUnit => {
	if (typeof v === 'string') return true;
	if (typeof v === 'boolean') return true;
	if (typeof v !== 'object') return false;
	return (v as BoolGetable).mathlang === 'bool_getable';
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
	if (typeof v !== 'object') return false;
	if ((v as NumberCheckableEquality).mathlang === 'number_checkable_equality') return true;
	if ((v as StringCheckable).mathlang === 'string_checkable') return true;
	if ((v as BoolComparison).mathlang === 'bool_comparison') return true;
	return false;
};

// // TODO: untangle this >:(
// export type StringCheckable = {
// 	mathlang: 'string_checkable';
// 	debug?: TYPES.MGSDebug;
// 	entity: string;
// 	property: string;
// 	expected_bool?: boolean;
// 	label: string;
// 	action:
// 		| 'CHECK_ENTITY_TICK_SCRIPT'
// 		| 'CHECK_ENTITY_LOOK_SCRIPT'
// 		| 'CHECK_ENTITY_INTERACT_SCRIPT'
// 		| 'CHECK_ENTITY_NAME'
// 		| 'CHECK_ENTITY_PATH'
// 		| 'CHECK_ENTITY_TYPE'
// 		| 'CHECK_WARP_STATE';
// 	stringLabel?: 'expected_script' | 'string' | 'geometry' | 'entity_type';
// 	comment?: string;
// };
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
	stringLabel?: 'expected_script' | 'string' | 'geometry' | 'entity_type';
	comment?: string;
};

export const isStringCheckable = (v: unknown): v is StringCheckable => {
	if (typeof v !== 'object') return false;
	return (v as MathlangNode).mathlang === 'string_checkable';
};

export type BoolBinaryExpression = (
	| {
			// ==, !==, &&, ||
			lhs: BoolExpression;
			rhs: BoolExpression;
	  }
	| {
			// ==, !==
			lhs: StringCheckable | string;
			rhs: StringCheckable | string;
	  }
	| {
			// ==, !==
			lhs: NumberCheckableEquality | number;
			rhs: NumberCheckableEquality | number;
	  }
) & {
	mathlang: 'bool_binary_expression';
	op: string;
	debug?: TYPES.MGSDebug;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
};
export const isBoolBinaryExpression = (v: unknown): v is BoolBinaryExpression => {
	if (typeof v !== 'object') return false;
	return (v as BoolBinaryExpression).mathlang === 'bool_binary_expression';
};

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
	if (typeof v !== 'object') return false;
	return (v as BoolGetable).mathlang === 'bool_getable';
};

// (Intermediate)
export type BoolSetable = {
	mathlang: 'bool_setable';
	type: string;
	value?: string;
};
export const isBoolSetable = (v: unknown): v is BoolSetable => {
	if (typeof v !== 'object') return false;
	return (v as BoolSetable).mathlang === 'bool_setable';
};

export type NumberCheckableEquality = {
	mathlang: 'number_checkable_equality';
	debug?: TYPES.MGSDebug;
	entity: string;
	property: string;
	expected_bool?: boolean;
	label?: string;
	action:
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
export const isNumberCheckableEquality = (v: unknown): v is NumberCheckableEquality => {
	if (typeof v !== 'object') return false;
	return (v as NumberCheckableEquality).mathlang === 'number_checkable_equality';
};

// ------------------------------ NEXT ------------------------------ \\

export type MovableIdentifier = {
	mathlang: 'movable_identifier';
	type: string;
	value: string;
};
export const isMovableIdentifier = (v: unknown): v is MovableIdentifier => {
	if (typeof v !== 'object') return false;
	return (v as MovableIdentifier).mathlang === 'movable_identifier';
};

export type CoordinateIdentifier = {
	mathlang: 'coordinate_identifier';
	type: string;
	value: string;
	polygonType?: string;
};
export const isCoordinateIdentifier = (v: unknown): v is CoordinateIdentifier => {
	if (typeof v !== 'object') return false;
	return (v as CoordinateIdentifier).mathlang === 'coordinate_identifier';
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

export const isDirectionTarget = (v: unknown): v is DirectionTarget => {
	if (typeof v !== 'object') return false;
	if ((v as DirectionTarget).action === 'SET_ENTITY_DIRECTION') {
		return typeof (v as TYPES.SET_ENTITY_DIRECTION).direction === 'string';
	}
	if ((v as DirectionTarget).action === 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY') {
		return (
			typeof (v as TYPES.SET_ENTITY_DIRECTION_TARGET_GEOMETRY).target_geometry === 'string'
		);
	}
	if ((v as DirectionTarget).action === 'SET_ENTITY_DIRECTION_TARGET_ENTITY') {
		return typeof (v as TYPES.SET_ENTITY_DIRECTION_TARGET_ENTITY).target_entity === 'string';
	}
	return false;
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
	if (!isNodeMathlang(v)) return false;
	if (isNodeAction(v)) return false; // load bearing??
	if (isGotoLabel(v)) return true;
	if (isBoolGetable(v)) return true;
	if (isBoolComparison(v)) return true;
	if (isStringCheckable(v)) return true;
	if (isNumberCheckableEquality(v)) return true;
	return false;
};
