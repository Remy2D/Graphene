#ifndef GRAPHENE_CONFIGURATION_H
#define GRAPHENE_CONFIGURATION_H

#include <string>
#include <unordered_map>
#include <boost/property_tree/ptree.hpp>

namespace config {

enum PropertyKey {
    AUTOSAVE_DELAY_SECONDS,
    LOG_FILE_PATH,
    LOG_LEVEL,
    UI_FONT_SIZE
};

class Configuration {

public:
    Configuration();
    std::string getString(PropertyKey key);
    int getInt(PropertyKey key);

private:
    boost::property_tree::ptree properties;
    static std::string resolvePropertyKey(PropertyKey key);
};


}  // namespace config

inline config::Configuration &getConfiguration() {
    static config::Configuration configuration;
    return configuration;
}

#endif