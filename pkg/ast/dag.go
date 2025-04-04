package ast

import "fmt"

type DAGNode struct {
	ID       string
	Children []*DAGNode
	Parents  []*DAGNode
	Data     interface{}
}

func NewDAGNode(id string, data interface{}) *DAGNode {
	return &DAGNode{
		ID:   id,
		Data: data,
	}
}

func (n *DAGNode) AddChild(child *DAGNode) error {
	if n == child || createsCycle(n, child) {
		return fmt.Errorf("cycle detected")
	}

	n.Children = append(n.Children, child)
	child.Parents = append(child.Parents, n)
	return nil
}
func createsCycle(a, b *DAGNode) bool {
	visited := make(map[string]bool)
	var check func(*DAGNode) bool

	check = func(node *DAGNode) bool {
		if node.ID == a.ID {
			return true
		}
		if visited[node.ID] {
			return false
		}
		visited[node.ID] = true
		for _, p := range node.Parents {
			if check(p) {
				return true
			}
		}
		return false
	}

	return check(b)
}
