const indent = '  ';
let indentCount = 1;;
let currIndent = '';
const setIndent = () => currIndent = indent.repeat(indentCount);
const increaseIndent = () => {
	indentCount += 1;
	setIndent();
};
const decreaseIndent = () => {
	indentCount -= 1;
	setIndent();
};
setIndent();

const translateOne = (data) => {
	if (data.action) {
		const fn = actions[data.action];
		if (!fn) throw new Error ('Fn needed for ' + data.action);
		return fn(data);
	}
	if (data.mathlang) {
		const fn = mathlang[data.mathlang];
		if (!fn) throw new Error ('Fn needed for ' + data.mathlang);
		return fn(data);
	} 
	throw new Error ('Fn needed for ???')
}

const sanitizeLabel = label => {
	if (label.includes(' ')) {
		return '_'+label.replaceAll(' ', '_').replaceAll('#', '');
	} else {
		return '_'+label;
	}
}

const validateGoto = (data) => {
	if (data.mathlang === 'goto_label') {
		if (!data.label || typeof data.label !== 'string') {
			throw new Error ('Goto not a label jump?', data);
		}
		return `goto label ${sanitizeLabel(data.label)}`;
	}
	if (!data.jump_index) {
		throw new Error ('Goto not a index jump?', data);
	}
	return `goto index ${data.jump_index}`;
}
const setBool = (data, lhs) => {
	const param = data.boolParamName || 'expected_bool';
	return `${currIndent}${lhs} = ${data[param]};`
}

const check = (data, lhs) => {
	const param = data.boolParamName || 'expected_bool';
	const bang = !data[param] ? '!' : '';
	const goto = validateGoto(data);
	return `${currIndent}if (${bang}${lhs}) { ${goto}; }`;
}

const actions = {
	SET_SAVE_FLAG: (data) => setBool(data, data.lhs),
	SET_PLAYER_CONTROL: (data) => setBool(data, 'player_control'),
	CHECK_DEBUG_MODE: (data) => check(data, 'debug_mode'),
	CHECK_ENTITY_GLITCHED: (data) => check(data, `entity "${data.entity}" glitched`),
}

const mathlang = {
	goto_label: (data) => `${currIndent}${validateGoto(data)};`,
	label_definition: (data) => `${currIndent}${sanitizeLabel(data.label)}:`,
}
const translateScript = (scriptName, actions) => {
	const lines = [
		scriptName + ' {',
		...actions.map(translateOne).flat(),
		'}'
	].join('\n');
	return lines;
};

module.exports = {
	translateScript,
}