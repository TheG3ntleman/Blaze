#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdlib.h>

// Including primitives

typedef float numeric;

typedef enum exprType {
  SCALAR,
  BINARY_OPERATION
} exprType;

typedef enum exprSubType {
  VARIABLE_SCALAR,
  CONSTANT_SCALAR,
  ADD_BINARY_OPERATION
} exprSubType;

typedef struct expr {

  exprType type;
  exprSubType sub_type;
  char update;
  numeric value;
  void *data;

} expr;

/*
 * Add the following functions:
 *  1. makeExpr();
 *  2. deleteExpr();
 *  3. unsafe non-recursive delete.
 * */

expr *makeExpr();

#endif
