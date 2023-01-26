#include "expressions.h"

expr *makeExpr() {
  expr *exp = (expr*)malloc(sizeof(expr));
  exp->x = 0;
  exp->changed = 1;
  return exp;
}

void deleteExpr(expr *exp) {
  // Do the full tree generality shit later.
  switch(exp->ptype) {
    case CONSTANT:
      free(exp);
      break;
    case SCALAR:
      free(exp);
      break;
    case BIN_OP:
      deleteExpr(exp->operands[0]);
      deleteExpr(exp->operands[1]);
      free(exp); 
      break;
  };
}

// IO STUFF

void printExprRaw(expr *exp) {
  switch (exp->ptype) {
    case CONSTANT:
      printf("'%f'", exp->x);
      break;
    case SCALAR:
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


