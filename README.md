# stl_wrapper

A C++17 library collection containing a safe stl wrapper and a thread-safe logger.

## Requirements

- CMake 3.16+
- C++17-compatible compiler (GCC, Clang, or MSVC)

## Building

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Executables are placed in `build/bin/`.

## Libraries

### `array_s<T, N>`

A wrapper around `std::array` that adds bounds-checked access via `.at()`.

```cpp
#include "wrapped_array.hpp"

array_s<int, 3> arr{10, 20, 30};

arr[1];       // unchecked access → 20
arr.at(1);    // bounds-checked  → 20
arr.at(5);    // throws std::out_of_range
arr.size();   // → 3
```

### `cstmlib::logging::Logger`

A static, thread-safe logger that writes to a file and optionally to the console.

```cpp
#include "logger.hpp"
using namespace cstmlib::logging;

Logger::init("logs/app.log");          // must be called first; creates directories
Logger::set_level(LogLevel::Debug);    // filter: Debug, Info, Warning, Error
Logger::enable_console_output(true);   // also print to stdout/stderr

Logger::debug("debug message");
Logger::info("app started");
Logger::warning("using defaults");
Logger::error("something failed");     // goes to stderr

Logger::shutdown();                    // flush and close the file
```

Log lines are formatted as `[YYYY-MM-DD HH:MM:SS] [D/I/W/E] message`.

## Examples

| Executable | Source | Description |
|---|---|---|
| `wrapper_array_example` | `examples/wrapper_array_example/` | Basic `array_s` usage and exception handling |
| `logger_example` | `examples/logger_example/` | Logger init, level filtering, and shutdown |
| `combined_lib_example` | `examples/combined_lib_usage/` | Both libraries used together |

Run after building:

```bash
./build/bin/wrapper_array_example
./build/bin/logger_example
./build/bin/combined_lib_example
```
