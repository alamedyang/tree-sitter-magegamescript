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
export type Dialog = {
	mathlang: 'dialog';
	info: DialogInfo;
	debug: TYPES.MGSDebug;
	wrap: number;
	// TODO
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

export type Constant = {
	value: MGSValue;
	debug: TYPES.MGSDebug;
};
export type FileState = {
	p: ProjectState;
	fileName: File;
	constants: Record<string, Constant>;
	settings: {
		default: Record<string, any>;
		entity: Record<string, any>;
		label: Record<string, any>;
		serial: Record<string, any>;
	};
	nodes: Record<string, any>[];
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

export type ProjectState = {
	parser: Parser;
	fileMap: Record<string, any>;
	gotoSuffixValue: number;
	scripts: Record<string, any>;
	dialogs: Record<string, any>;
	serialDialogs: Record<string, any>;
	errors: Record<string, any>;
	warnings: Record<string, any>;
	errorCount: number;
	warningCount: number;
	advanceGotoSuffix: () => number;
	getGotoSuffix: () => number;
	newError: (error: MGSMessage) => void;
	newWarning: (warning: MGSMessage) => void;
	addScript: (args: any, fileName: number) => void;
	addDialog: (args: any) => void;
	addSerialDialog: (args: any) => void;
	detectDuplicates: () => void;
	copyScriptOne: (fileName: string) => void;
	copyScriptAll: () => void;
	bakeLabels: () => void;
	printProblems: () => void;
	parseFile: (fileName: string) => FileState;
};
