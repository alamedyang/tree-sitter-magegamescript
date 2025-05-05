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
		if (!fieldNode) {
			if (data.optionalCaptures.includes(field)) {
				ret[field] = null;
			} else {
				throw new Error ("THIS SHOULDN'T HAPPEN FIX IT")
			}
		} else {
			const capture = handleCapture(f, fieldNode);
			if (!Array.isArray(capture)) {
				ret[field] = capture;
			} else {
				spreadFields[field] = {
					node: fieldNode,
					captures: capture,
				};
			}
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
	let spreadRet = [];
	if (spreadSize === -Infinity) {
		spreadRet = [ ret ];
	} else {
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
	}
	if (data.detective) {
		spreadRet.forEach(item=>{
			// try the action detective
			for (let i = 0; i < data.detective.length; i++) {
				const clueData = data.detective[i];
				const solved = clueData.match(item);
				if (solved) {
					const newValues = clueData.values(item);
					Object.entries(newValues)
						.forEach(([k,v])=>{ item[k] = v; });
					return;
				}
			}
			f.newError({
				locations: [{ node }],
				message: data.detectError(item),
			})
		});
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
	action_set_position: {
		values: {},
		captures: [ 'movable', 'coordinate' ],
		detective: [
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				values: (v) => ({ action: 'TELEPORT_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity',
				values: (v) => ({ action: 'SET_CAMERA_TO_FOLLOW_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				values: (v) => ({ action: 'TELEPORT_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'entity',
				values: (v) => mathSequenceFns.moveEntityToEntity(
					v.coordinate.value,
					v.movable.value,
				),
			},
		],
		detectError: (v) => `incompatible movable identifier and position identifier`,
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
				values: (v) => ({ action: 'PAN_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				values: (v) => ({ action: 'PAN_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				values: (v) => ({ action: 'LOOP_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity'
					&& !v.forever,
				values: (v) => ({ action: 'PAN_CAMERA_TO_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'origin'
					&& !v.forever,
				values: (v) => ({ action: 'WALK_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				values: (v) => ({ action: 'WALK_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				match: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				values: (v) => ({ action: 'LOOP_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
		],
		detectError: (v) => {
			if (v.coordinate.type === 'entity') {
				if (v.movable.type === 'entity') {
					return `cannot move an entity to another entity's position over time`;
				}
				if (v.movable.type === 'camera') {
					return `cannot move camera to an entity's position forever`;
				}
			}
			if (!!v.forever) {
				return `'forever' can only be used with geometry lengths, not origins`
			}
			return `incompatible movable identifier and position identifier`;
		},
	},
};

const mathSequenceFns = {
	moveEntityToEntity: (copyFrom, copyTo) => {
		return {
			mathlang: 'math_sequence',
			steps: [
				{
					type: 'copy_entity_value_to_entity_value',
					copyFrom: { entity: copyFrom, field: 'x' },
					copyTo: { entity: copyTo, field: 'x' }
				},
				{
					type: 'copy_entity_value_to_entity_value',
					copyFrom: { entity: copyFrom, field: 'y' },
					copyTo: { entity: copyTo, field: 'y' }
				},
			]
		}
	},
}

module.exports = { handleAction, handleActionsInit };
