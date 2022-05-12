MAKE_DIR = $(PWD)/leetCode/c
SUB_DIRS := ${shell find ${MAKE_DIR}/* -type d -print}

.PHONY: default
default:
	@echo "Run \"make all\" or \"make clean\" to use makefile"

.PHONY: clean
clean:

	@for subdir in $(SUB_DIRS); do \
		cd $$subdir ; $(MAKE) clean ; \	
		echo "Cleaning directory $$subdir" ; \
	done	

.PHONY: all
all:

	@for subdir in $(SUB_DIRS); do \
		cd $$subdir ; $(MAKE) build ; \
		echo "Running makefile in $$subdir" ; \
	done	
