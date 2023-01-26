# Project config

SOURCE_FILES = src/main.c \
							 src/blaze/core.c \
							 src/blaze/evaluate/evaluate.c \
							 src/blaze/evaluate/fwdEvaluate.c \
							 src/blaze/primitives/expressions.c \
							 src/blaze/primitives/scalar.c \
							 src/blaze/primitives/polynomials.c

OBJECT_FILES = src/main.o \
							 src/blaze/core.o \
							 src/blaze/evaluate/evaluate.o \
							 src/blaze/evaluate/fwdEvaluate.o \
							 src/blaze/primitives/expressions.o \
							 src/blaze/primitives/scalar.o \
							 src/blaze/primitives/polynomials.o
EXE_NAME = program

# Compilation settings

CC = gcc
C_FLAGS = -Wall -Wextra
L_FLAGS = -lstdc++ -lm

# Recipes

all: build
	./$(EXE_NAME)

build: $(EXE_NAME)

$(EXE_NAME): $(OBJECT_FILES)
	$(CC) $^ $(L_FLAGS) -o $@

%.o: %.c
	$(CC) -c $^ $(C_FLAGS) -o $@

.PHONY: clean oclean

clean:
	rm $(OBJECT_FILES) $(EXE_NAME)

oclean:
	rm $(EXE_NAME)
