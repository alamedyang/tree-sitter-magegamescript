import { Node as TreeSitterNode } from 'web-tree-sitter';
import { FileState } from './parser-file.ts';
import * as ACTION from './parser-bytecode-info.ts';

export class AnyNode {}
export const cloneNode = (node: AnyNode) => {
	if (node instanceof MathlangNode) return node.clone();
	if (node instanceof ACTION.Action) return ACTION.summonActionConstructor(node);
	throw new Error('need to know how to clone third type of node apparently');
};
export class MathlangNode extends AnyNode {
	mathlang: string;
	args: Record<string, unknown>;
	debug: MathlangLocation;
	clone() {
		return this.constructor(MathlangNode);
	}
	print() {
		return `// MATHLANG: ${this.mathlang}`;
	}
}

export type MGSPrimitive = string | boolean | number;
export const isMGSPrimitive = (v: unknown): v is MGSPrimitive => {
	if (typeof v === 'string') return true;
	if (typeof v === 'number') return true;
	if (typeof v === 'boolean') return true;
	return false;
};

export class MathlangLocation {
	f?: FileState;
	node: TreeSitterNode;
	fileName: string;
	comment?: string;
	constructor(f: FileState, node: TreeSitterNode, comment?: string) {
		this.f = f;
		this.fileName = f.fileName;
		this.node = node;
		if (comment) this.comment = comment;
	}
}

// TODO redo this part
export type MGSLocation = {
	node: TreeSitterNode;
	fileName?: string;
};
export type MathlangMessage = {
	// error or warning
	locations: MathlangLocation[];
	message: string;
	footer?: string;
};

const truncate = (s: string, n: number): string => {
	const orig = s.replace(/\n/g, ' ');
	return s.length > n + 3 ? orig.slice(0, n) + '...' : orig;
};

// ------------------------------ SETTINGS ------------------------------ \\

export class AddDialogSettings extends MathlangNode {
	mathlang: 'add_dialog_settings';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	targets: AddDialogSettingsTarget[];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
	clone() {
		return new AddDialogSettings(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, targets: AddDialogSettingsTarget[]) {
		return new AddDialogSettings(debug, { targets });
	}
}

export class AddDialogSettingsTarget extends MathlangNode {
	mathlang: 'add_dialog_settings_target';
	args: Record<string, unknown>;
	type: string;
	debug: MathlangLocation;
	parameters: DialogParameter[];
	target?: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
		this.type = ACTION.breakIfNotString(args.type);
		this.parameters = args.parameters;
		if (typeof args.target === 'string') this.target = args.target;
	}
	clone() {
		return new AddDialogSettingsTarget(this.debug, this.args);
	}
	static quick(
		debug: MathlangLocation,
		type: string,
		parameters: DialogParameter[],
		target?: string,
	) {
		return new AddDialogSettingsTarget(debug, {
			type,
			parameters,
			target,
		});
	}
}

export class AddSerialDialogSettings extends MathlangNode {
	mathlang: 'add_serial_dialog_settings';
	args: Record<string, unknown>;
	parameters: SerialDialogParameter[];
	debug: MathlangLocation;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
	clone() {
		return new AddSerialDialogSettings(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, parameters: SerialDialogParameter[]) {
		return new AddSerialDialogSettings(debug, {
			parameters,
		});
	}
}

// ------------------------------ CONTROL ------------------------------ \\

export class ReturnStatement extends MathlangNode {
	mathlang: 'return_statement';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	constructor(debug: MathlangLocation) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'return_statement';
	}
	clone() {
		return new ReturnStatement(this.debug);
	}
}
export class ContinueStatement extends MathlangNode {
	mathlang: 'continue_statement';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	constructor(debug: MathlangLocation) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'continue_statement';
	}
	clone() {
		return new ContinueStatement(this.debug);
	}
}
export class BreakStatement extends MathlangNode {
	mathlang: 'break_statement';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	constructor(debug: MathlangLocation) {
		super();
		this.args = {};
		this.debug = debug;
		this.mathlang = 'break_statement';
	}
	clone() {
		return new BreakStatement(this.debug);
	}
}

