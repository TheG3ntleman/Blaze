#include "tests.h"

void feature_test() {
  printf("\n\nRunning feature test.\n\n");

  // Simple unary operation test
  expr *a = makeScalar("a"); 
  setScalar(a, 3); 
  expr *x = negate(a);
  evaluate(x);

  printf("\nSimple unary operation test\n"
         "-(a:%f) = x:%f\n", a->value, x->value);

  // Simple binary option test (add)
  expr *y = makeScalar("y");
  expr *z = add(x, y);

  setScalar(y, 4);

  evaluate(z);

  printf("\nSimple binary operation test \n"
         "x:%f + y:%f = z:%f\n", x->value, y->value, z->value);

  printf("This test consisted of DAG creation (with scalars and add)\n"
         " and expression evaluation.\n");

  deleteExpr(z);

  printf("Delete function tested and executed successfully.\n");

  // Checking subtraction.
  x = makeScalar("x"), y = makeScalar("y");
  setScalar(x, 3);
  setScalar(y, 4);
  printf("\nChecking subtraction\n");
  z = subtract(x, y);
  evaluate(z);
  printf("x:%f - y:%f = z:%f\n", x->value, y->value, z->value);
  deleteExpr(z);

  // Checking raise.
  x = makeScalar("x"), y = makeScalar("y");
  setScalar(x, 3);
  setScalar(y, 4);
  z = raise(x, y);
  evaluate(z);
  printf("x:%f ^ y:%f = z:%f\n", x->value, y->value, z->value);
  deleteExpr(z);

  // Test polynomial functionality here.
  x = makeScalar("x");
  setScalar(x, 1);
  numeric coeffs[] = {1, 2, 3}; 
  y = makePolynomial(x, 3, coeffs);
  evaluate(y);
  printf("the polynomial has evaluated to %f\n", y->value);
}

