#ifndef CORE_HPP
#define CORE_HPP

// Primitive includes
#include "evaluate/evaluate.h"
#include "primitives/expressions.h"

// other includes
#include "io/io.h"

void evalExpr(expr *exp);

// Bin ops 

// Basic arithmetic

expr *add(expr *a, expr *b);
expr *subtract(expr *a, expr *b);
expr *multiply(expr *a, expr *b);
expr *divide(expr *a, expr *b);

// Algebraic

expr *raise(expr *a, expr *b);
expr *constRaise(expr *a, numeric x);

#endif
