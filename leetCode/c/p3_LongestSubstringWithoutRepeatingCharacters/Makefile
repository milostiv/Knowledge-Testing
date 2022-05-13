# Makefile for a shared library in C

CC = gcc # C compiler
LIB_LOC = -L/home/milostiv/programming/mylib
LIB_LOC_GITHUB = -L/home/runner/work/Programming/Programming/mylib

SRCS = lc3.c # Source file name
OUTPUT = $(SRCS:.c=.out) # Output file name

.PHONY: clean
clean:
	-$(RM) $(OUTPUT)

.PHONY: build
build: 
	$(CC) $(LIB_LOC) $(SRCS) -o $(OUTPUT) -lmylib

.PHONY: build_github
build_github: 
	$(CC) $(LIB_LOC_GITHUB) $(SRCS) -o $(OUTPUT) -lmylib
