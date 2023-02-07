#include "err.h"

char *outputBuffer;

void reportError(char *message, char *location, char errorLevel) {
  if (errorLevel != 0) {
  sprintf(outputBuffer, "Error: \"%s\" occured at \n\t%s \nwith an error level of %d\n", message, location, (int)errorLevel);
  } else { 
    // A simple 'else' for now
    // When other error levels are added
    // this can be extended.
    printf("Error: \"%s\" occured at \n\t%s \nwith an error level of %d\n", message, location, (int)errorLevel);
    exit(0);
  }
}

void printExprBlock() {

}

void printExpr() {

}

char *getOutputBuffer() {
  return outputBuffer;
}
