#ifndef RAISE_H
#define RAISE_H

#include <math.h>

#include "../primitives/expression.h"
#include "binary_operation.h"
#include "../err.h"

expr *raise(expr *operand1, expr *operand2);
void forwardRaise(expr *expression, expr **operands);

#endif
