import { Node as TreeSitterNode } from 'web-tree-sitter';
import { type FileState } from './parser-file.ts';
import {
	ConditionalBlock,
	reportMissingChildNodes,
	reportErrorNodes,
	debugLog,
	expandBoolExpression,
	autoIdentifierName,
	newElse,
	ifChainMaker,
	simpleBranchMaker,
	quickTemporary,
	autoDebug,
} from './parser-utilities.ts';

import { buildSerialDialogFromInfo, buildDialogFromInfo } from './parser-dialogs.ts';

import {
	handleCapture,
	captureForFieldName,
	optionalTextForFieldName,
	textForFieldName,
	capturesForFieldName,
	stringCaptureForFieldName,
	numberCaptureForFieldName,
	checkVariable,
	mandatoryChildForFieldName,
	handleChildrenForFieldName,
	handleNamedChildren,
} from './parser-capture.ts';
import { changeVarByValue, handleAction } from './parser-actions.ts';
import {
	isActionNode,
	type CopyMacro,
	type AnyNode,
	type LabelDefinition,
	type MGSMessage,
	type AddDialogSettings,
	type MathlangSequence,
	type DialogInfo,
	type IncludeNode,
	type AddDialogSettingsTarget,
	type DialogSettings,
	type AddSerialDialogSettings,
	type SerialDialogOption,
	type SerialOptionType,
	type DialogOption,
	type DialogDefinition,
	type SerialDialogDefinition,
	type SerialDialogInfo,
	type SerialDialog,
	type Dialog,
	type ScriptDefinition,
	isMGSPrimitive,
	isDialogParameter,
	type ConstantDefinition,
	type JSONLiteral,
	isAddDialogSettingsTarget,
	isSerialDialogOption,
	isDialogOption,
	isSerialDialog,
	isDialog,
	isSerialDialogParameter,
	isDialogIdentifier,
	isBoolExpression,
	type GotoLabel,
	isMathlangSequence,
	isReturnStatement,
	isContinueStatement as isContinueStatement,
	isBreakStatement as isBreakStatement,
	isJSONLiteral,
	newLabelDefinition,
	newGotoLabel,
	newSequence,
	newSerialDialogDefinition,
	newDialogDefinition,
	newCheckSaveFlag,
	newScriptDefinition,
	newConstantDefinition,
	newIncludeNode,
	newAddDialogSettings,
	newAddSerialDialogSettings,
	type BoolGetable,
} from './parser-types.ts';
import {
	type RUN_SCRIPT,
	type CheckAction,
	type GOTO_ACTION_INDEX,
	isCheckAction,
	type SHOW_SERIAL_DIALOG,
} from './parser-bytecode-info.ts';

export const handleNode = (f: FileState, node: TreeSitterNode): AnyNode[] => {
	debugLog(`handleNode: ${node.grammarType}`);

	// Tree-sitter does not (?) report these on its own; we have to seek them each time
	reportMissingChildNodes(f, node);
	reportErrorNodes(f, node);

	// Actions are their own beast and are handled elsewhere
	if (node.grammarType.startsWith('action_')) {
		return handleAction(f, node);
	}

	// Look up the handler function
	const nodeFn = nodeFns[node.grammarType];
	if (!nodeFn) {
		throw new Error('no parser-node function for ' + node.grammarType);
	}

	// Do it
	const ret = nodeFn(f, node);
	return ret;
};

const includeRecursion: string[] = [];

