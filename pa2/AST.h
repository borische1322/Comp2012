#ifndef AST_H
#define AST_H

#include <string>

#include "Util.h"

// TODO: Write the definition of AST and ExprAST.
class AST {
    public:

    virtual ~AST(){}
    virtual const char* getTokenName() const = 0;
    virtual void print(u32 indent) const = 0;

};

class ExprAST: public AST {
    public:
    virtual ~ExprAST() {}
    virtual void print(u32 indent) const;
};

#endif  // AST_H
