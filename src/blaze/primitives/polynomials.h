#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include "expressions.h"
#include "../io/io.h"

expr *makePolynomial(uint degree, numeric *coeffecient_arr, expr *scalar);
void setPolynomial(uint degree, numeric *coeffecient_arr, expr *polynomial);
void deletePolynomial(expr *exp);

#endif
