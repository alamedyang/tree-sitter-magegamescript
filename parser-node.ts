import {
	reportMissingChildNodes,
	reportErrorNodes,
	debugLog,
	expandCondition,
	label,
	gotoLabel,
	simpleBranchMaker,
	newSequence,
	newSerialDialog,
	showSerialDialog,
	newTemporary,
	dropTemporary,
	autoIdentifierName,
} from './parser-utilities.ts';

import { buildSerialDialogFromInfo, buildDialogFromInfo } from './parser-dialogs.ts';

import {
	handleCapture,
	captureForFieldName,
	textForFieldName,
	capturesForFieldName,
} from './parser-capture.ts';
import { handleAction } from './parser-actions.ts';
import {
	isNodeAction,
	type MathlangBoolComparison,
	type MathlangCopyMacro,
	type AnyNode,
	type LabelDefinitionNode,
	type MGSMessage,
	type AddDialogSettingsNode,
	type MathlangSerialDialogParameter,
	type MathlangSequence,
} from './parser-types.ts';
import { Node } from 'web-tree-sitter';
import { type FileState } from './parser-file.ts';

export const handleNode = (f, node) => {
	// ->[]
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
		f.newError({
			locations: [{ node }],
			message: 'no parser-node function for ' + node.grammarType,
		});
		return [];
	}

	// Do it
	const ret = nodeFn(f, node);
	return ret;
};

// // Cyclic dependency bodge!
// handleActionsInit(handleNode);

