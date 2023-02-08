#include "negate.h"
#include "unary_operation.h"

expr *negate(expr *expression) {
  expr *negated_expression = makeUnaryOperation(expression);
  negated_expression->sub_type = NEGATE_UNARY_OPERATION;
  return negated_expression;
}

void forwardNegate(expr *expression, expr *operand) {
  expression->value = -1.0f * operand->value;
}
