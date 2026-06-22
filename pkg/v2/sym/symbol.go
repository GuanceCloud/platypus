package sym

type Sym struct {
	Name string
	Kind KindCat
	Type Type
}

type tables struct {
	v []*Syms
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
	tbs.tables.v = append(tbs.tables.v, &Syms{})
	return &Tables{
		tables: tbs.tables,
		parent: tbs.cur,
		cur:    len(tbs.tables.v) - 1,
	}
}

func (tbs *Tables) ScopeID() int {
	return tbs.cur
}

func (tbs *Tables) scope() *Syms {
	return tbs.tables.v[tbs.cur]
}

func (tbs *Tables) Define(name string, sym *Sym) bool {
	return tbs.tables.v[tbs.cur].Define(name, sym)
}

func (tbs *Tables) GetCur(name string) (*Sym, bool) {
	return tbs.tables.v[tbs.cur].Get(name)
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

type Syms struct {
	Symbols map[string]*Sym

	ParentID int
	ID       int
}

func NewSyms(parent *Syms) *Syms {
	var parentID, id int
	if parent != nil {
		parentID = parent.ID
		id = parentID + 1
	}

	return &Syms{
		Symbols:  map[string]*Sym{},
		ParentID: parentID,
		ID:       id,
	}
}

func (s *Syms) Define(name string, sym *Sym) bool {
	if _, ok := s.Symbols[name]; ok {
		return false
	}

	s.Symbols[name] = sym
	return true
}

func (s *Syms) Get(name string) (*Sym, bool) {
	sym, ok := s.Symbols[name]
	return sym, ok
}
