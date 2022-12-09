import { Range } from './semantic';

export interface FormatOptions {
	fileId: string
}

export interface FormatResult {
	formatted: string
	range: Range
}
