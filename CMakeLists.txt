cmake_minimum_required(VERSION 3.13)

include(cmake/BuildType.cmake)
include(cmake/ToolchainConfig.cmake)

if (NOT PROJECT_NAME)
    message(WARNING "Undefined PROJECT_NAME variable (e.g. cmake -DPROJECT_NAME:STRING=service_skeleton).")
    set(PROJECT_NAME service)
endif()

if (UNITTEST)
    # Enabling ctest
    enable_testing()

    set(PROJECT_NAME "${PROJECT_NAME}_UnitTest")
endif()

# service attributes
set(SERVICE_NAME XYZ)
set(SERVICE_DOMAIN com.${COMPANY_ALIAS})
###
### Project settings
###
set(SERVICE_VERSION_MAJOR "0")
set(SERVICE_VERSION_MINOR "0")
set(SERVICE_VERSION_PATCH "1")
set(SERVICE_VERSION "${SERVICE_VERSION_MAJOR}.${SERVICE_VERSION_MINOR}.${SERVICE_VERSION_PATCH}")

project(${PROJECT_NAME} VERSION "${SERVICE_VERSION}")

configure_file(version.h.in ${PROJECT_BINARY_DIR}/src/version.h)
message(STATUS "${PROJECT_NAME} version ${SERVICE_VERSION}")

include(CheckCXXCompilerFlag)

# Turn verbosity on/off
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add source subdirectory
add_subdirectory(src)
# add_subdirectory(Components/Vector)
add_subdirectory(Components/BinarySearchTree)
