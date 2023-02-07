#include "add.h"
#include "binary_operation.h"

expr* add(expr *operand1, expr *operand2) {
  expr *sum = makeBinaryOperation(operand1, operand2);
  sum->sub_type = ADD_BINARY_OPERATION;
  return sum;
}

void forwardAdd(expr *expression, expr **operands) {
  //expr **operands = getBinaryOperationData(expression);
  //printf("exp: %f, op1: %f, op2: %f\n", expression->value, operands[0]->value, operands[1]->value);

  switch (operands[0]->type) {
    case SCALAR:
      expression->value = operands[0]->value + operands[1]->value;
      break;
    case BINARY_OPERATION:
      expression->value = operands[0]->value + operands[1]->value;
      break;
    default:
      expression->value = operands[0]->value + operands[1]->value;
      break;
  }
}
