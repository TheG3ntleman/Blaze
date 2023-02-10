#include "polynomial.h"
#include "expression.h"

expr *makePolynomial(expr* variable, uint degree, numeric *coeffecient_array) {
  
  expr *polynomial = makeExpr();
  polynomial->type = POLYNOMIAL;
  polynomial->update = 1;
  polynomial->value = 0;

  uint non_zero_coeffecients = 0;
  for (uint i = 0; i < degree; i++) {
    if (coeffecient_array[i] == 0)
      non_zero_coeffecients++;
  }

  //if (non_zero_coeffecients > degree/2) {
    // Will store coeffecients in array
    polynomial->sub_type = FULL_POLYNOMIAL;
    polynomial->data = malloc(sizeof(polynomialData));
    polynomialData *data = getPolynomialData(polynomial);
    data->coeffecients = malloc(sizeof(numeric) *degree);
    data->degree = degree;
    data->variable = variable;
    for (uint i = 0; i < degree; i++) 
      data->coeffecients[i] = coeffecient_array[i];
  //}

  return polynomial;
}

void setPolynomial(expr *polynomial, numeric *coeffecient_array) {
  polynomialData *data =  getPolynomialData(polynomial);
  for (uint i = 0; i < data->degree; i++)
    data->coeffecients[i] = coeffecient_array[i];
}

void deletePolynomial(expr *polynomial) {
  free(getPolynomialData(polynomial)->coeffecients);
  free(polynomial->data);
}

polynomialData* getPolynomialData(expr *polynomial){
  return (polynomialData*)polynomial->data;
}

void forwardPolynomial(expr *polynomial) {
  polynomialData *data = getPolynomialData(polynomial);
  numeric variable_value = data->variable->value, x = 0;
  polynomial->value = 0;
  for (uint i = 0; i < data->degree; i++) {
    polynomial->value += data->coeffecients[i] * pow(variable_value, i);
  }
}
