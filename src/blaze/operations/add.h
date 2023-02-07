#ifndef ADD_H
#define ADD_H

#include "binary_operation.h"
#include "../primitives/expression.h"
#include "../err.h"

expr* add(expr *operand1, expr *operand2);

void forwardAdd(expr* expression, expr **operands);

#endif
