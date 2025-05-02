const fs = require('fs');
const path = require('path');
const TreeSitter = require('web-tree-sitter');
const {Parser, Language} = TreeSitter;

let verbose = true;
const debugLog = (message) => { if (verbose) console.log(message); };

/* ------------------------------- CAPTURE HANDLING ------------------------------- */

const handleCapture = (f, node) => {
	debugLog(`-->> Capturing: ${node.grammarType}`);
	reportAnyErrors(f, node);
	reportAnyMissingChildren(f, node);
	const parseAs = node.grammarType;
	// expansions cannot be recursive, so this is fine
	if (node.grammarType.endsWith('_expansion')) {
		return node.namedChildren.map(v=>handleCapture(f, v));
	}
	if (parseAs === 'CONSTANT') {
		const lookup = f.constants[node.text];
		if (lookup === undefined) {
			f.errors.push({
				message: `Constant ${node.text} is undefined`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
				fileName: f.fileName,
			});
		}
		return lookup?.value || node.text;
	}
	const fn = captureFns[parseAs];
	if (!fn) throw new Error (`No handler function found for token ${parseAs}`);
	return fn(f, node);
};
const captureFns = {
	BOOL: (f, node) => {
		const text = node.text;
		if (text === 'true') return true;
		if (text === 'false') return false;
		if (text === 'on') return true;
		if (text === 'off') return false;
		if (text === 'open') return true;
		if (text === 'closed') return false;
	},
	BAREWORD: (f, node) => node.text,
	QUOTED_STRING: (f, node) => node.text.slice(1, -1),
	NUMBER: (f, node) => Number(node.text),
	DURATION: (f, node) => {
		let n = parseInt(node.namedChild('NUMBER').text);
		let suffixNode = node.childForFieldName('suffix');
		if (suffixNode?.text === 's') n *= 1000; 
		return n;
	},
	DISTANCE: (f, node) => Number(node.text),
	QUANTITY: (f, node) => {
		if (node.childCount === 0) {
			if (node.text === 'once') return 1;
			if (node.text === 'twice') return 2;
			if (node.text === 'thrice') return 3;
		}
		let n = parseInt(node.namedChild('NUMBER').text);
		let suffixNode = node.childForFieldName('suffix');
		if (suffixNode?.text === 's') n *= 1000; 
		return n;
	},
	COLOR: (f, node) => {
		if (node.childCount === 0) {
			if (node.text === 'white') return '#FFFFFF';
			if (node.text === 'black') return '#000000';
			if (node.text === 'red') return '#FF0000';
			if (node.text === 'green') return '#00FF00';
			if (node.text === 'blue') return '#0000FF';
			if (node.text === 'magenta') return '#FF00FF';
			if (node.text === 'cyan') return '#00FFFF';
			if (node.text === 'yellow') return '#FFFF00';
		}
		if (node.text.length === 4) {
			const a = node.text[1];
			const b = node.text[2];
			const c = node.text[3];
			return `#${a}${a}${b}${b}${c}${c}`;
		}
		return node.text;
	},
	CONSTANT: (f, node) => node.text,
	entity_or_map_identifier: (f, node) => {
		const targetNode = node.childForFieldName('target');
		const target = targetNode.text;
		let entity = '';
		if (target === 'map') entity = '%MAP%'
		if (target === 'self') entity = '%SELF%'
		if (target === 'player') entity = '%PLAYER%'
		if (target === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return entity;
	},
	entity_identifier: (f, node) => {
		const typeNode = node.childForFieldName('entity_type');
		const type = typeNode.text;
		let entity = '';
		if (type === 'self') entity = '%SELF%'
		if (type === 'player') entity = '%PLAYER%'
		if (type === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return entity;
	},
	movable_identifier: (f, node) => {
		const targetNode = node.childForFieldName('type');
		const target = targetNode.text;
		let entity = '';
		if (target === 'camera') {
			return {
				mathlang: 'movable_identifier',
				debug: node,
				fileName: f.fileName,
				type: 'camera',
				value: 'camera',
			}
		}
		if (target === 'self') entity = '%SELF%'
		if (target === 'player') entity = '%PLAYER%'
		if (target === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
			type: 'entity',
			value: entity,
		};
	},
	coordinate_identifier: (f, node) => {
		const typeNode = node.childForFieldName('type');
		const type = typeNode.text;
		let entity = '';
		if (type === 'geometry') {
			const geometryNode = node.childForFieldName('geometry');
			const geometry = geometryNode
				? handleCapture(f, geometryNode)
				: 'UNDEFINED GEOMETRY';
			return {
				mathlang: 'movable_identifier',
				debug: node,
				fileName: f.fileName,
				type: 'geometry',
				value: geometry,
			}
		}
 		if (type === 'self') entity = '%SELF%'
		if (type === 'player') entity = '%PLAYER%'
		if (type === 'entity') {
			const entityNode = node.childForFieldName('entity');
			entity = entityNode
				? handleCapture(f, entityNode)
				: 'UNDEFINED ENTITY';
		}
		return {
			mathlang: 'movable_identifier',
			debug: node,
			fileName: f.fileName,
			type: 'entity',
			value: entity,
		};
	},
};

/* ------------------------------- ACTION HANDLING ------------------------------- */

const handleAction = (f, node) => {
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error (`No action data nor handler function found for action ${node.grammarType}`);
		return customFn(f, node);
	}
	let ret = {
		debug: node,
		fileName: f.fileName,
		...data.values,
	};
	const captures = data.captures || [];
	const fancyCaptures = data.fancyCaptures || [];
	const spreadFields = {};
	let spreadSize = -Infinity;
	captures.forEach(fieldName=>{
		const fieldNode = node.childForFieldName(fieldName);
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			ret[fieldName] = capture;
		} else {
			spreadFields[fieldName] = {
				node: fieldNode,
				captures: capture,
			};
		}
	});
	fancyCaptures.forEach(({field, label})=>{
		const fieldNode = node.childForFieldName(field);
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			ret[label] = capture;
		} else {
			spreadFields[label] = {
				node: fieldNode,
				captures: capture,
			};
		}
	});
	// count spreads
	Object.values(spreadFields).forEach(captureData=>{
		const len = captureData.captures.length;
		if (spreadSize === -Infinity) spreadSize = len;
		if (spreadSize !== len) {
			f.errors.push({
				message: `spreads must have the same count of items within a given action`,
				locations: [{
					node: captureData.node, 
					fileName: f.fileName,
				}],
			});
			spreadSize = Math.max(spreadSize, len);
		}
	});
	// no spreads if spreadSize is unchanged
	if (spreadSize === -Infinity) return [ret];
	// otherwise, handle spreads
	const spreadRet = [];
	for (let i = 0; i < spreadSize; i++) {
		const insert = {
			...ret,
		};
		Object.keys(spreadFields).forEach(fieldName=>{
			const allValues = spreadFields[fieldName].captures;
			const currValue = allValues[i % allValues.length];
			insert[fieldName] = currValue;
		});
		spreadRet.push(insert);
	}
	return spreadRet;
};

