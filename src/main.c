
#include "blaze/core.h"

/*
 * Description of user side interface to define new variables:
 * variable x = createNewVariable(value);
 * */

int main() {

  expr *x = makeScalar(3);
  expr *y = makeScalar(4);
  expr *z = makeScalar(300);

  expr *sum = add(x, y);
  sum = multiply (z, sum);
  sum = constRaise(sum, 2);

  printExpr(sum);
  printf("Value of expr before eval: %f\n", sum->x);
  evalExpr(sum);
  printf("Value of expr before eval: %f\n", sum->x);
  evalExpr(sum);
  deleteExpr(sum);
  /*
  // output of this code: ((300.000000x(3.000000+4.000000))^'2.000000')
  */

  return 0;
}
