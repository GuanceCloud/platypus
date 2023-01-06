import { assert } from 'console';
import TParser = require('web-tree-sitter');
import { Range } from '../semantic';
import { IContext, Context } from './context';

export interface FormatOptions {
    tree: TParser.Tree;
}

export interface FormatResult {
    formatted: string
    range: Range
}

export interface IFormatter {
    format(opts?: FormatOptions): FormatResult
}

export class Formatter implements IFormatter {
    format(opts: FormatOptions): FormatResult {
        // Format the syntax tree by traversing it and generating a new string
        // Use syntax direction translation to map from the tree to the string
        const ctx = new Context();
        opts.tree.rootNode.children.forEach(child => {
            this.formatInlineStmt(child, ctx);
        });
        console.log("[DEBUG]", opts.tree.rootNode.toString());
        console.log("[DEBUG]", ctx.build());
        return {
            formatted: ctx.build(),
            range: {
                start: opts.tree.rootNode.startPosition,
                end: opts.tree.rootNode.endPosition,
            },
        };
    }

    formatInlineStmt(node: TParser.SyntaxNode, ctx: IContext) {
        const stmt = node.children[0];
        const newlines = node.children[1];
        ctx.writeIndent();
        this.formatStmt(stmt, ctx);
        if (newlines.text.length > 1) {
            ctx.newline();
        }
    }

    formatStmt(node: TParser.SyntaxNode, ctx: IContext) {
        switch (node.type) {
            case "comment":
                this.formatComment(node, ctx);
                break;
            case "if_stmt":
                this.formatIfStmt(node, ctx);
                break;
            case "for_in_stmt":
                this.formatForInStmt(node, ctx);
                break;
            case "continue_stmt":
                this.formatContinueStmt(node, ctx);
                break;
            case "break_stmt":
                this.formatBreakStmt(node, ctx);
                break;
            case "expr_stmt":
                this.formatExprStmt(node, ctx);
                break;
            case "assign_stmt":
                this.formatAssignStmt(node, ctx);
                break;
            default:
                ctx.write(node.text);
                break;
        }
        ctx.newline();
    }

