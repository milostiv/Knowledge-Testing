MAKE_DIR_C = $(PWD)/leetCode/c
SUB_DIRS_C := ${shell find ${MAKE_DIR_C}/* -type d -print}
DIR_SHELL = $(PWD)/leetCode/shell
SUB_DIRS_SHELL := ${shell find ${DIR_SHELL}/* -type d -print}

.PHONY: default
default:
	@echo "Run \"make all\" or \"make clean\" to use makefile"

.PHONY: clean
clean:

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) clean ; \
	done

.PHONY: all
all:

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) build ; \
	done

	@echo "Testing shell scripts:\n"

	@for subdir in $(SUB_DIRS_SHELL); do \
		cd $$subdir ; ./*.sh || exit 1 ; \
	done	
	
.PHONY: all_github
all_github:

	@for subdir in $(SUB_DIRS_C); do \
		cd $$subdir ; $(MAKE) build_github ; ./*.out || exit 1 ; \
	done

	@echo "Testing shell scripts:\n"

	@for subdir in $(SUB_DIRS_SHELL); do \
		cd $$subdir ; ./*.sh || exit 1 ; \
	done	
