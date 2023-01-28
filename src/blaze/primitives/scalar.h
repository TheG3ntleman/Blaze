#ifndef SCALAR_H
#define SCALAR_H

#include "expressions.h"
#include "../io/io.h"

expr *makeConstant(numeric x);
void setConstant(numeric x, expr *constant);

expr *makeVariable(char *symbol);
void setVariable(numeric x, expr *var);

void deleteScalar(expr *var);

#endif
