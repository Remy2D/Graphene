#include "Configuration.h"
#include "Logger.h"

#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>

config::Configuration::Configuration() {
    if (boost::filesystem::exists("~/.graphene/config.json")) {
        boost::property_tree::json_parser::read_json("~/.graphene/config.json", properties);
        return;
    }

    boost::property_tree::json_parser::read_json("resources/defaults.json", properties);
}

std::string config::Configuration::getString(config::PropertyKey key) {
    return properties.get<std::string>(resolvePropertyKey(key));
}

int config::Configuration::getInt(config::PropertyKey key) {
    return properties.get<int>(resolvePropertyKey(key));
}

std::string config::Configuration::resolvePropertyKey(config::PropertyKey key) {
    switch (key) {
        case AUTOSAVE_DELAY_MILLISECONDS:
            return "general.autosaveDelayMilliseconds";
        case LOG_FILE_PATH:
            return "log.filePath";
        case LOG_LEVEL:
            return "log.loggingLevel";
        case UI_FONT_SIZE:
            return "ui.fontSize";
        default:
            LOG_ERROR("Wrong property key");
            throw std::exception();
    }
}
