#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <stdlib.h>

typedef float numeric;

typedef enum exprType {
  SCALAR,
  POLYNOMIAL,
  BIN_OP
} exprType;

typedef enum subType {
  // SCALAR SUBTYPES
  CONSTANT_SCALAR,
  VARIABLE_SCALAR,
  // POLYNOMIAL SUBTYPES
  SUBTYPE_POLYNOMIAL,
  // BINARY OPERATION TYPES
  ADD_BIN_OP,
  SUBTRACT_BIN_OP,
  MULTIPLY_BIN_OP,
  DIVIDE_BIN_OP,
  RAISE_BIN_OP
} subType;

// SPECIAL DATA STRUCTS (COULD BE AVOIDED HERE 
// AND WRITTEN  IN CORRESPODNING PRIMITIVE FILES
// If data field becomes void*, however, would
// that fuck up debugging?)

typedef struct polynomialInfo {
  unsigned int degree;
  numeric *coeffecients;
} polynomialInfo;

// EXPR STRUCT

typedef struct expr {

  exprType type;
  numeric value;
  char changed; // flag to indicate whether expr has changed or not.
  subType subtype;
  union {
    struct expr **operands;
    char *symbol;
    // Right now only supports raw numeric
    // coeffecients but will support
    // more general expression coeffecients
    // later.
    polynomialInfo *polynomialInfo;
  } data;

} expr;

expr *makeExpr();


#endif
