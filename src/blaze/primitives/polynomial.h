#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <math.h>
#include "expression.h"


typedef struct polynomialData {
  expr *variable;
  uint degree;
  numeric *coeffecients;
} polynomialData;

expr *makePolynomial(expr* variable, uint degree, numeric *coeffecients);

void setPolynomial(expr *polynomial, numeric *coeffecient_array);

void deletePolynomial(expr *polynomial);
void forwardPolynomial(expr *expression);

polynomialData* getPolynomialData(expr *polynomial);

#endif
