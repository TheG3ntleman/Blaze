#include "evaluate.h"

void evaluate(expr *expression) {
  switch (expression->type) {
    case SCALAR:
      // Do nothing.
      break;
    case BINARY_OPERATION:
      expr **operands = getBinaryOperationData(expression);
      switch(expression->sub_type) {
        case ADD_BINARY_OPERATION:
          evaluate(operands[0]);
          evaluate(operands[1]);
          forwardAdd(expression, operands);
          break;
      }
      break;
  };
}
