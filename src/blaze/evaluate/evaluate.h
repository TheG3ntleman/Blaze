#ifndef EVALUATE_H
#define EVALUATE_H

#include "../primitives/expressions.h"
#include "../primitives/scalar.h"
#include "../primitives/polynomials.h"
#include "fwdEvaluate.h"

void evalExpr(expr *exp);
void deleteExpr(expr *exp);

#endif
