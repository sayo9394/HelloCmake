# Top level Makefile for the Application

# Project name
PROJECT_NAME ?= cmake-test

CURRENT_PWD_DIR = ${shell pwd}

BUILD_DIR = build/application

# Macro to run one or all ctest unittests
define RUN_UNITTEST
	$(if $(ARG), cd $(1) && ctest -R _UnitTest -V -R $(ARG), cd $(1) && ctest -R _UnitTest --output-on-failure --timeout 240)
endef

.PHONY: all
all: build

$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) &&  CC=clang CXX=clang++ cmake -G "Unix Makefiles"       \
		$(CURRENT_PWD_DIR)                             \
		-DPROJECT_NAME:STRING=${PROJECT_NAME}          \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
.NOTPARALLEL: config

config: $(BUILD_DIR)/Makefile

build: config
	cd $(BUILD_DIR) && $(MAKE)

# clean generated files
clean:
	if [ -d $(BUILD_DIR) ]; then rm -rf $(BUILD_DIR); fi;

# -----------------------------[ UNIT-TEST ]------------------------------------
UNITTEST_BUILD_DIR = build/unittest

config-unittest: config
	mkdir -p $(UNITTEST_BUILD_DIR)
	cd $(UNITTEST_BUILD_DIR) &&  CC=clang CXX=clang++ cmake -G "Unix Makefiles" \
		$(CURRENT_PWD_DIR)                                \
		-DPROJECT_NAME:STRING=${PROJECT_NAME}             \
		-DUNITTEST:BOOL=TRUE                              \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
.NOTPARALLEL: config-unittest

build-unittest: config-unittest
	cd $(UNITTEST_BUILD_DIR) && $(MAKE)

run-unittest: build-unittest
	$(call RUN_UNITTEST,$(UNITTEST_BUILD_DIR))

# clean generated files
clean-unittest:
	if [ -d $(UNITTEST_BUILD_DIR) ]; then rm -rf $(UNITTEST_BUILD_DIR); fi;

# ------------------------------[ COMMON ]--------------------------------------
EXTERN_DIRS = build 
clean:
	$(foreach dir,$(EXTERN_DIRS),if [ -d ${dir} ]; then rm -rf $(dir); fi;)
NOTPARALLEL: clean
