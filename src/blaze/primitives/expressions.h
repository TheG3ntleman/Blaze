#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <stdlib.h>

typedef float numeric;

typedef enum exprType {
  SCALAR,
  BIN_OP
} exprType;

typedef enum scalarType {
  CONSTANT,
  VARIABLE
} scalarType;

typedef enum binOpType {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  RAISE
} binOpType;

typedef struct expr {

  exprType type;
  numeric value;
  char changed; // flag to indicate whether expr has changed or not.
  union {
    binOpType binary_operation_type;
    scalarType scalar_type;
  } subtype;
  union {
    struct expr **operands;
    char *symbol;
  } data;

} expr;

expr *makeExpr();
void deleteExpr(expr *exp);


#endif
