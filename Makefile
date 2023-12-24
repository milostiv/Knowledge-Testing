MAKE_DIR_C = $(PWD)/leetCode/c
SUB_DIRS_C := ${shell find ${MAKE_DIR_C}/* -type d -print}
MAKE_DIR_CPP = $(PWD)/leetCode/cpp
SUB_DIRS_CPP := ${shell find ${MAKE_DIR_CPP}/* -type d -print}

.PHONY: default
default:
	@echo "Run \"make all\" or \"make clean\" to use makefile"

.PHONY: clean
clean:

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) clean ; \
	done

	@for subdir in $(SUB_DIRS_CPP); do \
		cd $$subdir ; $(MAKE) clean ; \
	done

.PHONY: all
all:

	@echo "Compiling C files:\n"

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) build ; \
	done

	@echo "\nCompiling C++ files:\n" 

	@for subdir in $(SUB_DIRS_CPP); do \
		cd $$subdir ; $(MAKE) build ; \
	done
	
.PHONY: all_github
all_github:

	@echo "Compiling C files:\n"

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) build_github ;\
	done

	@echo "\nCompiling C++ files:\n"
    
	@for subdir in $(SUB_DIRS_CPP); do \
		cd $$subdir ; $(MAKE) build_github ;\
	done
