MAKE_DIR = $(PWD)/leetCode/c
SUB_DIRS := ${shell find ${MAKE_DIR}/* -type d -print}

.PHONY: default
default:
	@echo "Run \"make all\" or \"make clean\" to use makefile"

.PHONY: clean
clean:

	@for subdir in $(SUB_DIRS); do \
		cd $$subdir ; $(MAKE) clean ; \
	done

.PHONY: all
all:

	@for subdir in $(SUB_DIRS); do \
		cd $$subdir ; $(MAKE) build ; \
	done	

.PHONY: all_github
all_github:

	@for subdir in $(SUB_DIRS); do \
		cd $$subdir ; $(MAKE) build_github ; ./*.out ; \
	done	
