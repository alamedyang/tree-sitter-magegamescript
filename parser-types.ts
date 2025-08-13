import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-bytecode-info.ts';

export type MGSPrimitive = string | boolean | number;
export const isMGSPrimitive = (v: unknown): v is MGSPrimitive => {
	if (typeof v === 'string') return true;
	if (typeof v === 'number') return true;
	if (typeof v === 'boolean') return true;
	return false;
};

export class AnyNode {}

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

export class MathlangNode extends AnyNode {
	mathlang: string;
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
}

// ------------------------------ SETTINGS ------------------------------ \\

export class AddDialogSettings extends MathlangNode {
	mathlang: 'add_dialog_settings';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	targets: AddDialogSettingsTarget[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.targets ||
			!Array.isArray(args.targets) ||
			!args.targets.every((v) => v instanceof AddDialogSettingsTarget)
		) {
			throw new Error('AddDialogSettings not given valid AddDialogSettingsTarget[]');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'add_dialog_settings';
		this.targets = args.targets;
	}
	clone(prev: AddDialogSettings) {
		return new AddDialogSettings(prev.debug, prev.args);
	}
}

export class AddDialogSettingsTarget extends MathlangNode {
	mathlang: 'add_dialog_settings_target';
	args: Record<string, unknown>;
	type: string;
	debug: TYPES.MGSDebug;
	parameters: DialogParameter[];
	target?: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.parameters ||
			!Array.isArray(args.parameters) ||
			!args.parameters.every((v) => v instanceof DialogParameter)
		) {
			throw new Error('AddDialogSettingsTarget not given valid DialogParameter[]');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'add_dialog_settings_target';
		this.type = TYPES.breakIfNotString(args.type, 'AddDialogSettingsTarget type');
		this.parameters = args.parameters;
		if (typeof args.target === 'string') this.target = args.target;
	}
	clone(prev: AddDialogSettingsTarget) {
		return new AddDialogSettingsTarget(prev.debug, prev.args);
	}
}

export class AddSerialDialogSettings extends MathlangNode {
	mathlang: 'add_serial_dialog_settings';
	args: Record<string, unknown>;
	parameters: SerialDialogParameter[];
	debug: TYPES.MGSDebug;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.parameters ||
			!Array.isArray(args.parameters) ||
			!args.parameters.every((v) => v instanceof SerialDialogParameter)
		) {
			throw new Error('AddSerialDialogSettings not given valid SerialDialogParameter[]');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'add_serial_dialog_settings';
		this.parameters = args.parameters;
	}
	clone(prev: AddSerialDialogSettings) {
		return new AddSerialDialogSettings(prev.debug, prev.args);
	}
}

// ------------------------------ CONTROL ------------------------------ \\

export class ReturnStatement extends MathlangNode {
	mathlang: 'return_statement';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	constructor(debug: TYPES.MGSDebug) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'return_statement';
	}
	clone(prev: ReturnStatement) {
		return new ReturnStatement(prev.debug);
	}
}
export class ContinueStatement extends MathlangNode {
	mathlang: 'continue_statement';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	constructor(debug: TYPES.MGSDebug) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'continue_statement';
	}
	clone(prev: ContinueStatement) {
		return new ContinueStatement(prev.debug);
	}
}
export class BreakStatement extends MathlangNode {
	mathlang: 'break_statement';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	constructor(debug: TYPES.MGSDebug) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'break_statement';
	}
	clone(prev: BreakStatement) {
		return new BreakStatement(prev.debug);
	}
}

// ------------------------------ DIALOG ------------------------------ \\

