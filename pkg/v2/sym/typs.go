package sym

type TypCat int

const (
	TypAnyCat TypCat = iota
	TypBoolCat
	TypIntCat
	TypStringCat
	TypFloatCat
	TypMapCat
	TypListCat
	TypClassCat
	TypFuncCat
)

type KindCat int

const (
	KindVarb KindCat = 1 << iota
	KindConst
	KindFunc
	KindClass
)

var (
	Bool  = &TypBool{}
	Float = &TypFloat{}
	Int   = &TypInt{}
	Str   = &TypString{}
	Any   = &TypAny{}
)

type Type interface {
	Category() TypCat
}

type TypAny struct{}

func (*TypAny) Category() TypCat { return TypAnyCat }

type TypBool struct{}

func (*TypBool) Category() TypCat { return TypBoolCat }

type TypInt struct{}

func (*TypInt) Category() TypCat { return TypIntCat }

type TypFloat struct{}

func (*TypFloat) Category() TypCat { return TypFloatCat }

type TypString struct{}

func (*TypString) Category() TypCat { return TypStringCat }

type TypMap struct {
	Key   Type
	Value Type
}

func (*TypMap) Category() TypCat { return TypMapCat }

type TypList struct {
	Elem Type
}

func NewListTyp(tp Type) *TypList {
	return &TypList{
		Elem: tp,
	}
}

func NewMapTyp() *TypMap {
	return &TypMap{
		Key:   Str,
		Value: Any,
	}
}

func (*TypList) Category() TypCat { return TypListCat }

type Field struct {
	Name string
	Type Type
}

type TypClass struct {
	Name   string
	Fields []*Field
	Method map[string]TypFunc
}

func (*TypClass) Category() TypCat { return TypClassCat }

type Param struct {
	Type   Type
	IsVarb bool
}

type TypFunc struct {
	Name    string
	Params  []*Param
	Returns []Type
}

func (TypFunc) Category() TypCat { return TypFuncCat }

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
