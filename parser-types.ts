import { Parser, Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';

export type MGSValue = string | boolean | number;
export type MathlangNode =
	| MathlangDialogDefinition
	| MathlangSerialDialogDefinition
	| MathlangScriptDefinition
	| MathlangConstantDefinition
	| MathlangIncludeDefinition
	| MathlangBoolComparison
	| MathlangAddDialogSettings
	| MathlangAddSerialDialogSettings
	| MathlangDialogOption
	| MathlangSerialDialogOption
	| MathlangDialog
	| MathlangSerialDialog
	| MathlangJSON
	| MathlangComment
	| MathlangReturnStatement
	| MathlangGotoLabel
	| MathlangCopyMacro;

export type MathlangDialogDefinition = {
	mathlang: 'dialog_definition';
	dialogName: string;
	dialogs: Dialog[];
	debug: TYPES.MGSDebug;
};
export type Dialog = DialogSettings & {
	mathlang: 'dialog';
	info: DialogInfo; // for debugging
	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
};
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
	label: 'string';
	script: 'string';
	debug: TreeSitterNode;
	fileName: string;
};
export type SerialDialog = {
	// TODO fix all of these
	mathlang: 'serial_dialog';
	info: SerialDialogInfo; // for debugging
	messages: string[];
	options?: SerialDialogOption[];
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
	label: 'string';
	script: 'string';
	debug: TreeSitterNode;
	fileName: string;
};
export type MathlangSerialDialogDefinition = {
	mathlang: 'serial_dialog_definition';
	dialogName: string;
	serialDialog: SerialDialog;
	debug: TYPES.MGSDebug;
};
export type MathlangScriptDefinition = {
	mathlang: 'script_definition';
	scriptName: string;
	actions: TYPES.Action[];
	debug: TYPES.MGSDebug;
};
export type MathlangConstantDefinition = {
	mathlang: 'constant_assignment';
	label: string;
	value: string | boolean | number;
	debug: TYPES.MGSDebug;
};
export type MathlangIncludeDefinition = {
	mathlang: 'include_macro';
	value: string;
	debug: TYPES.MGSDebug;
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
};
export type MathlangAddDialogSettings = {
	mathlang: 'add_dialog_settings_target';
	type: string;
	debug: TYPES.MGSDebug;
};
export type MathlangAddSerialDialogSettings = {
	mathlang: 'add_serial_dialog_settings_target';
	parameters: Record<string, MGSValue>;
	debug: TYPES.MGSDebug;
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
export type MathlangJSON = {
	mathlang: 'json_literal';
	json: JSON;
	debug: TYPES.MGSDebug;
};
export type MathlangComment = {
	mathlang: 'comment';
	comment: string;
	debug: TYPES.MGSDebug;
};
export type MathlangReturnStatement = {
	mathlang: 'return_statement';
	debug: TYPES.MGSDebug;
};
export type MathlangGotoLabel = {
	mathlang: 'goto_label';
	label: string;
	debug: TYPES.MGSDebug;
};
export type MathlangCopyMacro = {
	mathlang: 'copy_script';
	script: string;
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

export type Constant = {
	value: MGSValue;
	debug: TYPES.MGSDebug;
};
export type FileState = {
	p: ProjectState;
	fileName: string;
	constants: Record<string, Constant>;
	settings: {
		default: DialogSettings;
		entity: DialogSettings;
		label: DialogSettings;
		serial: SerialDialogSettings;
	};
	nodes: Record<string, MathlangNode | TYPES.Action>[];
	errorCount: number;
	warningCount: number;
	newError: (message: MGSMessage) => void;
	newWarning: (message: MGSMessage) => void;
	includeFile: (newName: string) => void;
	printableMessageInformation: () => string;
};

export type MGSLocation = {
	node: TreeSitterNode;
	fileName?: string;
};

export type MGSMessage = {
	locations: MGSLocation[];
	message: string;
	footer?: string;
};
export type Script = {
	actions: TYPES.Action[];
	preActions: TYPES.Action[];
	duplicates?: Script[];
};

type MathlangOrActionNode = TYPES.Action | MathlangNode;
type FileMapEntry = {
	arrayBuffer: Promise<unknown>;
	fileText: () => string;
	name: string;
	text: Promise<unknown>;
	type: string;
};
type addScriptArgs = {
	mathlang: 'script_definition';
	scriptName: string;
	rawNodes: MathlangOrActionNode[];
	actions: MathlangOrActionNode[];
	debug: TreeSitterNode;
	fileName: string;
};
type addDialogArgs = {
	mathlang: 'dialog_definition';
	debug: TreeSitterNode;
	dialogName: string;
	dialogs: Dialog[];
	fileName: string;
};
type addSerialDialogArgs = {
	mathlang: 'serial_dialog_definition';
	debug: TreeSitterNode;
	serialDialogName: string;
	serialDialogs: SerialDialog;
	fileName: string;
};
export type ProjectState = {
	parser: Parser;
	fileMap: Record<string, FileMapEntry>;
	gotoSuffixValue: number;
	scripts: Record<string, Script>;
	dialogs: Record<string, Dialog>;
	serialDialogs: Record<string, SerialDialog>;
	errors: MGSMessage[];
	warnings: MGSMessage[];
	errorCount: number;
	warningCount: number;
	advanceGotoSuffix: () => number;
	getGotoSuffix: () => number;
	newError: (error: MGSMessage) => void;
	newWarning: (warning: MGSMessage) => void;
	addScript: (args: addScriptArgs, fileName: number) => void;
	addDialog: (args: addDialogArgs) => void;
	addSerialDialog: (args: addSerialDialogArgs) => void;
	detectDuplicates: () => void;
	copyScriptOne: (fileName: string) => void;
	copyScriptAll: () => void;
	bakeLabels: () => void;
	printProblems: () => void;
	parseFile: (fileName: string) => FileState;
};
