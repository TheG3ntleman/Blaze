
#include <time.h>
#include "blaze/core.h"
#include "blaze/evaluate/evaluate.h"
#include "blaze/primitives/scalar.h"

/*
 * Description of user side interface to define new variables:
 * variable x = createNewVariable(value);
 * */
int main() {

  uint a = 1, b = 1;
  //scanf("%u %u", &a, &b);

  clock_t t;
  for (a = 1; a < 1; a *= 2) {
    t = clock();
    for (uint i = 0; i < a; i++) {
      expr *x = makeConstant(0);
      for (uint j = 0; j < b; j++) {
        expr *y = makeConstant(j + 1);
        x = add(y, x); 
      }
      evalExpr(x);
      //printf("x has a value of %f\n", x->value);
      deleteExpr(x);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%u,%lf\n", a, time_taken);
  }

  printf("Finished.\n");
  
  return 0;
}
