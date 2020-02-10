#ifndef GRAPHENE_LOGGER_H
#define GRAPHENE_LOGGER_H

#include "Configuration.h"

#include <fstream>
#include <string>

namespace logger {

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    explicit Logger(const std::string& loggingLevel);
    ~Logger();

    void log(const std::string &message, LogLevel level);

private:
    void createLogFile();
    static LogLevel getLoggingLevel(const std::string &logLevel);

    LogLevel loggingLevel;
    std::ofstream logFile;
};

inline logger::Logger &getLogger() {
    static logger::Logger logger(
            getConfiguration().getString(config::PropertyKey::LOG_LEVEL)
    );

    return logger;
}

}  // namespace log
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// http://students.mimuw.edu.pl/~bg209244/mouse_emulator/Logger.h
#define LOG(message, logLevel)                                            \
    do {                                                                  \
        std::stringstream ss;                                             \
        ss << "[" << __FILENAME__ << " " << __LINE__ <<"]: " << message;  \
        logger::getLogger().log(ss.str(), logLevel);                      \
    } while (false)

#define LOG_INFO(message) LOG(message, logger::LogLevel::INFO)
#define LOG_DEBUG(message) LOG(message, logger::LogLevel::DEBUG)
#define LOG_WARNING(message) LOG(message, logger::LogLevel::WARNING)
#define LOG_ERROR(message) LOG(message, logger::LogLevel::ERROR)

#endif  // GRAPHENE_LOGGER_H