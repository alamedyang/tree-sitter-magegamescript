import { Node as TreeSitterNode } from 'web-tree-sitter';
import * as TYPES from './parser-types.ts';
import { ansiTags as ansi } from './parser-utilities.js';

// Linux-sempai says use only red, or red and cyan, and don't use the others; you have no idea whether they're using a dark or light theme, or what their theme is like and some colors WILL NOT show up, depending.

const tagsToAnsiEscapes = (str: string) => {
	let ret = str;
	Object.entries(ansi).forEach(([k, v]) => {
		// TODO: what if you want to actually print <r>?
		// Do this again but ignoring escaped chars
		const reg = new RegExp(`<${k}>`, 'g');
		ret = ret.replace(reg, v);
	});
	return ret;
};

const countCharLength = (str: string) => {
	let length = 0;
	let remainder = str;
	while (remainder.length) {
		const percent = remainder.match(/^%.*%/); // entity name
		if (percent) {
			length += 12;
			remainder = remainder.slice(percent[0].length);
			continue;
		}
		const dollar = remainder.match(/^\$.*\$/); // variable (int) value
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
		// TODO: maybe don't do this part; probably slow
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

const wrapText = (origStr: string, wrap: number, doAnsiWrapBodge: boolean = false): string => {
	// todo: hyphenated words?
	let str = origStr
		.replace(/\\n/g, '\n')
		.replace(/\\t/g, '\t')
		.replace(/\\"/g, '\"')
		.replace(/[“”]/g, '"')
		.replace(/[‘’]/g, "'")
		.replace(/…/g, '...')
		.replace(/—/g, '--') // emdash
		.replace(/–/g, '-'); // endash
	if (wrap === 0) {
		return str;
	} else {
		str = str.replace(/\t/g, '    ');
	}
	const result: string[] = [];
	str.split('\n').forEach((line) => {
		const chunkRegExp = new RegExp(/(?<spaces>[ ]*|^)(?<word>[^ ]+|$)/g);
		let insert = '';
		let insertLength = 0;
		let chunk = chunkRegExp.exec(line);
		while (chunk?.[0] !== '') {
			if (!chunk) break;
			const spaces = chunk.groups?.spaces;
			const word = chunk.groups?.word;
			if (spaces === undefined || word === undefined) throw new Error('TS FR');
			const spacesLength = spaces.length;
			const wordLength = countCharLength(word);
			const potentialLength = insertLength + wordLength + spacesLength;
			if (potentialLength <= wrap || insert === '') {
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
const ansiWrapBodge = (arr: string[]) => {
	let wrappedTags = new Set();
	const bodged = arr.map((line) => {
		const prevTags = wrappedTags.size ? [...wrappedTags].join('') : '';
		let pos = 0;
		while (pos < line.length) {
			if (line[pos] !== '\u001B') {
				pos += 1;
				continue;
			}
			if (line.slice(pos + 1).startsWith('[0m')) {
				wrappedTags = new Set();
				pos += 4;
				continue;
			}
			const tag = line[pos] + line.slice(pos + 1).match(/\[\d+m/);
			wrappedTags.add(tag);
			pos += tag.length;
			continue;
		}
		return prevTags + line;
	});
	return bodged;
};

export const buildSerialDialogFromInfo = (f: TYPES.FileState, info: TYPES.SerialDialogInfo) => {
	const serialDialogSettings: TYPES.SerialDialogSettings = {
		wrap: 80,
		...(f.settings.serial || {}), // global settings
		...info.settings, // local settings
	};
	const serialDialog: TYPES.SerialDialog = {
		mathlang: 'serial_dialog',
		info,
		messages: [],
	};
	serialDialog.messages = info.messages
		.map(tagsToAnsiEscapes)
		.map((message: string) => wrapText(message, serialDialogSettings.wrap as number, true));
	if (info.options.length > 0) {
		const firstOptionType = info.options[0].optionType;
		serialDialog[firstOptionType] = info.options;
		const warnNodes: TYPES.MGSLocation[] = [];
		info.options.forEach((option) => {
			if (option.optionType !== firstOptionType) {
				const node = option.debug.firstChild;
				if (!node) throw new Error('TS');
				warnNodes.push({ node });
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

const longerAlignments = {
	BL: 'BOTTOM_LEFT',
	TL: 'TOP_LEFT',
	BR: 'BOTTOM_RIGHT',
	TR: 'TOP_RIGHT',
};

export const buildDialogFromInfo = (
	f: TYPES.FileState,
	info: TYPES.DialogInfo,
	messageNodes: TreeSitterNode[],
) => {
	const ident = info.identifier;
	let found = false;
	let specificSettings: TYPES.DialogSettings = {};
	if (ident.type === 'label') {
		const settingsLookup = f.settings.label[ident.value];
		if (settingsLookup) {
			specificSettings = settingsLookup;
		} else {
			specificSettings = {
				...f.settings.entity[ident.value],
				entity: ident.value,
			};
		}
		found = true;
	} else if (ident.type === 'name') {
		specificSettings.name = ident.value;
		found = true;
	}
	if (!found || ident.type === 'entity') {
		specificSettings = f.settings.entity[ident.value] || {};
		specificSettings.entity = ident.value;
	}
	const dialogSettings = {
		wrap: 42,
		alignment: 'BOTTOM_LEFT',
		...f.settings.default, // global default settings
		...specificSettings, // global specific settings
		...info.settings, // local specific settings
	};
	const expandedAbbreviation = longerAlignments[dialogSettings.alignment];
	if (expandedAbbreviation) {
		dialogSettings.alignment = expandedAbbreviation;
	}
	const dialog: TYPES.Dialog = {
		...dialogSettings,
		mathlang: 'dialog',
		messages: [],
		info,
	};
	// this needs to be outside to get the actual wrap value btw:
	dialog.messages = info.messages.map((message: string) =>
		wrapText(message, dialogSettings.wrap),
	);
	if (info.options.length > 0) {
		dialog.response_type = 'SELECT_FROM_SHORT_LIST';
		dialog.options = info.options;
		dialog.options.forEach((option, i) => {
			if (dialog.options?.[i]) {
				dialog.options[i].label = wrapText(option.label, 0);
			}
		});
	}
	const lastIndex = dialog.messages.length - 1;
	dialog.messages.forEach((message, i) => {
		const targetSize = lastIndex === i && dialog.options ? 1 : 5;
		const splitMessage: string[] = message.split('\n');
		if (splitMessage.length > targetSize) {
			let warningMessage = `dialog messages longer than 5 lines will wrap off the bottom`;
			if (lastIndex === i && dialog.options) {
				warningMessage = `messages before dialog options will collide if more than 1 line`;
			}
			f.newWarning({
				locations: [{ node: messageNodes[i] }],
				message: warningMessage,
				footer:
					`When wrapped:\n` +
					splitMessage
						.map((v, i, arr) => {
							let row: number | string = i + 1;
							if (arr.length > 9) {
								row = row < 10 ? '0' + row : row;
							}
							let ret = `${row}> ${v}`;
							if (i >= targetSize) {
								ret = ansi.r + `(x) ` + ret + ansi.reset;
							} else {
								ret = `    ` + ret;
							}
							return ret;
						})
						.join('\n'),
			});
		}
	});
	return dialog;
};
