MAKE_DIR = $(PWD)/leetCode/c
PYT_DIR = $(PWD)/leetCode/python
SUB_DIRS := ${shell find ${MAKE_DIR}/* -type d -print}
PYT_SUB_DIRS := ${shell find ${PYT_DIR}/* -type d -print}

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
		cd $$subdir ; $(MAKE) build_github ; ./*.out || exit 1; \
	done

	@for subdir in $(PYT_SUB_DIRS); do \
		cd $$subdir ; ./*.py || exit 1; \
	done