actionFns = {
	action_show_dialog: (f, node) => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = nameNode
			? nameNode.text
			: f.fileName
				+ '-' + node.startPosition.row
				+ ':' + node.startPosition.column;
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = (dialogNodes||[]).map(child=>handleNode(f, child)).flat();
		const showDialogAction = {
			action: 'SHOW_DIALOG',
			dialog: name,
			debug: node,
			fileName: f.fileName
		}
		if (dialogs.length === 0) {
			return [showDialogAction];
		}
		const dialogDefinition = {
			mathlang: 'dialog_definition',
			dialogName: name,
			dialogs: dialogs,
			debug: node,
			fileName: f.fileName,
		};
		return [
			dialogDefinition,
			showDialogAction
		];
	},
	action_concat_serial_dialog: (f, node) => action_show_serial_dialog(f, node, true),
	action_show_serial_dialog: (f, node, concat) => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const name = nameNode
			? nameNode.text
			: f.fileName
				+ '-' + node.startPosition.row
				+ ':' + node.startPosition.column;
		const serialDialogNodes = node.childrenForFieldName('serial_dialog');
		const serialDialogs = (serialDialogNodes||[]).map(child=>handleNode(f, child)).flat();
		const showSerialDialogAction = {
			action: 'SHOW_SERIAL_DIALOG',
			disable_newline: !concat,
			serial_dialog: name,
			debug: node,
			fileName: f.fileName
		}
		if (serialDialogs.length === 0) {
			return [showSerialDialogAction];
		}
		const serialDialogDefinition = {
			mathlang: 'serial_dialog_definition',
			dialogName: name,
			serialDialog: serialDialogs[0],
			debug: node,
			fileName: f.fileName,
		};
		return [
			serialDialogDefinition,
			showSerialDialogAction
		];
	},
	action_set_position: (f, node) => {
		const movableNodes = node.childrenForFieldName('movable');
		const movables = movableNodes
			.map(v=>handleCapture(f, v)).flat();
		const coordNodes = node.childrenForFieldName('coordinate');
		const coords = coordNodes
			.map(v=>handleCapture(f, v)).flat();
		if (
			movables.length > 1
			&& coords.length > 1
			&& movables.length !== coords.length
		) {
			f.errors = [{
				message: `spreads inside this action must contain same number of items`,
				locations: [{
					node: node, 
					fileName: f.fileName,
				}],
			}];
		}
		const ret = [];
		const maxSpreads = Math.max(movables.length, coords.length);
		for (let i = 0; i < maxSpreads; i++) {
			const insert = {
				debug: node,
				fileName: f.fileName,
			};
			const movable = movables[i % movables.length];
			const coord = coords[i % coords.length];
			if (movable.type === 'camera') {
				if (coord.type === 'geometry') {
					insert.action = 'TELEPORT_CAMERA_TO_GEOMETRY',
					insert.geometry = coord.value;
					ret.push(insert);
					continue;
				} else if (coord.type === 'entity') {
					insert.action = 'SET_CAMERA_TO_FOLLOW_ENTITY',
					insert.entity = coord.value;
					ret.push(insert);
					continue;
				}
			} else if (movable.type === 'entity') {
				if (coord.type === 'geometry') {
					insert.action = 'TELEPORT_ENTITY_TO_GEOMETRY',
					insert.entity = movable.value;
					insert.geometry = coord.value;
					ret.push(insert);
					continue;
				} else if (coord.type === 'entity') {
					ret.push({
						mathlang: 'math_sequence',
						steps: [
							{
								type: 'copy_values',
								copyFrom: { entity: coord.value, field: 'x' },
								copyTo: { entity: movable.value, field: 'x' }
							},
							{
								type: 'copy_values',
								copyFrom: { entity: coord.value, field: 'y' },
								copyTo: { entity: movable.value, field: 'y' }
							},
						]
					});
					continue;
				}
			}
			throw new Error("unreachable?");
		}
		return ret;
	}
};

