add_executable(logger_example
    logger_example.cpp
)

target_link_libraries(logger_example
    PRIVATE
        logger
)

target_compile_features(logger_example PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(logger_example PRIVATE /W4)
else()
    target_compile_options(logger_example PRIVATE -Wall -Wextra -Wpedantic)
endif()