#ifndef EXP_H
#define EXP_H

#include <math.h>
#include "unary_operation.h"

expr *expRaise(expr *operand);
void forwardExpRaise(expr *expression, expr *operand);

#endif
