include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Change the default location of executable to bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set service source files
set(SOURCES
    main.cpp
)

if (UNITTEST)

    include(../cmake/BuildGoogletest.cmake)

    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/test
    )

    add_definitions(-D__UNITTEST__)
    # Remove the main service file from source file list
    list(REMOVE_ITEM SOURCES main.cpp)

    # Add the unittest source file to list
    list(APPEND SOURCES test/gtest_main.cpp)

    set(EXTRA_LIBRARIES
        gmock
        gtest)

    set(EXTRA_UNITTEST_INTERFACES )

    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

add_executable(${PROJECT_NAME}
    ${SOURCES}
)


target_link_libraries(${PROJECT_NAME}
                      ${EXTRA_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${EXTRA_UNITTEST_INTERFACES}
)

if (UNITTEST)
    # Add test to ctest
    add_test(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})
endif()
