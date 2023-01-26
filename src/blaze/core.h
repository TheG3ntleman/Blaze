#ifndef CORE_HPP
#define CORE_HPP

#include "primitives/expressions.h"
#include "primitives/scalar.h"

void evalExpr(expr *exp);

// Bin ops 

// Basic arithmetic

expr *add(expr *a, expr *b);
expr *subtract(expr *a, expr *b);
expr *multiply(expr *a, expr *b);

// Algebraic

//expr *raise(expr *a, expr *b);
expr *constRaise(expr *a, numeric x);

#endif
