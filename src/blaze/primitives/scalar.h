#ifndef SCALAR_H
#define SCALAR_H

#include "expressions.h"

expr *makeConstant(numeric x);
expr *makeZeroScalar();
expr *makeScalar(numeric x);
void setScalar(numeric x, expr *var);

#endif
