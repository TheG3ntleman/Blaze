#include "core.h"

// EXPR ALLOCATION/DEALLOCATION
// CONSTANT STUFF

// SCALAR STUFF
// BIN OPS
// op/OP/Op stands for operation

// Basic Arithmetic

expr *makeBinOp(expr *a, expr *b, binOpType opType) {
  expr *op = makeExpr();
  op->ptype = BIN_OP;
  op->btype = opType;
  op->operands = (expr**)malloc(sizeof(expr*) * 2); // multiplying 2 because add is binary.
  op->operands[0] = a, op->operands[1] = b;
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

// Algebraic 

//expr *raise(expr *a, expr *b);
expr *constRaise(expr *a, numeric x) {
  expr *power = makeConstant(x);
  return makeBinOp(a, power, RAISE);
}

