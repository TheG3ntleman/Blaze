#include "core.h"

// EXPR ALLOCATION/DEALLOCATION
// CONSTANT STUFF

// SCALAR STUFF
// BIN OPS
// op/OP/Op stands for operation

// Basic Arithmetic

expr *makeBinOp(expr *a, expr *b, binOpType opType) {
  expr *op = makeExpr();
  op->type = BIN_OP;
  op->value = 0;
  op->changed = 0;
  op->subtype.binary_operation_type = opType;
  op->data.operands = (expr**)malloc(sizeof(expr*) * 2); // multiplying 2 because add is binary.
  op->data.operands[0] = a, op->data.operands[1] = b;
  return op;
}

expr *add(expr *a, expr *b) {
  return makeBinOp(a, b, ADD);
}

expr *subtract(expr *a, expr *b) {
  return makeBinOp(a, b, SUBTRACT);
}

expr *multiply(expr *a, expr *b) {
  return makeBinOp(a, b, MULTIPLY);
}

expr *divide(expr *a, expr *b) {
  return makeBinOp(a, b, DIVIDE);
}

expr *raise(expr *a, expr *b) {
  return makeBinOp(a, b, RAISE);
}

expr *constRaise(expr *a, numeric x) {
  expr *power = makeConstant(x);
  return makeBinOp(a, power, RAISE);
}

