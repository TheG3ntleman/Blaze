
#include "blaze/core.h"
#include "blaze/primitives/scalar.h"

/*
 * Description of user side interface to define new variables:
 * variable x = createNewVariable(value);
 * */
int main() {

  /*int x;
  int y = x*x*x;
  int z = 3*x*x;
  int z = 3 ; // x = 1;*/

  expr *x = makeConstant(2);
  expr *y = makeConstant(3);
  expr *z = makeConstant(4);

  expr *sum = add(x, y), *quotient = divide(x, y);
  sum = multiply (z, sum);
  sum = raise(sum, x);

  printExpr(sum);
  printf("Value of expr before eval: %f\n", sum->value);
  evalExpr(sum);
  printf("Value of expr before eval: %f\n", sum->value);


  expr *k = makeVariable("x");
  sum = add(sum, k);
  printExpr(sum);

  printf("Expression and value for quotient:\n");
  printExpr(quotient);
  evalExpr(quotient); // Buggy here
  printf("quotient = %f\n", quotient->value);
 
  deleteExpr(sum);
  deleteExpr(quotient);
  // output of this code: ((300.000000x(3.000000+4.000000))^'2.000000')
  

  return 0;
}
