import { ILinterRule, DiagnosticLevel, Diagnostic } from './rule';

export const LinterRuleS0001: ILinterRule = {
	ruleId: 'S0001',
	name: 'Syntax error',
	description: 'S0001',
	documentation: 'S0001',
	query: `(ERROR) @error`,
	lint: (captures, rule, fileId) => {
		return captures.map(capture => {
			const node = capture.node;
			const range = {
				start: {
					row: node.startPosition.row,
					column: node.startPosition.column,
				},
				end: {
					row: node.endPosition.row,
					column: node.endPosition.column,
				},
			};

			const diagnostic: Diagnostic = {
				fileId: fileId,
				range,
				ruleId: rule.ruleId,
				level: DiagnosticLevel.Error,
				message: `Unexpect token "${node.text}"`,
				documentation: rule.documentation,
			};
			return diagnostic;
		});
	}
};
