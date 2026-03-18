add_library(wrapped_array INTERFACE)

target_include_directories(wrapped_array
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(wrapped_array INTERFACE cxx_std_17)