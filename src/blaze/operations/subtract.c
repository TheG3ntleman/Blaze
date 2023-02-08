#include "subtract.h"
#include "binary_operation.h"

expr *subtract(expr *operand1, expr *operand2) {
  expr *diff = makeBinaryOperation(operand1, operand2);
  diff->sub_type = SUBTRACT_BINARY_OPERATION;
  return diff;
}

void forwardSubtract(expr *expression, expr **operands) {
  expression->value = operands[0]->value - operands[1]->value;
}
