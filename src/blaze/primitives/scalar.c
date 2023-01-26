#include "scalar.h"

expr *makeConstant(numeric x) {
  expr *constant = makeExpr();
  constant->type = SCALAR;
  constant->subtype.scalar_type = CONSTANT;
  constant->changed = 1;
  constant->value = x;
  return constant; 
}

void setConstant(numeric x, expr *constant) {
  if (constant->type == SCALAR) {
    if (constant->subtype.scalar_type == CONSTANT) {
      constant->value = x;
      constant->changed = 1;
    } else
        reportError("Attempt to set non-constant scalar", "setConstant", 0);
  } else
      reportError("Attempt to set non-scalar value", "setConstant", 0);
}

expr *makeVariable(char *symbol) {
  expr *variable = makeExpr();
  variable->type = SCALAR;
  variable->subtype.scalar_type = VARIABLE;
  variable->value = 0;
  variable->changed = 0;
  variable->data.symbol = symbol;
  return variable;
}

void setVariable(numeric x, expr *var) {
  if (var->type == SCALAR) {
    if (var->subtype.scalar_type == VARIABLE) {
      var->value = x;
      var->changed = 1;
    } else
        reportError("Attempt to set non-variable scalar", "setVariable", 0);
  } else
      reportError("Attempt to set non-scalar value", "setVariable", 0);
}