actionData = {
	action_return_statement: {
		// TODO: everything after is unreachable
		// Ditto some other actions, too
		values: { mathlang: 'return_statement' },
	},
	action_close_dialog: {
		values: { action: 'CLOSE_DIALOG' },
	},
	action_close_serial_dialog: {
		values: { action: 'CLOSE_SERIAL_DIALOG' },
	},
	action_save_slot: {
		values: { action: 'SLOT_SAVE' },
	},
	action_load_slot: {
		values: { action: 'SLOT_LOAD' },
		captures: [ 'slot' ],
	},
	action_erase_slot: {
		values: { action: 'SLOT_ERASE' },
		captures: [ 'slot' ],
	},
	action_load_map: {
		values: { action: 'LOAD_MAP' },
		captures: [ 'map' ],
	},
	action_goto_label: {
		values: { mathlang: 'goto_label' },
		captures: [ 'label' ],
	},
	action_goto_index: {
		values: { action: 'GOTO_ACTION_INDEX' },
		captures: [ 'action_index' ],
	},
	action_run_script: {
		values: { action: 'RUN_SCRIPT' },
		captures: [ 'script' ],
	},
	action_non_blocking_delay: {
		values: { action: 'NON_BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
	action_blocking_delay: {
		values: { action: 'BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
	action_delete_command: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND' },
		captures: [ 'command' ],
	},
	action_delete_command_arg: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT' },
		captures: [ 'command', 'argument' ],
	},
	action_delete_alias: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS' },
		captures: [ 'alias' ],
	},
	action_hide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: false,
		},
		captures: [ 'command' ],
	},
	action_unhide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: true,
		},
		captures: [ 'command' ],
	},
	action_camera_shake: {
		values: { action: 'SET_SCREEN_SHAKE' },
		captures: [ 'amplitude', 'distance', 'duration' ],
	},
	action_camera_fade_in: {
		values: { action: 'SCREEN_FADE_IN' },
		captures: [ 'color', 'duration' ],
	},
	action_camera_fade_out: {
		values: { action: 'SCREEN_FADE_OUT' },
		captures: [ 'color', 'duration' ],
	},
	action_pause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: true },
		captures: [ 'script' ],
		fancyCaptures: [{ field: 'entity_or_map', label: 'entity' }],
	},
	action_unpause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: false },
		captures: [ 'script' ],
		fancyCaptures: [{ field: 'entity_or_map', label: 'entity' }],
	},
	action_play_entity_animation: {
		values: { action: 'PLAY_ENTITY_ANIMATION' },
		captures: [ 'animation', 'count' ],
		fancyCaptures: [{ field: 'entity_identifier', label: 'entity' }],
	},
};

/* ------------------------------- NODE HANDLING ------------------------------- */

