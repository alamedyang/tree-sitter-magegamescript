const handleCapture = require('./parser-capture.js');

let handleNode;
const handleActionsInit = (handleNodeFn) => {
	handleNode = handleNodeFn;
};

const genericIdent = (f, node, fieldName, label = fieldName) => {
	const childNodes = node.childrenForFieldName(fieldName);
	if (childNodes) {
		return childNodes.map(v=>handleCapture(f, v));
	}
	f.newError({
		locations: [{ node }],
		message: `undefined ${label} identifier`,
	})
	return 'UNDEFINED ' + label.toLocaleUpperCase();
};
const spreadValues = (f, commonFields, fieldsToSpread) => {
	// count spreads
	let spreadSize = -Infinity;
	Object.values(fieldsToSpread).forEach(fieldName=>{
		const len = fieldName.captures.length;
		// spreadSize won't be 1
		if (spreadSize === -Infinity) spreadSize = len;
		if (spreadSize !== len) {
			fieldName.newError({
				locations: [{ node: fieldName.node }],
				message: `spreads must have the same count of items within a given action`,
			});
			spreadSize = Math.max(spreadSize, len);
		}
	});
	// if it's single, pass it back
	if (spreadSize === -Infinity) {
		return [ commonFields ];
	}
	// spread action into multiple variants
	let multis = [];
	for (let i = 0; i < spreadSize; i++) {
		const currUnit = { ...commonFields };
		Object.keys(fieldsToSpread).forEach(fieldName=>{
			const allValues = fieldsToSpread[fieldName].captures;
			const currValue = allValues[i % allValues.length];
			currUnit[fieldName] = currValue;
		});
		multis.push(currUnit);
	}
	return multis;
};

const handleAction = (f, node) => {
	if (!handleNode) {
		throw new Error("handleAction cannot be called until handleNode has been provided to the init function")
	}
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error (`No action data nor handler function found for action ${node.grammarType}`);
		return customFn(f, node);
	}
	let action = {
		debug: node,
		fileName: f.fileName,
		...data.values,
	};
	const captures = data.captures || [];
	const capturesToRelabel = data.relabeledCaptures || [];
	const fieldsToSpread = {};
	captures.forEach(field=>{
		const fieldNode = node.childForFieldName(field);
		if (!fieldNode) {
			if (data.optionalCaptures?.includes(field)) {
				action[field] = null;
			} else {
				throw new Error ("THIS SHOULDN'T HAPPEN FIX IT")
			}
		} else {
			const capture = handleCapture(f, fieldNode);
			if (!Array.isArray(capture)) {
				action[field] = capture;
			} else {
				fieldsToSpread[field] = {
					node: fieldNode,
					captures: capture,
				};
			}
		}
	});
	capturesToRelabel.forEach(({field, label})=>{
		const fieldNode = node.childForFieldName(field);
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			action[label] = capture;
		} else {
			fieldsToSpread[label] = {
				node: fieldNode,
				captures: capture,
			};
		}
	});
	const spreads = spreadValues(f, action, fieldsToSpread);
	if (data.detective) {
		spreads.forEach(action=>{
			// try the action detective
			for (let i = 0; i < data.detective.length; i++) {
				const clueData = data.detective[i];
				const solved = clueData.match(action);
				if (solved) {
					const values = clueData.values(action, f, node);
					Object.entries(values)
						.forEach(([k,v])=>{ action[k] = v; });
					return;
				}
			}
			f.newError(data.detectError(action))
			action.error = true;
		});
	}
	return spreads;
};

