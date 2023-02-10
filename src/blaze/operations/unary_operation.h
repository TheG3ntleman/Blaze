#ifndef UNARY_OPERATION_H
#define UNARY_OPERATION_H

#include "../primitives/expression.h"

expr* makeUnaryOperation(expr *operand);
expr* getUnaryOperationData(expr *operation);

#endif
