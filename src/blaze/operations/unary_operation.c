#include "unary_operation.h"

expr* makeUnaryOperation(expr *operand) {
  expr *operation = (expr*)malloc(sizeof(expr));
  operation->type = UNARY_OPERATION;
  operation->update = 1;
  operation->value = 0;
  operation->data = malloc(sizeof(expr*)); // space for 1 expr pointer 
  ((expr**)operation->data)[0] = operand;  // (expr*)
  return operation;
}

inline expr* getUnaryOperationData(expr *unary_operation) {
  return ((expr **)unary_operation->data)[0];
}
