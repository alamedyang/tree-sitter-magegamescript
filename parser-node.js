const {
	reportMissingChildNodes,
	reportErrorNodes,
	debugLog,
	expandCondition,
	label,
	gotoLabel,
	simpleBranchMaker,
	newMathSequence,
	newSerialDialog,
	showSerialDialog,
} = require('./parser-utilities.js');

const {
	buildSerialDialogFromInfo,
	buildDialogFromInfo,
} = require('./parser-dialogs.js');

const handleCapture = require('./parser-capture.js');
const { handleAction, handleActionsInit } = require('./parser-actions.js');

const handleNode = (f, node) => { // ->[]
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
		throw new Error ('no named node function for '+ node.grammarType);
	}

	// Do it
	return nodeFn(f, node);
};

// Cyclic dependency bodge!
handleActionsInit(handleNode);

// These must return an array, because they might produce multiple things (or zero things)
// NOTICE: The caller should flat() what it receives!
const nodeFns = {
	line_comment: (f, node) => [],
	block_comment: (f, node) => [],
	ERROR: (f, node) => {
		const err = {
			locations: [{ node }],
			message: 'syntax error',
		}
		// I guess feel free to add more of these as they come up
		// This might be the only place some of them can be detected
		if (node.namedChildren.some(v=>v.type === 'over_time_operator')) {
			err.message = `malformed 'do over time' expression`
			err.footer = `should take the form '@movable -> @coordinate over @duration [forever];'\n`
				+ `   @movable = (player | self | entity @string) position | camera\n`
				+ `   @coordinate = (player | self | entity @string) position | geometry @string (origin | length)`
		}
		f.newError(err);
		return [];
	},
	script_definition: (f, node) => {
		const nameNode = node.childForFieldName('script_name');
		const name = handleCapture(f, nameNode);
		const actions = node.lastChild
			.namedChildren // error nodes are caught above
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
				locations: [{ node }],
				message: `cannot redefine constant ${ret.label}`,
			});
		}
		f.constants[label] = {
			value,
			type: valueNode.grammarType, // fyi only; not using this currently
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
				f.p.parseFile(prereqName);
			} else {
				debugLog(`include_macro: prerequesite "${prereqName}" already parsed`);
			}
			debugLog(`include_macro: merging ${prereqName} into ${f.fileName}...`);
			f.includeFile(prereqName); // incorporate their crawl state into us
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
				if (len === 0) return; // empties are ignored
				horizontal.push(handled);
				if (len === 1) return;
				if (multipleCount === -Infinity) multipleCount = len;
				if (multipleCount !== len) {
					f.newError({
						locations: [{ node }],
						message: `spreads inside rand!() must contain same number of items`,
					});
				}
			});
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
		return label(f, node, label);
	},
	add_dialog_settings: (f, node) => {
		const targets = node.namedChildren
			.map(child=>handleNode(f, child)) // add_dialog_settings_target
			.flat();
		return [{
			mathlang: 'add_dialog_settings',
			targets,
			debug: node,
			fileName: f.fileName,
		}]
	},
	add_dialog_settings_target: (f, node) => {
		let settingsTarget;
		const type = node.firstChild.text;
		const ret = {
			mathlang: 'add_dialog_settings_target',
			type,
			debug: node,
			fileName: f.fileName,
		};
		// figure out which settings we're adding to (the "target")
		if (type === 'default') {
			settingsTarget = f.settings.default;
		} else if (type === 'label' || type === 'entity') {
			const targetNode = node.childForFieldName('target');
			if (targetNode) {
				const target = handleCapture(f, targetNode);
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
		const parameters = node.childrenForFieldName('dialog_parameter')
			.map(innerChild=>handleCapture(f, innerChild));
		parameters.forEach(param=>{
			settingsTarget[param.property] = param.value;
		});
		ret.parameters = parameters;
		return [ret];
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
	serial_dialog_option: (f, node) => {
		const optionNode = node.childForFieldName('option_type');
		const labelNode = node.childForFieldName('label');
		const scriptNode = node.childForFieldName('script');
		if (!optionNode || !labelNode || !scriptNode) {
			f.newError({
				locations: [{ node }],
				message: `malformed serial_dialog option`,
			});
			return [];
		}
		let optionType;
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
				locations: [{ node }],
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
		const serialDialog = handleNode(f, serialDialogNode);
		return [ newSerialDialog(f, node, name, serialDialog[0]) ];
	},
	dialog_definition: (f, node) => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = handleCapture(f, nameNode);
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = dialogNodes
			.map(dialogNode=>handleNode(f, dialogNode))
			.flat();
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
		const params = paramNodes.map(node=>handleCapture(f, node));
		const options = optionNodes.map(node=>handleNode(f, node)).flat();
		// TODO: make options more closely resemble final form?
		const settings = {};
		params.forEach(param=>{ settings[param.property] = param.value; });
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
		const identifier = handleCapture(f, identifierNode);
		const params = paramNodes.map(v=>handleCapture(f, v));
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
		const dialogs = buildDialogFromInfo(f, info, messageNodes);
		return [{
			mathlang: 'dialog',
			info,
			dialogs,
			debug: node,
			fileName: f.fileName,
		}];
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
			});
		}
		return [{
			mathlang: 'json_literal',
			json: parsed,
			debug: node,
			fileName: f.fileName,
		}];
	},
	debug_macro: (f, node) => {
		const checkDebugInfo = {
			action: 'CHECK_DEBUG_MODE',
			boolParamName: 'expected_bool'
		};
		const ret = [];
		let name;
		const serialDialogNode = node.childForFieldName('serial_dialog');
		if (serialDialogNode) {
			const serialDialog = handleNode(f, serialDialogNode).flat();
			name = autoIdentifierName(f, node);
			ret.push(newSerialDialog(f, node, name, serialDialog));
		} else {
			const nameNode = node.childForFieldName('serial_dialog_name');
			name = handleCapture(f, nameNode);
		}
		const action = simpleBranchMaker(
			f,
			node,
			checkDebugInfo,
			showSerialDialog(f, node, name),
			[],
		);
		ret.push(action);
		return ret;
	},
	if_chain: (f, node) => {
		const ifs = node.childrenForFieldName('if_block');
		const elzeNode = node.childForFieldName('else_block');
		const rendezvousLabel = `rendezvous #${f.p.advanceGotoSuffix()}`;
		const steps = [];
		let bottomSteps = [
			label(f, node, rendezvousLabel),
		];
		ifs.forEach(iff=>{
			const ifLabel = `if true #${f.p.advanceGotoSuffix()}`;
			// const elseLabel = `if else #${f.p.getGotoSuffix()}`;
			const conditionNode = iff.childForFieldName('condition').namedChildren[0];
			const condition = handleCapture(f, conditionNode);
			const bodyNode = iff.childForFieldName('body');
			const conditions = expandCondition(f, conditionNode, condition, ifLabel);
			const body = bodyNode.namedChildren.map(v=>handleNode(f, v)).flat();
			// add top half
			conditions.forEach(v=>steps.push(v));
			// add bottom half
			const bottomInsert = [
				label(f, node, ifLabel),
				...body,
				gotoLabel(f, node, rendezvousLabel),
			];
			bottomSteps = bottomInsert.concat(bottomSteps);
		});
		if (elzeNode) {
			const elze = elzeNode.lastChild.namedChildren.map(v=>handleNode(f, v)).flat();
			steps.push(
				...elze,
				gotoLabel(f, node, rendezvousLabel),
			);
		}
		const combined = steps.concat(bottomSteps);
		return {
			mathlang: 'if_sequence',
			steps: combined,
		}
	},
};

module.exports = handleNode;

// TODO: what is the difference between handleNode() and handleCapture() except that you have to flatten handleNode()?
// Is it that you return complex thing vs primitive value?
// Is it that action wants to call handleCapture() and then work on its properties?
