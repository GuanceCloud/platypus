import TParser = require('web-tree-sitter');

import { ILinterRule, Diagnostic } from './rule';
import { LinterRuleS0001 } from './S0001';

export interface ILinter {
    lint(opts?: LintOptions): LintResult
}

export interface LintOptions {
    fileId: string
    tree: TParser.Tree;
    parser: TParser;
    rules?: ILinterRule[];
}

export interface LintResult {
    diagnostics: Diagnostic[];
}

export const defaultRules: ILinterRule[] = [
    LinterRuleS0001,
];

export class Linter implements ILinter {
    lint(opts: LintOptions): LintResult {
        const rules = [LinterRuleS0001];
        if (opts.rules) {
            rules.push(...opts.rules);
        }

        const diagnostics: Diagnostic[] = [];
        rules.forEach(rule => {
            const query = opts.parser.getLanguage().query(rule.query);
            const captures = query.captures(opts.tree.rootNode);
            diagnostics.push(...rule.lint(captures, rule, opts.fileId));
        });

        return {
            diagnostics,
        };
    }
}
