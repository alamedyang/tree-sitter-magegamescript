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
	no_arg_actions: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// SLOT_SAVE
			'save slot;',
			// CLOSE_DIALOG
			'close dialog;',
			// CLOSE_SERIAL_DIALOG
			'close serial_dialog;',
		],
	},
	simple_actions: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// BLOCKING_DELAY
			'wait 1000ms;',
			// NON_BLOCKING_DELAY
			'block 999ms;',
			// SLOT_LOAD
			'load slot 0;',
			// SLOT_ERASE
			'erase slot 0;',
			// LOAD_MAP
			'load map goatMap;',
		],
	},
	SET_SCRIPT_PAUSE: {
		autoAddReturn: true,
		input: [
			// SET_SCRIPT_PAUSE
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
	},
	commands_and_aliases: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// REGISTER_SERIAL_DIALOG_COMMAND
			'command callGoat = goatScript;',
			'command callGoat fail = goatScript;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND
			'delete command callGoat;',
			// TODO: how to delete the fail though?
			// REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
			'command callGoat + billy = billyScript;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
			'delete command callGoat + billy;',
			// REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
			'alias g = callGoat;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS
			'delete alias g;',
			// SET_SERIAL_DIALOG_COMMAND_VISIBILITY
			'hide command callGoat;',
			'unhide command callGoat;',
		],
	},
	set_position: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// SET_CAMERA_TO_FOLLOW_ENTITY
			'camera = player position;',
			// TELEPORT_CAMERA_TO_GEOMETRY
			'camera = geometry stick;',
			// TELEPORT_ENTITY_TO_GEOMETRY
			'player position = geometry stick;',
			// SET_ENTITY_DIRECTION_TARGET_ENTITY
			'self direction = player;',
			'entity Bender direction = player;',
			'player direction = player;',
			'player direction = self;',
			'self direction = self;',
			'entity Bender direction = self;',
			'player direction = entity Bob;',
			'self direction = entity Bob;',
			'entity Bender direction = entity Bob;',
			// SET_ENTITY_DIRECTION_TARGET_GEOMETRY
			'player direction = geometry stick;',
			'self direction = geometry stick;',
			'entity Bender direction = geometry stick;',
		],
	},
	set_position_over_time: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// WALK_ENTITY_TO_GEOMETRY
			'player position -> geometry stick origin over 1ms;',
			'self position -> geometry stick origin over 1ms;',
			'entity Oscar position -> geometry stick origin over 1ms;',
			// WALK_ENTITY_ALONG_GEOMETRY
			'player position -> geometry stick length over 1ms;',
			'self position -> geometry stick length over 1ms;',
			'entity Oscar position -> geometry stick length over 1ms;',
			// LOOP_ENTITY_ALONG_GEOMETRY
			'player position -> geometry stick length over 1ms forever;',
			'self position -> geometry stick length over 1ms forever;',
			'entity Oscar position -> geometry stick length over 1ms forever;',
			// PAN_CAMERA_TO_ENTITY
			'camera -> player position over 1ms;',
			'camera -> self position over 1ms;',
			'camera -> entity Bob position over 1ms;',
			// PAN_CAMERA_TO_GEOMETRY
			'camera -> geometry stick origin over 1ms;',
			// PAN_CAMERA_ALONG_GEOMETRY
			'camera -> geometry stick length over 1ms;',
			// LOOP_CAMERA_ALONG_GEOMETRY
			'camera -> geometry stick length over 1ms forever;',
		],
	},
	other_do_over_time: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// SET_SCREEN_SHAKE
			'camera shake -> 20ms 50px over 100ms;',
			// SCREEN_FADE_IN
			'camera fade in -> #000000 over 100ms;',
			// SCREEN_FADE_OUT
			'camera fade out -> #FFFFFF over 100ms;',
			// PLAY_ENTITY_ANIMATION
			'player animation -> 0 4x;',
			'self animation -> 0 4x;',
			'entity George animation -> 0 4x;',
		],
	},
	simpleTranslations: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// seconds -> milliseconds
			`wait 1s;`,
			// color words -> hex
			'camera fade in -> white over 1s;',
			'camera fade in -> black over 1s;',
			'camera fade in -> red over 1s;',
			'camera fade in -> green over 1s;',
			'camera fade in -> blue over 1s;',
			'camera fade in -> magenta over 1s;',
			'camera fade in -> cyan over 1s;',
			'camera fade in -> yellow over 1s;',
			'camera fade in -> #ABC over 1;',
			'camera fade in -> #def over 1;',
			// counts
			'player animation -> 0 once;',
			'player animation -> 0 twice;',
			'player animation -> 0 thrice;',
			// pix -> px
			'camera shake -> 2s 50pix over 1000;',
		],
		expected: [
			`wait 1000ms;`,
			'camera fade in -> #FFFFFF over 1000ms;',
			'camera fade in -> #000000 over 1000ms;',
			'camera fade in -> #FF0000 over 1000ms;',
			'camera fade in -> #00FF00 over 1000ms;',
			'camera fade in -> #0000FF over 1000ms;',
			'camera fade in -> #FF00FF over 1000ms;',
			'camera fade in -> #00FFFF over 1000ms;',
			'camera fade in -> #FFFF00 over 1000ms;',
			'camera fade in -> #AABBCC over 1ms;',
			'camera fade in -> #ddeeff over 1ms;',
			'player animation -> 0 1x;',
			'player animation -> 0 2x;',
			'player animation -> 0 3x;',
			'camera shake -> 2000ms 50px over 1000ms;',
		],
	},
	set_string: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// SET_WARP_STATE
			'warp_state = goat;',
			// SET_ENTITY_NAME
			'player name = goat;',
			'self name = goat;',
			'entity Billy name = goat;',
			// SET_ENTITY_TYPE
			'player type = goat;',
			'self type = goat;',
			'entity Billy type = goat;',
			// SET_ENTITY_PATH
			'player path = goat;',
			'self path = goat;',
			'entity Billy path = goat;',
			// SET_ENTITY_DIRECTION
			'player direction = north;',
			'self direction = north;',
			'entity Billy direction = north;',
			// SET_ENTITY_LOOK_SCRIPT
			'player on_look = goatScript;',
			'self on_look = goatScript;',
			'entity Billy on_look = goatScript;',
			// SET_ENTITY_INTERACT_SCRIPT
			'player on_interact = goatScript;',
			'self on_interact = goatScript;',
			'entity Billy on_interact = goatScript;',
			// SET_ENTITY_TICK_SCRIPT
			'player on_tick = goatScript;',
			'self on_tick = goatScript;',
			'entity Billy on_tick = goatScript;',
			// SET_MAP_TICK_SCRIPT
			'map on_tick = goatScript;',
		],
	},
	set_bool_exp_ok: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// SET_SAVE_FLAG
			'flagName = true;',
			// SET_HEX_EDITOR_STATE
			'hex_editor = true;',
			// SET_HEX_EDITOR_DIALOG_MODE
			'hex_dialog_mode = true;',
			// SET_HEX_EDITOR_CONTROL
			'hex_control = true;',
			// SET_HEX_EDITOR_CONTROL_CLIPBOARD
			'hex_clipboard = false;',
			// SET_SERIAL_DIALOG_CONTROL
			'serial_control = false;',
			// SET_PLAYER_CONTROL
			'player_control = false;',
			// SET_LIGHTS_CONTROL
			'lights_control = false;',
			// SET_LIGHTS_STATE
			'light MEM1 = true;',
			// SET_ENTITY_GLITCHED
			'entity Bob glitched = false;',
		],
	},
	set_bool_exp_ok_translations: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'flagName = true;',
			'hex_editor = on;',
			'hex_dialog_mode = down;',
			'hex_control = open;',
			'hex_clipboard = false;',
			'serial_control = off;',
			'player_control = up;',
			'lights_control = closed;',
			'light MEM1 = on;',
			'entity Bob glitched = true;',
		],
		expected: [
			'flagName = true;',
			'hex_editor = true;',
			'hex_dialog_mode = true;',
			'hex_control = true;',
			'hex_clipboard = false;',
			'serial_control = false;',
			'player_control = false;',
			'lights_control = false;',
			'light MEM1 = true;',
			'entity Bob glitched = true;',
		],
	},
	bool_exp_simple_branch: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = debug_mode',
		],
		expected: [
			'// simple branch on: debug_mode',
			'if (debug_mode) { goto label if_***; }',
			'entity Bob glitched = false;',
			'goto label rendezvous_***;',
			"if_***:",
			'entity Bob glitched = true;',
			"rendezvous_***:",
		],
	},
	bool_exp_simple_branch_inverse: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = !debug_mode',
		],
		expected: [
			'if (!debug_mode) { goto label if_***; }',
			'entity Bob glitched = false;',
			'goto label rendezvous_***;',
			"if_***:",
			'entity Bob glitched = true;',
			"rendezvous_***:",
		],
	},
	bool_exp_simple_or: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = debug_mode || isGoatGrumpy;',
		],
		expected: [
			'if (debug_mode) { goto label if_***; }',
			'if (isGoatGrumpy) { goto label if_***; }',
			'entity Bob glitched = false;',
			'goto label rendezvous_***;',
			"if_***:",
			'entity Bob glitched = true;',
			"rendezvous_***:",
		],
	},
	bool_exp_simple_and: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = debug_mode && isGoatGrumpy;',
		],
		expected: [
			'if (debug_mode) { goto label if_true_*A*; }',
			'goto label rendezvous_*A*;',
			'if_true_*A*:',
			'if (isGoatGrumpy) { goto label if_true_*B*; }',
			'rendezvous_*A*:',
			'entity \'Bob\' glitched = false;',
			'goto label rendezvous_*Y*;',
			'if_true_*B*:',
			'entity \'Bob\' glitched = true;',
			'rendezvous_*Y*:',
		],
	},
	bool_exp_invert_or: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = !(debug_mode || isGoatGrumpy)',
		],
		expected: [
			'if (!debug_mode) { goto label if_true_*A*; }',
			'goto label rendezvous_*A*;',
			'if_true_*A*:',
			'if (!isGoatGrumpy) { goto label if_true_*B*; }',
			'rendezvous_*A*:',
			'entity \'Bob\' glitched = false;',
			'goto label rendezvous_*Y*;',
			'if_true_*B*:',
			'entity \'Bob\' glitched = true;',
			'rendezvous_*Y*:',
		],
	},
	bool_exp_invert_and: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'entity Bob glitched = !(debug_mode && isGoatGrumpy)',
		],
		expected: [
			"if (!debug_mode) { goto label if_true_*A*; }",
			"if (!isGoatGrumpy) { goto label if_true_*A*; }",
			"entity \"Bob\" glitched = false;",
			"goto label rendezvous_*Y*;",
			"if_true_*A*:",
			"entity \"Bob\" glitched = true;",
			"rendezvous_*Y*:",
		],
	},
	set_int_exp_ok: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			// MUTATE_VARIABLES
			'bothVarsAre = ambiguous;', // and that's ok

			// MUTATE_VARIABLE
			'goatCount = 0;',

			// COPY_VARIABLE
			'goatCount = player x;',
			'player y = goatCount;',
		]
	},
	int_exp_chain_literal_getable: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = 1 + player x;',
		],
		expected: [
			"*A* = 1;",
			"*B* = player x;",
			"*A* += *B*;",
			"goatCount = *A*;",
		],
	},
	int_exp_chain_getable_getable: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = player y + player x;',
		],
		expected: [
			"*A* = player y;",
			"*B* = player x;",
			"*A* += *B*;",
			"goatCount = *A*;",
		],
	},
	int_exp_chain_literal_getable_mult: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = 1 + player x * 99;',
		],
		expected: [
			"*A* = 1;",
			"*B* = player x;",
			"*B* *= 99;",
			"*A* += *B*;",
			"goatCount = *A*;",
		  ],
	},
	int_exp_chain_literal_getable_mult_parens: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = (1 + player x) * 99;',
		],
		expected: [
			"*A* = 1;",
			"*B* = player x;",
			"*A* += *B*;",
			"*A* *= 99;",
			"goatCount = *A*;",
		],
	},
	ambiguous_bool_disambiguate: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = !!notAmbiguous;',
		],
		expected: [
			'if (notAmbiguous) { goto label if_***; }',
			'goatCount = false;',
			'goto label rendezvous_***;',
			"if_***:",
			'goatCount = true;',
			"rendezvous_***:",
		],
	},
	ambiguous_bool_single_invert: {
		type: 'actions',
		autoAddReturn: true,
		input: [
			'goatCount = !notAmbiguous;',
		],
		expected: [
			'if (!notAmbiguous) { goto label if_***; }',
			'goatCount = false;',
			'goto label rendezvous_***;',
			"if_***:",
			'goatCount = true;',
			"rendezvous_***:",
		],
	},
};