// These must return an array, because they might produce multiple things (or zero things)
// NOTICE: The caller should flat() what it receives!
const nodeFns = {
	line_comment: () => [],
	block_comment: () => [],
	semicolon: () => [],
	ERROR: (f: FileState, node: TreeSitterNode): [] => {
		const err: MGSMessage = {
			locations: [{ node }],
			message: 'syntax error',
		};
		// I guess feel free to add more of these as they come up
		// This might be the only place some of them can be detected
		// (This is only for nodes so malformed that tree-sitter can't tell what they are)
		if (node.namedChildren.some((v) => v?.grammarType === 'over_time_operator')) {
			err.message = `malformed 'do over time' expression`;
			err.footer =
				`should take the form '@movable -> @coordinate over @duration [forever];'\n` +
				`   @movable = (player | self | entity @string) position | camera\n` +
				`   @coordinate = (player | self | entity @string) position | geometry @string (origin | length)`;
		}
		f.newError(err);
		return [];
	},
	script_definition: (f: FileState, node: TreeSitterNode): [ScriptDefinition] => {
		const name = stringCaptureForFieldName(f, node, 'script_name');
		const rawActions: AnyNode[] = handleNamedChildren(f, node.lastChild || node);
		const actions: AnyNode[] = [];
		// flatten sequences
		rawActions.forEach((raw) => {
			if (isMathlangSequence(raw)) {
				raw.steps.forEach((step) => actions.push(step));
			} else if (isJSONLiteral(raw)) {
				raw.json.forEach((obj) => {
					if (isActionNode(obj)) {
						actions.push(obj);
					} else {
						f.newError({
							message: 'invalid JSON action: ' + JSON.stringify(obj),
							locations: [{ node: raw.debug.node }],
						});
					}
				});
			} else {
				actions.push(raw);
			}
		});
		// add auto return label
		const returnLabel = 'end of script ' + f.p.advanceGotoSuffix();
		const lastChild = node.lastChild;
		if (!lastChild) throw new Error('could not find final node in script block');
		const labelAction: LabelDefinition = newLabelDefinition(f, lastChild, returnLabel);
		actions.push(labelAction);
		// change all return statements to goto labels
		actions.forEach((action, i) => {
			if (isReturnStatement(action)) {
				actions[i] = newGotoLabel(f, action.debug.node, returnLabel);
			}
		});
		return [newScriptDefinition(f, node, name, actions)];
	},
	constant_assignment: (f: FileState, node: TreeSitterNode): ConstantDefinition[] => {
		const label = textForFieldName(f, node, 'label');
		const value = captureForFieldName(f, node, 'value');
		if (!isMGSPrimitive(value)) {
			const valueNode = node.childForFieldName('value');
			f.newError({
				message: `constant value not an MGS primitive (${label})`,
				locations: [{ node: valueNode || node }],
			});
			return [];
		}
		if (f.constants[label]) {
			f.newError({
				locations: [{ node }],
				message: `cannot redefine constant ${label}`,
			});
		}
		f.constants[label] = {
			debug: autoDebug(f, node),
			value,
		};
		return [newConstantDefinition(f, node, label, value)];
	},
	include_macro: (f: FileState, node: TreeSitterNode): IncludeNode[] => {
		// Recursion detection
		if (includeRecursion.includes(f.fileName)) {
			includeRecursion.push(f.fileName);
			throw new Error(
				`include_macro recursion\n       ${includeRecursion.join('\n       -> ')}`,
			);
		}
		includeRecursion.push(f.fileName);
		const fileName = stringCaptureForFieldName(f, node, 'fileName');
		if (!f.p.fileMap[fileName].parsed) {
			debugLog(`include_macro: must first parse prerequesite "${fileName}"`);
			f.p.parseFile(fileName);
		} else {
			debugLog(`include_macro: prerequesite "${fileName}" already parsed`);
		}
		debugLog(`include_macro: merging ${fileName} into ${f.fileName}...`);

		// INCLUDE FILE
		const newFile = f.p.fileMap[fileName].parsed;
		if (!newFile) throw new Error(`missing file to include: ${fileName}`);
		// add their constants to us
		Object.keys(newFile.constants).forEach((constantName) => {
			if (f.constants[constantName]) {
				f.newError({
					message: `cannot redefine constant ${constantName} (via 'include')`,
					locations: [
						{
							fileName: newFile.fileName,
							node: newFile.constants[constantName].debug.node,
						},
					],
				});
			}
			f.constants[constantName] = newFile.constants[constantName];
		});
		// add their actual node entries to us (might help debugging)
		newFile.nodes.forEach((node) => {
			f.nodes.push(node);
		});
		// add (serial) dialog settings
		['default', 'serial'].forEach((type) => {
			Object.keys(newFile.settings[type]).forEach((param) => {
				f.settings[type][param] = newFile.settings[type][param];
			});
		});
		// ...some of which are extra layered
		['entity', 'label'].forEach((type) => {
			Object.keys(newFile.settings[type]).forEach((target) => {
				const params = Object.keys(newFile.settings[type][target]);
				f.settings[type][target] = f.settings[type][target] || {};
				params.forEach((param) => {
					f.settings[type][target][param] = newFile.settings[type][target][param];
					// (I apologize for this)
				});
			});
		});
		includeRecursion.pop();
		return [newIncludeNode(f, node, fileName)];
	},
	rand_macro: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const horizontal: AnyNode[][] = [];
		// count items per spread
		let spreadCount = -Infinity;
		node.namedChildren
			.filter((v) => v !== null)
			.forEach((innerNode) => {
				const actions: AnyNode[] = handleNode(f, innerNode);
				const len = actions.length;
				if (len === 0) return; // empties are ignored
				horizontal.push(actions);
				if (len === 1) return; // singles are passed through
				if (spreadCount === -Infinity) spreadCount = len;
				if (spreadCount !== len) {
					f.newError({
						locations: [{ node: innerNode }],
						message: `spreads inside rand!() must contain same number of items`,
					});
				}
			});
		// tilt the other direction
		// [{a:1},{a:2}], [{b:3}], [{c:4},{c:5}] ->
		// [{a:1},{b:3},{c:4}], [{a:2},{b:3},{c:5}]
		const vertical: AnyNode[][] = [];
		for (let i = 0; i < spreadCount; i++) {
			const insert = horizontal.map((arr) => {
				return arr[i % arr.length];
			});
			vertical.push(insert);
		}
		// slices -> if chain
		const temp = quickTemporary();
		const iffs: ConditionalBlock[] = vertical.map((body, i) => {
			return {
				condition: checkVariable(f, node, temp, i, '=='),
				debug: autoDebug(f, node),
				body,
			};
		});
		const sequence: MathlangSequence = ifChainMaker(f, node, iffs, [], 'rand_macro');
		sequence.steps.unshift(changeVarByValue(temp, vertical.length, '?')); // the RNG roll
		return [sequence];
	},
	label_definition: (f: FileState, node: TreeSitterNode): [LabelDefinition] => {
		const label = textForFieldName(f, node, 'label');
		return [newLabelDefinition(f, node, label)];
	},
	add_dialog_settings: (f: FileState, node: TreeSitterNode): [AddDialogSettings] => {
		const targets = handleNamedChildren(f, node);
		if (!targets.every(isAddDialogSettingsTarget)) {
			throw new Error('add_dialog_settings node not a AddDialogSettingsTarget');
		}
		return [newAddDialogSettings(f, node, targets)];
	},
	add_dialog_settings_target: (f: FileState, node: TreeSitterNode): [AddDialogSettingsTarget] => {
		let settingsTarget: DialogSettings = {};
		const type = textForFieldName(f, node, 'type');
		const ret: AddDialogSettingsTarget = {
			mathlang: 'add_dialog_settings_target',
			debug: autoDebug(f, node),
			type,
		};
		// figure out which settings target it is
		if (type === 'default') {
			settingsTarget = f.settings.default;
		} else if (type === 'label' || type === 'entity') {
			const target = stringCaptureForFieldName(f, node, 'target');
			f.settings[type][target] = f.settings[type][target] || {};
			settingsTarget = f.settings[type][target];
			ret.target = target;
		} else {
			throw new Error(`unknown target type: ${type}`);
		}
		// find the settings themselves
		const parameters = capturesForFieldName(f, node, 'dialog_parameter');
		if (!parameters.every(isDialogParameter)) {
			throw new Error('not every dialog_parameter is a DialogParameter');
		}
		parameters.forEach((param) => {
			settingsTarget[param.property] = param.value;
		});
		ret.parameters = parameters;
		return [ret];
	},
	add_serial_dialog_settings: (f: FileState, node: TreeSitterNode): [AddSerialDialogSettings] => {
		const parameters = capturesForFieldName(f, node, 'serial_dialog_parameter');
		if (!parameters.every(isSerialDialogParameter)) {
			throw new Error('not every serial_dialog_parameter is a SerialDialogParameter');
		}
		parameters.forEach((param) => {
			f.settings.serial[param.property] = param.value;
		});
		return [newAddSerialDialogSettings(f, node, parameters)];
	},
	serial_dialog_option: (f: FileState, node: TreeSitterNode): [SerialDialogOption] => {
		const optionChar = textForFieldName(f, node, 'option_type');
		let optionType: SerialOptionType = 'options';
		if (optionChar === '_') optionType = 'text_options';
		else if (optionChar !== '#') throw new Error('invalid option type: ' + optionChar);
		return [
			{
				mathlang: 'serial_dialog_option',
				optionType,
				label: stringCaptureForFieldName(f, node, 'label'),
				debug: autoDebug(f, node),
				script: stringCaptureForFieldName(f, node, 'script'),
			},
		];
	},
	dialog_option: (f: FileState, node: TreeSitterNode): [DialogOption] => {
		return [
			{
				mathlang: 'dialog_option',
				debug: autoDebug(f, node),
				label: stringCaptureForFieldName(f, node, 'label'),
				script: stringCaptureForFieldName(f, node, 'script'),
			},
		];
	},
	serial_dialog_definition: (f: FileState, node: TreeSitterNode): [SerialDialogDefinition] => {
		const serialDialogNode = mandatoryChildForFieldName(f, node, 'serial_dialog');
		const name = stringCaptureForFieldName(f, node, 'serial_dialog_name');
		const serialDialog = handleNode(f, serialDialogNode);
		if (serialDialog.length !== 1) {
			throw new Error('serial dialogs must have only 1 serial dialog');
		}
		if (!isSerialDialog(serialDialog[0])) throw new Error('missing serial dialog');
		return [newSerialDialogDefinition(f, node, name, serialDialog[0])];
	},
	dialog_definition: (f: FileState, node: TreeSitterNode): [DialogDefinition] => {
		const dialogName = stringCaptureForFieldName(f, node, 'dialog_name');
		const dialogs = handleChildrenForFieldName(f, node, 'dialog');
		if (!dialogs.every(isDialog)) throw new Error('not every dialog is a Dialog');
		return [newDialogDefinition(f, node, dialogName, dialogs)];
	},
	serial_dialog: (f: FileState, node: TreeSitterNode): [SerialDialog] => {
		const settings = {};
		const params = capturesForFieldName(f, node, 'serial_dialog_parameter');
		if (!params.every(isSerialDialogParameter)) {
			throw new Error('not every serial dialog parameter is a SerialDialogParameter');
		}
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		// TODO: make options more closely resemble final form?
		const options = handleChildrenForFieldName(f, node, 'serial_dialog_option');
		if (!options.every(isSerialDialogOption)) {
			throw new Error('not every serial dialog option not aSerialDialogOption');
		}
		const messages = capturesForFieldName(f, node, 'serial_message');
		if (!messages.every((v) => typeof v === 'string')) {
			throw new Error('not every message is a string');
		}
		const info: SerialDialogInfo = {
			settings,
			messages,
			options,
		};
		const serialDialog = buildSerialDialogFromInfo(f, info);
		return [serialDialog];
	},
	dialog: (f: FileState, node: TreeSitterNode): [Dialog] => {
		// Identifier
		const identifier = captureForFieldName(f, node, 'dialog_identifier');
		if (!isDialogIdentifier(identifier)) {
			throw new Error('dialog_identifier is not a DialogIdentifier');
		}
		// Settings
		const settings = {};
		const params = capturesForFieldName(f, node, 'dialog_parameter');
		if (!params.every(isDialogParameter)) {
			throw new Error('not every dialog_parameter is a DialogParameter');
		}
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		// Messages
		const messageN = node.childrenForFieldName('message');
		const messages = messageN.map((v) => handleCapture(f, v));
		if (!messages.every((v) => typeof v === 'string')) {
			throw new Error('not every dialog_message is a string');
		}
		// Options
		const options = handleChildrenForFieldName(f, node, 'dialog_option');
		if (!options.every(isDialogOption)) {
			throw new Error('not every dialog_option is a DialogOption');
		}
		// Build it
		const info: DialogInfo = {
			identifier,
			settings,
			messages,
			options,
		};
		const dialogs = buildDialogFromInfo(f, info, messageN);
		return [
			{
				...dialogs,
				debug: autoDebug(f, node),
			},
		];
	},
	json_literal: (f: FileState, node: TreeSitterNode): JSONLiteral[] => {
		// TODO: do it more by hand so that errors can be reported more accurately?
		const jsonNode = node.namedChildren[0];
		if (!jsonNode) throw new Error('could not find JSON node');
		const text = jsonNode.text;
		try {
			const parsed = JSON.parse(text);
			return [
				{
					mathlang: 'json_literal',
					debug: autoDebug(f, node),
					json: parsed,
				},
			];
		} catch {
			f.newError({
				locations: [{ node }],
				message: `JSON syntax error`,
				footer: `Generic error. Check trailing commas!`,
			});
		}
		return [];
	},
	copy_macro: (f: FileState, node: TreeSitterNode): [CopyMacro] => {
		return [
			{
				mathlang: 'copy_script',
				debug: autoDebug(f, node),
				script: stringCaptureForFieldName(f, node, 'script'),
			},
		];
	},
	debug_macro: (f: FileState, node: TreeSitterNode): AnyNode[] => {
		const ret: AnyNode[] = [];
		let name = '';
		const serialDialogNode = node.childForFieldName('serial_dialog');
		if (serialDialogNode) {
			const serialDialog = handleNode(f, serialDialogNode);
			if (!isSerialDialog(serialDialog[0])) {
				throw new Error('serial dialog not a SerialDialog');
			}
			name = autoIdentifierName(f, node);
			ret.push(newSerialDialogDefinition(f, node, name, serialDialog[0]));
		} else {
			// might just be the name of a serial dialog, and not a serial-dialog-in-place
			name = stringCaptureForFieldName(f, node, 'serial_dialog_name');
		}
		const condition: BoolGetable = {
			mathlang: 'bool_getable',
			action: 'CHECK_DEBUG_MODE',
			expected_bool: true,
		};
		const ifTrue: SHOW_SERIAL_DIALOG = {
			action: 'SHOW_SERIAL_DIALOG',
			disable_newline: false,
			serial_dialog: name,
		};
		const action = simpleBranchMaker(f, node, condition, [ifTrue], []);
		ret.push(action);
		return ret;
	},
	looping_block: (f: FileState, node: TreeSitterNode, printGotoLabel: string): AnyNode[] => {
		return handleNamedChildren(f, node).map((v) => {
			if (Array.isArray(v)) return v;
			if (isContinueStatement(v)) {
				return newGotoLabel(f, v.debug.node, `condition #${printGotoLabel}`);
			} else if (isBreakStatement(v)) {
				return newGotoLabel(f, v.debug.node, `rendezvous #${printGotoLabel}`);
			}
			return v;
		});
	},
	while_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const block = new ConditionalBlock(f, node, 'while');
		const n = f.p.advanceGotoSuffix();
		const conditionL = `while condition #${n}`;
		const bodyL = `while body #${n}`;
		const rendezvousL = `while rendezvous #${n}`;
		const steps = [
			newLabelDefinition(f, block.conditionNode || node, conditionL),
			...expandBoolExpression(f, block.conditionNode || node, block.condition, bodyL),
			newGotoLabel(f, node, rendezvousL),
			newLabelDefinition(f, block.bodyNode || node, bodyL),
			...block.body,
			newGotoLabel(f, block.conditionNode || node, conditionL),
			newLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'parser-node: while_block')];
	},
	do_while_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const doWhyle = new ConditionalBlock(f, node, 'do while');
		const n = f.p.advanceGotoSuffix();
		const conditionL = `do while condition #${n}`;
		const bodyL = `do while body #${n}`;
		const rendezvousL = `do while rendezvous #${n}`;
		const steps = [
			newLabelDefinition(f, doWhyle.bodyNode || node, bodyL),
			...doWhyle.body,
			newLabelDefinition(f, doWhyle.conditionNode || node, conditionL),
			...expandBoolExpression(f, doWhyle.conditionNode || node, doWhyle.condition, bodyL),
			newLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'parser-node: do_while_block')];
	},
	for_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `for condition #${n}`;
		const bodyL = `for body #${n}`;
		const rendezvousL = `for rendezvous #${n}`;
		const continueL = `for continue #${n}`;
		const conditionN = mandatoryChildForFieldName(f, node, 'condition');
		const condition = handleCapture(f, conditionN);
		if (!isBoolExpression(condition)) throw new Error('invalid condition');
		const bodyN = mandatoryChildForFieldName(f, node, 'body');
		const incrementerN = mandatoryChildForFieldName(f, node, 'incrementer');
		const body: AnyNode[] = handleNode(f, bodyN).map((v: AnyNode) => {
			if (isContinueStatement(v)) return newGotoLabel(f, node, continueL);
			if (isBreakStatement(v)) return newGotoLabel(f, node, rendezvousL);
			return v;
		});
		const initializer = mandatoryChildForFieldName(f, node, 'initializer');
		const steps: AnyNode[] = [
			...handleNode(f, initializer),
			newLabelDefinition(f, conditionN, conditionL),
			...expandBoolExpression(f, conditionN, condition, bodyL),
			newGotoLabel(f, node, rendezvousL),
			newLabelDefinition(f, bodyN, bodyL),
			...body,
			newLabelDefinition(f, incrementerN, continueL),
			...handleNode(f, incrementerN),
			newGotoLabel(f, conditionN, conditionL),
			newLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'parser-node: for_block')];
	},
	if_single: (
		f: FileState,
		node: TreeSitterNode,
	): (CheckAction | GotoLabel | GOTO_ACTION_INDEX | RUN_SCRIPT)[] => {
		// for parsing the bytecode output; not really meant to be seen in the wild
		// e.g. `if varName then goto label LABELNAME;`
		// vs `if (varName) { /*do stuff at the label destination*/ }`
		const type = optionalTextForFieldName(f, node, 'type');
		const conditionN = node.childForFieldName('condition');
		let condition = handleCapture(f, conditionN);
		if (typeof condition === 'string') {
			condition = newCheckSaveFlag(f, node, condition, true);
		}
		if (typeof condition === 'boolean') {
			if (!type) {
				const script = stringCaptureForFieldName(f, node, 'script');
				return condition ? [{ action: 'RUN_SCRIPT', script }] : [];
			} else if (type === 'index') {
				const index = numberCaptureForFieldName(f, node, 'index');
				return condition ? [{ action: 'GOTO_ACTION_INDEX', action_index: index }] : [];
			} else if (type === 'label') {
				const label = stringCaptureForFieldName(f, node, 'label');
				return condition ? [newGotoLabel(f, node, label)] : [];
			}
		}
		if (isCheckAction(condition)) {
			if (!type) {
				condition.success_script = stringCaptureForFieldName(f, node, 'script');
			} else if (type === 'index') {
				condition.jump_index = numberCaptureForFieldName(f, node, 'index');
			} else if (type === 'label') {
				condition.label = stringCaptureForFieldName(f, node, 'label');
			}
			return [condition];
		}
		throw new Error('invalid if_single');
	},
	if_chain: (f: FileState, node: TreeSitterNode): AnyNode[] => {
		const ifNodes = node.childrenForFieldName('if_block').filter((v) => v !== null);
		const iffs = ifNodes.map((v) => new ConditionalBlock(f, v, 'if'));
		const elseNode = node.childForFieldName('else_block');
		const elseBody = newElse(f, elseNode);
		return [ifChainMaker(f, node, iffs, elseBody, 'if_chain')];
	},
};

// TODO: what is the difference between handleNode() and handleCapture() except that you have to flatten handleNode()?
// Is it that you return complex thing vs primitive value?
// Is it that action wants to call handleCapture() and then work on its properties?
// It is, perhaps, that handleCapture() should check values against registered constants, and nodes shouldn't care about that
