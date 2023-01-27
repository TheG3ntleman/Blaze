#include "io.h"

// error stuff

void reportError(char *msg, char *location, char errorLevel) {
  printf("Error: \"%s\" occured as %s", msg, location);
  // 0 - continue, 1 - break program.
  if (errorLevel)
    exit(0);
}

// IO STUFF

// Add default handlings later.
void printExprRaw(expr *exp) {
  switch (exp->type) {
    case SCALAR:
      if (exp->subtype == CONSTANT_SCALAR)
        printf("%f", exp->value);
      else if (exp->subtype == VARIABLE_SCALAR)
        printf("%s", exp->data.symbol);
      else 
        printf("?s?"); // Bad Scalar
      break;
    case BIN_OP:
      printf("(");
      printExprRaw(exp->data.operands[0]);
      switch(exp->subtype) {
        case ADD_BIN_OP:
          printf("+");
          break;
        case SUBTRACT_BIN_OP:
          printf("-");
          break;
        case MULTIPLY_BIN_OP:
          printf("x");
          break;
        case DIVIDE_BIN_OP:
          printf("/");
          break;
        case RAISE_BIN_OP:
          printf("^");
          break;
      };
      printExprRaw(exp->data.operands[1]);
      printf(")");
      break;
  }
}

void printExpr(expr *exp) {
  printExprRaw(exp);
  printf("\n");
}


