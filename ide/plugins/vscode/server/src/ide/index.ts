import path = require('path');
import TParser = require('web-tree-sitter');

import { File, ISemanticModel, newSemanticModel } from './semantic';
import { Diagnostic, ILinter, Linter, LintResult } from './linter';
import { LintOptions } from './lint';
import { FormatOptions, FormatResult } from './format';


export interface IDE {
	acceptFile(sourceFile: File): IDE;

	format(opts: FormatOptions): FormatResult;

	lint(opts: LintOptions): LintResult;

	info(): ISemanticModel;
}

export class IDEProvider implements IDE {
	private parser?: TParser;
	private linter: ILinter;
	private csts: { [fileId: string]: TParser.Tree };

	constructor() {
		this.parser = undefined;
		this.linter = new Linter();
		this.csts = {};
		return this;
	}

	async init(): Promise<IDE> {
		await TParser.init();
		this.parser = new TParser();
        const lang = await TParser.Language.load(path.join(__dirname, "..", "..", "src", 'tree-sitter-platypus.wasm'));
        this.parser.setLanguage(lang);
		return this;
    }

	acceptFile(source: File): IDE {
		if (!this.parser) {
			throw new Error("Parser not initialized");
		}
		const tree = this.parser.parse(source.content);
		this.csts[source.fileId] = tree;
		return this;
	}

	format(opts: FormatOptions): FormatResult {
		throw new Error('Method not implemented.');
	}

	lint(opts: LintOptions): LintResult {
		if (!this.parser) {
			throw new Error("Parser not initialized");
		}

		const tree = this.csts[opts.fileId];
		const result =  this.linter.lint({
			fileId: opts.fileId,
			tree: tree,
			parser: this.parser,
		});

		return {
			diagnostics: result.diagnostics,
		};
	}

	info(): ISemanticModel {
		return newSemanticModel();
	}
}
