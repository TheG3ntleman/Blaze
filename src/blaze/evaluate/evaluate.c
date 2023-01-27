#include "evaluate.h"
#include "fwdEvaluate.h"

void evalExpr(expr *exp) {
  switch (exp->type) {

    case SCALAR:
      break;
    case BIN_OP:
      evalExpr(exp->data.operands[0]);
      evalExpr(exp->data.operands[1]);
      if (exp->data.operands[1]->changed == 0 && exp->data.operands[0]->changed == 0 && exp->changed == 0) {
        //printf("Not re-evaluating.\n");
        break;
      }
      exp->changed = 1;
      switch (exp->subtype) {
        case ADD_BIN_OP:
          exp->value = fwdAdd(exp->data.operands[0]->value, exp->data.operands[1]->value);
          break;
        case SUBTRACT_BIN_OP:
          exp->value = fwdSub(exp->data.operands[0]->value, exp->data.operands[1]->value);
          break;
        case MULTIPLY_BIN_OP:
          exp->value = fwdMul(exp->data.operands[0]->value, exp->data.operands[1]->value);
          break;
        case DIVIDE_BIN_OP:
          exp->value = fwdDiv(exp->data.operands[0]->value, exp->data.operands[1]->value);          
          break;
        case RAISE_BIN_OP:
          exp->value = fwdRaise(exp->data.operands[0]->value, exp->data.operands[1]->value);

      };
      exp->data.operands[0]->changed = 0;
      exp->data.operands[1]->changed = 0;
      break;
  };
}


