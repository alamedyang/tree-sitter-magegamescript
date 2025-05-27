const TreeSitter = require('web-tree-sitter');
const { Parser, Language } = TreeSitter;

const { debugLog } = require('./parser-utilities.js');
const { parseProject } = require('./parser.js');
const { ansiTags } = require('./parser-dialogs.js');

// const fileMap = {
// 	"binaryOperations.mgs": {
// 		fileText: ``
// 			+ `\n simple { a = 1; player x = 1; }`
// 			+ `\n addition { a = 1+2; player x = 1+2; }`
// 			+ `\n order1 { a = 1+2*3; player x = 1+2*3; }`
// 			+ `\n order2 { a = 1*2+3; player x = 1*2+3; }`,
// 		expected: [],
// 	},
// };

const roundTripTestData = {
	noArgActions: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'save slot;',
			'close dialog;',
			'close serial_dialog;',
		],
	},
	simpleActions: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'wait 1000ms;',
			'block 999ms;',
			'load slot 0;',
			'erase slot 0;',
			'load map goatMap;',
		],
	},
	simpleTranslations: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			`wait 1s;`
		],
		expected: [
			`wait 1000ms;`
		],
	},
	SET_SCRIPT_PAUSE: {
		autoAddReturn: true,
		input: [
			'pause player on_look;',
			'pause self on_look;',
			'pause entity Bob on_look;',
			'pause entity "Bob" on_look;',
			'unpause player on_look;',
			'unpause self on_look;',
			'unpause entity Bob on_look;',
			'unpause entity "Bob" on_look;',
			'pause player on_interact;',
			'pause self on_interact;',
			'pause entity Bob on_interact;',
			'pause entity "Bob" on_interact;',
			'unpause player on_interact;',
			'unpause self on_interact;',
			'unpause entity Bob on_interact;',
			'unpause entity "Bob" on_interact;',
			'pause player on_tick;',
			'pause self on_tick;',
			'pause entity Bob on_tick;',
			'pause entity "Bob" on_tick;',
			'unpause player on_tick;',
			'unpause self on_tick;',
			'unpause entity Bob on_tick;',
			'unpause entity "Bob" on_tick;',
			'pause map on_tick;',
			'unpause map on_tick;',
			'pause map on_load;',
			'unpause map on_load;',
			'pause map on_command;',
			'unpause map on_command;',
		],
	}
};

const actionArrayToScript = (scriptName, actionArray, autoAddReturn) => {
	const ret = [
		`${scriptName} {`,
		...actionArray.map(v=>'\t'+v),
	];
	if (autoAddReturn) {
		ret.push(`\tend_of_script_*:`);
	}
	ret.push('}');
	return ret.join('\n')
};

// The actual tests that are to be run
const roundTripTests = {};
Object.entries(roundTripTestData).forEach(([testName, data])=>{
	if (data.type === 'actions') {
		const fileText = actionArrayToScript(testName, data.input);
		const expected = data.expected
			? actionArrayToScript(testName, data.expected, data.autoAddReturn)
			: actionArrayToScript(testName, data.input, data.autoAddReturn);
		roundTripTests[testName] = { fileText, expected };
	}
});
const testFileName = 'TESTS.mgs';
const fileMap = {
	[testFileName]: {
		fileText: Object.values(roundTripTests)
			.map(v=>v.fileText)
			.join('\n\n'),
	},
};

const makeTextUniform = (text) => text.trim()
	.replace(/[\t ]+/g, ' ')
	.replace(/\/\/.*?[\n|$]/g, '');
const compareTexts = (_found, _expected, fileName, scriptName) => {
	const foundLines = makeTextUniform(_found)
		.split('\n')
		.map(v=>v.trim())
		.filter(v=>!!v);
	const expectedLines = makeTextUniform(_expected)
		.split('\n')
		.map(v=>v.trim())
		.filter(v=>!!v);
	if (foundLines.length !== expectedLines.length) {
		return {
			status: 'fail',
			message: 'different line counts',
		}
	}
	const lines = [];
	foundLines.forEach((found,  i)=>{
		const expected = expectedLines[i];
		if (expected === found) {
			// we good
			return;
		}
		// pull out the wildcards
		const regExpected = new RegExp(expected.replaceAll('*', '.+?'));
		if (found.match(regExpected)) {
			// we good
			return;
		}
		// or they really are different
		const diff = [];
		const foundChars = found.split('');
		for (let i = 0; i < foundChars.length; i++) {
			const c = foundChars[i];
			if (c !== expected[i]) {
				diff.push(ansiTags.yellow);
			}
			diff.push(c);
		}
		lines.push({
			expected,
			found,
			diff: diff.join(''),
			fileName,
			lineIndex: i
		});
	})
	if (lines.length) {
		return {
			status: 'fail',
			message: `${scriptName}: lines do not match`,
			lines,
		}
	} else {
		return {
			status: 'success'
		}
	}
};

const errors = [];

const runTests = async () => {
	parseProject(fileMap, {}).then(result=>{
		// console.log(result);
		Object.keys(result.scripts).forEach(scriptName => {
			const expected = roundTripTests[scriptName].expected;
			const found = result.scripts[scriptName].print;
			const compared = compareTexts(found, expected, testFileName, scriptName);
			if (compared.status !== 'success') {
				errors.push(compared);
			}
		})
		errors.forEach(error=>{
			console.error(error.message);
			if (error.lines) {
				error.lines.forEach(v=>{
					console.error(`   Found: ${v.diff}`);
					console.error(`Expected: ${v.expected}`);
				});
			}
		})
		if (errors.length === 0) {
			console.log("All tests good, chief!")
		}
		console.log('BREAK ME')
	});
};

runTests();
