/* --------------------------------------------------------------------------------------------
 * Copyright (c) Microsoft Corporation. All rights reserved.
 * Licensed under the MIT License. See License.txt in the project root for license information.
 * ------------------------------------------------------------------------------------------ */
import {
	createConnection,
	TextDocuments,
	Diagnostic,
	DiagnosticSeverity,
	ProposedFeatures,
	InitializeParams,
	DidChangeConfigurationNotification,
	CompletionItem,
	CompletionItemKind,
	DocumentFormattingParams,
	TextDocumentPositionParams,
	TextDocumentSyncKind,
	InitializeResult,
	Position,
	HoverParams,
	Hover,
	MarkupKind,
} from 'vscode-languageserver/node';

import {
	TextDocument,
	TextEdit,
} from 'vscode-languageserver-textdocument';

import data, {FunctionSepcification} from './data';


// import Parser = require("tree-sitter");
// import PPL = require("tree-sitter-ppl");

import Parser = require('web-tree-sitter');
import { SlowBuffer } from 'buffer';

// Create a connection for the server, using Node's IPC as a transport.
// Also include all preview / proposed LSP features.
const connection = createConnection(ProposedFeatures.all);

// Create a simple text document manager.
const documents: TextDocuments<TextDocument> = new TextDocuments(TextDocument);

// const parser = new Parser();
// parser.setLanguage(PPL);

let hasConfigurationCapability = false;
let hasWorkspaceFolderCapability = false;
let hasDiagnosticRelatedInformationCapability = false;

connection.onInitialize(async (params: InitializeParams) => {
	const capabilities = params.capabilities;

	// Does the client support the `workspace/configuration` request?
	// If not, we fall back using global settings.
	hasConfigurationCapability = !!(
		capabilities.workspace && !!capabilities.workspace.configuration
	);
	hasWorkspaceFolderCapability = !!(
		capabilities.workspace && !!capabilities.workspace.workspaceFolders
	);
	hasDiagnosticRelatedInformationCapability = !!(
		capabilities.textDocument &&
		capabilities.textDocument.publishDiagnostics &&
		capabilities.textDocument.publishDiagnostics.relatedInformation
	);

	const result: InitializeResult = {
		capabilities: {
			textDocumentSync: TextDocumentSyncKind.Incremental,
			// Tell the client that this server supports code completion.
			completionProvider: {
				resolveProvider: true,
			},
			// hoverProvider: true,
			documentFormattingProvider: true,
		}
	};
	if (hasWorkspaceFolderCapability) {
		result.capabilities.workspace = {
			workspaceFolders: {
				supported: true
			}
		};
	}
	return result;
});

connection.onInitialized(() => {
	if (hasConfigurationCapability) {
		// Register for all configuration changes.
		connection.client.register(DidChangeConfigurationNotification.type, undefined);
	}
	if (hasWorkspaceFolderCapability) {
		connection.workspace.onDidChangeWorkspaceFolders(_event => {
			connection.console.log('Workspace folder change event received.');
		});
	}
});

// The example settings
interface ExtensionSettings {
	maxNumberOfProblems: number;
}

// The global settings, used when the `workspace/configuration` request is not supported by the client.
// Please note that this is not the case when using this server with the client provided in this example
// but could happen with other clients.
const defaultSettings: ExtensionSettings = { maxNumberOfProblems: 1000 };
let globalSettings: ExtensionSettings = defaultSettings;

// Cache the settings of all open documents
const documentSettings: Map<string, Thenable<ExtensionSettings>> = new Map();

connection.onDidChangeConfiguration(change => {
	if (hasConfigurationCapability) {
		// Reset all cached document settings
		documentSettings.clear();
	} else {
		globalSettings = <ExtensionSettings>(
			(change.settings.languageServerExample || defaultSettings)
		);
	}

	// Revalidate all open text documents
	documents.all().forEach(validateTextDocument);
});

function getDocumentSettings(resource: string): Thenable<ExtensionSettings> {
	if (!hasConfigurationCapability) {
		return Promise.resolve(globalSettings);
	}
	let result = documentSettings.get(resource);
	if (!result) {
		result = connection.workspace.getConfiguration({
			scopeUri: resource,
			section: 'languageServerExample'
		});
		documentSettings.set(resource, result);
	}
	return result;
}