const actionArrayToScript = (scriptName, actionArray, autoAddReturn) => {
	const ret = [
		`${scriptName} {`,
		...actionArray.map(v=>'\t'+v),
	];
	if (autoAddReturn) {
		ret.push(`\tend_of_script_***:`);
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

const sanitize = (str) => str.replace(/([\{\}\[\]\(\)\.\$\|\+\-\*\/])/g, '\\$1');
const makeTextUniform = (text) => text.trim()
	.replace(/[\t ]+/g, ' ')
	.replace(/\/\/.*?[\n$]/g, '');
const compareTexts = (_found, _expected, fileName, scriptName) => {
	const foundLines = makeTextUniform(_found)
		.replaceAll('=', '\n=')
		.split(/\n/g)
		.map(v=>v.trim())
		.filter(v=>!!v);
	const expectedLines = makeTextUniform(_expected)
		.replaceAll('=', '\n=')
		.split(/\n/g)
		.map(v=>v.trim())
		.filter(v=>!!v);
	if (foundLines.length !== expectedLines.length) {
		const maxLength = expectedLines.reduce((acc, curr)=>Math.max(acc, curr.length),-Infinity);
		const flushLines = expectedLines.map(s=>'   '+s.padEnd(maxLength+4, ' '));
		const comboLines = flushLines.map((left, i)=>{
			let right = foundLines[i] || '';
			if (expectedLines[i] !== right) {
				right = ansiTags.yellow + right + ansiTags.reset;
			}
			return left + right;
		});
		for (let i = comboLines.length; i < foundLines.length; i++) {
			const left = ' '.repeat(maxLength+4);
			const right = foundLines[i];
			comboLines.push(left+right);
		}
		return {
			status: 'fail',
			message: scriptName + ': different line counts',
			lengthDiff: comboLines,
		}
	}
	const lines = [];
	const registeredLabels = {};
	foundLines.forEach((found,  i)=>{
		const expected = expectedLines[i];
		if (expected === found) {
			return;
		}
		// registering specific wildcards
		const wild = expected.match(/(.*)(\*[A-Z]+\*)(.*)/);
		if (wild){
			const sanitary = wild.map(sanitize);
			const pattern = new RegExp(`${sanitary[1]}([\\da-zA-Z_]+)${sanitary[3]}`);
			const label = sanitary[2];
			const capture = found.match(pattern);
			if (capture) {
				if (!registeredLabels[label]) {
					registeredLabels[label] = capture[1];
				} else if (registeredLabels[label] !== capture[1]) {
					const diff = wild[1] + ansiTags.yellow + capture[1] + wild[3];
					lines.push({
						expected,
						found,
						diff,
						value: capture[1],
						fileName,
						lineIndex: i
					})
				}
				return;
			}
		}
		// wild wildcards
		const clean = sanitize(expected).replaceAll('\\*\\*\\*', '.+?');
		const regExpected = new RegExp(clean);
		if (found.match(regExpected)) {
			return;
		}
		if (found.replace(/"|'/g, '') === expected.replaceAll(/"|'/g, '')) {
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
			message: `${scriptName}: mismatched lines`,
			lines: lines.map(v=>{
				if (v.value) {
					let registered;
					Object.entries(registeredLabels).forEach(([k,val])=>{
						if (val===v.value) {
							registered = k;
						}
					});
					v.diff += ` (${registered})`;
				}
				return v;
			}),
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
		});
		errors.forEach(error=>{
			console.error('\n'+error.message);
			if (error.lines) {
				error.lines.forEach(v=>{
					console.error(`   Found: ${v.diff}`);
					console.error(`Expected: ${v.expected}`);
				});
			}
			if (error.lengthDiff) {
				console.error(error.lengthDiff.join('\n'));
			}
		});
		if (errors.length === 0) {
			console.log("All tests good, chief!");
		}
		console.log('BREAK ME');
	});
};

runTests();
