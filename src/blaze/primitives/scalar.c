#include "scalar.h"

expr *makeScalar(char* symbol) {
  expr *scalar = makeExpr();
  scalar->type = SCALAR;
  scalar->sub_type = VARIABLE_SCALAR;
  scalar->update = 1;
  scalar->value = 0;
  scalar->data = (void *)symbol;
  return scalar;
}

void setScalar(expr *scalar, numeric x) {
 scalar->value = x; 
}

char* getScalarData(expr *scalar) {
  return (char*)scalar->data; 
}
