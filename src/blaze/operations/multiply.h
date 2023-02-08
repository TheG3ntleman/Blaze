#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "../err.h"
#include "../primitives/expression.h"
#include "binary_operation.h"

expr *multiply(expr* operand1, expr *operand2);
void forwardMultiply(expr *expression, expr **operands);

#endif
