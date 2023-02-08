#include "divide.h"
#include "binary_operation.h"

expr *divide(expr *operand1, expr *operand2) {
  expr *quotient = makeBinaryOperation(operand1, operand2);
  quotient->sub_type = DIVIDE_BINARY_OPERATION;
  return quotient;
}

void forwardDivide(expr *expression, expr **operands) {
  if (operands[1]->value == 0) 
    reportError("division by zero", "scalar forward divide", 1);
  expression->value = operands[0]->value/operands[1]->value;
}
