#ifndef SCALAR_H
#define SCALAR_H

#include "expression.h"

expr *makeScalar(char *symbol);

void setScalar(expr *scalar, numeric x);
char* getScalarData(expr *scalar); // Returns scalar symbol that's it

#endif
