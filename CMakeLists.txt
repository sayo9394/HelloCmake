cmake_minimum_required(VERSION 3.1)

project(HelloCmake C CXX)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# Set a default build type for single-configuration
# CMake generators if no build type is set.
IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE RelWithDebInfo)
ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

# Select flags.
SET(CMAKE_CXX_FLAGS 			"${CMAKE_CXX_FLAGS} -Wall -fno-rtti")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO 	"${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g")
SET(CMAKE_CXX_FLAGS_RELEASE 		"${CMAKE_CXX_FLAGS_RELEASE} -O2")
SET(CMAKE_CXX_FLAGS_DEBUG  		"${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")


# Turn verbosity on/off
set(CMAKE_VERBOSE_MAKEFILE OFF)

include(cmake/gtest.cmake)

# Enabling ctest
enable_testing()

include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(Components/Vector)
add_subdirectory(Components/LinkedList)
add_subdirectory(Components/BinarySearchTree)
