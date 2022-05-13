# Makefile for a shared library in C

CC = gcc # C compiler
LIB_LOC = -L/home/runner/work/Programming/Programming/mylib

SRCS = lc10.c # Source file name
OUTPUT = $(SRCS:.c=.out) # Output file name

.PHONY: clean
clean:
	-$(RM) $(OUTPUT)

.PHONY: build
build: 
	$(CC) $(LIB_LOC) $(SRCS) -o $(OUTPUT) -lmylib
