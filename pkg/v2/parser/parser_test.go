// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.
//
// ====================================================================================
// Copyright 2015 The Prometheus Authors
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package parser

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"github.com/stretchr/testify/assert"
)

func TestSS(t *testing.T) {
	txt := `
if a == 1 { #123

# 123

 	gx(x)
}
#if a==1{gx(x)}
`
	v, err := ParsePipeline("x", txt)
	t.Error(err)
	t.Error(v.String())
}

func TestExprSeparation(t *testing.T) {
	cases := []struct {
		name     string
		in       string
		expected ast.Stmts
		err      string
		fail     bool
	}{
		{
			name: "test_if_nl",
			in: `

			# 0
			[

			1, 3,
			"3",
			true,
			1.]

			[
				1, 3,
				"3",
				true,
				1.
			]

			# 只支持基础数据类型
			[1, 3, "3", true, 1. ,
				[1, 3, "3", true, 1.
					], {}
			]

			a = 1; func1()
			func2(1, 3,
				"3", true, 1.

			)
			if true {
				;
			}

			#2
			if true {

			} elif false {
			} elif x == y {	 a =
				a + 1	}
				a = b; a=c
					a =d

			#3
			if true {
			} elif false {
			} elif x == y {
				a =
				a +
				1
			} else {

			}
			`,
			expected: ast.Stmts{
				&ast.ListLiteral{
					List: []ast.Node{
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 3},
						&ast.StringLiteral{Val: "3"},
						&ast.BoolLiteral{Val: true},
						&ast.FloatLiteral{Val: 1.},
					},
				},

				&ast.ListLiteral{
					List: []ast.Node{
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 3},
						&ast.StringLiteral{Val: "3"},
						&ast.BoolLiteral{Val: true},
						&ast.FloatLiteral{Val: 1.},
					},
				},

				&ast.ListLiteral{
					List: []ast.Node{
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 3},
						&ast.StringLiteral{Val: "3"},
						&ast.BoolLiteral{Val: true},
						&ast.FloatLiteral{Val: 1.},

						&ast.ListLiteral{
							List: []ast.Node{
								&ast.IntegerLiteral{Val: 1},
								&ast.IntegerLiteral{Val: 3},
								&ast.StringLiteral{Val: "3"},
								&ast.BoolLiteral{Val: true},
								&ast.FloatLiteral{Val: 1.},
							},
						},
						&ast.MapLiteral{},
					},
				},
				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
				},
				&ast.CallExpr{Obj: &ast.Identifier{Name: "func1"}},
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "func2"},
					Param: ast.FuncArgList{
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 3},
						&ast.StringLiteral{Val: "3"},
						&ast.BoolLiteral{Val: true},
						&ast.FloatLiteral{Val: 1.},
					},
				},
				&ast.IfelseStmt{
					IfList: []*ast.IfStmtElem{
						{Condition: &ast.BoolLiteral{Val: true}},
					},
				},

				&ast.IfelseStmt{
					IfList: []*ast.IfStmtElem{
						{Condition: &ast.BoolLiteral{Val: true}},
						{Condition: &ast.BoolLiteral{Val: false}},
						{
							Condition: &ast.ConditionalExpr{
								LHS: &ast.Identifier{Name: "x"},
								Op:  AstOp(EQEQ),
								RHS: &ast.Identifier{Name: "y"},
							},
							Block: &ast.BlockStmt{Stmts: ast.Stmts{
								&ast.AssignmentExpr{
									Op:  ast.EQ,
									LHS: []ast.Node{&ast.Identifier{Name: "a"}},
									RHS: []ast.Node{&ast.ArithmeticExpr{
										LHS: &ast.Identifier{Name: "a"},
										RHS: &ast.IntegerLiteral{Val: 1},
										Op:  AstOp(ADD),
									}},
								},
							}},
						},
					},
				},

				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.Identifier{Name: "b"}},
				},
				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.Identifier{Name: "c"}},
				},
				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.Identifier{Name: "d"}},
				},

				&ast.IfelseStmt{
					IfList: []*ast.IfStmtElem{
						{Condition: &ast.BoolLiteral{Val: true}},
						{Condition: &ast.BoolLiteral{Val: false}},
						{
							Condition: &ast.ConditionalExpr{
								LHS: &ast.Identifier{Name: "x"},
								Op:  AstOp(EQEQ),
								RHS: &ast.Identifier{Name: "y"},
							},
							Block: &ast.BlockStmt{Stmts: ast.Stmts{
								&ast.AssignmentExpr{
									Op:  ast.EQ,
									LHS: []ast.Node{&ast.Identifier{Name: "a"}},
									RHS: []ast.Node{&ast.ArithmeticExpr{
										LHS: &ast.Identifier{Name: "a"},
										RHS: &ast.IntegerLiteral{Val: 1},
										Op:  AstOp(ADD),
									}},
								},
							}},
						},
					},
					Else: nil,
				},
			},
		},
		{
			name: "+||",
			in:   "a * 1 + b || x + 1 && 1 / 2 == 1",
			expected: ast.Stmts{

				&ast.ConditionalExpr{
					Op: AstOp(EQEQ),
					LHS: &ast.ConditionalExpr{
						Op: AstOp(OR),
						LHS: &ast.ArithmeticExpr{
							Op: AstOp(ADD),
							LHS: &ast.ArithmeticExpr{
								Op:  AstOp(MUL),
								LHS: &ast.Identifier{Name: "a"},
								RHS: &ast.IntegerLiteral{Val: 1},
							},
							RHS: &ast.Identifier{Name: "b"},
						},
						RHS: &ast.ConditionalExpr{
							Op: AstOp(AND),
							LHS: &ast.ArithmeticExpr{
								Op:  AstOp(ADD),
								LHS: &ast.Identifier{Name: "x"},
								RHS: &ast.IntegerLiteral{Val: 1},
							},
							RHS: &ast.ArithmeticExpr{
								Op:  AstOp(DIV),
								LHS: &ast.IntegerLiteral{Val: 1},
								RHS: &ast.IntegerLiteral{Val: 2},
							},
						},
					},
					RHS: &ast.IntegerLiteral{Val: 1},
				},
			},
		},
		{
			name: "+||",
			in: `a * -1 + b || x + 1 && 1 / 2 == 1
			a += b + +!-1
			a -= 1
			a *= 1
			a /= 1
			a %= 1
			`,
			expected: ast.Stmts{

				&ast.ConditionalExpr{
					Op: AstOp(EQEQ),
					LHS: &ast.ConditionalExpr{
						Op: AstOp(OR),
						LHS: &ast.ArithmeticExpr{
							Op: AstOp(ADD),
							LHS: &ast.ArithmeticExpr{
								Op:  AstOp(MUL),
								LHS: &ast.Identifier{Name: "a"},
								RHS: &ast.IntegerLiteral{Val: -1},
							},
							RHS: &ast.Identifier{Name: "b"},
						},
						RHS: &ast.ConditionalExpr{
							Op: AstOp(AND),
							LHS: &ast.ArithmeticExpr{
								Op:  AstOp(ADD),
								LHS: &ast.Identifier{Name: "x"},
								RHS: &ast.IntegerLiteral{Val: 1},
							},
							RHS: &ast.ArithmeticExpr{
								Op:  AstOp(DIV),
								LHS: &ast.IntegerLiteral{Val: 1},
								RHS: &ast.IntegerLiteral{Val: 2},
							},
						},
					},
					RHS: &ast.IntegerLiteral{Val: 1},
				},

				&ast.AssignmentExpr{
					Op: ast.ADDEQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "a",
					}},
					RHS: []ast.Node{
						&ast.ArithmeticExpr{
							Op:  ast.ADD,
							LHS: &ast.Identifier{Name: "b"},
							RHS: &ast.UnaryExpr{
								Op: ast.ADD,
								RHS: &ast.UnaryExpr{
									Op:  ast.NOT,
									RHS: &ast.IntegerLiteral{Val: -1},
								},
							},
						},
					},
				},

				&ast.AssignmentExpr{
					Op: ast.SUBEQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "a",
					}},
					RHS: []ast.Node{&ast.IntegerLiteral{
						Val: 1,
					}},
				},
				&ast.AssignmentExpr{
					Op: ast.MULEQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "a",
					}},
					RHS: []ast.Node{&ast.IntegerLiteral{
						Val: 1,
					}},
				},
				&ast.AssignmentExpr{
					Op: ast.DIVEQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "a",
					}},
					RHS: []ast.Node{&ast.IntegerLiteral{
						Val: 1,
					}},
				},
				&ast.AssignmentExpr{
					Op: ast.MODEQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "a",
					}},
					RHS: []ast.Node{&ast.IntegerLiteral{
						Val: 1,
					}},
				},
			},
		},
	}

	// for idx := len(cases) - 1; idx >= 0; idx-- {
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			Stmts, err := ParsePipeline("", tc.in)

			if !tc.fail {
				assert.Equal(t, err, nil)
			} else {
				t.Logf("expected error: %s", err)
				assert.NotNil(t, err, "")
				return
			}

			if !tc.fail {
				var x, y string
				x = tc.expected.String()
				y = Stmts.String()
				assert.Nil(t, err)
				assert.Equal(t, x, y)
				// t.Logf("ok %s -> %s", tc.in, y)
			} else {
				t.Logf("%s -> expect fail: %v", tc.in, err)
				assert.NotNil(t, err, "")
			}
		})
	}
}

