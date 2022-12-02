// import TParser = require('web-tree-sitter');

// export interface ISymbol {
// 	name: string
// 	kind: SymbolKind;
// 	type: SymbolType;
// 	declare: TParser.SyntaxNode;
// 	properties: object;
// }

// export enum SymbolType {
// 	global,
// }

// export enum SymbolKind {
// 	Const,
// 	Function,
// }

// export interface SymbolTable {
// 	free(): void;
// 	lookup(name: string): ISymbol | undefined;
// }

export interface File {
	fileId: string;
	content: string;
}

export interface Position {
    row: number;
    column: number;
}

export interface Range {
    start: Position;
    end: Position;
}
