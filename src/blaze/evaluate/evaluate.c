#include "evaluate.h"

void evalExpr(expr *exp) {
  switch (exp->ptype) {

    case CONSTANT:
      break;
    case SCALAR:
      break;
    case BIN_OP:
      evalExpr(exp->operands[0]);
      evalExpr(exp->operands[1]);
      if (exp->operands[1]->changed == 0 && exp->operands[0]->changed == 0) {
        //printf("Not re-evaluating.\n");
        break;
      }
      exp->changed = 1;
      switch (exp->btype) {
        case ADD:
          exp->x = fwdAdd(exp->operands[0]->x, exp->operands[1]->x);
          break;
        case SUBTRACT:
          exp->x = fwdSub(exp->operands[0]->x, exp->operands[1]->x);
          break;
        case MULTIPLY:
          exp->x = fwdMul(exp->operands[0]->x, exp->operands[1]->x);
          break;
        case RAISE:
          exp->x = fwdRaise(exp->operands[0]->x, exp->operands[1]->x);

      };
      exp->operands[0]->changed = 0;
      exp->operands[1]->changed = 0;
      break;
  };
}


