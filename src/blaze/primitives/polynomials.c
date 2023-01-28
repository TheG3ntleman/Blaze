#include "polynomials.h"
#include "expressions.h"


expr *makePolynomial(uint degree, numeric *coeffecient_arr, expr *exp) {
  expr *polynomial = makeExpr();
  polynomial->type = POLYNOMIAL;
  polynomial->subtype = SUBTYPE_POLYNOMIAL;
  polynomial->value = 0;
  polynomial->changed = 1;
  polynomial->data.polynomialInfo = (polynomialInfo*)malloc(sizeof(polynomialInfo));
  polynomial->data.polynomialInfo->degree = degree;
  polynomial->data.polynomialInfo->coeffecients = coeffecient_arr;
  return polynomial;
}

void setPolynomial(uint degree, numeric *coeffecient_arr, expr *polynomial) {
}

void deletePolynomial(expr *polynomial) {
  free(polynomial->data.polynomialInfo);
  free(polynomial);
}
