const buildDialogFromState = state => {
	const dialogSettings = state.final.dialogSettings || [];
	const identifier = state.inserts.dialogIdentifier;
	const parameters = state.inserts.dialogParameters;
	const messages = state.inserts.dialogMessages || [];
	const options = state.inserts.dialogOptions;
	const result = {};
	// getting params from dialogSettings
	if (identifier.type === "name") {
		result.name = identifier.value;
	}
	if (identifier.type === "label") {
		const entityEntries = dialogSettings.filter(item => {
			return item.type === "label"
				&& item.value === identifier.value;
		});
		if (entityEntries.length > 0) {
			entityEntries.forEach(entry => {
				Object.keys(entry.parameters).forEach(propertyName => {
					result[propertyName] = entry.parameters[propertyName];
				});
			})
		} else {
			identifier.type = "entity";
			// result.labelWarning = `No settings found for label "${identifier.value}" -- treating as entity name`;
			// treat as entitiy; will handle immediately below
		}
	}
	if (identifier.type === "entity" || Object.keys(result).length === 0) {
		const entityEntries = dialogSettings.filter(entry => {
			return entry.type === "entity"
				&& entry.value === identifier.value;
		})
		if (entityEntries.length) {
			entityEntries.forEach(entry => {
				Object.keys(entry.parameters).forEach(propertyName => {
					result[propertyName] = entry.parameters[propertyName];
				})
			})
		}
		result.entity = identifier.value;
	}
	// put in global params only if no existing params by that name
	const globalParams = dialogSettings.filter(item => item.type === "global");
	if (globalParams.length) {
		globalParams.forEach(globalEntry => {
			Object.keys(globalEntry.parameters).forEach(propertyName => {
				if (!result[propertyName]) {
					result[propertyName] = globalEntry.parameters[propertyName];
				}
			})
		})
	}
	// override the above with params found in the dialog itself
	if (parameters) {
		Object.keys(parameters).forEach(parameterName => {
			result[parameterName] = parameters[parameterName];
		})
	}
	result.messages = messages.map(string => {
		const cleanedString = mgs.cleanString(string);
		return mgs.wrapText(cleanedString, result.messageWrap, mgs.dialogWrapSpecials);
	});
	if (options?.length) {
		result.response_type = "SELECT_FROM_SHORT_LIST";
		result.options = options.map(option => {
			return {
				label: mgs.cleanString(option.label),
				script: option.script
			}
		});
	}
	const alignmentMap = {
		"BL": "BOTTOM_LEFT",
		"BR": "BOTTOM_RIGHT",
		"TL": "TOP_LEFT",
		"TR": "TOP_RIGHT",
		"BOTTOM_LEFT": "BOTTOM_LEFT",
		"BOTTOM_RIGHT": "BOTTOM_RIGHT",
		"TOP_LEFT": "TOP_LEFT",
		"TOP_RIGHT": "TOP_RIGHT"
	};
	const newAlignment = alignmentMap[result.alignment];
	if (!newAlignment) {
		const warningMessage = "Alignment cannot be " + result.alignment + "; falling back to 'BOTTOM_LEFT'";
		console.warn(warningMessage);
		result.alignWarning = warningMessage;
		result.alignment = "BOTTOM_LEFT";
	} else {
		result.alignment = newAlignment;
	}
	delete result.messageWrap;
	return result;
};

const wrapText = (inputString, wrapTo, wrapSpecials) => {
	// TODO: hyphenated words?
	wrapTo = wrapTo || 42; // magic number alert!
	const stringsResults = [];
	const countSpaces = string => {
		const match = string.match(/^ +/);
		return match ? match[0].length : false;
	};
	inputString.split('\n').forEach(line => {
		let workingString = mgs.cleanString(line);
		let pos = 0;
		let insert = '';
		let insertLength = 0;
		let lastSpaceFound = null;
		while (workingString.substring(pos).length) {
			// spaces (newlines removed above; tabs were converted to spaces prior)
			const spaceCount = countSpaces(workingString.substring(pos));
			if (spaceCount) {
				lastSpaceFound = pos;
				pos += spaceCount;
				insert += ' '.repeat(spaceCount);
				insertLength += spaceCount;
				continue;
			}
			// things other than spaces
			const word = mgs.countWordChars(
				workingString.substring(pos),
				wrapSpecials
			);
			if (insertLength + word.size > wrapTo) {
				const choppedInsert = insert.substring(0, lastSpaceFound);
				stringsResults.push(choppedInsert);
				workingString = workingString.substring(pos);
				pos = 0;
				insert = '';
				insertLength = 0;
				lastSpaceFound = null;
			}
			pos += word.match.length;
			insert += word.match;
			insertLength += word.size;
		}
		stringsResults.push(insert);
	})
	return stringsResults.join('\n');
};
const buildSerialDialogFromState = state => {
	const messages = state.inserts.serialDialogMessages || [];
	const options = state.inserts.serialDialogOptions || [];
	const optionType = state.inserts.serialOptionType || null;
	const result = {};
	// wrap amount
	const globalParams = state.final.serialDialogParameters || {};
	const localParams = state.inserts.serialDialogParameters || {};
	let wrapTo = 80;
	if (localParams.messageWrap) {
		wrapTo = localParams.messageWrap;
	} else if (globalParams.messageWrap) {
		wrapTo = globalParams.messageWrap;
	}	
	result.messages = messages.map(string => {
		const cleanedString = mgs.cleanString(string);
		const wrappedString = mgs.wrapText(cleanedString, wrapTo, mgs.serialWrapSpecials);
		return mgs.replaceTagsWithAnsi(wrappedString);
	});
	if (options?.length) {
		if (optionType === 'options') { // multiple choice
			result.options = options.map(item => {
				item.label = mgs.cleanString(mgs.replaceTagsWithAnsi(item.label));
				return item;
			});
		} else if (optionType === 'text_options') { // free choice
			result.text_options = {};
			options.forEach(item => {
				const label = mgs.cleanString(item.label);
				result.text_options[label] = item.script;
			})
		}
	}
	return result;
};
