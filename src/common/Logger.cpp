#include "Logger.h"

#include <boost/chrono.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

void logger::Logger::log(const std::string &message, LogLevel level) {
    if (level >= loggingLevel && logFile) {
        logFile << message << std::endl;
        logFile.flush();
    }
}

logger::Logger::Logger(std::string logLevel, std::string logFilePath) {
    loggingLevel = getLoggingLevel(logLevel);

    createLogFile(logFilePath);
}

logger::Logger::~Logger() {
    logFile.close();
}

logger::LogLevel logger::Logger::getLoggingLevel(std::string &logLevel) {
    if ("INFO" == logLevel) {
        return logger::LogLevel::INFO;
    }

    if ("WARNING" == logLevel) {
        return logger::LogLevel::WARNING;
    }

    if ("ERROR" == logLevel) {
        return logger::LogLevel::ERROR;
    }

    if ("DEBUG" == logLevel) {
        return logger::LogLevel::DEBUG;
    }

    throw std::exception();
}

void logger::Logger::createLogFile(std::string &logFilePath) {
    boost::replace_all(logFilePath, "~", getenv("HOME"));
    boost::filesystem::path path(logFilePath);

    boost::system::error_code ec;
    boost::filesystem::create_directory(path.remove_filename().string(), ec);

    if (ec.failed()) {
        throw std::exception();
    }

    logFile.open(logFilePath, std::ios::app | std::ios::out);
}


