package sym

type Sym struct {
	Name string
	Type Type
}

type SymTable struct {
	Symbols map[string]Sym
	Parent  *SymTable
}

func NewSymTable() SymTable {
	return SymTable{
		Symbols: make(map[string]Sym),
		Parent:  nil,
	}
}

func (s *SymTable) Add(name string, sym Sym) {
	s.Symbols[name] = sym
}

func (s *SymTable) Get(name string) (Sym, bool) {
	sym, ok := s.Symbols[name]
	if !ok && s.Parent != nil {
		return s.Parent.Get(name)
	}
	return sym, ok
}

func (s *SymTable) SetParent(parent *SymTable) {
	s.Parent = parent
}
