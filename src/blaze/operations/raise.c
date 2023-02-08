#include "raise.h"
#include "binary_operation.h"

expr *raise(expr *operand1, expr *operand2) {
  expr *res = makeBinaryOperation(operand1, operand2);
  res->sub_type = RAISE_BINARY_OPERATION;
  return res;
}

void forwardRaise(expr *expression, expr **operands) {
  expression->value = powf(operands[0]->value, operands[1]->value); 
}
