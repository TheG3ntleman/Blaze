
#include "blaze/core.h"

/*
 * Description of user side interface to define new variables:
 * variable x = createNewVariable(value);
 * */

int main() {

  expr *x = makeVariable(3);
  expr *y = makeVariable(4);
  expr *z = makeVariable(300);
  expr *sum = add(x, y);
  sum = multiply (z, sum);
  sum = constRaise(sum, 43);
  printExpr(sum);
  deleteExpr(sum);

  return 0;
}