export class DialogDefinition extends MathlangNode {
	mathlang: 'dialog_definition';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	dialogName: string;
	dialogs: Dialog[];
	duplicates?: DialogDefinition[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.dialogs ||
			!Array.isArray(args.dialogs) ||
			!args.dialogs.every((v) => v instanceof Dialog)
		) {
			throw new Error('DialogDefinition not given valid Dialog[]');
		}
		if (args.duplicates) {
			if (
				!Array.isArray(args.duplicates) ||
				!args.duplicates.every((v) => v instanceof DialogDefinition)
			) {
				throw new Error('DialogDefinition not given valid DialogDefinition[]');
			} else {
				this.duplicates = args.duplicates;
			}
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_definition';
		this.dialogName = TYPES.breakIfNotString(args.dialogName, 'DialogDefinition dialogName');
		this.dialogs = args.dialogs;
	}
	clone(prev: DialogDefinition) {
		return new DialogDefinition(prev.debug, prev.args);
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

export class DialogParameter extends MathlangNode {
	mathlang: 'dialog_parameter';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	property: string;
	value: MGSPrimitive;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_parameter';
		this.property = TYPES.breakIfNotString(args.property, 'DialogParameter property');
		this.value = TYPES.breakIfNotStringOrNumber(args.value, 'DialogParameter value');
	}
	clone(prev: DialogParameter) {
		return new DialogParameter(prev.debug, prev.args);
	}
}

export class Dialog extends MathlangNode {
	wrap?: number;
	emote?: number;
	entity?: string;
	name?: string;
	portrait?: string;
	alignment?: string;
	border_tileset?: string;

	mathlang: 'dialog';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;

	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.messages ||
			!Array.isArray(args.messages) ||
			!args.messages.every((v) => typeof v === 'string')
		) {
			throw new Error('Dialog not given valid messages:string[]');
		}
		if (args.options && Array.isArray(args.options)) {
			if (args.options.length && args.options.every((v) => v instanceof DialogOption)) {
				this.options = args.options;
				this.response_type = 'SELECT_FROM_SHORT_LIST';
			}
		}
		this.mathlang = 'dialog';
		this.args = args;
		this.debug = debug;
		this.messages = args.messages;
		if (typeof args.settings === 'object' && args.settings !== null) {
			Object.entries(args.settings).forEach(([k, v]) => {
				this[k] = v; // todo: this is a little bit of trust, eh?
			});
		}
	}
	clone(prev: Dialog) {
		return new DialogParameter(prev.debug, prev.args);
	}
}

export type DialogInfo = {
	identifier: DialogIdentifier;
	settings: DialogSettings;
	messages: string[];
	options: DialogOption[];
};

export class DialogIdentifier extends MathlangNode {
	mathlang: 'dialog_identifier';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	type: DialogIdentifierType;
	value: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (args.type !== 'label' && args.type !== 'entity' && args.type !== 'name') {
			throw new Error('invalid DialogIdentifier type');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_identifier';
		this.type = args.type;
		this.value = TYPES.breakIfNotString(args.value, 'DialogIdentifier value');
	}
	clone(prev: DialogIdentifier) {
		return new DialogIdentifier(prev.debug, prev.args);
	}
}
type DialogIdentifierType = 'label' | 'entity' | 'name';

export class DialogOption extends MathlangNode {
	mathlang: 'dialog_option';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	label: string;
	script: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_option';
		this.label = TYPES.breakIfNotString(args.label, 'DialogOption label');
		this.script = TYPES.breakIfNotString(args.script, 'DialogOption script');
	}
	clone(prev: DialogOption) {
		return new DialogOption(prev.debug, prev.args);
	}
}

// ------------------------------ SERIAL DIALOG ------------------------------ \\

export class SerialDialogDefinition extends MathlangNode {
	mathlang: 'serial_dialog_definition';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	dialogName: string;
	serialDialog: SerialDialog;
	duplicates?: SerialDialogDefinition[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (!(args.serialDialog instanceof SerialDialog)) {
			throw new Error('SerialDialogDefinition not given valid SerialDialog');
		}
		if (args.duplicates) {
			if (
				!Array.isArray(args.duplicates) ||
				!args.duplicates.every((v) => v instanceof SerialDialogDefinition)
			) {
				throw new Error('SerialDialogDefinition not given valid SerialDialogDefinition[]');
			} else {
				this.duplicates = args.duplicates;
			}
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_definition';
		this.dialogName = TYPES.breakIfNotString(
			args.dialogName,
			'SerialDialogDefinition dialogName',
		);
		this.serialDialog = args.serialDialog;
	}
	clone(prev: SerialDialogDefinition) {
		return new SerialDialogDefinition(prev.debug, prev.args);
	}
}

export type SerialDialogSettings = {
	wrap?: number;
};

export class SerialDialogParameter extends MathlangNode {
	mathlang: 'serial_dialog_parameter';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	property: string;
	value: MGSPrimitive;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_parameter';
		this.property = TYPES.breakIfNotString(args.property, 'SerialDialogParameter property');
		this.value = TYPES.breakIfNotStringOrNumber(args.value, 'SerialDialogParameter value');
	}
	clone(prev: SerialDialogParameter) {
		return new SerialDialogParameter(prev.debug, prev.args);
	}
}

