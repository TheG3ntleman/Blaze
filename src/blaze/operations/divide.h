#ifndef DIVIDE_H
#define DIVIDE_H

#include "../err.h"
#include "../primitives/expression.h"
#include "binary_operation.h"

expr *divide(expr *operand1, expr *operand2);
void forwardDivide(expr *expression, expr **operands);

#endif
