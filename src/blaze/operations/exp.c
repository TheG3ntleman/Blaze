#include "exp.h"
#include "unary_operation.h"

expr *expRaise(expr *operand) {
  expr *exp_node = makeUnaryOperation(operand);
  exp_node->sub_type = EXP_RAISE_UNARY_OPERATION;
  return exp_node;
}

void forwardExpRaise(expr *expression, expr *operand) {
  expression->value =  expf(operand->value);
}
