#include <iostream>

#include "cstmlib/logging/logger.hpp"

int main()
{
    using namespace cstmlib::logging;

    if (!Logger::init("build/logs/app.log"))
    {
        std::cerr << "Logger init failed.\n";
        return 1;
    }

    Logger::set_level(LogLevel::Debug);
    Logger::enable_console_output(true);

    Logger::debug("Debug mesaji");
    Logger::info("Uygulama basladi");
    Logger::warning("Config bulunamadi, default degerler kullaniliyor");
    Logger::error("Bir hata olustu");

    Logger::shutdown();
    return 0;
}