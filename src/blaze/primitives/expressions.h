#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "../evaluate/fwdEvaluate.h"

typedef enum exprType {
  CONSTANT,
  SCALAR,
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

// IO stuff
void printExprRaw(expr *exp);
void printExpr(expr *exp);

#endif
