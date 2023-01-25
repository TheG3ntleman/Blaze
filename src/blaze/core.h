#ifndef CORE_HPP
#define CORE_HPP

#include <stdlib.h>
#include <stdio.h>
#include "primitives.h"

typedef enum exprType {
  CONSTANT,
  VARIABLE,
  BIN_OP
} exprType;

typedef enum binOpType {
  ADD,
  SUBTRACT,
  MULTIPLY, 
  RAISE
} binOpType;

typedef struct expr {

  exprType ptype;
  numeric x;
  char changed; // flag to indicate whether expr has changed or not.
  union {
    binOpType btype; 
  };
  union {
    struct expr **operands; 
  };

} expr;

expr *makeExpr();
void deleteExpr(expr *exp);

expr *makeZeroVariable();
expr *makeVariable(numeric x);
void set(numeric x, expr *var);
void evalExpr(expr *exp);

// Bin ops 

// Basic arithmetic

expr *add(expr *a, expr *b);
expr *subtract(expr *a, expr *b);
expr *multiply(expr *a, expr *b);

// Algebraic

//expr *raise(expr *a, expr *b);
expr *constRaise(expr *a, numeric x);

// IO stuff
void printExprRaw(expr *exp);
void printExpr(expr *exp);

#endif
