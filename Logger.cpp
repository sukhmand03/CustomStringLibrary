#include "Logger.h"
#include <ctime>
#include <stdexcept>

Logger::Logger() {
    ofs_.open("myString.log", std::ios::app);
    if (!ofs_) throw std::runtime_error("Failed to open myString.log");
}

Logger::~Logger() {
    if (ofs_) ofs_.close();
}

Logger& Logger::Instance() {
    static Logger instance;
    return instance;
}

void Logger::Log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::time_t t = std::time(nullptr);
    ofs_ << std::asctime(std::localtime(&t))
         << ": " << message << "\n";
}
