
#include "blaze/core.h"

/*
 * Description of user side interface to define new variables:
 * variable x = createNewVariable(value);
 * */

int main() {

  // ((300.000000x(3.000000+4.000000))^'43.000000')

  expr *x = makeVariable(3);
  expr *y = makeVariable(4);
  expr *z = makeVariable(300);
  expr *sum = add(x, y);
  sum = multiply (z, sum);
  printExpr(sum);
  printf("Value of expr before eval: %f\n", sum->x);
  evalExpr(sum);
  printf("Value of expr before eval: %f\n", sum->x);
  evalExpr(sum);
  deleteExpr(sum);

  return 0;
}
