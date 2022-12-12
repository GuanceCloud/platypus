import functions, { IFunction } from './builtins';
import keywords, { IKeyword } from './keywords';

export interface ISemanticModel {
	builtins: {[name: string]: IFunction};

	keywords: {[name: string]: IKeyword};
}

export const newSemanticModel = (): ISemanticModel => {
	return {
		keywords: keywords.reduce((target: { [name: string]: IKeyword }, item: IKeyword) => {
			target[item.name] = item;
			return target;
		}, {}),
		builtins: functions.reduce((target: { [name: string]: IFunction }, item: IFunction) => {
			target[item.name] = item;
			return target;
		}, {}),
	};
};
