#ifndef BINARY_OPERATION_H
#define BINARY_OPERATION_H

#include "../primitives/expression.h"

expr* makeBinaryOperation(expr *operand1, expr *operand2);
expr** getBinaryOperationData(expr *binary_operation);

#endif
