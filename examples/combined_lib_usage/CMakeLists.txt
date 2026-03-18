add_executable(combined_example
    main.cpp
)

target_link_libraries(combined_example
    PRIVATE
        logger
        wrapped_array
)

target_compile_features(combined_example PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(combined_example PRIVATE /W4)
else()
    target_compile_options(combined_example PRIVATE -Wall -Wextra -Wpedantic)
endif()