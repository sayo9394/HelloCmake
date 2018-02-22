# Project name
PROJECT_NAME	= HelloCMake

CURRENT_PWD_DIR = ${shell pwd}
CURRENT_DIR		= ${shell cygpath -m $(CURRENT_PWD_DIR)}

# Macro to run one or all ctest unittests
define RUN_UNITTEST
	$(if $(ARG), cd $(1) && ctest -R _UnitTest -V -R $(ARG), cd $(1) && ctest -R _UnitTest --timeout 240)
endef

# MB device release config/build/clean targets
config-unittest: build/unittest/Makefile
build/unittest/Makefile:
	mkdir -p build/unittest
	cd build/unittest && cmake -G "Unix Makefiles" $(CURRENT_PWD_DIR) -DUNITTEST:BOOL=True -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
.NOTPARALLEL: config-unittest

build-unittest: config-unittest
	cd build/unittest && $(MAKE)

run-unittest: build-unittest
	$(call RUN_UNITTEST,build/unittest)

clean-unittest:
	rm -rf build/unittest