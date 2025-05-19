package sym

type TypCategory int

const (
	TypAnyCat TypCategory = iota
	TypBoolCat
	TypIntCat
	TypStringCat
	TypFloatCat
	TypMapCat
	TypListCat
	TypClassCat
	TypFuncCat
)

type Type interface {
	Category() TypCategory
}

type TypAny struct{}

func (*TypAny) Category() TypCategory { return TypAnyCat }

type TypBool struct{}

func (*TypBool) Category() TypCategory { return TypBoolCat }

type TypInt struct{}

func (*TypInt) Category() TypCategory { return TypIntCat }

type TypFloat struct{}

func (*TypFloat) Category() TypCategory { return TypFloatCat }

type TypString struct{}

func (*TypString) Category() TypCategory { return TypStringCat }

type TypMap struct {
	Key   Type
	Value Type
}

func (*TypMap) Category() TypCategory { return TypMapCat }

type TypList struct {
	Elem Type
}

func (*TypList) Category() TypCategory { return TypListCat }

type Field struct {
	Name string
	Type Type
}

type TypClass struct {
	Name   string
	Fields []*Field
	Method map[string]TypFunc
}

func (*TypClass) Category() TypCategory { return TypClassCat }

type TypFunc struct {
	Name    string
	Params  []*Field
	Results []*Field
}

func (TypFunc) Category() TypCategory { return TypFuncCat }

type TypeDesc struct {
	typs []Type
}

var innerTypes = []Type{
	&TypAny{},
	&TypBool{},
	&TypInt{},
	&TypFloat{},
	&TypString{},
	&TypList{
		Elem: &TypAny{},
	},
	&TypMap{Key: &TypString{},
		Value: &TypAny{}},
}

const (
	TypAnyIdx = iota
	TypBoolIdx
	TypIntIdx
	TypFloatIdx
	TypStringIdx
	TypListIdx
	TypMapIdx
)

func NewTypeDesc() TypeDesc {
	return TypeDesc{
		typs: append([]Type{}, innerTypes...)}
}

func (t *TypeDesc) Insert(typ Type) int {
	t.typs = append(t.typs, typ)
	return len(t.typs) - 1
}

func (t *TypeDesc) Get(i int) Type {
	return t.typs[i]
}

func (t *TypeDesc) Len() int {
	return len(t.typs)
}