export class SerialDialog extends MathlangNode {
	mathlang: 'serial_dialog';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;

	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (
			!args.messages ||
			!Array.isArray(args.messages) ||
			!args.messages.every((v) => typeof v === 'string')
		) {
			throw new Error('Dialog not given valid messages:string[]');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog';
		this.messages = args.messages;
		if (args.options && Array.isArray(args.options)) {
			if (args.options.length && args.options.every((v) => v instanceof SerialDialogOption)) {
				this.options = args.options;
			}
		}
		if (args.text_options && Array.isArray(args.text_options)) {
			if (
				args.text_options.length &&
				args.text_options.every((v) => v instanceof SerialDialogOption)
			) {
				this.text_options = args.text_options;
			}
		}
	}
	clone(prev: SerialDialog) {
		return new SerialDialog(prev.debug, prev.args);
	}
}

export type SerialDialogInfo = {
	settings: SerialDialogSettings;
	messages: string[];
	options: SerialDialogOption[];
};

export type SerialOptionType = 'text_options' | 'options';
export class SerialDialogOption extends MathlangNode {
	mathlang: 'serial_dialog_option';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	optionType: SerialOptionType;
	label: string;
	script: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (args.optionType !== 'text_options' && args.optionType !== 'options') {
			throw new Error('invalid option type ' + args.optionType);
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_option';
		this.optionType = args.optionType;
		this.label = TYPES.breakIfNotString(args.label, 'SerialDialogOption label');
		this.script = TYPES.breakIfNotString(args.script, 'SerialDialogOption script');
	}
	clone(prev: SerialDialogOption) {
		return new SerialDialogOption(prev.debug, prev.args);
	}
}
// ------------------------------ ONE-OFFS ------------------------------ \\

export class IncludeNode extends MathlangNode {
	mathlang: 'include_macro';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	value: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'include_macro';
		this.value = TYPES.breakIfNotString(args.value, 'IncludeNode value');
	}
	clone(prev: IncludeNode) {
		return new IncludeNode(prev.debug, prev.args);
	}
}

export class ConstantDefinition extends MathlangNode {
	mathlang: 'constant_assignment';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	label: string;
	value: string | boolean | number;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		if (!isMGSPrimitive(args.value)) throw new Error('not primitive');
		this.args = args;
		this.debug = debug;
		this.mathlang = 'constant_assignment';
		this.label = TYPES.breakIfNotString(args.label, 'ConstantDefinition label');
		this.value = args.value;
	}
	clone(prev: ConstantDefinition) {
		return new ConstantDefinition(prev.debug, prev.args);
	}
}

export class ScriptDefinition extends MathlangNode {
	mathlang: 'script_definition';
	args: Record<string, unknown>;
	debug: TYPES.MGSDebug;
	scriptName: string;
	prePrint?: string;
	testPrint?: string;
	print?: string;
	rawNodes?: AnyNode[];
	actions: AnyNode[];
	preActions?: AnyNode[];
	duplicates?: ScriptDefinition[];
	copyScriptResolved?: boolean;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'script_definition';
		this.scriptName = TYPES.breakIfNotString(args.scriptName, 'ScriptDefinition scriptName');
		if (typeof args.prePrint === 'string') this.prePrint = args.prePrint;
		if (typeof args.testPrint === 'string') this.testPrint = args.testPrint;
		if (typeof args.print === 'string') this.print = args.print;
		if (args.rawNodes) {
			if (
				!Array.isArray(args.rawNodes) ||
				!args.rawNodes.every((v) => v instanceof AnyNode)
			) {
				throw new Error('ScriptDefinition not given valid rawNodes:AnyNode[]');
			} else {
				this.rawNodes = args.rawNodes;
			}
		}
		if (args.preActions) {
			if (
				!Array.isArray(args.preActions) ||
				!args.preActions.every((v) => v instanceof AnyNode)
			) {
				throw new Error('ScriptDefinition not given valid preActions:AnyNode[]');
			} else {
				this.preActions = args.preActions;
			}
		}
		if (
			!args.actions ||
			!Array.isArray(args.actions) ||
			!args.actions.every((v) => v instanceof AnyNode)
		) {
			throw new Error('ScriptDefinition not given valid actions:AnyNode[]');
		}
		if (args.duplicates) {
			if (
				!Array.isArray(args.duplicates) ||
				!args.duplicates.every((v) => v instanceof ScriptDefinition)
			) {
				throw new Error('ScriptDefinition not given valid ScriptDefinition[]');
			} else {
				this.duplicates = args.duplicates;
			}
		}

