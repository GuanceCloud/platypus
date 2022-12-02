import Parser = require('web-tree-sitter');
import { File, Range } from '../semantic';

export interface Diagnostic {
    // The position information about source code.
    fileId: string;
    range: Range;

    // The diagnostic of linter.
    ruleId: string;
    level: DiagnosticLevel;
    message: string;
    documentation?: string;
}

export enum DiagnosticLevel {
    Error,
    Warning,
}

export interface ILinterRule {
    ruleId: string;
    name: string
    description: string;
    documentation: string;
    query: string;
	lint: (captures: Parser.QueryCapture[], rule: ILinterRule, fileId: string) => Diagnostic[];
}
