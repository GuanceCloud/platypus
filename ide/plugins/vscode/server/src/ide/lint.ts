import { Diagnostic } from './linter';

export interface LintOptions {
	fileId: string
}

export interface LintResult {
	diagnostics: Diagnostic[]
}