// Only keep settings for open documents
documents.onDidClose(e => {
	documentSettings.delete(e.document.uri);
});

// The content of a text document has changed. This event is emitted
// when the text document first opened or when its content has changed.
documents.onDidChangeContent(change => {
	validateTextDocument(change.document);
});

let languageParser: Parser;

async function validateTextDocument(textDocument: TextDocument): Promise<void> {
	if (!languageParser) {
		await Parser.init();
		languageParser = new Parser();
		const Lang = await Parser.Language.load('/Users/yufei/workspace/github/yufeiminds/ppl/ide/grammars/tree-sitter-ppl.wasm');
		languageParser.setLanguage(Lang);
	}

	// In this simple example we get the settings for every validate run.
	const settings = await getDocumentSettings(textDocument.uri);

	// The validator creates diagnostics for all uppercase words length 2 and more
	const text = textDocument.getText();
	const tree = languageParser.parse(text);
	console.debug(tree.rootNode.toString());

	const query: Parser.Query = languageParser.getLanguage().query(`(ERROR) @error`);

	const diagnostics: Diagnostic[] = query.captures(tree.rootNode).map(item => {
		console.debug('capture error', item.name, item.node.toString());
		const posRange = {
			start: Position.create(item.node.startPosition.row, item.node.startPosition.column),
			end: Position.create(item.node.endPosition.row, item.node.endPosition.column),
		};
		const diagnostic: Diagnostic = {
			severity: DiagnosticSeverity.Warning,
			range: posRange,
			message: 'Syntax error',
			source: 'ppl',
			relatedInformation: [
				{
					location: {
						uri: textDocument.uri,
						range: Object.assign({}, posRange)
					},
					message: `Unexpect token "${item.node.text}"`,
				},
			],
		};
		return diagnostic;
	});

	// Send the computed diagnostics to VSCode.
	connection.sendDiagnostics({ uri: textDocument.uri, diagnostics });
}

connection.onDidChangeWatchedFiles(_change => {
	// Monitored files have change in VSCode
	connection.console.log('We received an file change event');
});

// This handler provides the initial list of the completion items.
connection.onCompletion(
	(_textDocumentPosition: TextDocumentPositionParams): CompletionItem[] => {
		// The pass parameter contains the position of the text document in
		// which code complete got requested. For the example we ignore this
		// info and always provide the same completion items.
		const functionsItems: CompletionItem[] = data.functions.map((fn: FunctionSepcification, index: number) => ({
			label: fn.name,
			kind: CompletionItemKind.Function,
			data: index
		}));
		const keywordsItems: CompletionItem[] = data.keywords.map((keyword: string, index: number) => ({
			label: keyword,
			kind: CompletionItemKind.Keyword,
			data: index
		}));
		return [...functionsItems, ...keywordsItems];
	}
);

// This handler resolves additional information for the item selected in
// the completion list.
connection.onCompletionResolve(
	(item: CompletionItem): CompletionItem => {
		if (item.kind === CompletionItemKind.Function) {
			const fn = data.functions[item.data];
			item.detail = fn.description;
			item.documentation = fn.doc;
		}
		return item;
	}
);

// connection.onHover((params: HoverParams): Hover => {
// 	const textDocument = documents.get(params.textDocument.uri);

// 	const token = textDocument?.getText({
// 		start: params.position,
// 		end: params.position,
// 	});

// 	const text = textDocument.getText();
// 	const tree = languageParser.parse(text);
// 	console.debug(tree.rootNode.toString());


// 	const query: Parser.Query = languageParser.getLanguage().query(`(call_expr name: (identifier) @name)`);

// 	query.captures(tree.rootNode).forEach(item => {
// 		const slug = `${item.node.startPosition.row}-${item.node.startPosition.column}`;
// 		{
// 			contents: {
// 				kind: MarkupKind.Markdown,
// 				value: `Hello World, ${token}`
// 			}
// 		};
// 	});
	
// });

connection.onDocumentFormatting((params: DocumentFormattingParams): TextEdit[] => {
	const document = documents.get(params.textDocument.uri);
	if (!document) {
		return [];
	}

	const text = document.getText();
	const result: TextEdit[] = [];
	return result;
});

// Make the text document manager listen on the connection
// for open, change and close text document events
documents.listen(connection);

// Listen on the connection
connection.listen();
