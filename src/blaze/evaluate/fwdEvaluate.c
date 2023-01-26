#include "fwdEvaluate.h"


numeric fwdAdd(numeric x, numeric y) {
  return x + y;
}
numeric fwdSub(numeric x, numeric y) {
  return x - y;
}
numeric fwdMul(numeric x, numeric y) {
  return x*y;
}
numeric fwdDiv(numeric x, numeric y) {
  printf("x: %f, y: %f\n", x, y);
  if (y != 0)
    return (x/y);
  else 
    reportError("Attempted division by zero", "fwdDiv for scalar expression", 1);
  return 0;
}

numeric fwdRaise(numeric x, numeric y) {
  // Check if y is an integer power
  // If yes use the stack way or some other way to calculate this.
  // If no find roots of the equation using newton's method.
  return pow(x, y);
}