		this.actions = args.actions;
		if (args.copyScriptResolved) this.copyScriptResolved = true;
	}
	clone(prev: ScriptDefinition) {
		return new ScriptDefinition(prev.debug, prev.args);
	}
}

export class CommentNode extends MathlangNode {
	mathlang: 'comment';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	comment: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'comment';
		this.comment = TYPES.breakIfNotString(args.comment, 'CommentNode comment');
	}
	clone(prev: CommentNode) {
		return new CommentNode(prev.debug, prev.args);
	}
}

export class LabelDefinition extends MathlangNode {
	mathlang: 'label_definition';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	label: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'label_definition';
		this.label = TYPES.breakIfNotString(args.label, 'LabelDefinition label');
	}
	clone(prev: LabelDefinition) {
		return new LabelDefinition(prev.debug, prev.args);
	}
}

export class JSONLiteral extends MathlangNode {
	mathlang: 'json_literal';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	json: [JSON];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'json_literal';
		if (!Array.isArray(args.json)) throw new Error('need array');
		this.json = args.json; // how to cleanse this?
	}
	clone(prev: JSONLiteral) {
		return new JSONLiteral(prev.debug, prev.args);
	}
}

type CopyScript = CopyMacro | TYPES.COPY_SCRIPT;
export const isAnyCopyScript = (v: unknown): v is CopyScript => {
	return v instanceof TYPES.COPY_SCRIPT || v instanceof CopyMacro;
};

export class CopyMacro extends MathlangNode {
	mathlang: 'copy_script';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	script: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'copy_script';
		this.script = TYPES.breakIfNotString(args.script, 'CopyMacro script');
	}
	clone(prev: CopyMacro) {
		return new CopyMacro(prev.debug, prev.args);
	}
}

// needs to be one unit of thing for reasons, but still contain than one thing
export class MathlangSequence extends MathlangNode {
	mathlang: 'sequence';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	type: string;
	steps: AnyNode[];
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'sequence';
		if (
			!args.steps ||
			!Array.isArray(args.steps) ||
			!args.steps.every((v) => v instanceof AnyNode)
		) {
			throw new Error('MathlangSequence not given valid AnyNode[]');
		}
		this.type = TYPES.breakIfNotString(args.type, 'MathlangSequence type');
		this.steps = args.steps;

		if (!(this.steps[0] instanceof CommentNode)) {
			// TODO: the condition might catch other, non-sequence comments tho?
			const innerComment = debug.node.text.replace(/[\n\s\t]+/g, ' ');
			const comment = `${args.type}: ${innerComment}`;
			const mathlangComment = new CommentNode(debug, { comment });
			this.steps.unshift(mathlangComment);
		}

		const flatSteps: AnyNode[] = [];
		this.steps.forEach((v) => {
			if (v instanceof MathlangSequence) {
				flatSteps.push(...v.steps);
			} else {
				flatSteps.push(v);
			}
		});
		this.steps = flatSteps;
	}
	clone(prev: MathlangSequence) {
		return new MathlangSequence(prev.debug, prev.args);
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

export class IntGetable extends MathlangNode {
	mathlang: 'int_getable';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	field: string;
	entity: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'int_getable';
		this.field = TYPES.breakIfNotString(args.field, 'IntGetable field');
		this.entity = TYPES.breakIfNotString(args.entity, 'IntGetable entity');
	}
	clone(prev: IntGetable) {
		return new IntGetable(prev.debug, prev.args);
	}
}

