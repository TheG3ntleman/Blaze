#include "core.h"

// EXPR ALLOCATION/DEALLOCATION
// CONSTANT STUFF

// SCALAR STUFF
// BIN OPS
// op/OP/Op stands for operation

// Basic Arithmetic

expr *makeBinOp(expr *a, expr *b, subType opType) {
  expr *op = makeExpr();
  op->type = BIN_OP;
  op->value = 0;
  op->changed = 1;
  op->subtype = opType;
  op->data.operands = (expr**)malloc(sizeof(expr*) * 2); // multiplying 2 because add is binary.
  op->data.operands[0] = a, op->data.operands[1] = b;
  return op;
}

expr *add(expr *a, expr *b) {
  return makeBinOp(a, b, ADD_BIN_OP);
}

expr *subtract(expr *a, expr *b) {
  return makeBinOp(a, b, SUBTRACT_BIN_OP);
}

expr *multiply(expr *a, expr *b) {
  return makeBinOp(a, b, MULTIPLY_BIN_OP);
}

expr *divide(expr *a, expr *b) {
  return makeBinOp(a, b, DIVIDE_BIN_OP);
}

expr *raise(expr *a, expr *b) {
  return makeBinOp(a, b, RAISE_BIN_OP);
}

expr *constRaise(expr *a, numeric x) {
  expr *power = makeConstant(x);
  return makeBinOp(a, power, RAISE_BIN_OP);
}

