#include "multiply.h"

expr *multiply(expr *operand1, expr *operand2) {
  expr *product = makeBinaryOperation(operand1, operand2);
  product->sub_type = MULTIPLY_BINARY_OPERATION;
  return product;
}

void forwardMultiply(expr *expression, expr **operands) {
  expression->value = operands[0]->value * operands[1]->value;
}
