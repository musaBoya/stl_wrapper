cmake_minimum_required(VERSION 3.10.0)
project(array_wrapper VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(include)

set(PROJECT_SOURCES
    src/main.cpp
    include/wrapper_array.hpp
)


add_executable(array_wrapper ${PROJECT_SOURCES})

target_link_libraries(array_wrapper PUBLIC -lcurl)