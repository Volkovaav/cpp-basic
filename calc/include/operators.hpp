#pragma once
#include "astnode.hpp"
#include <string>

class Add: public ASTNode {
    public:
        Add(ASTNode *lhs, ASTNode *rhs):
        ASTNode("+", lhs, rhs)
        {}
        Add &operator=(const Add &) = default;
        ~Add();
};

class Sub:public ASTNode {
    public:
        Sub(ASTNode *lhs, ASTNode *rhs):
        ASTNode("-", lhs, rhs) 
        {}
        Sub &operator=(const Sub &) = default;
        ~Sub();
};

class Mul: public ASTNode {
    public:
        Mul(ASTNode *lhs, ASTNode *rhs):
        ASTNode("*", lhs, rhs)
        {}
        Mul &operator=(const Mul &) = default;
        ~Mul();
};

class Div: public ASTNode {
    public:
        Div(ASTNode *lhs, ASTNode *rhs ):
        ASTNode("/", lhs, rhs)
        {}
        Div &operator=(const Div &) = default;
        ~Div();

};