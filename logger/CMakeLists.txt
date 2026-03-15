cmake_minimum_required(VERSION 3.16)

project(MyLoggerProject LANGUAGES CXX)

add_library(cstmlib
    src/logging/logger.cpp
)

target_include_directories(cstmlib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(cstmlib PUBLIC cxx_std_20)

add_executable(logger_example
    examples/logger_example.cpp
)

target_link_libraries(logger_example
    PRIVATE
        cstmlib
)