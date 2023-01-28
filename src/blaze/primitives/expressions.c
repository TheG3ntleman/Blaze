#include "expressions.h"

expr *makeExpr() {
  expr *exp = (expr*)malloc(sizeof(expr));
  exp->value = 0;
  exp->changed = 1;
  return exp;
}


