# Project config

SOURCE_FILES = src/main.c \
							 src/blaze/core.c \
							 src/blaze/primitives/expression.c \
							 src/blaze/primitives/scalar.c \
							 src/blaze/primitives/delete.c \
							 src/blaze/operations/unary_operation.c \
							 src/blaze/operations/negate.c \
							 src/blaze/operations/binary_operation.c \
							 src/blaze/operations/add.c \
							 src/blaze/operations/subtract.c \
							 src/blaze/operations/multiply.c \
							 src/blaze/operations/divide.c \
							 src/blaze/operations/raise.c \
							 src/blaze/evaluate/evaluate.c \
							 src/blaze/err.c \
							 src/tests/feature_test.c \
							 src/tests/performance_test.c \

OBJECT_FILES = src/main.o \
							 src/blaze/core.o \
							 src/blaze/primitives/expression.o \
							 src/blaze/primitives/scalar.o \
							 src/blaze/primitives/delete.o\
							 src/blaze/operations/unary_operation.o \
							 src/blaze/operations/negate.o \
							 src/blaze/operations/binary_operation.o \
							 src/blaze/operations/add.o \
							 src/blaze/operations/subtract.o \
							 src/blaze/operations/multiply.o \
							 src/blaze/operations/divide.o \
							 src/blaze/operations/raise.o \
							 src/blaze/evaluate/evaluate.o \
							 src/blaze/err.o \
							 src/tests/feature_test.o \
							 src/tests/performance_test.o \

EXE_NAME = program

# Compilation settings

CC = gcc
C_FLAGS = -Wall -Wextra -O3
L_FLAGS = -lm

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