const handleNode = (f, node) => {
	reportAnyMissingChildren(f, node);
	reportAnyErrors(f, node);
	debugLog(`handleNode: ${node.grammarType}`)
	if (node.grammarType.startsWith('action_')) {
		return handleAction(f, node);
	}
	const nodeFn = nodeFns[node.grammarType];
	if (!nodeFn) {
		throw new Error ('no named node function for '+ node.grammarType);
	}
	return nodeFn(f, node);
}
const nodeFns = {
	line_comment: (f, node) => [],
	block_comment: (f, node) => [],
	ERROR: (f, node) => {
		f.errors.push({
			message: 'syntax error',
			locations: [{
				node: node, 
				fileName: f.fileName,
			}],
		})
		return [];
	},
	script_definition: (f, node) => {
		const nameNode = node.childForFieldName('script_name');
		const name = handleCapture(f, nameNode);
		const actions = node.lastChild.namedChildren
			.map(node=>handleNode(f, node))
			.flat();
		return [{
			mathlang: 'script_definition',
			scriptName: name,
			actions,
			debug: node,
			fileName: f.fileName,
		}];
	},
	constant_assignment: (f, node) => {
		const labelNode = node.childForFieldName('label');
		const valueNode = node.childForFieldName('value');
		const label = labelNode.text;
		const value = handleCapture(f, valueNode);
		f.constants = f.constants || {};
		if (f.constants[labelNode]) {
			f.errors.push({
				message: `cannot redefine constant ${ret.label}`,
				locations: [{
					node: node, 
					fileName: f.fileName,
				}],
			});
		}
		f.constants[label] = {
			value,
			type: valueNode.grammarType,
			debug: node,
			fileName: f.fileName,
		};
		return [{
			mathlang: 'constant_assignment',
			label,
			value,
			debug: node,
			fileName: f.fileName,
		}];
	},
	include_macro: (f, node) => {
		// TODO: ~~handle~~ prevent recursive references
		let includeFileNode = node.childForFieldName('fileName');
		let capture = handleCapture(f, includeFileNode);
		const prerequesites = Array.isArray(capture) ? capture : [ capture ];
		prerequesites.forEach(prereq=> {
			if (!fileMap[prereq].parsed) {
				debugLog(`include_macro: must first parse prerequesite "${prereq}"`);
				parseFile(prereq, f.parser)
			} else {
				debugLog(`include_macro: prerequesite "${prereq}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereq} into ${f.fileName}...`);
			f = mergeF(f, fileMap[prereq].parsed);
		});
		return [{
			mathlang: 'include_macro',
			value: capture,
			debug: node,
			fileName: f.fileName,
		}];
	},
	rand_macro: (f, node) => {
		const horizontal = [];
		let multipleCount = -Infinity;
		node.namedChildren
			.forEach(node=>{
				const handled = handleNode(f, node);
				const len = handled.length;
				if (len === 0) return;
				horizontal.push(handled);
				if (len === 1) return;
				if (multipleCount === -Infinity) multipleCount = len;
				if (multipleCount !== len) {
					f.errors = [{
						message: `spreads inside rand!() must contain same number of items`,
						locations: [{
							node: node, 
							fileName: f.fileName,
						}],
					}];
				}
			})
		const vertical = [];
		for (let i = 0; i < multipleCount; i++) {
			const insert = horizontal.map(unit=>{
				return unit[i % unit.length];
			})
			vertical.push(insert);
		}
		return [{
			mathlang: 'rand_macro',
			splits: vertical,
			debug: node,
			fileName: f.fileName,
		}];
	},
	label_definition: (f, node) => {
		const label = node.childForFieldName('label').text;
		return [{
			mathlang: 'label_definition',
			label,
			debug: node,
			fileName: f.fileName,
		}];
	},
	add_dialog_settings: (f, node) => {
		const targets = node.namedChildren
			.map(child=>handleNode(f, child))
			.flat();
		return [{
			mathlang: 'add_dialog_settings',
			targets,
			debug: node,
			fileName: f.fileName,
		}]
	},
	add_dialog_settings_target: (f, node) => {
		let bucket;
		const type = node.firstChild.type;
		const targetNode = node.childForFieldName('target');
		if (type === 'target_default') {
			bucket = f.settings.default;
		} else if (type === 'target_label') {
			if (!targetNode) {
				f.errors.push({
					message: `dialog_settings_target: malformed label definition`,
					locations: [{
						node, 
						fileName: f.fileName,
					}],
				})
			}
			const target = targetNode.text || 'UNDEFINED LABEL';
			f.settings.label[target] = f.settings.label[target] || {};
			bucket = f.settings.label[target];
		} else if (type === 'target_entity') {
			if (!targetNode) {
				f.errors.push({
					message: `dialog_settings_target: malformed entity definition`,
					locations: [{
						node, 
						fileName: f.fileName,
					}],
				})
			}
			const target = targetNode.text || 'UNDEFINED ENTITY';
			f.settings.label[target] = f.settings.label[target] || {};
			bucket = f.settings.entity[target];
		} else {
			throw new Error("This shouldn't happen, I think");
		}
		const parameters = node.childrenForFieldName('dialog_parameter')
			.map(innerChild=>handleNode(f, innerChild))
			.flat();
		parameters.forEach(param=>{
			bucket[param.property] = param.value;
		});
		return [{
			mathlang: 'add_dialog_settings_target',
			parameters,
			debug: node,
			fileName: f.fileName,
		}];
	},
	dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		if (!propNode || !valueNode) {
			f.errors.push({
				message: `malformed dialog parameter`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			});
			return [];
		}
		return [{
			mathlang: 'dialog_parameter',
			property: propNode.text,
			value: handleCapture(f, valueNode),
			debug: node,
			fileName: f.fileName,
		}];
	},
	add_serial_dialog_settings: (f, node) => {
		const parameters = node.namedChildren
			.map(child=>handleNode(f, child))
			.flat();
		parameters.forEach(param=>{
			f.settings.serial[param.property] = param.value;
		})
		return [{
			mathlang: 'add_serial_dialog_settings',
			parameters,
			debug: node,
			fileName: f.fileName,
		}];
	},
	serial_dialog_parameter: (f, node) => {
		const propNode = node.childForFieldName('property');
		const valueNode = node.childForFieldName('value');
		if (!propNode || !valueNode) {
			f.errors.push({
				message: `malformed serial_dialog parameter`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			});
			return [];
		}
		return [{
			mathlang: 'serial_dialog_parameter',
			property: handleCapture(f, propNode),
			value: handleCapture(f, valueNode),
			debug: node,
			fileName: f.fileName,
		}]
	},
	serial_dialog_option: (f, node) => {
		const optionNode = node.childForFieldName('option_type');
		const labelNode = node.childForFieldName('label');
		const scriptNode = node.childForFieldName('script');
		if (!optionNode || !labelNode || !scriptNode) {
			f.errors.push({
				message: `malformed serial_dialog option`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			});
			return [];
		}
		let optionType = null;
		if (optionNode.text === '_') optionType = 'text_options';
		else if (optionNode.text === '#') optionType = 'options';
		return [{
			mathlang: 'serial_dialog_option',
			optionType,
			label: handleCapture(f, labelNode),
			script: handleCapture(f, scriptNode),
			debug: node,
			fileName: f.fileName,
		}]
	},
	dialog_option: (f, node) => {
		const labelNode = node.childForFieldName('label');
		const scriptNode = node.childForFieldName('script');
		if (!labelNode || !scriptNode) {
			f.errors.push({
				message: `malformed dialog option`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			});
			return [];
		}
		return [{
			mathlang: 'dialog_option',
			label: handleCapture(f, labelNode),
			script: handleCapture(f, scriptNode),
			debug: node,
			fileName: f.fileName,
		}]
	},
	serial_dialog_definition: (f, node) => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const serialDialogNode = node.childForFieldName('serial_dialog');
		const name = handleCapture(f, nameNode);
		const dialog = handleNode(f, serialDialogNode);
		return [{
			mathlang: 'serial_dialog_definition',
			serialDialogName: name,
			serialDialog: dialog[0],
			debug: node,
			fileName: f.fileName,
		}];
	},
	dialog_definition: (f, node) => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = handleCapture(f, nameNode);
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = dialogNodes.map(child=>handleNode(f, child)).flat();
		return [{
			mathlang: 'dialog_definition',
			dialogName: name,
			dialogs: dialogs,
			debug: node,
			fileName: f.fileName,
		}];
	},
	serial_dialog: (f, node) => {
		const paramNodes = node.childrenForFieldName('serial_dialog_parameter');
		const messageNodes = node.childrenForFieldName('serial_message');
		const optionNodes = node.childrenForFieldName('serial_dialog_option');
		const params = paramNodes.map(v=>handleNode(f, v)).flat();
		const options = optionNodes.map(v=>handleNode(f, v)).flat();
		// TODO: make options more closely resemble final form?
		const settings = {};
		params.forEach(param=>{
			settings[param.property] = param.value;
		});
		const messages = messageNodes.map(v=>handleCapture(f, v));
		const info = {
			settings,
			messages,
			options
		};
		const serialDialog = buildSerialDialogFromInfo(f, info, node);
		return [{
			mathlang: 'serial_dialog',
			serialDialog,
			debug: node,
			fileName: f.fileName,
		}];
	},
	dialog: (f, node) => {
		const identifierNode = node.childForFieldName('dialog_identifier');
		const paramNodes = node.childrenForFieldName('dialog_parameter');
		const messageNodes = node.childrenForFieldName('message');
		const optionNodes = node.childrenForFieldName('dialog_option');
		// better way to do this?
		const identifier = handleNode(f, identifierNode)[0];
		const params = paramNodes.map(v=>handleNode(f, v)).flat();
		const settings = {};
		params.forEach(param=>{
			settings[param.property] = param.value;
		});
		const messages = messageNodes.map(v=>handleCapture(f, v));
		const options = optionNodes.map(v=>handleNode(f, v)).flat();
		const info = {
			identifier,
			settings,
			messages,
			options,
		}
		const dialogs = buildDialogFromInfo(f, info);
		return [{
			mathlang: 'dialog',
			info,
			dialogs,
			debug: node,
			fileName: f.fileName,
		}];
	},
	dialog_identifier: (f, node) => {
		let type;
		let value;
		const labelNode = node.childForFieldName('label');
		if (labelNode) {
			type = 'label';
			value = labelNode.text;
		} else {
			const typeNode = node.childForFieldName('type');
			const valueNode = node.childForFieldName('value');
			type = typeNode.text;
			value = valueNode
				? handleCapture(f, valueNode)
				: 'MALFORMED ENTITY IDENTIFIER';
			f.errors.push({
				message: `dialog identifier lacks a value`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			});
		}
		return [{
			mathlang: 'dialog_identifier',
			type,
			value,
			debug: node,
			fileName: f.fileName,
		}];
	},
	json_literal: (f, node) => {
		// TODO: do it more by hand so that errors can be reported more accurately
		const jsonNode = node.namedChildren[0];
		const text = jsonNode.text;
		let parsed = [];
		try {
			parsed = JSON.parse(text);
		} catch {
			f.errors.push({
				message: `JSON syntax error`,
				locations: [{
					node, 
					fileName: f.fileName,
				}],
			})
		}
		return [{
			mathlang: 'json_literal',
			json: parsed,
			debug: node,
			fileName: f.fileName,
		}]
	},
	entity_or_map_identifier: (f, node) => {
		const targetNode = node.childForFieldName('target');
		const targetType = handleCapture(f, targetNode);
		let entity = '';
		if (targetType === 'map') {
			entity = '%MAP%';
		} else if (targetType === 'self') {
			entity = '%SELF%';
		} else if (targetType === 'self') {
			entity = '%PLAYER%';
		} else {
			const valueNode = node.childForFieldName('entity');
			if (!valueNode) {
				f.errors.push({
					message: 'undefined entity in entity identifier',
					locations: [{
						node,
						fileName: f.fileName,
					}],
				});
				entity = 'UNDEFINED ENTITY';
			} else {
				entity = handleCapture(f, valueNode);
			}
		}
		return [{
			mathlang: 'entity_or_map_identifier',
			entity,
			debug: node,
			fileName: f.fileName,
			fieldsAsCapture: ['entity'],
		}]
	},
};
/* ------------------------------- DIALOG HANDLING ------------------------------- */

