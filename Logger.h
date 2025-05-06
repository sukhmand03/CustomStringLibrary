#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

/**
  Logger
 
 */
class Logger {
public:
    
    static Logger& Instance();

    /**
     message with timestamp
     */
    void Log(const std::string& message);

private:
    Logger();
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream ofs_;
    std::mutex    mtx_;
};

#endif // LOGGER_H
