#ifndef EVALUATE_H
#define EVALUATE_H

#include "../primitives/expression.h"
#include "../primitives/polynomial.h"

#include "../operations/unary_operation.h"
#include "../operations/negate.h"
#include "../operations/binary_operation.h"
#include "../operations/add.h"
#include "../operations/subtract.h"
#include "../operations/multiply.h"
#include "../operations/divide.h"
#include "../operations/raise.h"

void evaluate(expr *expression); 

#endif
