#include "io.h"

// error stuff

void reportError(char *msg, char *location, char errorLevel) {
  printf("Error: \"%s\" occured as %s", msg, location);
  // 0 - continue, 1 - break program.
  if (errorLevel)
    exit(0);
}

// IO STUFF

void printExprRaw(expr *exp) {
  switch (exp->type) {
    case SCALAR:
      if (exp->subtype.scalar_type == CONSTANT)
        printf("%f", exp->value);
      else if (exp->subtype.scalar_type == VARIABLE)
        printf("%s", exp->data.symbol);
      else 
        printf("?s?"); // Bad Scalar
      break;
    case BIN_OP:
      printf("(");
      printExprRaw(exp->data.operands[0]);
      switch(exp->subtype.binary_operation_type) {
        case ADD:
          printf("+");
          break;
        case SUBTRACT:
          printf("-");
          break;
        case MULTIPLY:
          printf("x");
          break;
        case DIVIDE:
          printf("/");
          break;
        case RAISE:
          printf("^");
          break;
      };
      printExprRaw(exp->data.operands[1]);
      printf(")");
      break;
    default:
      printf("?_?"); // Bad unknown
      break;
  }
}

void printExpr(expr *exp) {
  printExprRaw(exp);
  printf("\n");
}