// These must return an array, because they might produce multiple things (or zero things)
// NOTICE: The caller should flat() what it receives!
const nodeFns = {
	line_comment: () => [],
	block_comment: () => [],
	semicolon: () => [],
	ERROR: (f: FileState, node: Node) => {
		const err: MGSMessage = {
			locations: [{ node }],
			message: 'syntax error',
		};
		// I guess feel free to add more of these as they come up
		// This might be the only place some of them can be detected
		// (This is only for nodes so malformed that tree-sitter can't tell what it is)
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
	script_definition: (f: FileState, node: Node) => {
		const name = captureForFieldName(f, node, 'script_name');
		// error nodes are caught above
		const rawActions: AnyNode[] = (node.lastChild?.namedChildren || [])
			.map((v) => handleNode(f, v))
			.flat();
		const actions: AnyNode[] = [];
		// flatten sequences
		rawActions.forEach((raw) => {
			if (!isNodeAction(raw) && raw.mathlang === 'sequence') {
				raw.steps.forEach((step) => actions.push(step));
			} else if (!isNodeAction(raw) && raw.mathlang === 'json_literal') {
				if (!Array.isArray(raw.json)) throw new Error('JSON should be []');
				raw.json.forEach((obj) => actions.push(obj));
			} else {
				actions.push(raw);
			}
		});
		// add auto return destination
		// (this should be done prior to copy!(), but after flattening sequences)
		const returnLabel = 'end of script ' + f.p.advanceGotoSuffix();
		const lastChild = node.lastChild;
		if (!lastChild) throw new Error('should be a node');
		const labelAction: LabelDefinitionNode = label(f, lastChild, returnLabel);
		actions.push(labelAction);
		actions.forEach((action, i) => {
			if (isNodeAction(action)) {
				return;
			}
			if (action.mathlang === 'return_statement') {
				actions[i] = gotoLabel(f, action.debug.node, returnLabel);
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
	constant_assignment: (f: FileState, node: Node) => {
		const label = textForFieldName(f, node, 'label');
		const value = captureForFieldName(f, node, 'value');
		f.constants = f.constants || {};
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
	include_macro: (f: FileState, node: Node) => {
		// TODO: ~~handle~~ prevent recursive references
		const fileName = captureForFieldName(f, node, 'fileName');
		const prerequesites = Array.isArray(fileName) ? fileName : [fileName];
		prerequesites.forEach((prereqName) => {
			if (!f.p.fileMap[prereqName].parsed) {
				debugLog(`include_macro: must first parse prerequesite "${prereqName}"`);
				f.p.parseFile(prereqName);
			} else {
				debugLog(`include_macro: prerequesite "${prereqName}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereqName} into ${f.fileName}...`);
			f.includeFile(prereqName); // incorporate their crawl state into us
		});
		return [
			{
				mathlang: 'include_macro',
				value: fileName,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	rand_macro: (f: FileState, node: Node) => {
		const horizontal: AnyNode[][] = [];
		let multipleCount = -Infinity;
		node.namedChildren.forEach((innerNode) => {
			if (!innerNode) throw new Error('TS');
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
		vertical.forEach((body, i) => {
			const ifL = `if #${f.p.advanceGotoSuffix()}`;
			// add top half
			const condition: MathlangBoolComparison = {
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
				label(f, node, ifL),
				...body,
				gotoLabel(f, node, rendezvousL),
			];
			bottomSteps = bottomInsert.concat(bottomSteps);
		});
		dropTemporary();
		const combined = steps.concat(bottomSteps);
		combined.push(label(f, node, rendezvousL));
		return [newSequence(f, node, combined, 'rand macro')];
	},
	label_definition: (f, node) => label(f, node, textForFieldName(f, node, 'label')),
	add_dialog_settings: (f, node) => {
		const targets = node.namedChildren
			.map((child) => handleNode(f, child)) // add_dialog_settings_target
			.flat();
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
	add_dialog_settings_target: (f, node) => {
		let settingsTarget;
		const type = textForFieldName(f, node, 'type');
		const ret: AddDialogSettingsNode = {
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
			const target = captureForFieldName(f, node, 'target');
			if (target !== undefined) {
				f.settings[type][target] = f.settings[type][target] || {};
				settingsTarget = f.settings[type][target];
				ret.target = target;
			} else {
				f.newError({
					locations: [{ node }],
					message: `dialog_settings_target: malformed ${type} definition`,
				});
			}
		} else {
			throw new Error(`Unknown dialog settings target type: ${type}`);
		}
		// find the settings themselves
		const parameters = capturesForFieldName(f, node, 'dialog_parameter');
		parameters.forEach((param) => {
			settingsTarget[param.property] = param.value;
		});
		ret.parameters = parameters;
		return [ret];
	},
	add_serial_dialog_settings: (f: FileState, node: Node) => {
		const parameters: MathlangSerialDialogParameter[] = capturesForFieldName(
			f,
			node,
			'serial_dialog_parameter',
		);
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
	serial_dialog_option: (f, node) => {
		const optionChar = textForFieldName(f, node, 'option_type');
		let optionType;
		if (optionChar === '_') optionType = 'text_options';
		else if (optionChar === '#') optionType = 'options';
		return [
			{
				mathlang: 'serial_dialog_option',
				optionType,
				label: captureForFieldName(f, node, 'label'),
				script: captureForFieldName(f, node, 'script'),
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	dialog_option: (f, node) => {
		return [
			{
				mathlang: 'dialog_option',
				label: captureForFieldName(f, node, 'label'),
				script: captureForFieldName(f, node, 'script'),
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	serial_dialog_definition: (f, node) => {
		const serialDialogNode = node.childForFieldName('serial_dialog');
		const name = captureForFieldName(f, node, 'serial_dialog_name');
		const serialDialog = handleNode(f, serialDialogNode);
		return [newSerialDialog(f, node, name, serialDialog[0])];
	},
	dialog_definition: (f, node) => {
		const dialogName = captureForFieldName(f, node, 'dialog_name');
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = dialogNodes.map((v) => handleNode(f, v)).flat();
		return [
			{
				mathlang: 'dialog_definition',
				dialogName,
				dialogs,
				debug: {
					node,
					fileName: f.fileName,
				},
			},
		];
	},
	serial_dialog: (f, node) => {
		const settings = {};
		const params = capturesForFieldName(f, node, 'serial_dialog_parameter');
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		// TODO: make options more closely resemble final form?
		const options = node
			.childrenForFieldName('serial_dialog_option')
			.map((v) => handleNode(f, v))
			.flat();
		const info = {
			settings,
			messages: capturesForFieldName(f, node, 'serial_message'),
			options,
		};
		const serialDialog = buildSerialDialogFromInfo(f, info);
		return [serialDialog];
	},
	dialog: (f, node) => {
		const settings = {};
		const params = capturesForFieldName(f, node, 'dialog_parameter');
		const messageN = node.childrenForFieldName('message');
		params.forEach((v) => {
			settings[v.property] = v.value;
		});
		const options = node
			.childrenForFieldName('dialog_option')
			.map((v) => handleNode(f, v))
			.flat();
		const info = {
			identifier: captureForFieldName(f, node, 'dialog_identifier'),
			settings,
			messages: messageN.map((v) => handleCapture(f, v)),
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
	json_literal: (f, node) => {
		// todo: do it more by hand so that errors can be reported more accurately?
		const jsonNode = node.namedChildren[0];
		const text = jsonNode.text;
		let parsed = [];
		try {
			parsed = JSON.parse(text);
		} catch {
			f.newError({
				locations: [{ node }],
				message: `JSON syntax error`,
				footer: `Generic error. Check trailing commas!`,
			});
		}
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
	},
	copy_macro: (f: FileState, node: Node): MathlangCopyMacro[] => [
		{
			mathlang: 'copy_script',
			script: captureForFieldName(f, node, 'script'),
			debug: {
				node,
				fileName: f.fileName,
			},
		},
	],
	debug_macro: (f: FileState, node: Node) => {
		const ret: AnyNode[] = [];
		let name = '';
		const serialDialogNode = node.childForFieldName('serial_dialog');
		if (serialDialogNode) {
			const serialDialog = handleNode(f, serialDialogNode).flat();
			name = autoIdentifierName(f, node);
			ret.push(newSerialDialog(f, node, name, serialDialog));
		} else {
			name = captureForFieldName(f, node, 'serial_dialog_name');
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
	looping_block: (f: FileState, node: Node, printGotoLabel: string) => {
		return node.namedChildren.map((v) => {
			if (!v) throw new Error('TS');
			const handled = handleNode(f, v);
			if (handled.mathlang === 'continue_statement') {
				return gotoLabel(f, v, `while condition #${printGotoLabel}`);
			} else if (handled.mathlang === 'break_statement') {
				return gotoLabel(f, v, `while rendezvous #${printGotoLabel}`);
			}
			return handled;
		});
	},
	while_block: (f: FileState, node: Node) => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `while condition #${n}`;
		const bodyL = `while body #${n}`;
		const rendezvousL = `while rendezvous #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const condition = handleCapture(f, conditionN);
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const body = handleNode(f, bodyN)
			.flat()
			.map((v) => {
				if (v.mathlang === 'continue_statement') {
					return gotoLabel(f, node, conditionL);
				} else if (v.mathlang === 'break_statement') {
					return gotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const steps = [
			label(f, conditionN, conditionL),
			...expandCondition(f, conditionN, condition, bodyL),
			gotoLabel(f, node, rendezvousL),
			label(f, bodyN, bodyL),
			...body,
			gotoLabel(f, conditionN, conditionL),
			label(f, node, rendezvousL),
		];
		return newSequence(f, node, steps, 'while sequence');
	},
	do_while_block: (f: FileState, node: Node) => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `do while condition #${n}`;
		const bodyL = `do while body #${n}`;
		const rendezvousL = `do while rendezvous #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const condition = handleCapture(f, conditionN);
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const body = handleNode(f, bodyN)
			.flat()
			.map((v) => {
				if (v.mathlang === 'continue_statement') {
					return gotoLabel(f, node, conditionL);
				} else if (v.mathlang === 'break_statement') {
					return gotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const steps = [
			label(f, bodyN, bodyL),
			...body,
			label(f, conditionN, conditionL),
			...expandCondition(f, conditionN, condition, bodyL),
			label(f, node, rendezvousL),
		];
		return newSequence(f, node, steps, 'do-while sequence');
	},
	for_block: (f: FileState, node: Node): MathlangSequence => {
		const n = f.p.advanceGotoSuffix();
		const conditionL = `for condition #${n}`;
		const bodyL = `for body #${n}`;
		const rendezvousL = `for rendezvous #${n}`;
		const continueL = `for continue #${n}`;
		const conditionN = node.childForFieldName('condition');
		if (!conditionN) throw new Error('TS');
		const bodyN = node.childForFieldName('body');
		if (!bodyN) throw new Error('TS');
		const incrementerN = node.childForFieldName('incrementer');
		if (!incrementerN) throw new Error('TS');
		const body: AnyNode[] = handleNode(f, bodyN)
			.flat()
			.map((v: AnyNode) => {
				if (!isNodeAction(v) && v.mathlang === 'continue_statement') {
					return gotoLabel(f, node, continueL);
				} else if (!isNodeAction(v) && v.mathlang === 'break_statement') {
					return gotoLabel(f, node, rendezvousL);
				} else {
					return v;
				}
			});
		const steps: AnyNode[] = [
			...handleNode(f, node.childForFieldName('initializer')),
			label(f, conditionN, conditionL),
			...expandCondition(f, conditionN, handleCapture(f, conditionN), bodyL),
			gotoLabel(f, node, rendezvousL),
			label(f, bodyN, bodyL),
			...body,
			label(f, incrementerN, continueL),
			...handleNode(f, incrementerN),
			gotoLabel(f, conditionN, conditionL),
			label(f, node, rendezvousL),
		];
		return newSequence(f, node, steps, 'for sequence');
	},
	if_single: (f: FileState, node: Node): AnyNode | AnyNode[] => {
		const conditionN = node.childForFieldName('condition');
		let action = handleCapture(f, conditionN);
		// condition.mathlang = 'if_single';
		const type = textForFieldName(f, node, 'type');
		const isBool = typeof action === 'boolean';
		if (typeof action === 'string') {
			action = {
				mathlang: 'bool_getable',
				action: 'CHECK_SAVE_FLAG',
				expected_bool: true,
				save_flag: action,
			};
		}
		if (!type) {
			const script = captureForFieldName(f, node, 'script');
			if (isBool) {
				return action ? [{ action: 'RUN_SCRIPT', script }] : [];
			}
			delete action.mathlang;
			return {
				...action,
				success_script: script,
			};
		} else if (type === 'index') {
			const index = captureForFieldName(f, node, 'index');
			if (isBool) {
				return action ? [{ action: 'GOTO_ACTION_INDEX', action_index: index }] : [];
			}
			delete action.mathlang;
			return {
				...action,
				jump_index: index,
			};
		} else if (type === 'label') {
			const label = captureForFieldName(f, node, 'label');
			if (isBool) {
				return action ? [gotoLabel(f, node, label)] : [];
			}
			action.mathlang = 'if_branch_goto_label';
			return [
				{
					...action,
					label,
				},
			];
		}
		throw new Error('Unreachable?');
	},
	if_chain: (f: FileState, node: Node) => {
		const ifs = node.childrenForFieldName('if_block');
		const elzeN = node.childForFieldName('else_block');
		if (!ifs) throw new Error('I know, I got it');
		if (ifs.length === 1 && !elzeN) {
			const ifsZero = ifs[0];
			if (!ifsZero) throw new Error('srsly');
			const conditionN = ifsZero.childForFieldName('condition');
			let condition = handleCapture(f, conditionN);
			const bodyN = ifsZero.childForFieldName('body');
			if (!bodyN) throw new Error('srsly');
			const body = bodyN.namedChildren.map((v) => handleNode(f, v)).flat();
			if (body.length === 1 && (condition.action || typeof condition === 'string')) {
				if (body[0].action === 'RUN_SCRIPT') {
					if (typeof condition === 'string') {
						condition = {
							mathlang: 'bool_getable',
							action: 'CHECK_SAVE_FLAG',
							expected_bool: true,
							save_flag: condition,
						};
					}
					condition.success_script = body[0].script;
					delete condition.mathlang;
					return condition;
				} else if (body[0].mathlang === 'goto_label') {
					if (typeof condition === 'string') {
						condition = {
							mathlang: 'bool_getable',
							action: 'CHECK_SAVE_FLAG',
							expected_bool: true,
							save_flag: condition,
						};
					}
					condition.label = body[0].label;
					condition.mathlang = 'if_branch_goto_label';
					return condition;
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
			const bodyN = iff.childForFieldName('body');
			if (!bodyN) throw new Error('TS');
			const body = bodyN.namedChildren.map((v) => handleNode(f, v)).flat();
			// add top half
			expandCondition(f, conditionN, condition, ifL).forEach((v) => steps.push(v));
			// add bottom half
			const bottomInsert: AnyNode[] = [
				label(f, bodyN, ifL),
				...body,
				gotoLabel(f, bodyN, rendezvousL),
			];
			bottomSteps = bottomInsert.concat(bottomSteps);
		});
		if (elzeN && elzeN.lastChild) {
			steps.push(
				...elzeN.lastChild.namedChildren.map((v) => handleNode(f, v)).flat(),
				// gotoLabel(f, node, rendezvousLabel),
			);
		}
		steps.push(gotoLabel(f, node, rendezvousL));
		const combined = steps.concat(bottomSteps);
		combined.push(label(f, node, rendezvousL));
		return newSequence(f, node, combined, 'if sequence');
	},
};

// TODO: what is the difference between handleNode() and handleCapture() except that you have to flatten handleNode()?
// Is it that you return complex thing vs primitive value?
// Is it that action wants to call handleCapture() and then work on its properties?
// It is, perhaps, that handleCapture() should check values against registered constants, and nodes shouldn't care about that
