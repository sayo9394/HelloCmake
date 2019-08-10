#
# Copyright (C) 2019 Duncan Technologies Pty Ltd. All rights reserved.
#

if ("${TARGET_TYPE}" STREQUAL YOCTO)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    include(cmake/toolchains/Clang.cmake)
endif()

if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
endif()
