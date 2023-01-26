#include "expressions.h"

expr *makeExpr() {
  expr *exp = (expr*)malloc(sizeof(expr));
  exp->value = 0;
  exp->changed = 1;
  return exp;
}

void deleteExpr(expr *exp) {
  // Do the full tree generality shit later.
  switch(exp->type) {
    case SCALAR:
      free(exp);
      break;
    case BIN_OP:
      deleteExpr(exp->data.operands[0]);
      deleteExpr(exp->data.operands[1]);
      free(exp); 
      break;
  };
}

