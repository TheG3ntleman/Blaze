#ifndef NEGATE_H
#define NEGATE_H

// Should probably depricate 
// this, seems like a waste
// of memory.

// UNARY OPERTION
#include "unary_operation.h"

expr* negate(expr *operand);
void forwardNegate(expr *expression, expr *operand);

#endif
