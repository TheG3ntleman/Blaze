#ifndef ERR_H
#define ERR_H

#include <stdio.h>
#include <stdlib.h>

// All output from the library gets
// stored into either the error buffer
// or the output buffer. For now, there
// will only be one common buffer from
// simplicity.

// Max buffer size?

void reportError(char *message, char *location, char errorLevel);

// printExprRaw should only be a local function.
void printExpr();

char* getOutputBuffer();


#endif
