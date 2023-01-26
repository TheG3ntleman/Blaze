#include "scalar.h"

expr *makeConstant(numeric x) {
  expr *variable = makeExpr();
  variable->ptype = CONSTANT;
  variable->changed = 0;
  variable->x = x;
  return variable; 
}

expr *makeZeroScalar() {
  expr *variable = makeExpr(); 
  variable->ptype = SCALAR;
  variable->x = 0;
  return variable; 
}

expr *makeScalar(numeric x) {
  expr *variable = makeExpr();
  variable->ptype = SCALAR;
  variable->x = x;
  return variable; 
}

void setScalar(numeric x, expr *var) {
  if (var->ptype == SCALAR) {
    var->changed = 1;
    var->x = x;
  } else if (var->ptype == CONSTANT) 
      printf("Tried setting constant.\n");
}