func TestParserFor(t *testing.T) {
	cases := []struct {
		name     string
		in       string
		expected ast.Stmts
		err      string
		fail     bool
	}{
		{
			name: "for_x_in_y",
			in: `for x in y {
				b = 1
			}`,
			expected: ast.Stmts{
				&ast.ForInStmt{
					InExpr: &ast.InExpr{
						LHS: &ast.Identifier{Name: "x"},
						RHS: &ast.Identifier{Name: "y"},
					},
					Body: &ast.BlockStmt{Stmts: ast.Stmts{
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "b"}},
							RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
						},
					}},
				},
			},
		},
		{
			name: "for_x_in_y",
			in: `for x in [1,2.,"2"]  {
				if x != "2" {
					continue				} else {
					break
				}
				a = a + 1
			}`,
			expected: ast.Stmts{
				&ast.ForInStmt{
					InExpr: &ast.InExpr{
						LHS: &ast.Identifier{Name: "x"},
						RHS: &ast.ListLiteral{
							List: []ast.Node{
								&ast.IntegerLiteral{Val: 1},
								&ast.FloatLiteral{Val: 2.},
								&ast.StringLiteral{Val: "2"},
							},
						},
					},
					Body: &ast.BlockStmt{Stmts: ast.Stmts{
						&ast.IfelseStmt{
							IfList: []*ast.IfStmtElem{
								{
									Condition: &ast.ConditionalExpr{
										LHS: &ast.Identifier{Name: "x"},
										Op:  AstOp(NEQ),
										RHS: &ast.StringLiteral{Val: "2"},
									},
									Block: &ast.BlockStmt{Stmts: ast.Stmts{
										&ast.ContinueStmt{},
									}},
								},
							},
							Else: &ast.BlockStmt{Stmts: ast.Stmts{
								&ast.BreakStmt{},
							}},
						},
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "a"}},
							RHS: []ast.Node{&ast.ArithmeticExpr{
								LHS: &ast.Identifier{Name: "a"},
								Op:  AstOp(ADD),
								RHS: &ast.IntegerLiteral{Val: 1},
							}},
						},
					}},
				},
			},
		},
		{
			name: "for cond ",
			in: `for ; a == func() ; {
				b = 1
			}`,
			expected: ast.Stmts{
				&ast.ForStmt{
					Cond: &ast.ConditionalExpr{
						Op:  AstOp(EQEQ),
						LHS: &ast.Identifier{Name: "a"},
						RHS: &ast.CallExpr{
							Obj: &ast.Identifier{Name: "func"},
						},
					},
					Body: &ast.BlockStmt{Stmts: ast.Stmts{
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "b"}},
							RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
						},
					}},
				},
			},
		},
		{
			name: "for_; cond ; loop ",
			in: `for ; a == func() ; x = 2. {
				b=2
			}`,
			expected: ast.Stmts{&ast.ForStmt{
				Cond: &ast.ConditionalExpr{
					Op:  AstOp(EQEQ),
					LHS: &ast.Identifier{Name: "a"},
					RHS: &ast.CallExpr{
						Obj: &ast.Identifier{Name: "func"},
					},
				},
				Loop: &ast.AssignmentExpr{
					Op: ast.EQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "x",
					}},
					RHS: []ast.Node{&ast.FloatLiteral{
						Val: 2.,
					}},
				},
				Body: &ast.BlockStmt{Stmts: ast.Stmts{
					&ast.AssignmentExpr{
						Op:  ast.EQ,
						LHS: []ast.Node{&ast.Identifier{Name: "b"}},
						RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
					},
				}},
			}},
		},
		{
			name: "for init; cond ; loop ",
			in: `for y=2; a == func() ; x = 2. {
				b=2
			}`,
			expected: ast.Stmts{&ast.ForStmt{
				Init: &ast.AssignmentExpr{
					Op: ast.EQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "y",
					}},
					RHS: []ast.Node{&ast.FloatLiteral{
						Val: 2.,
					}},
				},
				Cond: &ast.ConditionalExpr{
					Op:  AstOp(EQEQ),
					LHS: &ast.Identifier{Name: "a"},
					RHS: &ast.CallExpr{
						Obj: &ast.Identifier{Name: "func"},
					},
				},
				Loop: &ast.AssignmentExpr{
					Op: ast.EQ,
					LHS: []ast.Node{&ast.Identifier{
						Name: "x",
					}},
					RHS: []ast.Node{&ast.FloatLiteral{
						Val: 2.,
					}},
				},
				Body: &ast.BlockStmt{Stmts: ast.Stmts{
					&ast.AssignmentExpr{
						Op:  ast.EQ,
						LHS: []ast.Node{&ast.Identifier{Name: "b"}},
						RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
					},
				}},
			}},
		},
	}

	// for idx := len(cases) - 1; idx >= 0; idx-- {
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			Stmts, err := ParsePipeline("", tc.in)

			if !tc.fail {
				assert.Nil(t, err)
			} else {
				t.Logf("expected error: %s", err)
				assert.NotNil(t, err, "")
				return
			}

			if !tc.fail {
				var x, y string
				x = tc.expected.String()
				y = Stmts.String()
				assert.Nil(t, err)
				assert.Equal(t, x, y)
				t.Logf("ok %s -> %s", tc.in, y)
			} else {
				t.Logf("%s -> expect fail: %v", tc.in, err)
				assert.NotNil(t, err, "")
			}
		})
	}
}

