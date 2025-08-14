import { type ProjectState } from './parser-project.ts';
import type {
	DialogSettings,
	MGSMessage,
	SerialDialogSettings,
	AnyNode,
	MGSPrimitive,
	MathlangLocation,
} from './parser-types.ts';
import { ansiTags as ansi } from './parser-utilities.ts';

// TODO move to mathlang types file
export type Constant = {
	value: MGSPrimitive;
	debug: MathlangLocation;
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
	printableMessageInformation: () => string;
};

export const makeFileState = (p: ProjectState, fileName: string): FileState => {
	// file crawl state
	const f: FileState = {
		p, // project crawl state
		fileName,

		// compile-time constants,
		// substituted for their registered token value as they are encounted
		constants: {},

		// dialog and serial dialog settings, applied to the (s)dialogs as we go
		settings: {
			default: {},
			entity: {},
			label: {},
			serial: {},
		},

		// root level nodes, e.g. script definitions, settings definitions
		nodes: [],

		// local error/warning counts
		errorCount: 0,
		warningCount: 0,

		newError: (message) => {
			message.locations.forEach((v) => {
				// local filename assumed (if absent)
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

		// print the file's parse status
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
