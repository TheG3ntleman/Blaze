#include "binary_operation.h"

expr* makeBinaryOperation(expr *operand1, expr *operand2) {
  expr *operation = (expr *)malloc(sizeof(expr));
  operation->type = BINARY_OPERATION;
  operation->update = 1;
  operation->value = 0;
  operation->data = malloc(sizeof(expr*) * 2);
  ((expr**)operation->data)[0] = operand1;
  ((expr**)operation->data)[1] = operand2;
  return operation;
}

inline expr** getBinaryOperationData(expr *binary_operation) {
  return (expr **)binary_operation->data;
}