const actionFns = {
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
	action_show_serial_dialog: (f, node, isConcat) => {
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
			disable_newline: !isConcat,
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
	// action_set_bool: (f, node) => {
	// 	const setableNode = node.childForFieldName('bool_setable');
	// 	const complexNode = setableNode.childForFieldName('bool_or_identifier');
	// 	const ret = {};
	// 	const fieldsToSpread = {};
	// 	let boolName = 'bool_value';
	// 	if (complexNode) {
	// 		const childBoolNode = complexNode.childForFieldName('bool_type');
	// 		let identifier;
	// 		let label;
	// 		if (!childBoolNode) {
	// 			const flagNameNode = complexNode.children[0];
	// 			ret.action = 'SET_SAVE_FLAG';
	// 			label = 'flag';
	// 			identifier = genericIdent(f, flagNameNode, 'save_flag', label);
	// 		} else if (childBoolNode.text === 'glitched') {
	// 			ret.action = 'SET_ENTITY_GLITCHED';
	// 			label = 'entity';
	// 			identifier = genericIdent(f, complexNode, 'entity_identifier', label);
	// 		} else if (complexNode.text === 'light') {
	// 			ret.action = 'SET_LIGHTS_STATE';
	// 			boolName = 'enabled';
	// 			label = 'lights';
	// 			identifier = genericIdent(f, complexNode, 'light', label);
	// 		} else {
	// 			throw new Error ("THIS SHOULDn'T HAPPEN but TS/Rust taught me to think about it");
	// 		}
	// 		if (identifier.length === 1) {
	// 			ret[label] = identifier[0];
	// 		} else {
	// 			fieldsToSpread[label] = identifier;
	// 		}
	// 	} else {
	// 		const type = setableNode.childForFieldName('bool_type');
	// 		if (type.text === 'player_control') {
	// 			action = 'SET_PLAYER_CONTROL';
	// 		} else if (type.text === 'lights_control') {
	// 			action = 'SET_LIGHTS_CONTROL';
	// 			boolName = 'enabled';
	// 		} else if (type.text === 'hex_editor') {
	// 			action = 'SET_HEX_EDITOR_STATE';
	// 		} else if (type.text === 'hex_dialog_mode') {
	// 			action = 'SET_HEX_EDITOR_DIALOG_MODE';
	// 		} else if (type.text === 'hex_control') {
	// 			action = 'SET_HEX_EDITOR_CONTROL';
	// 		} else if (type.text === 'hex_clipboard') {
	// 			action = 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
	// 		} else if (type.text === 'serial_control') {
	// 			action = 'SET_SERIAL_DIALOG_CONTROL';
	// 		} else {
	// 			throw new Error ("THIS SHOULDN'T HAPPEN: set bool action")
	// 		}
	// 	}
	// 	const boolNodes = node.childrenForFieldName('bool_getable');
	// 	const capturedBools = boolNodes.map(n=>handleCapture(f, n));
	// 	if (boolNodes.length === 1) {
	// 		ret[boolName] = capturedBools[0];
	// 	} else {
	// 		fieldsToSpread[boolName] = {
	// 			node: boolNodes,
	// 			captures: capturedBools,
	// 		};
	// 	}
	// 	const spreads = spreadValues(f, ret, fieldsToSpread);
	// 	const cleanedSpreads = spreads.map(spread=>{
	// 		if (typeof spread[boolName] === 'string') {
	// 			return mathSequenceFns.setBoolOnFlagName(f, node, spread, boolName);
	// 		} else {
	// 			return spread;
	// 		}
	// 	});
	// 	return cleanedSpreads;
	// },
};

const actionData = {
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
		relabeledCaptures: [{ field: 'entity_or_map', label: 'entity' }],
	},
	action_unpause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: false },
		captures: [ 'script' ],
		relabeledCaptures: [{ field: 'entity_or_map', label: 'entity' }],
	},
	action_play_entity_animation: {
		values: { action: 'PLAY_ENTITY_ANIMATION' },
		captures: [ 'animation', 'count' ],
		relabeledCaptures: [{ field: 'entity_identifier', label: 'entity' }],
	},
	action_set_bool: {
		values: {},
		captures: [ 'bool_setable', 'bool_or_identifier' ],
		detective: [
			{
				match: (v) => v.bool_setable.type === 'save_flag',
				values: (v, f, node) => {
					const action = {
						action: 'SET_SAVE_FLAG',
						save_flag: v.bool_setable.value,
					};
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'entity',
				values: (v, f, node) => {
					const action = {
						action: 'SET_ENTITY_GLITCHED',
						entity: v.bool_setable.value,
					};
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'light',
				values: (v, f, node) => {
					const action = {
						action: 'SET_LIGHTS_STATE',
						lights: v.bool_setable.value,
					};
					return actionSetBoolRHSMaker(f, v, node, action, 'enabled');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'player_control',
				values: (v, f, node) => {
					const action = { action: 'SET_PLAYER_CONTROL' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'lights_control',
				values: (v, f, node) => {
					const action = { action: 'SET_LIGHTS_CONTROL' };
					return actionSetBoolRHSMaker(f, v, node, action, 'enabled');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'hex_editor',
				values: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_STATE' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'hex_dialog_mode',
				values: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_DIALOG_MODE' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'hex_control',
				values: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_CONTROL' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'hex_clipboard',
				values: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
			{
				match: (v) => v.bool_setable.type === 'serial_control',
				values: (v, f, node) => {
					const action = { action: 'SET_SERIAL_DIALOG_CONTROL' };
					return actionSetBoolRHSMaker(f, v, node, action, 'bool_value');
				},
			},
		],
		detectError: (v) => ({
			locations: [{ node: v.debug }],
			message: `incompatible bool_setable and bool_or_identifier (lol good luck)`,
		}),
	},
	action_set_position: {
		values: {},
		captures: [ 'movable', 'coordinate' ],
		detective: [
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				values: (v) => ({
					action: 'TELEPORT_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity',
				values: (v) => ({
					action: 'SET_CAMERA_TO_FOLLOW_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				values: (v) => ({
					action: 'TELEPORT_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'entity',
				values: (v) => mathSequenceFns.moveEntityPosToEntityPos(
					v.coordinate.value,
					v.movable.value,
				),
			},
		],
		detectError: (v) => ({
			locations: [{ node: v.debug }],
			message: `incompatible movable identifier and position identifier`,
		}),
	},
	action_move_over_time: {
		values: {},
		captures: [ 'movable', 'coordinate', 'duration', 'forever' ],
		optionalCaptures: [ 'forever' ],
		detective: [
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'origin'
					&& !v.forever,
				values: (v) => ({
					action: 'PAN_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				values: (v) => ({
					action: 'PAN_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				values: (v) => ({
					action: 'LOOP_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity'
					&& !v.forever,
				values: (v) => ({
					action: 'PAN_CAMERA_TO_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'origin'
					&& !v.forever,
				values: (v) => ({
					action: 'WALK_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				values: (v) => ({
					action: 'WALK_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				values: (v) => ({
					action: 'LOOP_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
		],
		detectError: (v) => {
			const err = {
				message: `incompatible movable identifier and position identifier`,
				locations: [{ node: v.debug }],
			}
			if (v.coordinate.type === 'entity') {
				if (v.movable.type === 'entity') {
					err.message = `cannot move an entity to another entity's position over time`;
					err.locations[0].node = v.coordinate.debug;
					}
				if (v.movable.type === 'camera') {
					err.message = `cannot move camera to an entity's position forever`;
					err.locations[0].node = v.coordinate.debug;
				}
			} else if (!!v.forever) {
				err.message = `'forever' can only be used with geometry lengths, not single points`;
				err.locations[0].node = v.coordinate.debug;
			}
			return err;
		},
	},
};

const mathSequenceFns = {
	moveEntityPosToEntityPos: (copyFrom, copyTo) => {
		const variable = '__TEMP';
		return {
			mathlang: 'math_sequence',
			steps: [
				{
					mathlang: 'math_sequence', inbound: true,
					action: 'COPY_VARIABLE', variable,
					entity: copyFrom, field: 'x',
				},
				{
					mathlang: 'math_sequence', inbound: false,
					action: 'COPY_VARIABLE', variable,
					entity: copyTo, field: 'x',
				},
				{
					mathlang: 'math_sequence', inbound: true,
					action: 'COPY_VARIABLE', variable,
					entity: copyFrom, field: 'y',
				},
				{
					mathlang: 'math_sequence', inbound: false,
					action: 'COPY_VARIABLE', variable,
					entity: copyTo, field: 'y',
				},
			]
		}
	},
	setBoolOnFlagName: (f, node, action, boolName) => {
		const gotoLabel = f.p.gotoSuffix();
		const flagName = action.bool_value;
		return {
			mathlang: 'math_sequence',
			steps: [
				{
					// if flagName === true, goto label 'if is true #0'
					mathlang: 'label_to_index',
					action: "CHECK_SAVE_FLAG",
					expected_bool: true,
					label: `if #${gotoLabel}`,
					save_flag: flagName
				},
				{
					// set action bool_value to false
					...action,
					[boolName]: false,
				},
				{
					// goto label 'rendezvous #0'
					mathang: 'goto_label',
					label: `rendezvous #${gotoLabel}`
				},
				{
					// label 'if is true #0'
					mathang: 'label_definition',
					label: `if #${gotoLabel}`,
				},
				{
					// set action bool_value to true
					...action,
					[boolName]: true,
				},
				{
					// label: rendezvous #0
					mathang: 'label_definition',
					label: `rendezvous #${gotoLabel}`
				},
			].map(v=>({ ...v, node, fileName: f.fileName })),
		}
	},
};

const actionSetBoolRHSMaker = (f, v, node, action, boolLabel) => {
	if (v.bool_or_identifier.type === 'boolean') {
		action[boolLabel] = v.bool_or_identifier.value;
	} else {
		action = mathSequenceFns.setBoolOnFlagName(f, node, action, boolLabel);
	}
	return action;
};

module.exports = { handleAction, handleActionsInit };
