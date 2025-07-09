#include "../include/Settings.h"
#include "../include/Log.h"

#include <rapidjson/istreamwrapper.h>
#include <rapidjson/document.h>


Settings::Settings()
{
    options = std::ifstream("../options.json");
    if (!options.is_open())
    {
        FMT::error("Could not open options.json for reading\n");
    }
}

Settings::~Settings()
{
    options.close();
}

uint16_t Settings::GetWidth()
{
    rapidjson::IStreamWrapper isw(options);
    rapidjson::Document doc;
    doc.ParseStream(isw);
    if (doc.HasParseError())
    {
        FMT::error("Error parsing JSON\n");
    }

    return doc["window-size"]["width"].GetInt();
}

uint16_t Settings::GetHeight()
{
    rapidjson::IStreamWrapper isw(options);
    rapidjson::Document doc;
    doc.ParseStream(isw);
    if (doc.HasParseError())
    {
        FMT::error("Error parsing JSON\n");
    }

    return doc["window-size"]["height"].GetInt();
}

std::string Settings::GetTitle()
{
    rapidjson::IStreamWrapper isw(options);
    rapidjson::Document doc;
    doc.ParseStream(isw);
    if (doc.HasParseError())
    {
        FMT::error("Error parsing JSON\n");
    }

    return doc["window-size"]["width"].GetString();
}
