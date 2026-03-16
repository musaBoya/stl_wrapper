#include "logger.hpp"

#include <chrono>
#include <ctime>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace cstmlib::logging
{
    std::ofstream Logger::s_file{};
    std::mutex Logger::s_mutex{};
    LogLevel Logger::s_min_level = LogLevel::Debug;
    bool Logger::s_console_enabled = true;
    bool Logger::s_initialized = false;

    bool Logger::init(const std::string& file_path)
    {
        std::lock_guard<std::mutex> lock(s_mutex);

        if (s_file.is_open())
        {
            s_file.close();
        }

        std::filesystem::path path(file_path);

        if (path.has_parent_path())
        {
            std::error_code ec;
            std::filesystem::create_directories(path.parent_path(), ec);
            if (ec)
            {
                s_initialized = false;
                return false;
            }
        }

        s_file.open(file_path, std::ios::out | std::ios::app);
        s_initialized = s_file.is_open();

        return s_initialized;
    }

    void Logger::shutdown()
    {
        std::lock_guard<std::mutex> lock(s_mutex);

        if (s_file.is_open())
        {
            s_file.flush();
            s_file.close();
        }

        s_initialized = false;
    }

    void Logger::set_level(LogLevel level)
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        s_min_level = level;
    }

    void Logger::enable_console_output(bool enable)
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        s_console_enabled = enable;
    }

    void Logger::debug(const std::string& message)
    {
        log(LogLevel::Debug, message);
    }

    void Logger::info(const std::string& message)
    {
        log(LogLevel::Info, message);
    }

    void Logger::warning(const std::string& message)
    {
        log(LogLevel::Warning, message);
    }

    void Logger::error(const std::string& message)
    {
        log(LogLevel::Error, message);
    }

    void Logger::log(LogLevel level, const std::string& message)
    {
        std::lock_guard<std::mutex> lock(s_mutex);

        if (!s_initialized)
        {
            return;
        }

        if (static_cast<int>(level) < static_cast<int>(s_min_level))
        {
            return;
        }

        const std::string line =
            "[" + now_string() + "] "
            "[" + std::string(to_string(level)) + "] "
            + message;

        s_file << line << '\n';
        s_file.flush();

        if (s_console_enabled)
        {
            if (level == LogLevel::Error)
            {
                std::cerr << line << '\n';
            }
            else
            {
                std::cout << line << '\n';
            }
        }
    }

    const char* Logger::to_string(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::Debug:   return "D";     //"DEBUG"
            case LogLevel::Info:    return "I";     //"INFO"
            case LogLevel::Warning: return "W";     //"WARNING"
            case LogLevel::Error:   return "E";     //"ERROR"
            default:                return "U";     //"UNKNOWN"
        }
    }

    std::string Logger::now_string()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t time_now = std::chrono::system_clock::to_time_t(now);

        std::tm local_tm{};

    #if defined(_WIN32)
        localtime_s(&local_tm, &time_now);
    #else
        localtime_r(&time_now, &local_tm);
    #endif

        std::ostringstream oss;
        oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
}