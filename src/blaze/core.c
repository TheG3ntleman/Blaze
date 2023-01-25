#include "core.h"

// EXPR ALLOCATION/DEALLOCATION

expr *makeExpr() {
  return (expr*)malloc(sizeof(expr));
}

void deleteExpr(expr *exp) {
  // Do the full tree generality shit later.
  switch(exp->ptype) {
    case CONSTANT:
      free(exp);
      break;
    case VARIABLE:
      free(exp);
      break;
    case BIN_OP:
      deleteExpr(exp->operands[0]);
      deleteExpr(exp->operands[1]);
      free(exp); 
      break;
  };
}

// CONSTANT STUFF

expr *makeConstant(numeric x) {
  expr *variable = makeExpr();
  variable->ptype = CONSTANT;
  variable->x = x;
  return variable; 
}

// VARIABLE STUFF

expr *makeZeroVariable() {
  expr *variable = makeExpr(); 
  variable->ptype = VARIABLE;
  variable->x = 0;
  return variable; 
}

expr *makeVariable(numeric x) {
  expr *variable = makeExpr();
  variable->ptype = VARIABLE;
  variable->x = x;
  return variable; 
}

void set(numeric x, expr *var) {
  var->x = x;
}

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

// IO STUFF

void printExprRaw(expr *exp) {
  switch (exp->ptype) {
    case CONSTANT:
      printf("'%f'", exp->x);
      break;
    case VARIABLE:
      printf("%f", exp->x);      
      break;
    case BIN_OP:
      printf("(");
      printExprRaw(exp->operands[0]);
      switch(exp->btype) {
        case ADD:
          printf("+");
          break;
        case SUBTRACT:
          printf("-");
          break;
        case MULTIPLY:
          printf("x");
          break;
        case RAISE:
          printf("^");
          break;
      };
      printExprRaw(exp->operands[1]);
      printf(")");
      break;
    default:
      printf("?");
      break;
  }
}

void printExpr(expr *exp) {
  printExprRaw(exp);
  printf("\n");
}