export class IntBinaryExpression extends MathlangNode {
	mathlang: 'int_binary_expression';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	lhs: IntExpression;
	rhs: IntExpression;
	op: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'int_binary_expression';
		if (!isIntExpression(args.lhs)) {
			throw new Error('IntBinaryExpression LHS not IntExpression');
		}
		if (!isIntExpression(args.rhs)) {
			throw new Error('IntBinaryExpression RHS not IntExpression');
		}
		this.lhs = args.lhs;
		this.rhs = args.rhs;
		this.op = TYPES.breakIfNotString(args.op, 'IntBinaryExpression op');
	}
	clone(prev: IntBinaryExpression) {
		return new IntBinaryExpression(prev.debug, prev.args);
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
	return v instanceof TYPES.BoolGetable || (v as TYPES.BoolGetable)?.mathlang === 'bool_getable'; // todo remove?
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

export class BoolBinaryExpression extends MathlangNode {
	mathlang: 'bool_binary_expression';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	lhs: BoolExpression;
	rhs: BoolExpression;
	op: string;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'bool_binary_expression';
		if (!isBoolExpression(args.lhs)) throw new Error('not BoolExpression');
		if (!isBoolExpression(args.rhs)) throw new Error('not BoolExpression');
		if (!(args.lhsNode instanceof TreeSitterNode)) throw new Error('not TSNode');
		if (!(args.rhsNode instanceof TreeSitterNode)) throw new Error('not TSNode');
		this.op = TYPES.breakIfNotString(args.op, 'BoolBinaryExpression op');
		this.lhs = args.lhs;
		this.rhs = args.rhs;
		this.lhsNode = args.lhsNode;
		this.rhsNode = args.rhsNode;
	}
	clone(prev: BoolBinaryExpression) {
		return new BoolBinaryExpression(prev.debug, prev.args);
	}
	// TODO: make invert function?
}

// ------------------------------ INTERMEDIATES ------------------------------ \\

export class BoolSetable extends MathlangNode {
	mathlang: 'bool_setable';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'bool_setable';
		this.value = TYPES.breakIfNotString(args.value, 'BoolSetable value');
		this.type = TYPES.breakIfNotString(args.type, 'BoolSetable type');
	}
	clone(prev: BoolSetable) {
		return new BoolSetable(prev.debug, prev.args);
	}
}
export class MovableIdentifier extends MathlangNode {
	mathlang: 'movable_identifier';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'movable_identifier';
		this.value = TYPES.breakIfNotString(args.value, 'MovableIdentifier value');
		this.type = TYPES.breakIfNotString(args.type, 'MovableIdentifier type');
	}
	clone(prev: MovableIdentifier) {
		return new MovableIdentifier(prev.debug, prev.args);
	}
}
export class CoordinateIdentifier extends MathlangNode {
	mathlang: 'coordinate_identifier';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	type: string;
	value: string;
	polygonType?: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'coordinate_identifier';
		this.value = TYPES.breakIfNotString(args.value, 'CoordinateIdentifier value');
		this.type = TYPES.breakIfNotString(args.type, 'CoordinateIdentifier type');
		if (args.polygonType)
			this.polygonType = TYPES.breakIfNotString(
				args.polygonType,
				'CoordinateIdentifier polygonType',
			);
	}
	clone(prev: CoordinateIdentifier) {
		return new CoordinateIdentifier(prev.debug, prev.args);
	}
}
export class DirectionTarget extends MathlangNode {
	mathlang: 'direction_target';
	debug: TYPES.MGSDebug;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: TYPES.MGSDebug, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'direction_target';
		this.value = TYPES.breakIfNotString(args.value, 'DirectionTarget value');
		this.type = TYPES.breakIfNotString(args.type, 'DirectionTarget type');
	}
	clone(prev: DirectionTarget) {
		return new DirectionTarget(prev.debug, prev.args);
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
	if (!(v instanceof MathlangNode)) return false; // todo: load bearing?
	if (v instanceof TYPES.GotoLabel) return true;
	if (v instanceof TYPES.BoolGetable) return true;
	if (v instanceof TYPES.StringCheckable) return true;
	if (v instanceof TYPES.NumberComparison) return true;
	if (v instanceof TYPES.NumberCheckableEquality) return true;
	return false;
};