export class GotoLabel extends MathlangNode {
	mathlang: 'goto_label';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	label: string;
	comment?: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'goto_label';
		this.label = ACTION.breakIfNotString(args.label);
		if (typeof args.comment === 'string') this.comment = args.comment;
	}
	clone() {
		return new GotoLabel(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, label: string) {
		return new GotoLabel(debug, { label });
	}
	print() {
		return `${ACTION.printGotoSegment(this)};`;
	}
}

// ------------------------------ DIALOG ------------------------------ \\

export class DialogDefinition extends MathlangNode {
	mathlang: 'dialog_definition';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	dialogName: string;
	dialogs: Dialog[];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		if (
			!args.dialogs ||
			!Array.isArray(args.dialogs) ||
			!args.dialogs.every((v) => v instanceof Dialog)
		) {
			throw new Error('DialogDefinition not given valid Dialog[]');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_definition';
		this.dialogName = ACTION.breakIfNotString(args.dialogName);
		this.dialogs = args.dialogs;
	}
	clone() {
		return new DialogDefinition(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, dialogName: string, dialogs: Dialog[]) {
		return new DialogDefinition(debug, { dialogName, dialogs });
	}
	print() {
		const truncated = truncate(this.dialogs[0].messages[0], 40);
		return `// auto dialog: "${truncated}"`;
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
	debug: MathlangLocation;
	property: string;
	value: MGSPrimitive;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_parameter';
		this.property = ACTION.breakIfNotString(args.property);
		this.value = ACTION.breakIfNotStringOrNumber(args.value);
	}
	clone() {
		return new DialogParameter(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, property: string, value: string | number) {
		return new DialogParameter(debug, { property, value });
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
	debug: MathlangLocation;
	args: Record<string, unknown>;

	messages: string[];
	response_type?: 'SELECT_FROM_SHORT_LIST';
	options?: DialogOption[];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
	clone() {
		return new DialogParameter(this.debug, this.args);
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
	debug: MathlangLocation;
	type: DialogIdentifierType;
	value: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		if (args.type !== 'label' && args.type !== 'entity' && args.type !== 'name') {
			throw new Error('invalid DialogIdentifier type');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_identifier';
		this.type = args.type;
		this.value = ACTION.breakIfNotString(args.value);
	}
	clone() {
		return new DialogIdentifier(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, type: string, value: string) {
		return new DialogIdentifier(debug, { type, value });
	}
}
type DialogIdentifierType = 'label' | 'entity' | 'name';

export class DialogOption extends MathlangNode {
	mathlang: 'dialog_option';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	label: string;
	script: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'dialog_option';
		this.label = ACTION.breakIfNotString(args.label);
		this.script = ACTION.breakIfNotString(args.script);
	}
	clone() {
		return new DialogOption(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, label: string, script: string) {
		return new DialogOption(debug, {
			label,
			script,
		});
	}
}

// ------------------------------ SERIAL DIALOG ------------------------------ \\

export class SerialDialogDefinition extends MathlangNode {
	mathlang: 'serial_dialog_definition';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	dialogName: string;
	serialDialog: SerialDialog;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		if (!(args.serialDialog instanceof SerialDialog)) {
			throw new Error('SerialDialogDefinition not given valid SerialDialog');
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_definition';
		this.dialogName = ACTION.breakIfNotString(args.dialogName);
		this.serialDialog = args.serialDialog;
	}
	clone() {
		return new SerialDialogDefinition(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, dialogName: string, serialDialog: SerialDialog) {
		return new SerialDialogDefinition(debug, { dialogName, serialDialog });
	}
	print() {
		const truncated = truncate(this.serialDialog.messages[0], 40);
		return `// auto serial_dialog: "${truncated}"`;
	}
}

export type SerialDialogSettings = {
	wrap?: number;
};

export class SerialDialogParameter extends MathlangNode {
	mathlang: 'serial_dialog_parameter';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	property: string;
	value: MGSPrimitive;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_parameter';
		this.property = ACTION.breakIfNotString(args.property);
		this.value = ACTION.breakIfNotStringOrNumber(args.value);
	}
	clone() {
		return new SerialDialogParameter(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, property: string, value: string | number) {
		return new SerialDialogParameter(debug, { property, value });
	}
}

export class SerialDialog extends MathlangNode {
	mathlang: 'serial_dialog';
	debug: MathlangLocation;
	args: Record<string, unknown>;

	messages: string[];
	options?: SerialDialogOption[];
	text_options?: SerialDialogOption[];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
	clone() {
		return new SerialDialog(this.debug, this.args);
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
	debug: MathlangLocation;
	optionType: SerialOptionType;
	label: string;
	script: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		if (args.optionType !== 'text_options' && args.optionType !== 'options') {
			throw new Error('invalid option type ' + args.optionType);
		}
		this.args = args;
		this.debug = debug;
		this.mathlang = 'serial_dialog_option';
		this.optionType = args.optionType;
		this.label = ACTION.breakIfNotString(args.label);
		this.script = ACTION.breakIfNotString(args.script);
	}
	clone() {
		return new SerialDialogOption(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, optionType: string, label: string, script: string) {
		return new SerialDialogOption(debug, {
			optionType,
			label,
			script,
		});
	}
}
// ------------------------------ ONE-OFFS ------------------------------ \\

export class IncludeNode extends MathlangNode {
	mathlang: 'include_macro';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	value: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'include_macro';
		this.value = ACTION.breakIfNotString(args.value);
	}
	clone() {
		return new IncludeNode(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, value: string) {
		return new IncludeNode(debug, { value });
	}
}

export class ConstantDefinition extends MathlangNode {
	mathlang: 'constant_assignment';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	label: string;
	value: string | boolean | number;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		if (!isMGSPrimitive(args.value)) throw new Error('not primitive');
		this.args = args;
		this.debug = debug;
		this.mathlang = 'constant_assignment';
		this.label = ACTION.breakIfNotString(args.label);
		this.value = args.value;
	}
	clone() {
		return new ConstantDefinition(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, label: string, value: string | boolean | number) {
		return new ConstantDefinition(debug, { label, value });
	}
}

export class ScriptDefinition extends MathlangNode {
	mathlang: 'script_definition';
	args: Record<string, unknown>;
	debug: MathlangLocation;
	scriptName: string;
	prePrint?: string;
	testPrint?: string;
	printed?: string;
	rawNodes?: AnyNode[];
	actions: AnyNode[];
	preActions?: AnyNode[];
	copyScriptResolved?: boolean;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'script_definition';
		this.scriptName = ACTION.breakIfNotString(args.scriptName);
		if (typeof args.prePrint === 'string') this.prePrint = args.prePrint;
		if (typeof args.testPrint === 'string') this.testPrint = args.testPrint;
		if (typeof args.printed === 'string') this.printed = args.printed;
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

		this.actions = args.actions;
		if (args.copyScriptResolved) this.copyScriptResolved = true;
	}
	clone() {
		const clone = new ScriptDefinition(this.debug, this.args);
		clone.actions = clone.actions.map((v) => cloneNode(v));
		if (clone.rawNodes) {
			clone.rawNodes = clone.rawNodes.map((v) => cloneNode(v));
		}
		if (clone.preActions) {
			clone.preActions = clone.preActions.map((v) => cloneNode(v));
		}
		return clone;
	}
}

export class CommentNode extends MathlangNode {
	mathlang: 'comment';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	comment: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'comment';
		this.comment = ACTION.breakIfNotString(args.comment);
	}
	clone() {
		return new CommentNode(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, comment: string) {
		return new CommentNode(debug, { comment });
	}
	print() {
		const truncated = truncate(this.comment, 70);
		return `// ${truncated}`;
	}
}

export class LabelDefinition extends MathlangNode {
	mathlang: 'label_definition';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	label: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'label_definition';
		this.label = ACTION.breakIfNotString(args.label);
	}
	clone() {
		return new LabelDefinition(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, label: string) {
		return new LabelDefinition(debug, { label });
	}
	print() {
		return `${ACTION.sanitizeLabel(this.label)}:`;
	}
}

export class JSONLiteral extends MathlangNode {
	mathlang: 'json_literal';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	json: [JSON];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'json_literal';
		if (!Array.isArray(args.json)) throw new Error('need array');
		this.json = JSON.parse(JSON.stringify(args.json));
	}
	clone() {
		return new JSONLiteral(this.debug, this.args);
	}
}

export class CopyMacro extends MathlangNode {
	mathlang: 'copy_script';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	script: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'copy_script';
		this.script = ACTION.breakIfNotString(args.script);
	}
	clone() {
		return new CopyMacro(this.debug, this.args);
	}
	print() {
		return `copy!("${this.script}")`;
	}
}

// needs to be one unit of thing for reasons, but still contain than one thing
export class MathlangSequence extends MathlangNode {
	mathlang: 'sequence';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	type: string;
	steps: AnyNode[];
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
		this.type = ACTION.breakIfNotString(args.type);
		this.steps = args.steps;

		if (!(this.steps[0] instanceof CommentNode)) {
			// TODO: the condition might catch other, non-sequence comments tho?
			const innerComment = debug.node.text.replace(/[\n\s\t]+/g, ' ');
			const comment = `${args.type}: ${innerComment}`;
			const mathlangComment = CommentNode.quick(debug, comment);
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
	clone() {
		return new MathlangSequence(this.debug, this.args);
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
	debug: MathlangLocation;
	args: Record<string, unknown>;
	field: string;
	entity: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'int_getable';
		this.field = ACTION.breakIfNotString(args.field);
		this.entity = ACTION.breakIfNotString(args.entity);
	}
	clone() {
		return new IntGetable(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, entity: string, field: string) {
		return new IntGetable(debug, { entity, field });
	}
}

export class IntBinaryExpression extends MathlangNode {
	mathlang: 'int_binary_expression';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	lhs: IntExpression;
	rhs: IntExpression;
	op: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
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
		this.op = ACTION.breakIfNotString(args.op);
	}
	clone() {
		return new IntBinaryExpression(this.debug, this.args);
	}
}

// ------------------------------ BOOL EXPRESSIONS ------------------------------ \\

export type BoolExpression = BoolComparison | BoolBinaryExpression | BoolUnit;
export const isBoolExpression = (v: unknown): v is BoolExpression => {
	return isBoolComparison(v) || v instanceof BoolBinaryExpression || isBoolUnit(v);
};

export type BoolUnit = boolean | string | ACTION.BoolGetable;
export const isBoolUnit = (v: unknown): v is BoolUnit => {
	if (typeof v === 'string') return true;
	if (typeof v === 'boolean') return true;
	return (
		v instanceof ACTION.BoolGetable || (v as ACTION.BoolGetable)?.mathlang === 'bool_getable'
	); // todo remove?
};

export type BoolComparison =
	| ACTION.NumberCheckableEquality
	| ACTION.StringCheckable
	| ACTION.NumberComparison;
export const isBoolComparison = (v: unknown): v is BoolComparison => {
	if (v instanceof ACTION.NumberCheckableEquality) return true;
	if (v instanceof ACTION.StringCheckable) return true;
	if (v instanceof ACTION.NumberComparison) return true;
	return false;
};

export class BoolBinaryExpression extends MathlangNode {
	mathlang: 'bool_binary_expression';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	lhs: BoolExpression;
	rhs: BoolExpression;
	op: string;
	lhsNode: TreeSitterNode;
	rhsNode: TreeSitterNode;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'bool_binary_expression';
		if (!isBoolExpression(args.lhs)) throw new Error('not BoolExpression');
		if (!isBoolExpression(args.rhs)) throw new Error('not BoolExpression');
		if (!(args.lhsNode instanceof TreeSitterNode)) throw new Error('not TSNode');
		if (!(args.rhsNode instanceof TreeSitterNode)) throw new Error('not TSNode');
		this.op = ACTION.breakIfNotString(args.op);
		this.lhs = args.lhs;
		this.rhs = args.rhs;
		this.lhsNode = args.lhsNode;
		this.rhsNode = args.rhsNode;
	}
	clone() {
		return new BoolBinaryExpression(this.debug, this.args);
	}
	// TODO: make invert function?
}

// ------------------------------ INTERMEDIATES ------------------------------ \\

export class BoolSetable extends MathlangNode {
	mathlang: 'bool_setable';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'bool_setable';
		this.value = ACTION.breakIfNotString(args.value);
		this.type = ACTION.breakIfNotString(args.type);
	}
	clone() {
		return new BoolSetable(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, type: string, value: string) {
		return new BoolSetable(debug, { type, value });
	}
}
export class MovableIdentifier extends MathlangNode {
	mathlang: 'movable_identifier';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'movable_identifier';
		this.value = ACTION.breakIfNotString(args.value);
		this.type = ACTION.breakIfNotString(args.type);
	}
	clone() {
		return new MovableIdentifier(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, type: string, value: string) {
		return new MovableIdentifier(debug, { type, value });
	}
}
export class CoordinateIdentifier extends MathlangNode {
	mathlang: 'coordinate_identifier';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	type: string;
	value: string;
	polygonType?: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'coordinate_identifier';
		this.value = ACTION.breakIfNotString(args.value);
		this.type = ACTION.breakIfNotString(args.type);
		if (args.polygonType) this.polygonType = ACTION.breakIfNotString(args.polygonType);
	}
	clone() {
		return new CoordinateIdentifier(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, type: string, value: string, polygonType?: string) {
		return new CoordinateIdentifier(debug, { type, value, polygonType });
	}
}
export class DirectionTarget extends MathlangNode {
	mathlang: 'direction_target';
	debug: MathlangLocation;
	args: Record<string, unknown>;
	type: string;
	value: string;
	constructor(debug: MathlangLocation, args: Record<string, unknown>) {
		super();
		this.args = args;
		this.debug = debug;
		this.mathlang = 'direction_target';
		this.value = ACTION.breakIfNotString(args.value);
		this.type = ACTION.breakIfNotString(args.type);
	}
	clone() {
		return new DirectionTarget(this.debug, this.args);
	}
	static quick(debug: MathlangLocation, type: string, value: string) {
		return new DirectionTarget(debug, { type, value });
	}
}
// --------------------- Mathlang Nodes with labels --------------------- \\

export type MathlangNodeWithLabel =
	| GotoLabel
	| ACTION.BoolGetable
	| ACTION.StringCheckable
	| ACTION.NumberComparison
	| ACTION.NumberCheckableEquality;

export const doesMathlangHaveLabelToChangeToIndex = (v: unknown): v is MathlangNodeWithLabel => {
	if (!(v instanceof MathlangNode)) return false; // todo: load bearing?
	if (v instanceof GotoLabel) return true;
	if (v instanceof ACTION.BoolGetable) return true;
	if (v instanceof ACTION.StringCheckable) return true;
	if (v instanceof ACTION.NumberComparison) return true;
	if (v instanceof ACTION.NumberCheckableEquality) return true;
	return false;
};
