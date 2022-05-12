# Makefile for a shared library in C

CC = gcc # C compiler
LIB_LOC = -L/home/milostiv/programming/mylib

SRCS = lc13.c # Source file name
OUTPUT = $(SRCS:.c=.out) # Output file name

.PHONY: default
default:
	@echo "Run \"make build\" or \"make clean\" to use makefile"

.PHONY: clean
clean:
	-$(RM) $(OUTPUT)

.PHONY: build
build: 
	$(CC) $(LIB_LOC) $(SRCS) -o $(OUTPUT) -lmylib
