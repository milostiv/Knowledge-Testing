CXX = g++ # Cpp compiler

SRCS = homework2.cpp # Source file name
OUTPUT = $(SRCS:.cpp=.out) # Output file name

.PHONY: clean
clean:

	-$(RM) $(OUTPUT)

.PHONY: build
build: 

	$(CXX) $(LIB_LOC) $(SRCS) -o $(OUTPUT)
