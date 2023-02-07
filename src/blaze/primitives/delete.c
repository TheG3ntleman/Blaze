#include "delete.h"

void deleteExpr(expr *expression) {
  switch (expression->type) {
    case SCALAR:
      free(expression);
      break;
    case BINARY_OPERATION:
      expr **operands = getBinaryOperationData(expression);
      deleteExpr(operands[0]);
      deleteExpr(operands[1]);
      free(expression->data);
      free(expression);
      break;
    default:
      // Must handle this case. Use report error here.
      break;
  };
}
