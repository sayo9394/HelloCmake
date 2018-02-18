# define the project name of this address space
project(Vector C CXX)

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
)

if (UNITTEST)
    set(TEST_NAME ${PROJECT_NAME}_UnitTest)

    set(TEST_FILES
        test/Vector_UnitTest.cpp
    )

    add_executable(${TEST_NAME} ${TEST_FILES} ${SRC_FILES})
    add_dependencies(${TEST_NAME} googletest)
	target_link_libraries(	${TEST_NAME} ${GTEST_LIBS_DIR}/libgtest.a
							${GTEST_LIBS_DIR}/libgtest_main.a
							pthread
	)

    target_include_directories(${TEST_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Add test to ctest
    add_test(${TEST_NAME} ${TEST_NAME})    
endif()
