#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "../primitives/expression.h"
#include "binary_operation.h"
#include "../err.h"

expr *subtract(expr *operand1, expr *operand2);
void forwardSubtract(expr *expression, expr **operands);

#endif
