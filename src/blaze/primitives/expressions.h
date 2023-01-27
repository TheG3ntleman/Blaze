#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <stdlib.h>

typedef float numeric;

typedef enum exprType {
  SCALAR,
  POLYNOMIAL,
  BIN_OP
} exprType;
/*
typedef enum scalarType {
  CONSTANT,
  VARIABLE
} scalarType;

typedef enum polynomialType {
  SCALAR_POLYNOMIAL 
} polynomialType;

typedef enum binOpType {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  RAISE
} binOpType;*/

typedef enum subType {
  // SCALAR SUBTYPES
  CONSTANT_SCALAR,
  VARIABLE_SCALAR,
  // POLYNOMIAL SUBTYPES
  CONSTANT_SCALAR_POLYNOMIAL,
  VARIABLE_SCALAR_POLYNOMIAL,
  // BINARY OPERATION TYPES
  ADD_BIN_OP,
  SUBTRACT_BIN_OP,
  MULTIPLY_BIN_OP,
  DIVIDE_BIN_OP,
  RAISE_BIN_OP
} subType;

typedef struct expr {

  exprType type;
  numeric value;
  char changed; // flag to indicate whether expr has changed or not.
  subType subtype;
  /*union {
    binOpType binary_operation_type;
    scalarType scalar_type;
    polynomialType polynomial_type;
  } subtype;*/
  union {
    struct expr **operands;
    char *symbol;
    // Right now only supports raw numeric
    // coeffecients but will support
    // more general expression coeffecients
    // later.
    numeric *coeffecients;
  } data;

} expr;

expr *makeExpr();
void deleteExpr(expr *exp);


#endif
