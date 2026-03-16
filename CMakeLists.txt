cmake_minimum_required(VERSION 3.16)

project(stl_wrapper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_subdirectory(modules/logger)
add_subdirectory(modules/wrapper_array)
add_subdirectory(stl_wrapper_example/combined_lib_usage)