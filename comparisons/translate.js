const { printScript } = require('../parser-to-json.js');
const { scripts } = require('./one_file_at_a_time.js');

const printedMap = {};
Object.entries(scripts).forEach(([k,v])=>{
	const printed = printScript(k, v);
	printedMap[k] = printed;
});
const copyFromThis = Object.values(printedMap).join('\n\n')
console.log('DONE')
