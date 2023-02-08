#include "evaluate.h"

void evaluate (expr *expression) {
  switch (expression->type) {
    case SCALAR:
      break;
    case UNARY_OPERATION:
      ;
      expr *operand = getUnaryOperationData(expression);
      switch (expression->sub_type) {
        case NEGATE_UNARY_OPERATION:
          evaluate(operand);
          forwardNegate(expression, operand);
          break;
      }
      break;
    case BINARY_OPERATION:
      ;
      expr **operands = getBinaryOperationData(expression);
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
      break;
  }
}

