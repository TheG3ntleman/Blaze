#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "../primitives/expressions.h"

// Error messages and stuff
void reportError(char *msg, char *location, char errorLevel);

// IO stuff
void printExprRaw(expr *exp);
void printExpr(expr *exp);

#endif
