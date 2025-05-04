
const {
	reportMissingChildNodes,
	reportErrorNodes,
	debugLog,
} = require('./parser-utilities/general.js');

const {
	buildSerialDialogFromInfo,
	buildDialogFromInfo,
} = require('./parser-utilities/dialog-handling.js');

const handleCapture = require('./parser-capture.js');
const { handleAction, handleActionsInit } = require('./parser-actions.js');

const handleNode = (f, node) => {
	reportMissingChildNodes(f, node);
	reportErrorNodes(f, node);
	debugLog(`handleNode: ${node.grammarType}`)
	if (node.grammarType.startsWith('action_')) {
		return handleAction(f, node);
	}
	const nodeFn = nodeFns[node.grammarType];
	if (!nodeFn) {
		throw new Error ('no named node function for '+ node.grammarType);
	}
	return nodeFn(f, node);
};
handleActionsInit(handleNode);

const nodeFns = {
	line_comment: (f, node) => [],
	block_comment: (f, node) => [],
	ERROR: (f, node) => {
		f.newError({
			node,
			message: 'syntax error',
		});
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
			f.newError({
				node,
				message: `cannot redefine constant ${ret.label}`,
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
		prerequesites.forEach(prereqName=> {
			if (!f.p.fileMap[prereqName].parsed) {
				debugLog(`include_macro: must first parse prerequesite "${prereqName}"`);
				parseFile(p, prereqName);
			} else {
				debugLog(`include_macro: prerequesite "${prereqName}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereqName} into ${f.fileName}...`);
			f.includeFile(prereqName);
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
					f.newError({
						node,
						message: `spreads inside rand!() must contain same number of items`,
					});
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
				f.newError({
					node,
					message: `dialog_settings_target: malformed label definition`,
				});
			}
			const target = targetNode.text || 'UNDEFINED LABEL';
			f.settings.label[target] = f.settings.label[target] || {};
			bucket = f.settings.label[target];
		} else if (type === 'target_entity') {
			if (!targetNode) {
				f.newError({
					node,
					message: `dialog_settings_target: malformed entity definition`,
				});
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
			f.newError({
				node,
				message: `malformed dialog parameter`,
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
			f.newError({
				node,
				message: `malformed serial_dialog parameter`,
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
			f.newError({
				node,
				message: `malformed serial_dialog option`,
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
			f.newError({
				node,
				message: `malformed dialog option`,
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
			f.newError({
				node,
				message: `dialog identifier lacks a value`,
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
			f.newError({
				node,
				message: `JSON syntax error`,
			});
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
				f.newError({
					node,
					message: `undefined entity in entity identifier`,
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

module.exports = handleNode;
