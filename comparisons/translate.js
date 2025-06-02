import { writeFileSync } from 'node:fs';
import { printScript } from '../parser-to-json.ts';
import { composites } from './exfiltrated_composites.js';

const exfiltrate = {};

// script list goes here
[
	'show_dialog-timewarp',
	'show_dialog-bob-first-demo_map',
	'show_dialog-sheep-demo_map',
	'show_dialog-dsheep-demo_map',
	'show_dialog-max-demo_map',
	'show_dialog-timmy-demo_map',
	'show_dialog-kid-demo_map',
	'show_dialog-goose-demo_map',
	'show_dialog-beatrice-demo_map',
	'show_dialog-trekkie-demo_map',
	'show_dialog-verthandi-demo_map',
	'show_dialog-goat-demo_map',
	'show_dialog-cleo1-demo_map',
	// 'show_dialog-cleo2-demo_map',
	'show_dialog-cat-demo_map',
	'show_dialog-smith-demo_map',
	'check_if_player_is_goat_high-demo_map',
	'check_if_player_is_goat_low-demo_map',
	'move_goat1_to_low-demo_map',
	'move_goat2_to_low-demo_map',
	'move_goat1_to_high-demo_map',
	'move_goat2_to_high-demo_map',
	'loop_on_path_30s-demo_map',
	'loop_on_path_10s-demo_map',
	'loop_on_path_3s-demo_map',
	'show_dialog-demo-end-dream-q',
	'demo-end-dream-yes',
	'demo-end-dream-yes-save',
	'demo-end-dream-no',
].forEach((scriptName) => {
	const fromOtherThing = composites[scriptName];
	exfiltrate[scriptName] = fromOtherThing;
});

const printedMap = {};
Object.entries(exfiltrate).forEach(([k, v]) => {
	const printed = printScript(k, v);
	printedMap[k] = printed;
});
const copyFromThis = Object.values(printedMap).join('\n\n');

writeFileSync('./comparisons/export.mgs', copyFromThis);
