#include "evaluate.h"

void evaluate (expr *expression) {
  switch (expression->type) {
    case SCALAR:
      break;
    case POLYNOMIAL:
      //
      ;
      polynomialData *data = getPolynomialData(expression);
      if (expression->update == 0 && data->variable->update == 0)
        return ;
      evaluate(data->variable);
      forwardPolynomial(expression);
      expression->update = 0;
      break;
    case UNARY_OPERATION:
      ;
      expr *operand = getUnaryOperationData(expression);
      if (expression->update == 0 && operand->update == 0)
        return ;
      switch (expression->sub_type) {
        case NEGATE_UNARY_OPERATION:
          evaluate(operand);
          forwardNegate(expression, operand);
          break;
        case EXP_RAISE_UNARY_OPERATION:
          evaluate(operand);
          forwardExpRaise(expression, operand);
          break;
      }
      expression->update = 0;
      break;
    case BINARY_OPERATION:
      ;
      expr **operands = getBinaryOperationData(expression);
      if (expression->update == 0 && operands[0]->update == 0 && operands[1]->update == 0)
        return ;
      evaluate(operands[0]);
      evaluate(operands[1]);
      switch(expression->sub_type) {
        case ADD_BINARY_OPERATION:
          forwardAdd(expression, operands); 
          break;
        case SUBTRACT_BINARY_OPERATION:
          forwardSubtract(expression, operands);
          break;
        case MULTIPLY_BINARY_OPERATION:
          forwardMultiply(expression, operands);
          break;
        case DIVIDE_BINARY_OPERATION:
          forwardDivide(expression, operands);
          break;
        case RAISE_BINARY_OPERATION:
          forwardRaise(expression, operands);
          break;
      }
      expression->update = 0;
      break;
  }
}

