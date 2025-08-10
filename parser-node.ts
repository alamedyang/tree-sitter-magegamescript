import { Node as TreeSitterNode } from 'web-tree-sitter';
import { type FileState } from './parser-file.ts';
import {
	reportMissingChildNodes,
	reportErrorNodes,
	debugLog,
	expandCondition,
	makeLabelDefinition,
	makeGotoLabel,
	simpleBranchMaker,
	newSequence,
	newSerialDialog,
	showSerialDialog,
	newTemporary,
	dropTemporary,
	autoIdentifierName,
	newDialog,
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
} from './parser-capture.ts';
import { handleAction } from './parser-actions.ts';
import {
	isActionNode,
	type BoolComparison,
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
	isContinueStatement,
	isBreakStatement,
	isJSONLiteral,
	isGotoLabel,
} from './parser-types.ts';
import {
	type RUN_SCRIPT,
	type CheckAction,
	type GOTO_ACTION_INDEX,
	isCheckAction,
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
		// (This is only for nodes so malformed that tree-sitter can't tell what it is)
		// TODO: test that this is reachable
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
		// error nodes are caught above
		const rawActions: AnyNode[] = (node.lastChild?.namedChildren || [])
			.map((v) => {
				if (v === null) throw new Error('');
				return handleNode(f, v);
			})
			.flat();
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
						throw new Error('not a JSON action: ' + JSON.stringify(obj));
					}
				});
			} else {
				actions.push(raw);
			}
		});
		// add auto return destination
		// (this should be done prior to copy!(), but after flattening sequences)
		const returnLabel = 'end of script ' + f.p.advanceGotoSuffix();
		const lastChild = node.lastChild;
		if (!lastChild) throw new Error('should be a node');
		const labelAction: LabelDefinition = makeLabelDefinition(f, lastChild, returnLabel);
		actions.push(labelAction);
		actions.forEach((action, i) => {
			if (isActionNode(action)) {
				return;
			}
			if (isReturnStatement(action)) {
				actions[i] = makeGotoLabel(f, action.debug.node, returnLabel);
			}
		});
		return [
			{
				mathlang: 'script_definition',
				scriptName: name,
				actions,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	constant_assignment: (f: FileState, node: TreeSitterNode): [ConstantDefinition] => {
		const label = textForFieldName(f, node, 'label');
		const value = captureForFieldName(f, node, 'value');
		if (!isMGSPrimitive(value)) {
			throw new Error(`constant value not an MGS primitive (${label})`);
		}
		if (f.constants[label]) {
			f.newError({
				locations: [{ node }],
				message: `cannot redefine constant ${label}`,
			});
		}
		f.constants[label] = {
			value,
			debug: {
				node,
				fileName: f.fileName,
			},
		};
		return [
			{
				mathlang: 'constant_assignment',
				label,
				value,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
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
		// todo: Should this use the spread macro? Or should it be limited to actions?
		const rawFileNames = captureForFieldName(f, node, 'fileName');
		const fileNames = Array.isArray(rawFileNames) ? rawFileNames : [rawFileNames];
		if (!fileNames.every((v) => typeof v === 'string')) {
			throw new Error('include_macro prerequisites not all strings');
		}
		fileNames.forEach((prereqName) => {
			if (!f.p.fileMap[prereqName].parsed) {
				debugLog(`include_macro: must first parse prerequesite "${prereqName}"`);
				f.p.parseFile(prereqName);
			} else {
				debugLog(`include_macro: prerequesite "${prereqName}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereqName} into ${f.fileName}...`);

			// INCLUDE FILE
			const newFile = f.p.fileMap[prereqName].parsed;
			if (!newFile) throw new Error(`Missing file to include: ${prereqName}`);
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
		});
		return fileNames.map((fileName: string) => ({
			mathlang: 'include_macro',
			value: fileName,
			debug: {
				node,
				fileName: f.fileName,
			},
		}));
	},
	rand_macro: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const horizontal: AnyNode[][] = [];
		let multipleCount = -Infinity;
		node.namedChildren.forEach((innerNode) => {
			if (!innerNode) throw new Error('found null tree-sitter node in rand_macro');
			const handled: AnyNode[] = handleNode(f, innerNode);
			const len = handled.length;
			if (len === 0) return; // empties are ignored
			horizontal.push(handled);
			// count how much it spread
			if (len === 1) return; // singles are fine wherever
			if (multipleCount === -Infinity) multipleCount = len;
			if (multipleCount !== len) {
				f.newError({
					locations: [{ node: innerNode }],
					message: `spreads inside rand!() must contain same number of items`,
				});
			}
		});
		const vertical: AnyNode[][] = [];
		for (let i = 0; i < multipleCount; i++) {
			const insert = horizontal.map((unit) => {
				return unit[i % unit.length];
			});
			vertical.push(insert);
		}
		// put the slices into a sequence
		const temporary = newTemporary();
		const steps: AnyNode[] = [
			{
				action: 'MUTATE_VARIABLE',
				operation: 'RNG',
				value: vertical.length,
				variable: temporary,
			},
		];
		let bottomSteps: AnyNode[] = [];
		const rendezvousL = `rendezvous #${f.p.getGotoSuffix()}`;
		// TODO: why not use the "make quick if-else" function for this?
		vertical.forEach((body, i) => {
			const ifL = `if #${f.p.advanceGotoSuffix()}`;
			// add top half
			const condition: BoolComparison = {
				mathlang: 'bool_comparison',
				action: 'CHECK_VARIABLE',
				variable: temporary,
				value: i,
				comparison: '==',
				expected_bool: true,
				label: ifL,
				debug: {
					node,
					fileName: f.fileName,
				},
			};
			steps.push(condition);
			// add bottom half
			const bottomInsert: AnyNode[] = [
				makeLabelDefinition(f, node, ifL),
				...body,
				makeGotoLabel(f, node, rendezvousL),
			];
			bottomSteps = bottomInsert.concat(bottomSteps);
		});
		dropTemporary();
		const combined = steps.concat(bottomSteps);
		combined.push(makeLabelDefinition(f, node, rendezvousL));
		return [newSequence(f, node, combined, 'rand macro')];
	},
	label_definition: (f: FileState, node: TreeSitterNode): [LabelDefinition] => {
		const text = textForFieldName(f, node, 'label');
		return [makeLabelDefinition(f, node, text)];
	},
	add_dialog_settings: (f: FileState, node: TreeSitterNode): [AddDialogSettings] => {
		const targets = node.namedChildren
			.map((child) => {
				if (child === null) throw new Error('found null child node in add_dialog_settings');
				return handleNode(f, child);
			})
			.flat();
		if (!targets.every(isAddDialogSettingsTarget)) {
			throw new Error('Dialog Settings Target node not a dialog settings target');
		}
		return [
			{
				mathlang: 'add_dialog_settings',
				targets,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	add_dialog_settings_target: (f: FileState, node: TreeSitterNode): [AddDialogSettingsTarget] => {
		let settingsTarget: DialogSettings = {};
		const type = textForFieldName(f, node, 'type');
		const ret: AddDialogSettingsTarget = {
			mathlang: 'add_dialog_settings_target',
			type,
			debug: {
				node,
				fileName: f.fileName,
			},
		};
		// figure out which settings we're adding to (the "target")
		if (type === 'default') {
			settingsTarget = f.settings.default;
		} else if (type === 'label' || type === 'entity') {
			const target = stringCaptureForFieldName(f, node, 'target');
			f.settings[type][target] = f.settings[type][target] || {};
			settingsTarget = f.settings[type][target];
			ret.target = target;
		} else {
			throw new Error(`Unknown dialog settings target type: ${type}`);
		}
		// find the settings themselves
		const parameters = capturesForFieldName(f, node, 'dialog_parameter');
		if (!parameters.every(isDialogParameter)) {
			throw new Error('Not every capture is the thing');
		}
		parameters.forEach((param) => {
			settingsTarget[param.property] = param.value;
		});
		ret.parameters = parameters;
		return [ret];
	},
	add_serial_dialog_settings: (f: FileState, node: TreeSitterNode): [AddSerialDialogSettings] => {
		// This one is inconsistent with the others?
		const parameters = capturesForFieldName(f, node, 'serial_dialog_parameter');
		if (!parameters.every(isSerialDialogParameter)) {
			throw new Error('every serial dialog parameter not of the correct type');
		}
		parameters.forEach((param) => {
			f.settings.serial[param.property] = param.value;
		});
		return [
			{
				mathlang: 'add_serial_dialog_settings',
				parameters,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	// TODO: move these to parser-capture, so we can use capturesForFieldName() to get them
	serial_dialog_option: (f: FileState, node: TreeSitterNode): [SerialDialogOption] => {
		const optionChar = textForFieldName(f, node, 'option_type');
		let optionType: SerialOptionType = 'options';
		if (optionChar === '_') optionType = 'text_options';
		else if (optionChar !== '#') throw new Error('invalid option type');
		return [
			{
				mathlang: 'serial_dialog_option',
				optionType,
				label: stringCaptureForFieldName(f, node, 'label'),
				script: stringCaptureForFieldName(f, node, 'script'),
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	dialog_option: (f: FileState, node: TreeSitterNode): [DialogOption] => {
		return [
			{
				mathlang: 'dialog_option',
				label: stringCaptureForFieldName(f, node, 'label'),
				script: stringCaptureForFieldName(f, node, 'script'),
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	serial_dialog_definition: (f: FileState, node: TreeSitterNode): [SerialDialogDefinition] => {
		const serialDialogNode = node.childForFieldName('serial_dialog');
		if (serialDialogNode === null) throw new Error('node not found');
		const name = stringCaptureForFieldName(f, node, 'serial_dialog_name');
		const serialDialog = handleNode(f, serialDialogNode);
		if (serialDialog.length !== 1) throw new Error('');
		if (!isSerialDialog(serialDialog[0])) throw new Error('');
		return [newSerialDialog(f, node, name, serialDialog[0])];
	},
	dialog_definition: (f: FileState, node: TreeSitterNode): [DialogDefinition] => {
		const dialogName = stringCaptureForFieldName(f, node, 'dialog_name');
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = dialogNodes
			.map((v) => {
				if (v === null) throw new Error('missing node');
				return handleNode(f, v);
			})
			.flat();
		if (!dialogs.every(isDialog)) throw new Error('');
		return [newDialog(f, node, dialogName, dialogs)];
	},
	serial_dialog: (f: FileState, node: TreeSitterNode): [SerialDialog] => {
		const settings = {};
		const params = capturesForFieldName(f, node, 'serial_dialog_parameter');
		if (!params.every(isSerialDialogParameter)) throw new Error();
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		// TODO: make options more closely resemble final form?
		const options = node
			.childrenForFieldName('serial_dialog_option')
			.map((v) => {
				if (v === null) throw new Error('missing node');
				return handleNode(f, v);
			})
			.flat();
		if (!options.every(isSerialDialogOption)) {
			throw new Error('invalid option');
		}
		const messages = capturesForFieldName(f, node, 'serial_message');
		if (!messages.every((v) => typeof v === 'string')) throw new Error('Pff');
		const info: SerialDialogInfo = {
			settings,
			messages,
			options,
		};
		const serialDialog = buildSerialDialogFromInfo(f, info);
		return [serialDialog];
	},
	dialog: (f: FileState, node: TreeSitterNode): [Dialog] => {
		const settings = {};
		const params = capturesForFieldName(f, node, 'dialog_parameter');
		if (!params.every(isDialogParameter)) throw new Error();
		const messageN = node.childrenForFieldName('message');
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		const options = node
			.childrenForFieldName('dialog_option')
			.map((v) => {
				if (v === null) throw new Error('missing node');
				return handleNode(f, v);
			})
			.flat();
		if (!options.every(isDialogOption)) {
			throw new Error('invalid option');
		}
		const identifier = captureForFieldName(f, node, 'dialog_identifier');
		if (!isDialogIdentifier(identifier)) throw new Error('asdf');
		const messages = messageN.map((v) => handleCapture(f, v));
		if (!messages.every((v) => typeof v === 'string')) throw new Error('Pff');
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
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	json_literal: (f: FileState, node: TreeSitterNode): JSONLiteral[] => {
		// todo: do it more by hand so that errors can be reported more accurately?
		const jsonNode = node.namedChildren[0];
		if (!jsonNode) throw new Error('json node not found??');
		const text = jsonNode.text;
		try {
			const parsed = JSON.parse(text);
			return [
				{
					mathlang: 'json_literal',
					json: parsed,
					debug: {
						node,
						fileName: f.fileName,
					},
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
				script: stringCaptureForFieldName(f, node, 'script'),
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	debug_macro: (f: FileState, node: TreeSitterNode): AnyNode[] => {
		const ret: AnyNode[] = [];
		let name = '';
		const serialDialogNode = node.childForFieldName('serial_dialog');
		if (serialDialogNode) {
			const serialDialog = handleNode(f, serialDialogNode).flat();
			if (!isSerialDialog(serialDialog[0])) throw new Error();
			name = autoIdentifierName(f, node);
			ret.push(newSerialDialog(f, node, name, serialDialog[0]));
		} else {
			// todo: did I copy-pasta this? Why is this here?
			name = stringCaptureForFieldName(f, node, 'serial_dialog_name');
		}
		const action = simpleBranchMaker(
			f,
			node,
			{ action: 'CHECK_DEBUG_MODE', expected_bool: true },
			[showSerialDialog(f, node, name)],
			[],
		);
		ret.push(action);
		return ret;
	},
	looping_block: (f: FileState, node: TreeSitterNode, printGotoLabel: string): AnyNode[] => {
		return node.namedChildren
			.map((v) => {
				if (!v) throw new Error('TS');
				const handled = handleNode(f, v);
				if (Array.isArray(handled)) return handled;
				if (isContinueStatement(handled)) {
					return makeGotoLabel(f, v, `while condition #${printGotoLabel}`);
				} else if (isBreakStatement(handled)) {
					return makeGotoLabel(f, v, `while rendezvous #${printGotoLabel}`);
				}
				return handled;
			})
			.flat();
	},
	while_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `while condition #${n}`;
		const bodyL = `while body #${n}`;
		const rendezvousL = `while rendezvous #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const condition = handleCapture(f, conditionN);
		if (!isBoolExpression(condition)) throw new Error('not a condition');
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const body = handleNode(f, bodyN)
			.flat()
			.map((v) => {
				if (isContinueStatement(v)) {
					return makeGotoLabel(f, node, conditionL);
				} else if (isBreakStatement(v)) {
					return makeGotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const steps = [
			makeLabelDefinition(f, conditionN, conditionL),
			...expandCondition(f, conditionN, condition, bodyL),
			makeGotoLabel(f, node, rendezvousL),
			makeLabelDefinition(f, bodyN, bodyL),
			...body,
			makeGotoLabel(f, conditionN, conditionL),
			makeLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'while sequence')];
	},
	do_while_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `do while condition #${n}`;
		const bodyL = `do while body #${n}`;
		const rendezvousL = `do while rendezvous #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const condition = handleCapture(f, conditionN);
		if (!isBoolExpression(condition)) throw new Error('not a condition');
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const body = handleNode(f, bodyN)
			.flat()
			.map((v) => {
				if (isContinueStatement(v)) {
					return makeGotoLabel(f, node, conditionL);
				} else if (isBreakStatement(v)) {
					return makeGotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const steps = [
			makeLabelDefinition(f, bodyN, bodyL),
			...body,
			makeLabelDefinition(f, conditionN, conditionL),
			...expandCondition(f, conditionN, condition, bodyL),
			makeLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'do-while sequence')];
	},
	for_block: (f: FileState, node: TreeSitterNode): [MathlangSequence] => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `for condition #${n}`;
		const bodyL = `for body #${n}`;
		const rendezvousL = `for rendezvous #${n}`;
		const continueL = `for continue #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const condition = handleCapture(f, conditionN);
		if (!isBoolExpression(condition)) throw new Error('not a condition');
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const incrementerN = node.childForFieldName('incrementer');
		if (!incrementerN) throw new Error('TS');
		const body: AnyNode[] = handleNode(f, bodyN)
			.flat()
			.map((v: AnyNode) => {
				if (isContinueStatement(v)) {
					return makeGotoLabel(f, node, continueL);
				} else if (isBreakStatement(v)) {
					return makeGotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const initializer = node.childForFieldName('initializer');
		if (initializer === null) throw new Error('missing initializer');
		const steps: AnyNode[] = [
			...handleNode(f, initializer),
			makeLabelDefinition(f, conditionN, conditionL),
			...expandCondition(f, conditionN, condition, bodyL),
			makeGotoLabel(f, node, rendezvousL),
			makeLabelDefinition(f, bodyN, bodyL),
			...body,
			makeLabelDefinition(f, incrementerN, continueL),
			...handleNode(f, incrementerN),
			makeGotoLabel(f, conditionN, conditionL),
			makeLabelDefinition(f, node, rendezvousL),
		];
		return [newSequence(f, node, steps, 'for sequence')];
	},
	if_single: (
		f: FileState,
		node: TreeSitterNode,
	): (CheckAction | GotoLabel | GOTO_ACTION_INDEX | RUN_SCRIPT)[] => {
		const conditionN = node.childForFieldName('condition');
		// simple condition: bool_comparison, bool_unary, bool_getable, bool, string
		let condition = handleCapture(f, conditionN);
		if (!isBoolExpression(condition)) throw new Error('');
		const type = optionalTextForFieldName(f, node, 'type');
		if (condition === null) throw new Error('lol waht');
		if (condition === undefined) throw new Error('lol waht');
		if (typeof condition === 'number') throw new Error('lol waht');
		if (typeof condition === 'string') {
			condition = {
				mathlang: 'bool_getable',
				action: 'CHECK_SAVE_FLAG',
				expected_bool: true,
				save_flag: condition,
			};
		}
		if (!type) {
			const script = stringCaptureForFieldName(f, node, 'script');
			if (typeof condition === 'boolean') {
				return condition ? [{ action: 'RUN_SCRIPT', script }] : [];
			}
			const ret = {
				...condition,
				success_script: script,
			};
			if (!isCheckAction(ret)) throw new Error('pls');
			return [ret];
		} else if (type === 'index') {
			const index = numberCaptureForFieldName(f, node, 'index');
			if (typeof condition === 'boolean') {
				return condition ? [{ action: 'GOTO_ACTION_INDEX', action_index: index }] : [];
			}
			const ret = {
				...condition,
				jump_index: index,
			};
			if (!isCheckAction(ret)) throw new Error('pls');
			return [ret];
		} else if (type === 'label') {
			const label = stringCaptureForFieldName(f, node, 'label');
			if (typeof condition === 'boolean') {
				return condition ? [makeGotoLabel(f, node, label)] : [];
			}
			const ret = {
				...condition,
				label,
			};
			if (!isCheckAction(ret)) throw new Error('pls');
			return [ret];
		}
		throw new Error('Unreachable?');
	},
	if_chain: (f: FileState, node: TreeSitterNode): [AnyNode] => {
		const ifs = node.childrenForFieldName('if_block');
		const elzeN = node.childForFieldName('else_block');
		if (!ifs) throw new Error('I know, I got it');
		if (ifs.length === 1 && !elzeN) {
			const ifsZero = ifs[0];
			if (!ifsZero) throw new Error('srsly');
			const conditionN = ifsZero.childForFieldName('condition');
			let condition = handleCapture(f, conditionN);
			if (!isBoolExpression(condition)) throw new Error('');
			const bodyN = ifsZero.childForFieldName('body');
			if (!bodyN) throw new Error('srsly');
			const body = bodyN.namedChildren
				.map((v) => {
					if (v === null) throw new Error();
					return handleNode(f, v);
				})
				.flat();
			if (body.length === 1 && typeof condition === 'string') {
				if (isActionNode(body[0]) && body[0].action === 'RUN_SCRIPT') {
					if (typeof condition === 'string') {
						condition = {
							mathlang: 'bool_getable',
							action: 'CHECK_SAVE_FLAG',
							expected_bool: true,
							save_flag: condition,
						};
					}
					condition.success_script = body[0].script;
					return [condition];
				} else if (isGotoLabel(body[0])) {
					if (typeof condition === 'string') {
						condition = {
							mathlang: 'bool_getable',
							action: 'CHECK_SAVE_FLAG',
							expected_bool: true,
							save_flag: condition,
						};
					}
					condition.label = body[0].label;
					return [condition];
				}
			}
		}
		const rendezvousL: string = `rendezvous #${f.p.advanceGotoSuffix()}`;
		const steps: AnyNode[] = [];
		let bottomSteps: AnyNode[] = [];
		ifs.forEach((iff) => {
			if (!iff) throw new Error('TS');
			const ifL = `if true #${f.p.advanceGotoSuffix()}`;
			const conditionN = iff.childForFieldName('condition');
			if (!conditionN) throw new Error('TS');
			const condition = handleCapture(f, conditionN);
			if (!isBoolExpression(condition)) throw new Error('not a condition');
			const bodyN = iff.childForFieldName('body');
			if (!bodyN) throw new Error('TS');
			const body = bodyN.namedChildren
				.map((v) => {
					if (v === null) throw new Error();
					return handleNode(f, v);
				})
				.flat();
			// add top half
			expandCondition(f, conditionN, condition, ifL).forEach((v) => steps.push(v));
			// add bottom half
			const bottomInsert: AnyNode[] = [
				makeLabelDefinition(f, bodyN, ifL),
				...body,
				makeGotoLabel(f, bodyN, rendezvousL),
			];
			bottomSteps = bottomInsert.concat(bottomSteps);
		});
		if (elzeN && elzeN.lastChild) {
			steps.push(
				...elzeN.lastChild.namedChildren
					.map((v) => {
						if (v === null) throw new Error();
						return handleNode(f, v);
					})
					.flat(),
				// gotoLabel(f, node, rendezvousLabel),
			);
		}
		steps.push(makeGotoLabel(f, node, rendezvousL));
		const combined = steps.concat(bottomSteps);
		combined.push(makeLabelDefinition(f, node, rendezvousL));
		return [newSequence(f, node, combined, 'if sequence')];
	},
};

// TODO: what is the difference between handleNode() and handleCapture() except that you have to flatten handleNode()?
// Is it that you return complex thing vs primitive value?
// Is it that action wants to call handleCapture() and then work on its properties?
// It is, perhaps, that handleCapture() should check values against registered constants, and nodes shouldn't care about that
