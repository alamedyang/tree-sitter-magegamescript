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
	// todo: hyphenated words?
	let str = origStr
		.replace(/\\n/g, '\n')
		.replace(/\\t/g, '\t')
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

// This is for the web build, which does not carry over ansi styles when things are wrapped
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
		const warnNodes = [];
		info.options.forEach(option=>{
			if (option.optionType !== firstOptionType) {
				warnNodes.push({
					node: option.debug.firstChild,
				});
			}
		});
		if (warnNodes.length > 0) {
			f.newWarning({
				locations: warnNodes,
				message: `serial dialog option types mismatch; first type (${firstOptionType}) will be used`,
			});
		}
	}
	return serialDialog;
};

const buildDialogFromInfo = (f, info, messageNodes) => {
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
	// this needs to be outside to get the actual wrap value btw:
	dialog.messages = info.messages
		.map(message=>wrapText(message, dialog.wrap));
	if (info.options.length > 0) {
		dialog.response_type = 'SELECT_FROM_SHORT_LIST';
		dialog.options = info.options;
	}
	dialog.messages.forEach((message, i, arr)=>{
		const lastIndex = arr.length - 1;
		const targetSize = lastIndex === i && dialog.options ? 1 : 5;
		const splitMessage = message.split('\n');
		if (splitMessage.length > targetSize) {
			let warningMessage = `dialog messages longer than 5 lines will wrap off the bottom`;
			if (lastIndex === i && dialog.options) {
				warningMessage = `messages before dialog options will collide if more than 1 line`;
			}
			f.newWarning({
				locations: [{ node: messageNodes[i] }],
				message: warningMessage,
				footer: `When wrapped:\n` + splitMessage.map((v, i, arr)=>{
					let row = i+1;
					if (arr.length > 9) {
						row = row < 10 ? '0' + row : row;
					}
					let ret = `${row}> ${v}`;
					if (i >= targetSize) {
						ret = ansiTags.r + `(x) ` + ret + ansiTags.reset;
					} else {
						ret = `    ` + ret;
					}
					return ret;
				}).join('\n')
			});
		}
	})
	return dialog;
};

module.exports = {
	buildSerialDialogFromInfo,
	buildDialogFromInfo,
	ansiTags,
};
