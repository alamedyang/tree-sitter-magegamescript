const fs = require('node:fs');
const { printScript } = require('../parser-to-json.js');
const { composites } = require('./exfiltrated_composites.js');
const { scripts } = require('./one_file_at_a_time.js');

const exfiltrate = {};

// script list goes here
[
	'start_bling-rotate-auto',
	'start_bling-rotate-manual',
	'bling-goto-branches',
	// 'on_load-bling-mode-map',
	'bling-detect-mode',
	'loop-bling-listen-any',
	'loop-bling-listen-hax',
	'bling-goto-menu',
	'bling-rotate-state-increment',
	'bling-rotate-state-decrement',
	'loop-bling_timer',
	'loop-bling_timer-wait',
	'loop-bling-listen-manualrotate',
	'bling-manual-rotate-left',
	'bling-manual-rotate-right',
	'start_bling-dc801',
	'start_bling-dc801-2',
	'start_bling-zero',
	'start_bling-serial',
	'start_bling-digi-mage',
	'start_bling-digi-mage2',
	'start_bling-flying-toasters',
	'start_bling-qr',
].forEach(scriptName=>{
	const fromOtherThing = composites[scriptName];
	exfiltrate[scriptName] = fromOtherThing;
});

const printedMap = {};
Object.entries(exfiltrate).forEach(([k,v])=>{
	const printed = printScript(k, v);
	printedMap[k] = printed;
});
const copyFromThis = Object.values(printedMap).join('\n\n')

fs.writeFileSync('./comparisons/export.mgs', copyFromThis);
