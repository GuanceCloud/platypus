package sym

type Sym struct {
	Name string
	Kind KindCat
	Type Type
}

type tables struct {
	v []*SymTable
}

type Tables struct {
	tables *tables
	parent int
	cur    int
}

func NewTabels() *Tables {
	return &Tables{
		tables: &tables{},
		parent: 0,
		cur:    0,
	}
}

func (tbs *Tables) NextScope() *Tables {
	tbs.tables.v = append(tbs.tables.v, &SymTable{})
	return &Tables{
		tables: tbs.tables,
		parent: tbs.cur,
		cur:    len(tbs.tables.v) - 1,
	}
}

func (tbs *Tables) ScopeID() int {
	return tbs.cur
}

func (tbs *Tables) Define(name string, sym *Sym) bool {
	return tbs.tables.v[tbs.cur].Add(name, sym)
}

func (tbs *Tables) Get(name string) (*Sym, bool) {
	id := tbs.cur
	for {
		tb := tbs.tables.v[id]
		if v, ok := tb.Get(name); ok {
			return v, ok
		}
		if tb.ParentID != id {
			id = tb.ParentID
		} else {
			return nil, false
		}
	}
}

type SymTable struct {
	Symbols map[string]*Sym

	ParentID int
	ID       int
}

func NewSymTable(parent *SymTable) *SymTable {
	var parentID, id int
	if parent != nil {
		parentID = parent.ID
		id = parentID + 1
	}

	return &SymTable{
		Symbols:  map[string]*Sym{},
		ParentID: parentID,
		ID:       id,
	}
}

func (s *SymTable) Add(name string, sym *Sym) bool {
	if _, ok := s.Symbols[name]; ok {
		return false
	}

	s.Symbols[name] = sym
	return true
}

func (s *SymTable) Get(name string) (*Sym, bool) {
	sym, ok := s.Symbols[name]
	return sym, ok
}
