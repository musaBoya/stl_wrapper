#cmake_minimum_required(VERSION 3.10.0)
#project(wrapper_array VERSION 0.1.0 LANGUAGES C CXX)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#include_directories(include)
#
#set(PROJECT_SOURCES
#    src/main.cpp
#    include/wrapper_array.hpp
#)
#
#
#add_executable(wrapper_array ${PROJECT_SOURCES})
#
#target_link_libraries(wrapper_array PUBLIC -lcurl)
#target_include_directories(wrapper_array
#    PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/include
#)

cmake_minimum_required(VERSION 3.10.0)
project(wrapper_array VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(wrapper_array INTERFACE)

target_include_directories(wrapper_array
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(wrapper_array_example
    src/main.cpp
)

target_link_libraries(wrapper_array_example
    PRIVATE
        wrapper_array
)

if(MSVC)
    target_compile_options(wrapper_array_example PRIVATE /W4)
else()
    target_compile_options(wrapper_array_example PRIVATE -Wall -Wextra -Wpedantic)
endif()