    formatComment(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.text);
    }

    formatIfStmt(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('if');
        ctx.space();
        this.formatExpr(node.children[1], ctx);
        ctx.space();
        this.formatBlockStmts(node.children[2], ctx);
        for (let i = 3; i < node.children.length; i += 3) {
            const keyword = node.children[i].text;
            ctx.space();
            ctx.write(keyword);
            ctx.space();
            if (keyword == 'elif') {
                this.formatExpr(node.children[i + 1], ctx);
                ctx.space();
                this.formatBlockStmts(node.children[i + 2], ctx);
            } else {
                this.formatBlockStmts(node.children[i + 1], ctx);
            }
        }
    }

    formatForInStmt(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('for ');
        ctx.write(node.children[1].text);
        ctx.write(' in ');
        ctx.write(node.children[3].text);
        ctx.space();
        this.formatBlockStmts(node.children[4], ctx);
    }

    formatBlockStmts(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('{');
        ctx.newline();
        ctx.indent();
        const stmts = node.children.slice(1, -1);
        stmts.forEach((child, index) => {
            this.formatInlineStmt(child, ctx);
        });
        ctx.unindent();
        ctx.write('}');
    }

    formatContinueStmt(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('continue');
    }

    formatBreakStmt(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('break');
    }

    formatAssignStmt(node: TParser.SyntaxNode, ctx: IContext) {
        assert(node.type === "assign_stmt");
        this.formatIdentifier(node.children[0], ctx);
        ctx.space();
        ctx.write('=');
        ctx.space();
        this.formatExpr(node.children[2], ctx);
    }

    formatCallExpr(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.children[0].text);
        this.formatArgumentList(node.children[1], ctx);
    }

    formatArgumentList(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('(');
        if (node.text.length >= 80) {
            ctx.indent();
            ctx.newline();
            node.children.slice(1, -1).forEach((child, index) => {
                if (index % 2 !== 0 || child.isMissing()) {
                    return;
                }
                ctx.writeIndent();
                this.formatExpr(child, ctx);
                ctx.write(',');
                ctx.newline();
            });
            ctx.unindent();
        } else {
            node.children.slice(1, -1).forEach((child, index) => {
                if (index % 2 !== 0 || child.isMissing()) {
                    return;
                }
                if (index > 0) {
                    ctx.write(',');
                    ctx.space();
                }
                this.formatExpr(child, ctx);
            });
        }
        ctx.write(')');
    }

    formatExprStmt(node: TParser.SyntaxNode, ctx: IContext) {
        node.firstChild && this.formatExpr(node.firstChild, ctx);
    }

    formatExpr(node: TParser.SyntaxNode, ctx: IContext) {
        switch (node.type) {
            case "call_expr":
                this.formatCallExpr(node, ctx);
                break;
            case "binary_expr":
                this.formatBinaryExpr(node, ctx);
                break;
            case "paren_expr":
                this.formatParenExpr(node, ctx);
                break;
            case "list_expr":
                this.formatListExpr(node, ctx);
                break;
            case "map_expr":
                this.formatMapExpr(node, ctx);
                break;
            case "index_expr":
                this.formatIndexExpr(node, ctx);
                break;
            case "identifier":
                this.formatIdentifier(node, ctx);
                break;

            // Literals
            case "nil_lit":
                this.formatNilLit(node, ctx);
                break;
            case "number_lit":
                this.formatNumberLit(node, ctx);
                break;
            case "string_lit":
                this.formatStringLit(node, ctx);
                break;
            case "bool_lit":
                this.formatBoolLit(node, ctx);
                break;

            default:
                ctx.write(node.text);
                break;
        }
    }

    formatBinaryExpr(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.children[0].text);
        ctx.space();
        ctx.write(node.children[1].text);
        ctx.space();
        ctx.write(node.children[2].text);
    }

    formatParenExpr(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('(');
        this.formatExprStmt(node.children[1], ctx);
        ctx.write(')');
    }

    formatListExpr(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('[');
        node.children.slice(1, -1).forEach((child, index) => {
            if (index % 2 !== 0) {
                return;
            }
            if (index > 0) {
                ctx.write(',');
                ctx.space();
            }
            this.formatExprStmt(child, ctx);
        });
        ctx.write(']');
    }

    formatMapExpr(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('{');
        node.children.slice(1, -1).forEach((child, index) => {
            if (index % 2 !== 0) {
                return;
            }
            if (index > 0) {
                ctx.write(',');
                ctx.space();
            }
            this.formatMapElem(child, ctx);
        });
        ctx.write('}');
    }

    formatMapElem(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.children[0].text);
        ctx.write(': ');
        this.formatExprStmt(node.children[2], ctx);
        ctx.write(',');
        ctx.space();
    }

    formatIndexExpr(node: TParser.SyntaxNode, ctx: IContext) {
        this.formatIdentifier(node.children[0], ctx);
        ctx.write('[');
        this.formatExprStmt(node.children[2], ctx);
        ctx.write(']');
    }

    formatNilLit(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write('nil');
    }

    formatNumberLit(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.text);
    }

    formatStringLit(node: TParser.SyntaxNode, ctx: IContext) {
        switch (node.children[0].type) {
            case "quoted_string_lit":
                this.formatQuotedStringLit(node.children[0], ctx);
                break;
            case "multiline_string_lit":
                this.formatMultilineStringLit(node.children[0], ctx);
                break;
            default:
                // ctx.write(node.text);
                break;
        }
    }

    formatQuotedStringLit(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.text);
    }

    formatMultilineStringLit(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.text);
    }

    formatBoolLit(node: TParser.SyntaxNode, ctx: IContext) {
        ctx.write(node.text);
    }

    formatIdentifier(node: TParser.SyntaxNode, ctx: IContext) {
        assert(node.type === "identifier");
        ctx.write(node.text);
    }
}
