export interface IContext {
    space(): void
    newline(token?: string): void
    writeIndent(): void
    write(token: string): void
    build(): string
    indent(): void
    unindent(): void
}

export class Context implements IContext {
    private _output: string;
    private _indent: number;

    constructor() {
        this._output = '';
        this._indent = 0;
    }

    space(): void {
        this.write(' ');
    }

    newline(): void {
        this.write('\n');
    }

    writeIndent(): void {
        this._output += '    '.repeat(this._indent);
    }

    write(token: string): void {
        this._output += token;
    }

    indent(): void {
        this._indent += 1;
    }

    unindent(): void {
        this._indent -= 1;
    }

    build(): string {
        return this._output;
    }
}