const countCharLength = str => {
	let length = 0;
	let remainder = str;
	while (remainder.length) {
		const percent = remainder.match(/^%.*%/);
		if (percent) {
			length += 12;
			remainder = remainder.slice(percent[0].length);
			continue;
		}
		const dollar = remainder.match(/^\$.*\$/);
		if (dollar) {
			length += 5;
			remainder = remainder.slice(dollar[0].length);
			continue;
		}
		const esc = remainder.match(/^\\./);
		if (esc) {
			length += 1;
			remainder = remainder.slice(2);
			continue;
		}
		const canPrint = remainder.match(/^[-!"#$%&'()*+,./0-9:;<>=?@A-Z\[\]\\^_`a-z{}|~]+/);
		if (canPrint) {
			length += 1;
			remainder = remainder.slice(1);
			continue;
		}
		length += 0;
		remainder = remainder.slice(1);
	}
	return length;
};
const wrapText = (origStr, wrap, doAnsiWrapBodge) => {
	// // TODO: hyphenated words?
	let str = origStr
		.replace(/[“”]/g, '"')
		.replace(/[‘’]/g, "'")
		.replace(/…/g, "...")
		.replace(/\t/g, "    ")
		.replace(/—/g, "--") // emdash
		.replace(/–/g, "-"); // endash
	const result = [];
	str.split('\n').forEach(line => {
		const chunkRegExp = new RegExp(/(?<spaces>[ ]*|^)(?<word>[^ ]+|$)/g);
		let insert = '';
		let insertLength = 0;
		let chunk = chunkRegExp.exec(line);
		while (chunk[0] !== '') {
			const { spaces, word } = chunk.groups;
			const spacesLength = spaces.length;
			const wordLength = countCharLength(word);
			const potentialLength = insertLength + wordLength + spacesLength;
			if (
				potentialLength <= wrap
				|| insert === ''
			) {
				insert += spaces + word;
				insertLength += wordLength + spacesLength;
			} else {
				result.push(insert);
				insertLength = wordLength;
				insert = word;
			}
			chunk = chunkRegExp.exec(line);
		}
		result.push(insert);
	});
	const bodged = doAnsiWrapBodge ? ansiWrapBodge(result) : result;
	return bodged.join('\n');
};
// Linux-sempai says use only red, or red and cyan, and don't use the others; you have no idea whether they're using a dark or light theme, or what their theme is like and some colors WILL NOT show up, depending.
const ansiTags = {
	// styles
	'bold': '\u001B[1m', // aka bright
	'dim': '\u001B[2m', // aka dim
	'/': '\u001B[0m', 'reset': '\u001B[0m', // reset all styles
	// fg colors
	'k': '\u001B[30m', 'black': '\u001B[30m',
	'r': '\u001B[31m', 'red': '\u001B[31m',
	'g': '\u001B[32m', 'green': '\u001B[32m',
	'y': '\u001B[33m', 'yellow': '\u001B[33m',
	'b': '\u001B[34m', 'blue': '\u001B[34m',
	'm': '\u001B[35m', 'magenta': '\u001B[35m',
	'c': '\u001B[36m', 'cyan': '\u001B[36m',
	'w': '\u001B[37m', 'white': '\u001B[37m',
	// bg colors
	'bg-k': '\u001B[40m', 'bg-black': '\u001B[40m',
	'bg-r': '\u001B[41m', 'bg-red': '\u001B[41m',
	'bg-g': '\u001B[42m', 'bg-green': '\u001B[42m',
	'bg-y': '\u001B[43m', 'bg-yellow': '\u001B[43m',
	'bg-b': '\u001B[44m', 'bg-blue': '\u001B[44m',
	'bg-m': '\u001B[45m', 'bg-magenta': '\u001B[45m',
	'bg-c': '\u001B[46m', 'bg-cyan': '\u001B[46m',
	'bg-w': '\u001B[47m', 'bg-white': '\u001B[47m',
	// non-color-related
	'bell': '',
};
const tagsToAnsiEscapes = str => {
	let ret = str;
	Object.entries(ansiTags).forEach(([k,v])=>{
		// TODO: what if you want to actually print <r>?
		// Do this again but ignoring escaped chars
		ret = ret.replaceAll(`<${k}>`, v);
	});
	return ret;
};

// This is for the web build, which does not carry over ansi styleswhen things are wrapped
const ansiWrapBodge = arr => {
	let wrappedTags = new Set ();
	const bodged = arr.map(line=>{
		let prevTags = wrappedTags.size ? [...wrappedTags].join('') : '';
		let pos = 0;
		while (pos < line.length) {
			if (line[pos] !== '\u001B') {
				pos += 1;
				continue;
			}
			if (line.slice(pos+1).startsWith('[0m')) {
				wrappedTags = new Set();
				pos += 4;
				continue;
			}
			const tag = line[pos] + line.slice(pos+1).match(/\[\d+m/);
			wrappedTags.add(tag);
			pos += tag.length;
			continue;
		}
		return prevTags + line;
	});
	return bodged;
};
const buildSerialDialogFromInfo = (f, info) => {
	const serialDialog = {
		wrap: 80,
		...f.settings.serial || {}, // global settings
		...info.settings, // local settings
	};
	serialDialog.messages = info.messages
		.map(tagsToAnsiEscapes)
		.map(message=>wrapText(message, serialDialog.wrap, true));
	if (info.options.length > 0) {
		const firstOptionType = info.options[0].optionType;
		serialDialog[firstOptionType] = info.options;
		const warnLocations = [];
		info.options.forEach(option=>{
			if (option.optionType !== firstOptionType) {
				warnLocations.push({
					node: option.debug.firstChild,
					fileName: f.fileName,
				});
			}
		});
		if (warnLocations.length > 0) {
			f.warnings.push({
				message: `serial dialog option types mismatch; first type (${firstOptionType}) will be used`,
				locations: warnLocations,
			});
		}
	}
	return serialDialog;
};
const buildDialogFromInfo = (f, info) => {
	const ident = info.identifier;
	let specificSettings = {};
	if (ident.type === 'label') {
		specificSettings = f.settings.label[ident.value] || {};
	} else if (ident.type === 'entity') {
		specificSettings = f.settings.entity[ident.value] || {};
	}
	const dialog = {
		wrap: 42,
		alignment: 'BOTTOM_LEFT',
		...f.settings.default, // global default settings
		...specificSettings, // global specific settings
		...info.settings, // local specific settings
	};
	// this needs to be outside to get the actual wrap value:
	dialog.messages = info.messages
		.map(message=>wrapText(message, dialog.wrap));
	if (info.options.length > 0) {
		dialog.response_type = 'SELECT_FROM_SHORT_LIST';
		dialog.options = info.options;
	}
	// TODO: warn if messages are more than 5 lines
	return dialog;
};


/* ------------------------------- FILE HANDLING ------------------------------- */

// stolen from the other place
const makeMap = path => {
	let map = {};
	for (file of fs.readdirSync(
		path,
		{ withFileTypes: true }
	)) {
		let filePath = `${path}/${file.name}`

		if (file.isDirectory()) {
			map = {
				...map,
				...makeMap(filePath)
			};
		} else {
			let text = fs.readFileSync(filePath, 'utf-8')
			let type = filePath.split('.').pop()
			map[file.name] = {
				fileName: file.name,
				type,
				text,
			}
		}
	}
	return map;
}
const inputPath = path.resolve('./scenario_source_files');
const fileMap = makeMap(inputPath);

const mergeF = (f1, f2) => {
	Object.keys(f2.constants).forEach(constantName=>{
		if (f1.constants[constantName]) {
			f.errors.push({
				message: `cannot redefine constant ${constantName} (via 'include_macro')`,
				fileName: f2.fileName,
				locations: [{
					node: f2.constants[constantName].node, 
					fileName: f2.fileName,
				}],
			})
		}
		f1.constants[constantName] = f2.constants[constantName];
	});
	f2.nodes.forEach(node=>{ f1.nodes.push(node) });
	['default', 'serial'].forEach(type=>{
		const params = Object.keys(f2.settings[type]);
		params.forEach(param=>{
			f1.settings[type][param] = f2.settings[type][param];
		});
	});
	['entity', 'label'].forEach(type=>{
		const targets = Object.keys(f2.settings[type]);
		targets.forEach(target=>{
			const params = Object.keys(f2.settings[type][target]);
			f1.settings[type][target] = f1.settings[type][target] || {};
			params.forEach(param=>{
				f1.settings[type][target][param] = f2.settings[type][target][param];
			});
		});
	});
	return f1;
};

const parseFile = (fileName, parser) => {
	const tree = parser.parse(fileMap[fileName].text);
	let document = tree.rootNode;
	const f = {
		fileName,
		constants: {},
		settings: {
			default: {},
			entity: {},
			label: {},
			serial: {},
		},
		errors: [],
		warnings: [],
		nodes: [],
		parser,
	}
	const nodes = document.namedChildren
		.map(node=>handleNode(f, node))
		.flat();
	f.nodes = nodes;
	fileMap[fileName].parsed = f;
	return f;
};

/* ------------------------------- THE ACTUAL OWL ------------------------------- */
const finalizeActions = (p, rawActions) => {
	const actions = [];
	rawActions.forEach(node=>{
		if (!node.mathlang) {
			actions.push(node);
		} else if (node.mathlang === 'dialog_definition') {
			addDialog(p, node);
		} else if (node.mathlang === 'serial_dialog_definition') {
			addSerialDialog(p, node);
		}
	})
	return actions;
};

const addDialog = (p, node, fileName) => {
	const dialogName = node.dialogName;
	debugLog(`Finalizing dialog "${dialogName}" in file ${fileName}`);
	const data = node;
	if (!p.dialogs[dialogName]) {
		p.dialogs[dialogName] = data;
	} else {
		if (!p.dialogs[dialogName].duplicates) {
			p.dialogs[dialogName].duplicates = [ p.dialogs[dialogName] ];
		}
		p.dialogs[dialogName].duplicates.push(data);
	}
};
const addSerialDialog = (p, node, fileName) => {
	const serialDialogName = node.serialDialogName;
	debugLog(`Finalizing serial dialog "${serialDialogName}" in file ${fileName}`);
	const data = node;
	if (!p.dialogs[serialDialogName]) {
		p.dialogs[serialDialogName] = data;
	} else {
		if (!p.dialogs[serialDialogName].duplicates) {
			p.dialogs[serialDialogName].duplicates = [ p.dialogs[serialDialogName] ];
		}
		p.dialogs[serialDialogName].duplicates.push(data);
	}
};
const addScript = (p, node, fileName) => {
	const scriptName = node.scriptName;
	debugLog(`Finalizing script "${scriptName}" in file ${fileName}`);
	const actions = finalizeActions(p, node.actions);
	const data = {
		fileName,
		node: node,
		actions,
	};
	if (!p.scripts[scriptName]) {
		p.scripts[scriptName] = data;
	} else {
		if (!p.scripts[scriptName].duplicates) {
			p.scripts[scriptName].duplicates = [ p.scripts[scriptName] ];
		}
		p.scripts[scriptName].duplicates.push(data);
	}
};

(async () => {
	await Parser.init();
	const parser = new Parser();
	const Lang = await Language.load('tree-sitter-magegamescript.wasm');
	parser.setLanguage(Lang);
	
	Object.keys(fileMap).forEach(fileName=>{
		if (!fileMap[fileName].parsed) {
			debugLog(`Parsing file ${ansiTags.c}"${fileName}"${ansiTags.reset}`);
			parseFile(fileName, parser);
		}
	});
	const p = { // 'project' :P
		serialDialogs: {},
		dialogs: {},
		scripts: {},
		errors: [],
		warnings: [],
	};
	Object.keys(fileMap).forEach(fileName=>{
		let errorCount = 0;
		let warningCount = 0;
		fileMap[fileName].parsed.errors.forEach(error=>{
			p.errors.push(error);
			errorCount += 1;
		})
		fileMap[fileName].parsed.warnings.forEach(warning=>{
			p.warnings.push(warning);
			warningCount += 1;
		})
		fileMap[fileName].parsed.nodes.forEach(node=>{
			if (node.mathlang === 'script_definition') {
				addScript(p, node, fileName);
			} else if (node.mathlang === 'dialog_definition') {
				addDialog(p, node, fileName);
			} else if (node.mathlang === 'serial_dialog_definition') {
				addSerialDialog(p, node, fileName);
			}
		})
		if (verbose) {
			let message = `${ansiTags.g}File ${fileName} complete!${ansiTags.reset}`;
			if (errorCount > 0 || warningCount > 0) {
				const errorMessage = errorCount
					? `${ansiTags.r}${errorCount} error${errorCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 errors`;
				const warningMessage = warningCount
					? `${ansiTags.y}${warningCount} warning${warningCount === 1 ? '' : 's'}${ansiTags.reset}`
					: `0 warnings`;
				if (errorCount > 0 && warningCount > 0) {
					message += ` (${errorMessage}, ${warningMessage})`;
				} else if (errorCount > 0) {
					message += ` (${errorMessage})`;
				} else if (warningCount > 0) {
					message += ` (${warningMessage})`;
				}
			}
			console.log(message);
		}
	})
	Object.entries(p.scripts).forEach(([scriptName, script])=>{
		if (script.duplicates) {
			p.errors.push({
				message: `multiple scripts with name "${scriptName}"`,
				locations: script.duplicates.map(dupe=>{
					return {
						fileName: dupe.fileName,
						node: dupe.node.debug.firstNamedChild,
					}
				}),
			});
		}
	});
	Object.entries(p.dialogs).forEach(([dialogName, dialog])=>{
		if (dialog.duplicates) {
			p.errors.push({
				message: `multiple dialogs with name "${dialogName}"`,
				locations: dialog.duplicates.map(dupe=>{
					return {
						fileName: dupe.fileName,
						node: dupe.debug.firstNamedChild,
					}
				}),
			});
		}
	});
	Object.entries(p.serialDialogs).forEach(([serialDialogName, serialDialog])=>{
		if (serialDialog.duplicates) {
			p.errors.push({
				message: `multiple serial dialogs with name "${serialDialogName}"`,
				locations: serialDialog.duplicates.map(dupe=>{
					return {
						fileName: dupe.fileName,
						node: dupe.debug.firstNamedChild,
					}
				}),
			});
		}
	});
	p.errors.forEach(error=>{
		console.error(`\nError: ${error.message}`);
		error.locations.forEach(location=>{
			console.error(getPrintableLocationData(location));
		})
	});
	p.warnings.forEach(warning=>{
		console.warn(`\n${ansiTags.y}Warning: ${warning.message}`);
		warning.locations.forEach(location=>{
			console.error(ansiTags.y + getPrintableLocationData(location) + ansiTags.reset);
		});
	});
	console.log("ASYNC WHY ARE YOU LIKE THIS");
})();

const getPrintableLocationData = (location) => {
	const fileName = location.fileName;
	const allLines = fileMap[fileName].text.split('\n');
	let row = location.node.startPosition.row;
	let col = location.node.startPosition.column;
	const line = allLines[row].replaceAll('\t', ' ');
	const arrow = '~'.repeat(col) + '^';
	const message
		= `╓-${fileName} ${row}:${col}\n`
		+ '║ ' + `${line}\n`
		+ '╙~' + arrow;
	return message;
};
const reportAnyMissingChildren = (f, node) => {
	const missingNodes = node.children.filter(child=>child.isMissing);
	missingNodes.forEach(missingChild=>{
		f.errors.push({
			message: `missing token: ${missingChild.type}`,
			locations: [{
				node: missingChild, 
				fileName: f.fileName,
			}],
		});
	});
	return missingNodes;
};
const reportAnyErrors = (f, node) => {
	const errorNodes = node.namedChildren.filter(child=>child.type === 'ERROR');
	errorNodes.forEach(errorNode=>{
		f.errors.push({
			message: 'syntax error',
			locations: [{
				node: errorNode, 
				fileName: f.fileName,
			}],
		})
	})
	return errorNodes;
};

console.log("WHY IS THIS BEFORE THE ASYNC");
