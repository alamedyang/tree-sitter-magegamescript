const makeProjectState = () => {
	const p = { // 'project' :P
		serialDialogs: {},
		dialogs: {},
		scripts: {},
		errors: [],
		warnings: [],
	};
	p.addScript = (node, fileName) => {
		const scriptName = node.scriptName;
		const actions = finalizeActions(p, node.actions, fileName);
		const data = {
			fileName,
			node,
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
	}
	p.addDialog = (node, fileName) => {
		const dialogName = node.dialogName;
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
	p.addSerialDialog = (node, fileName) => {
		const serialDialogName = node.serialDialogName;
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
	p.detectDuplicates = (type) => {
		Object.entries(p[type]).forEach(([k, v])=>{
			if (v.duplicates) {
				p.errors.push({
					locations: v.duplicates.map(dupe=>({
						fileName: dupe.fileName,
						// TODO: work this part out better
						node: type === 'scripts'
							? dupe.node.debug.firstNamedChild
							: dupe.debug.firstNamedChild,
					})),
					message: `multiple ${type} with name "${k}"`,
				});
			}
		});
	};
	p.printMessages = (fileMap, type) => {
		p[type].forEach(thing=>{
			let printFn = console.log;
			if (type === 'warnings') printFn = console.warn;
			if (type === 'errors') printFn = console.error;
			printFn(`\nError: ${thing.message}`);
			thing.locations.forEach(location=>{
				const locationData = getPrintableLocationData(fileMap, location);
				printFn(locationData);
			})
		});
	};
	return p;
};

const getPrintableLocationData = (fileMap, location) => {
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

const mathSequence = {
	copy_entity_value_to_entity_value: (p, step) => {
		const variable = '__TEMP';
		return [
			{
				mathlang: 'math_sequence', step,
				action: 'COPY_VARIABLE', inbound: true,
				...step.copyFrom, variable,
			},
			{
				mathlang: 'math_sequence', step,
				action: 'COPY_VARIABLE', inbound: false,
				...step.copyTo, variable,
			}
		];
	}
}

const finalizeActions = (p, rawActions, fileName) => {
	const ret = [];
	rawActions.forEach(node=>{
		if (!node.mathlang) {
			ret.push(node);
		} else if (node.mathlang === 'dialog_definition') {
			p.addDialog(node, fileName);
		} else if (node.mathlang === 'serial_dialog_definition') {
			p.addSerialDialog(node, fileName);
		} else if (node.mathlang === 'math_sequence') {
			node.steps
				.map(step=>mathSequence[step.type](p, step))
				.forEach(v=>ret.push(v));
		}
	})
	return ret;
};

module.exports = {
	makeProjectState,
};
