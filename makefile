# Project config

SOURCE_FILES = src/main.c src/smathlib/core.c
OBJECT_FILES = src/main.o src/smathlib/core.o
EXE_NAME = program

# Compilation settings

CC = gcc
C_FLAGS = -Wall -Wextra
L_FLAGS = -lstdc++

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
