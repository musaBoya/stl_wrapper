#include <iostream>

#include "logger.hpp"
#include "wrapper_array.hpp"

int main()
{
    Logger::init("build/logs/app.log");

    Logger::info("Combined example started");

    ArrayWrapper<int, 5> arr;

    Logger::info("Filling array");

    for (size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = static_cast<int>(i * 10);
    }

    Logger::info("Printing array values");

    for (size_t i = 0; i < arr.size(); ++i)
    {
        Logger::debug(
            "arr[" + std::to_string(i) + "] = " + std::to_string(arr[i]));
    }

    Logger::info("Testing safe access");

    try
    {
        arr.at(10);
    }
    catch (const std::exception& e)
    {
        Logger::error(std::string("Exception: ") + e.what());
    }

    Logger::info("Combined example finished");

    return 0;
}