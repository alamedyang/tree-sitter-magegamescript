const handleCapture = require('./parser-capture.js');

let handleNode;
const handleActionsInit = (handleNodeFn) => {
	handleNode = handleNodeFn;
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
	let ret = {
		debug: node,
		fileName: f.fileName,
		...data.values,
	};
	const captures = data.captures || [];
	const fancyCaptures = data.fancyCaptures || [];
	const spreadFields = {};
	let spreadSize = -Infinity;
	captures.forEach(field=>{
		const fieldNode = node.childForFieldName(field);
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			ret[field] = capture;
		} else {
			spreadFields[field] = {
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
			f.newError({
				locations: [{ node: captureData.node }],
				message: `spreads must have the same count of items within a given action`,
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
		const fieldNames = [ 'movable', 'coordinate' ];
		const fields = {};
		const fieldCounts = {};
		let maxSpreadCount = -Infinity;
		fieldNames.forEach(fieldName=>{
			const nodes = node.childrenForFieldName(fieldName);
			const handled = nodes.map(v=>handleCapture(f, v)).flat();
			fields[fieldName] = handled;
			fieldCounts[fieldName] = handled.length;
			maxSpreadCount = Math.max(maxSpreadCount, handled.length);
		});
		const lengthsMismatched = Object.values(fieldCounts)
			.some(n=>n !== 1 && n !== maxSpreadCount);
		if (lengthsMismatched) {
			f.newError({
				locations: [{ node }],
				message: `spreads inside this action must contain same number of items`,
			});
		}
		const ret = [];
		for (let i = 0; i < maxSpreadCount; i++) {
			const insert = {
				debug: node,
				fileName: f.fileName,
			};
			const movable = fields.movable[i % fields.movable.length];
			const coord = fields.coordinate[i % fields.coordinate.length];
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
								type: 'copy_entity_value_to_entity_value',
								copyFrom: { entity: coord.value, field: 'x' },
								copyTo: { entity: movable.value, field: 'x' }
							},
							{
								type: 'copy_entity_value_to_entity_value',
								copyFrom: { entity: coord.value, field: 'y' },
								copyTo: { entity: movable.value, field: 'y' }
							},
						]
					});
					continue;
				}
			}
			f.newError({
				locations: [{ node }],
				message: 'incompatible combination of movable identifier and position identifier',
			});
		}
		return ret;
	}
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

module.exports = { handleAction, handleActionsInit };
