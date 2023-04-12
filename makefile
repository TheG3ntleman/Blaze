# Project config

SOURCE_FILES = src/main.c \
							 src/blaze/blaze.c

HEADER_FILES = src/blaze/blaze.h

OBJECT_FILES = src/main.o \
							 src/blaze/blaze.o

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

%.o: %.c $(HEADER_FILES)
	$(CC) -c $< $(C_FLAGS) -o $@

.PHONY: clean oclean

clean:
	rm $(OBJECT_FILES) $(EXE_NAME) 

oclean:
	rm $(EXE_NAME) 
