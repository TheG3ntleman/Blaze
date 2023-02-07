#include "tests.h"

#define NUM_TEST_ITERATIONS 1000
#define NUM_NODES 100000 // Dont make this too high to avoid stack overflows. 

void performance_test() {
  printf("\n\nRunning performance test.\n\n");
 
  // TEST-I: Graph contruction

  clock_t start_time = clock();
  for (uint i = 0; i < NUM_TEST_ITERATIONS; i++) {
    expr *sum = makeScalar("x");
    setScalar(sum, 0);
    for (uint j = 0; j < NUM_NODES; j++) {
      expr *increment = makeScalar("i");
      setScalar(increment, j + 1);
      sum = add(sum, increment);
    }
    deleteExpr(sum);
  }
  double time_taken = ((double)clock()-start_time)/CLOCKS_PER_SEC;
  printf("It took %lf to complete test 1" \
         "(graph construction).\n", time_taken/NUM_TEST_ITERATIONS);

  // TEST-I Evaluate

  float answer = 0;
  
  expr *sum = makeScalar("x");
  setScalar(sum, 0);
  for (uint j = 0; j < NUM_NODES; j++) {
    expr *increment = makeScalar("i");
    setScalar(increment, j + 1);
    sum = add(sum, increment);
  }
  
  start_time = clock();
  for (uint i = 0; i < NUM_TEST_ITERATIONS; i++) {
    evaluate(sum);
    answer = (answer * i) + sum->value;
    answer /= i + 1;
  }
  time_taken = ((double)clock()-start_time)/CLOCKS_PER_SEC;
  deleteExpr(sum);
  printf("It took %lf to complete test 1" \
         "(evaluate). The answer evaluated to %f.\n", time_taken/NUM_TEST_ITERATIONS, answer);

  // TEST-I Graph construction and evaluate.

  answer = 0;

  start_time = clock();
  for (uint i = 0; i < NUM_TEST_ITERATIONS; i++) {
    sum = makeScalar("x");
    setScalar(sum, 0);
    for (uint j = 0; j < NUM_NODES; j++) {
      expr *increment = makeScalar("i");
      setScalar(increment, j + 1);
      sum = add(sum, increment);
    }
    evaluate(sum);
    answer = (answer * i) + sum->value;
    answer /= i + 1;
    deleteExpr(sum);
  }
  time_taken = ((double)clock()-start_time)/CLOCKS_PER_SEC;
  printf("It took %lf to complete test 1" \
         "(evaluate and graph construction). The answer evaluated to %f.\n", time_taken/NUM_TEST_ITERATIONS, answer);

}
