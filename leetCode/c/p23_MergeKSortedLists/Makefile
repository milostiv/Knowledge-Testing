CC = gcc # C compiler
INC = -I/home/milostiv/Programming/mylib
INC_GITHUB = -I/home/runner/work/Programming/Programming/mylib
LIB_LOC = -L/home/milostiv/Programming/mylib
LIB_LOC_GITHUB = -L/home/runner/work/Programming/Programming/mylib

SRCS = lc23.c # Source file name
OUTPUT = $(SRCS:.c=.out) # Output file name

.PHONY: clean
clean:

	-$(RM) $(OUTPUT)

.PHONY: build
build: 

	$(CC) $(LIB_LOC) $(SRCS) $(INC) -o $(OUTPUT) -lmylib

.PHONY: build_github
build_github:

	$(CC) $(LIB_LOC_GITHUB) $(SRCS) $(INC_GITHUB) -o $(OUTPUT) -lmylib 
	@test -f $(OUTPUT) || (echo "Can not compile $(SRCS) file"; exit 1)
