#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <math.h>
#include "../io/io.h"

typedef float numeric;

// forward functions

numeric fwdAdd(numeric x, numeric y);
numeric fwdSub(numeric x, numeric y);
numeric fwdMul(numeric x, numeric y);
numeric fwdDiv(numeric x, numeric y);

numeric fwdRaise(numeric x, numeric y);

#endif
