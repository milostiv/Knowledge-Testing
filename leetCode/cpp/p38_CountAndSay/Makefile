CXX = g++ # Cpp compiler

SRCS = lc38.cpp # Source file name
OUTPUT = $(SRCS:.cpp=.out) # Output file name

.PHONY: clean
clean:

	-$(RM) $(OUTPUT)

.PHONY: build
build: 

	$(CXX) $(LIB_LOC) $(SRCS) -o $(OUTPUT)

.PHONY: build_github
build_github:

	$(CXX) $(LIB_LOC_GITHUB) $(SRCS) -o $(OUTPUT)
	@test -f $(OUTPUT) || (echo "Can not compile $(SRCS) file"; exit 1)
