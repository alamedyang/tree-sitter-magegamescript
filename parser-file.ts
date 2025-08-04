import { type MGSDebug } from './parser-bytecode-info.ts';
import { type ProjectState } from './parser-project.ts';
import type {
	DialogSettings,
	MGSMessage,
	SerialDialogSettings,
	AnyNode,
	MGSPrimitive,
} from './parser-types.ts';
import { ansiTags as ansi } from './parser-utilities.ts';

export type Constant = {
	value: MGSPrimitive;
	debug: MGSDebug;
};
export type FileState = {
	p: ProjectState;
	fileName: string;
	constants: Record<string, Constant>;
	settings: {
		default: DialogSettings;
		entity: DialogSettings;
		label: DialogSettings;
		serial: SerialDialogSettings;
	};
	nodes: AnyNode[];
	errorCount: number;
	warningCount: number;
	newError: (message: MGSMessage) => void;
	newWarning: (message: MGSMessage) => void;
	includeFile: (newName: string) => void;
	printableMessageInformation: () => string;
};

export const makeFileState = (p: ProjectState, fileName: string): FileState => {
	// file crawl state
	const f: FileState = {
		p, // project state, because we need to reach in sometimes
		fileName,

		// compile-time constants,
		// substituted for their registered token value as they are encounted
		constants: {},

		// dialog and serial dialog settings, applied to the (s)dialogs as we go
		// (adding a setting later means only later (s)dialogs will be affected)
		settings: {
			default: {},
			entity: {},
			label: {},
			serial: {},
		},

		// root level nodes like script definitions, settings definitions, etc
		nodes: [],

		// some warnings/errors are at the file level, but others are not encountered until all files are mushed together; this count only concerns the former
		errorCount: 0,
		warningCount: 0,
		// errors involving multiple files (duplicate definitions) are detected later, so their count is added later

		// local errors/warnings will add the filename here for sanity's sake
		// (rather than needing to be added each time there's an error)
		// errors made this way should only be concerned with the original file itself,
		// and so the crawl state's filename should be correct in all cases
		newError: (message) => {
			message.locations.forEach((v) => {
				// only put on a filename if one was not provided in the locations entry
				// (should be able to override default filename if necessary)
				if (!v.fileName) v.fileName = fileName;
			});
			p.newError(message);
			f.errorCount += 1;
		},
		newWarning: (message) => {
			message.locations.forEach((v) => {
				if (!v.fileName) v.fileName = fileName;
			});
			p.newWarning(message);
			f.warningCount += 1;
		},

		// add a new file's crawl state to ours (overriding existing values) (i.e. `include`)
		includeFile: (newName: string) => {
			// Push ifs up! Don't call this function unless you know the file is parsed already
			const newFile = p.fileMap[newName].parsed;
			if (!newFile) throw new Error(`Missing file to include: ${newName}`);
			// add their constants to us
			Object.keys(newFile.constants).forEach((constantName) => {
				if (f.constants[constantName]) {
					f.newError({
						message: `cannot redefine constant ${constantName} (via 'include')`,
						locations: [
							{
								fileName: newFile.fileName,
								node: newFile.constants[constantName].debug.node,
							},
						],
					});
				}
				f.constants[constantName] = newFile.constants[constantName];
			});
			// add their actual node entries to us (might help debugging)
			newFile.nodes.forEach((node) => {
				f.nodes.push(node);
			});
			// add (serial) dialog settings
			['default', 'serial'].forEach((type) => {
				Object.keys(newFile.settings[type]).forEach((param) => {
					f.settings[type][param] = newFile.settings[type][param];
				});
			});
			// ...some of which are extra layered
			['entity', 'label'].forEach((type) => {
				Object.keys(newFile.settings[type]).forEach((target) => {
					const params = Object.keys(newFile.settings[type][target]);
					f.settings[type][target] = f.settings[type][target] || {};
					params.forEach((param) => {
						f.settings[type][target][param] = newFile.settings[type][target][param];
						// (I apologize for this)
					});
				});
			});
		},

		// log an individual file's parse status
		printableMessageInformation: () => {
			if (f.errorCount === 0 && f.warningCount === 0) {
				return `(${ansi.green}OK${ansi.reset})`;
			}
			const errMessage = f.errorCount
				? `${ansi.red}${f.errorCount} error${f.errorCount === 1 ? '' : 's'}${ansi.reset}`
				: `0 errors`;
			const warnMessage = f.warningCount
				? `${ansi.yellow}${f.warningCount} warning${f.warningCount === 1 ? '' : 's'}${ansi.reset}`
				: `0 warnings`;
			const ret = [errMessage, warnMessage].join(', ');
			return `(${ret})`;
		},
	};
	return f;
};
