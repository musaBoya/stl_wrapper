add_executable(wrapped_array_example
    wrapped_array_example.cpp
)

target_link_libraries(wrapped_array_example
    PRIVATE
        wrapped_array
)

target_compile_features(wrapped_array_example PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(wrapped_array_example PRIVATE /W4)
else()
    target_compile_options(wrapped_array_example PRIVATE -Wall -Wextra -Wpedantic)
endif()