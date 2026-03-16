add_executable(combined_example
    main.cpp
)

target_link_libraries(combined_example
    PRIVATE
        logger
        wrapper_array
)

if(MSVC)
    target_compile_options(combined_example PRIVATE /W4)
else()
    target_compile_options(combined_example PRIVATE -Wall -Wextra -Wpedantic)
endif()