func TestParser(t *testing.T) {
	cases := []struct {
		name     string
		in       string
		expected ast.Stmts
		err      string
		fail     bool
	}{
		{
			name: "if-condition-list-paren2",
			in:   `if ((a==b) && (a==c)) || a==d { }`,
			expected: ast.Stmts{&ast.IfelseStmt{
				IfList: ast.IfList{
					&ast.IfStmtElem{Condition: &ast.ConditionalExpr{
						Op: AstOp(OR),
						LHS: &ast.ParenExpr{
							Param: &ast.ConditionalExpr{
								Op: AstOp(AND),
								LHS: &ast.ParenExpr{
									Param: &ast.ConditionalExpr{
										Op:  AstOp(EQEQ),
										LHS: &ast.Identifier{Name: "a"},
										RHS: &ast.Identifier{Name: "b"},
									},
								},
								RHS: &ast.ParenExpr{
									Param: &ast.ConditionalExpr{
										Op:  AstOp(EQEQ),
										LHS: &ast.Identifier{Name: "a"},
										RHS: &ast.Identifier{Name: "c"},
									},
								},
							},
						},
						RHS: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "a"},
							RHS: &ast.Identifier{Name: "d"},
						},
					}},
				},
			}},
		},

		{
			name: "if-condition-list-paren",
			in:   `if (a==b) && (a==c) { }`,
			expected: ast.Stmts{&ast.IfelseStmt{
				IfList: ast.IfList{&ast.IfStmtElem{
					Condition: &ast.ConditionalExpr{
						Op: AstOp(AND),
						LHS: &ast.ParenExpr{
							Param: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "a"},
								RHS: &ast.Identifier{Name: "b"},
							},
						},
						RHS: &ast.ParenExpr{
							Param: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "a"},
								RHS: &ast.Identifier{Name: "c"},
							},
						},
					},
				}},
			}},
		},

		{
			name: "if-condition-list",
			in:   `if a==b && a==c { }`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op: AstOp(AND),
								LHS: &ast.ConditionalExpr{
									Op:  AstOp(EQEQ),
									LHS: &ast.Identifier{Name: "a"},
									RHS: &ast.Identifier{Name: "b"},
								},
								RHS: &ast.ConditionalExpr{
									Op:  AstOp(EQEQ),
									LHS: &ast.Identifier{Name: "a"},
									RHS: &ast.Identifier{Name: "c"},
								},
							},
						},
					},
				},
			},
		},

		{
			name: "if-error-non-condition",
			in:   `if { }`,
			fail: true,
		},

		{
			name: "if-elif-error-non-condition",
			in: `
			if key=="11" {

			} elif {

			}`,
			fail: true,
		},

		{
			name: "if-elif-elif-error-non-condition",
			in: `
			if key=="11" {

			} elif key=="22" {

			} elif {

			}`,
			fail: true,
		},

		{
			name: "if-elif-else-expr",
			in: `
			if key=="11" {
				g1(arg)
			} elif key=="22" {
				g2(arg)
			} else {
				g3(arg)
			}`,
			expected: ast.Stmts{&ast.IfelseStmt{
				IfList: ast.IfList{
					&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
						Block: &ast.BlockStmt{Stmts: ast.Stmts{
							&ast.CallExpr{
								Obj: &ast.Identifier{Name: "g1"},
								Param: []ast.Node{
									&ast.Identifier{Name: "arg"}},
							},
						}},
					},
					&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "22"},
						},
						Block: &ast.BlockStmt{Stmts: ast.Stmts{&ast.CallExpr{
							Obj: &ast.Identifier{Name: "g2"},
							Param: []ast.Node{
								&ast.Identifier{Name: "arg"}},
						}}},
					},
				},
				Else: &ast.BlockStmt{Stmts: ast.Stmts{
					&ast.CallExpr{
						Obj: &ast.Identifier{Name: "g3"},
						Param: []ast.Node{
							&ast.Identifier{Name: "arg"},
						},
					},
				}},
			}},
		},

		{
			name: "if-elif-expr",
			in: `
			if key=="11" {
				g1(arg)
			} elif key=="22" {
				g2(arg)
			}`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "key"},
								RHS: &ast.StringLiteral{Val: "11"},
							},
							Block: &ast.BlockStmt{Stmts: ast.Stmts{&ast.CallExpr{
								Obj: &ast.Identifier{Name: "g1"},
								Param: []ast.Node{
									&ast.Identifier{Name: "arg"},
								},
							}}},
						},
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "key"},
								RHS: &ast.StringLiteral{Val: "22"},
							},
							Block: &ast.BlockStmt{Stmts: ast.Stmts{
								&ast.CallExpr{
									Obj: &ast.Identifier{Name: "g2"},
									Param: []ast.Node{
										&ast.Identifier{Name: "arg"}},
								},
							}},
						},
					},
				},
			},
		},

		{
			name: "if-elif-else-non-ast.Stmts",
			in: `
			if key=="11"{

			} elif key=="22" {

			} else {

			}`,
			expected: ast.Stmts{&ast.IfelseStmt{
				IfList: ast.IfList{
					&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
					},
					&ast.IfStmtElem{Condition: &ast.ConditionalExpr{
						Op:  AstOp(EQEQ),
						LHS: &ast.Identifier{Name: "key"},
						RHS: &ast.StringLiteral{Val: "22"},
					}},
				},
				Else: &ast.BlockStmt{Stmts: ast.Stmts{}},
			}},
		},

		{
			name: "if-elif-non-ast.Stmts",
			in: `
			if key=="11" {

			} elif key=="22" {

			}`,
			expected: ast.Stmts{&ast.IfelseStmt{
				IfList: ast.IfList{
					&ast.IfStmtElem{Condition: &ast.ConditionalExpr{
						Op:  AstOp(EQEQ),
						LHS: &ast.Identifier{Name: "key"},
						RHS: &ast.StringLiteral{Val: "11"},
					}},
					&ast.IfStmtElem{Condition: &ast.ConditionalExpr{
						Op:  AstOp(EQEQ),
						LHS: &ast.Identifier{Name: "key"},
						RHS: &ast.StringLiteral{Val: "22"},
					}},
				},
			}},
		},

		{
			name: "if-expr-non-ast.Stmts",
			in:   `if key=="11" { }`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
					}},
				},
			},
		},
		{
			name: "if-else-expr-non-ast.Stmts",
			in: `
			if key=="11" {

			} else {

			}`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "key"},
								RHS: &ast.StringLiteral{Val: "11"},
							},
						},
					},
				},
			},
		},

		{
			name: "if-expr-non-ast.Stmts",
			in:   `if key=="11" { }`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
					}},
				},
			},
		},

		{
			name: "if-else-expr",
			in:   `if key=="11" { g1(arg);   g2(arg) } else { h(arg) } #ddwwdw `,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "key"},
								RHS: &ast.StringLiteral{Val: "11"},
							},
							Block: &ast.BlockStmt{Stmts: ast.Stmts{
								&ast.CallExpr{
									Obj: &ast.Identifier{Name: "g1"},
									Param: []ast.Node{

										&ast.Identifier{Name: "arg"},
									},
								},
								&ast.CallExpr{
									Obj: &ast.Identifier{Name: "g2"},
									Param: []ast.Node{
										&ast.Identifier{Name: "arg"},
									},
								},
							}},
						},
					},
					Else: &ast.BlockStmt{Stmts: ast.Stmts{
						&ast.CallExpr{
							Obj: &ast.Identifier{Name: "h"},
							Param: []ast.Node{
								&ast.Identifier{Name: "arg"},
							},
						},
					}},
				},
			},
		},
		// {
		// 	name: "if-else-expr",
		// 	in:   `if match(_,"./*")=="11" { g1(arg) g2(arg) } else { h(arg) }`,
		// 	expected: ast.Stmts{
		// 		&ast.IfelseStmt{
		// 			ast.IfList: ast.IfList{
		// 				&IfExpr{
		// 					Condition: &ast.ConditionalExpr{
		// 						Op:  AstOp(EQEQ),
		// 						LHS: &ast.Identifier{Name: "match(_, './*')"},
		// 						RHS: &ast.StringLiteral{Val: "11"},
		// 					},
		// 					ast.Stmts: ast.Stmts{
		// 						&FuncStmt{
		// 							Name:  "g1",
		// 							Param: []ast.Node{&ast.Identifier{Name: "arg"}},
		// 						},
		// 						&FuncStmt{
		// 							Name:  "g2",
		// 							Param: []ast.Node{&ast.Identifier{Name: "arg"}},
		// 						},
		// 					},
		// 				},
		// 			},
		// 			Else: ast.Stmts{
		// 				&FuncStmt{
		// 					Name:  "h",
		// 					Param: []ast.Node{&ast.Identifier{Name: "arg"}},
		// 				},
		// 			},
		// 		},
		// 	},
		// },

		{
			name: "if-else-expr-newline",
			in: `
			if key=="11" { #11aa
				g(arg) } else {


				h(arg)
			}`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
						Block: &ast.BlockStmt{Stmts: ast.Stmts{
							&ast.CallExpr{
								Obj: &ast.Identifier{Name: "g"},
								Param: []ast.Node{
									&ast.Identifier{Name: "arg"},
								},
							},
						}},
					}},
					Else: &ast.BlockStmt{Stmts: ast.Stmts{&ast.CallExpr{
						Obj: &ast.Identifier{Name: "h"},
						Param: []ast.Node{
							&ast.Identifier{Name: "arg"},
						},
					}}},
				},
			},
		},

		{
			name: "if-nil",
			in:   `if abc == nil {}`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{
						&ast.IfStmtElem{
							Condition: &ast.ConditionalExpr{
								Op:  AstOp(EQEQ),
								LHS: &ast.Identifier{Name: "abc"},
								RHS: &ast.NilLiteral{},
							},
						},
					},
				},
			},
		},

		{
			name: "if-expr",
			in:   `if key=="11" { g(arg) }`,
			expected: ast.Stmts{
				&ast.IfelseStmt{IfList: ast.IfList{
					&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
						Block: &ast.BlockStmt{
							Stmts: ast.Stmts{
								&ast.CallExpr{
									Obj: &ast.Identifier{Name: "g"},
									Param: []ast.Node{
										&ast.Identifier{Name: "arg"},
									},
								},
							},
						},
					},
				}},
			},
		},

		{
			name: "if-expr-newline",
			in: `
			if key=="11" {
				g(arg)
			}`,
			expected: ast.Stmts{
				&ast.IfelseStmt{
					IfList: ast.IfList{&ast.IfStmtElem{
						Condition: &ast.ConditionalExpr{
							Op:  AstOp(EQEQ),
							LHS: &ast.Identifier{Name: "key"},
							RHS: &ast.StringLiteral{Val: "11"},
						},
						Block: &ast.BlockStmt{Stmts: ast.Stmts{&ast.CallExpr{
							Obj: &ast.Identifier{Name: "g"},
							Param: []ast.Node{
								&ast.Identifier{Name: "arg"},
							},
						}}},
					}},
				},
			},
		},

		{
			name: "array-list in function arg value",
			in:   `f([1, 2.0, "3", true, false, nil, null, id_123])`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{&ast.ListLiteral{
						List: []ast.Node{
							&ast.IntegerLiteral{Val: 1},
							&ast.FloatLiteral{Val: 2.0},
							&ast.StringLiteral{Val: "3"},
							&ast.BoolLiteral{Val: true},
							&ast.BoolLiteral{Val: false},
							&ast.NilLiteral{},
							&ast.NilLiteral{},
							&ast.Identifier{Name: "id_123"},
						},
					}},
				},
			},
		},

		{
			name: "attr-expr in function arg value",
			in:   `f(arg=a.b.c)`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{&ast.AssignmentExpr{
						Op:  ast.EQ,
						LHS: []ast.Node{&ast.Identifier{Name: "arg"}},
						RHS: []ast.Node{&ast.AttrExpr{
							Obj: &ast.Identifier{Name: "a"},
							Attr: &ast.AttrExpr{
								Obj: &ast.AttrExpr{
									Obj:  &ast.Identifier{Name: "b"},
									Attr: &ast.Identifier{Name: "c"},
								},
							},
						}},
					}},
				},
			},
		},

		{
			name: "func_call_in_assignement_right",
			in:   `a = fx("a", true, a1=["b", 1.1])`,
			expected: ast.Stmts{
				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.CallExpr{
						Obj: &ast.Identifier{Name: "fx"},
						Param: []ast.Node{
							&ast.StringLiteral{Val: "a"},
							&ast.BoolLiteral{Val: true},
							&ast.AssignmentExpr{
								Op:  ast.EQ,
								LHS: []ast.Node{&ast.Identifier{Name: "a1"}},
								RHS: []ast.Node{&ast.ListLiteral{
									List: []ast.Node{
										&ast.StringLiteral{Val: "b"},
										&ast.FloatLiteral{Val: 1.1},
									},
								}},
							},
						},
					}},
				},
			},
		},

		{
			name: "naming args",
			in:   `f(arg1=1, arg2=2)`,
			expected: ast.Stmts{

				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "arg1"}},
							RHS: []ast.Node{&ast.IntegerLiteral{Val: 1}},
						},
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "arg2"}},
							RHS: []ast.Node{&ast.IntegerLiteral{Val: 2}},
						},
					},
				},
			},
		},

		{
			name: "func-cond-param-and-kwarg",
			in:   `f(arg1>1, arg2=2)`,
			expected: ast.Stmts{

				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{
						&ast.ConditionalExpr{
							LHS: &ast.Identifier{Name: "arg1"},
							Op:  ast.GT,
							RHS: &ast.IntegerLiteral{Val: 1},
						},
						&ast.AssignmentExpr{
							Op:  ast.EQ,
							LHS: []ast.Node{&ast.Identifier{Name: "arg2"}},
							RHS: []ast.Node{&ast.IntegerLiteral{Val: 2}},
						},
					},
				},
			},
		},

		{
			name: "json attr",
			in:   `f(.[2].x[3])`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{&ast.AttrExpr{
						Obj: &ast.IndexExpr{
							Index: &ast.IntegerLiteral{Val: 2},
						},
						Attr: &ast.IndexExpr{
							Obj:   &ast.Identifier{Name: "x"},
							Index: &ast.IntegerLiteral{Val: 3},
						},
					}},
				},
			},
		},

		{ // 如果 y 是 map 则支持
			name: "multi-dim arr",
			in: `f(x.y[2.5])
			{}
			a = {"1": 2, 3.1: 1}
			`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{
						&ast.AttrExpr{
							Obj: &ast.Identifier{Name: "x"},
							Attr: &ast.IndexExpr{
								Obj:   &ast.Identifier{Name: "y"},
								Index: &ast.FloatLiteral{Val: 2.5},
							},
						},
					},
				},
				&ast.MapLiteral{},
				&ast.AssignmentExpr{
					Op:  ast.EQ,
					LHS: []ast.Node{&ast.Identifier{Name: "a"}},
					RHS: []ast.Node{&ast.MapLiteral{
						KeyValeList: [][2]ast.Node{
							{
								&ast.StringLiteral{Val: "1"},
								&ast.IntegerLiteral{Val: 2},
							},
							{
								&ast.FloatLiteral{Val: 3.1},
								&ast.IntegerLiteral{Val: 1},
							},
						},
					}},
				},
			},
		},

		{
			in: `f(x.y[1][2].z)`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{
						&ast.AttrExpr{
							Obj: &ast.IndexExpr{
								Obj: &ast.IndexExpr{
									Obj: &ast.AttrExpr{
										Obj: &ast.Identifier{
											Name: "x",
										},
										Attr: &ast.Identifier{
											Name: "y",
										},
									},
									Index: &ast.IntegerLiteral{
										Val: 1,
									},
								},
								Index: &ast.IntegerLiteral{
									Val: 2,
								},
							},

							Attr: &ast.Identifier{
								Name: "z",
							},

							// Obj: &ast.Identifier{Name: "x"},
							// Attr: &ast.AttrExpr{
							// 	Obj: &ast.IndexExpr{
							// 		Obj: &ast.IndexExpr{
							// 			Obj: ,
							// 		},
							// 		Index: []ast.Node{
							// 			&ast.IntegerLiteral{Val: 1},
							// 			&ast.IntegerLiteral{Val: 2},
							// 		},
							// 	},
							// 	Attr: &ast.Identifier{Name: "z"},
							// },
						},
					},
				},
			},
		},

		{
			name: "case:-multiple-functions",
			in: `f1()
		f2()
		f3()`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f1"},
				},
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f2"},
				},
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f3"},
				},
			},
		},

		{
			name: "embedded functions",
			in:   `f1(g(f2("abc"), 123.0), 1, 2)`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f1"},
					Param: []ast.Node{
						&ast.CallExpr{
							Obj: &ast.Identifier{Name: "g"},
							Param: []ast.Node{

								&ast.CallExpr{
									Obj: &ast.Identifier{Name: "f2"},
									Param: []ast.Node{
										&ast.StringLiteral{Val: "abc"},
									},
								},
								&ast.FloatLiteral{
									Val: 123.0,
								},
							},
						},
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 2},
					},
				},
			},
		},

		{
			name: "attr syntax with index syntax in function arg",
			in:   `json(_, x.y[1].z)`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "json"},
					Param: []ast.Node{
						&ast.Identifier{Name: "_"},
						&ast.AttrExpr{
							Obj: &ast.IndexExpr{
								Obj: &ast.AttrExpr{
									Obj:  &ast.Identifier{Name: "x"},
									Attr: &ast.Identifier{Name: "y"},
								},
								Index: &ast.IntegerLiteral{Val: 1},
							},
							Attr: &ast.Identifier{Name: "Z"},
						},
					},
				},
			},
		},

		{
			name: "simple attr syntax",
			in:   `json(_, x.y.z)`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "json"},
					Param: []ast.Node{
						&ast.Identifier{Name: "_"},
						&ast.AttrExpr{
							Obj: &ast.Identifier{Name: "x"},
							Attr: &ast.AttrExpr{
								Obj:  &ast.Identifier{Name: "y"},
								Attr: &ast.Identifier{Name: "z"},
							},
						},
					},
				},
			},
		},

		{
			name: "simple attr syntax",
			in:   `match(_,"p([a-z]+)ch")`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "match"},
					Param: []ast.Node{
						&ast.Identifier{Name: "_"},
						&ast.StringLiteral{Val: "p([a-z]+)ch"},
					},
				},
			},
		},

		{
			name: "many param",
			in:   `f(a, b, 1, 2, )`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "f"},
					Param: []ast.Node{
						&ast.Identifier{Name: "a"},
						&ast.Identifier{Name: "b"},
						&ast.IntegerLiteral{Val: 1},
						&ast.IntegerLiteral{Val: 2},
					},
				},
			},
		},

		{
			name: `func-arg-with-multi-line-string`,
			in: `abc(x, """
this
is
multiline-string
""")`,
			expected: ast.Stmts{

				&ast.CallExpr{
					Obj: &ast.Identifier{Name: "abc"},
					Param: []ast.Node{
						&ast.Identifier{Name: "x"},
						&ast.StringLiteral{Val: `
this
is
multiline-string
`},
					},
				},
			},
		},
		{
			name: `func-func`,
			in: `f1()
			f2()
			`,
			expected: ast.Stmts{
				&ast.CallExpr{
					Obj:   &ast.Identifier{Name: "f1"},
					Param: nil,
				},
				&ast.CallExpr{
					Obj:   &ast.Identifier{Name: "f2"},
					Param: nil,
				},
			},
		},
		{
			name: "valid slice with identifier",
			in:   `a[1:3]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj: &ast.Identifier{Name: "a"},
					Start: &ast.IntegerLiteral{
						Val: 1,
					},
					End: &ast.IntegerLiteral{
						Val: 3,
					},
				},
			},
		},
		{
			name: "valid slice default start and end",
			in:   `a[:]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj:   &ast.Identifier{Name: "a"},
					Start: nil,
					End:   nil,
				},
			},
		},
		{
			name: "valid slice with step",
			in:   `a[1:3:2]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj: &ast.Identifier{Name: "a"},
					Start: &ast.IntegerLiteral{
						Val: 1,
					},
					End: &ast.IntegerLiteral{
						Val: 3,
					},
					Step: &ast.IntegerLiteral{
						Val: 2,
					},
				},
			},
		},
		{
			name: "valid slice with double colon but empty step",
			in:   `a[::]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj:   &ast.Identifier{Name: "a"},
					Start: nil,
					End:   nil,
					Step:  nil,
				},
			},
		},
		{
			name: "valid slice with string",
			in:   `"hello"[:3]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj:   &ast.StringLiteral{Val: "hello"},
					Start: nil,
					End: &ast.IntegerLiteral{
						Val: 3,
					},
				},
			},
		},
		{
			name: "valid slice with list",
			in:   `[1, 2, 3, 4][1:]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj: &ast.ListLiteral{
						List: []ast.Node{
							&ast.IntegerLiteral{Val: 1},
							&ast.IntegerLiteral{Val: 2},
							&ast.IntegerLiteral{Val: 3},
							&ast.IntegerLiteral{Val: 4},
						},
					},
					Start: &ast.IntegerLiteral{
						Val: 1,
					},
					End: nil,
				},
			},
		},
		{
			name: "valid nested slice with identifier",
			in:   `a[1:3][0:2]`,
			expected: ast.Stmts{
				&ast.SliceExpr{
					Obj: &ast.SliceExpr{
						Obj: &ast.Identifier{Name: "a"},
						Start: &ast.IntegerLiteral{
							Val: 1,
						},
						End: &ast.IntegerLiteral{
							Val: 3,
						},
					},
					Start: &ast.IntegerLiteral{
						Val: 0,
					},
					End: &ast.IntegerLiteral{
						Val: 2,
					},
				},
			},
		},
		{
			name: "invalid slice with invalid object type",
			in:   `true[1:3]`,
			expected: ast.Stmts{&ast.SliceExpr{
				Obj: &ast.BoolLiteral{
					Val: true,
				},
				Start: &ast.IntegerLiteral{
					Val: 1,
				},
				End: &ast.IntegerLiteral{
					Val: 3,
				},
			}},
		},
		{
			name: "invalid slice with invalid start type",
			in:   `a["1":3]`,
			fail: true,
		},
		{
			name: "invalid slice with invalid end type",
			in:   `a[1:"3"]`,
			fail: true,
		},
		{
			name: "invalid slice with no object",
			in:   `[1:3]`,
			fail: true,
		},
	}

	// for idx := len(cases) - 1; idx >= 0; idx-- {
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			Stmts, err := ParsePipeline("", tc.in)

			if !tc.fail {
				assert.Nil(t, err)
			} else {
				t.Logf("expected error: %s", err)
				if err == nil {
					t.Error(tc)
				}
				assert.NotNil(t, err, "")
				return
			}

			if !tc.fail {
				var x, y string
				x = tc.expected.String()
				y = Stmts.String()
				assert.Nil(t, err)
				assert.Equal(t, x, y)
				t.Logf("ok %s -> %s", tc.in, y)
			} else {
				t.Logf("%s -> expect fail: %v", tc.in, err)
				assert.NotNil(t, err, "")
			}
		})
	}
}

func TestParserEOLS(t *testing.T) {
	cases := []string{
		`

`,
		`
;
`,
		`

;;
`,
		`
;

`,
		`

a + 1
`,
		`

a + 1
;`,
		`

;
a

`,

		`

a
`,
		`
a +  #abc
1
a + 1
x in [abc]

x in # dd
[ abc]

x in
[ abc];

x in [	abc
]

x[
	a
]
x[a]
x[
	a]
x in pt_kvs_keys(fields=false,tags=true)
cALl(
	a, v,
	c )
cALl(	a, v,
		c 
	)
cALl(a, v,c)

{ #d
	x: call( #33

	),
	a : x , d: e,
	c: x
}
{}
a =
b
`,
		`
x[-1:3]
x[:][1:3]
x[1:2:3]
x[1:2:]
x[::1]
"hello"[a:b]
x[x[1]:1]
func(a, b, c)[func(a, b, c):b]
[1,2,3,4][a:b]`,
	}

	for _, v := range cases {
		stmts, err := ParsePipeline("", v)
		if err != nil {
			t.Fatal(err)
		}
		t.Log(stmts)
	}
}
