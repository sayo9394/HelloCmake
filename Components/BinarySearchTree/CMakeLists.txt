# define the project name of this address space
project(BinarySearchTree C CXX)

if (UNITTEST)
    set(TEST_NAME ${PROJECT_NAME}_UnitTest)

    set(TEST_FILES
        test/BinarySearchTree_UnitTest.cpp
        ../../src/test/gtest_main.cpp
    )

    add_executable(${TEST_NAME} ${TEST_FILES} ${SRC_FILES})
	target_link_libraries(	${TEST_NAME} gmock gtest
							pthread
	)

    target_include_directories(${TEST_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Add test to ctest
    add_test(${TEST_NAME} ${TEST_NAME})    
endif()
