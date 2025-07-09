#include "../include/Settings.h"
#include "../include/Log.h"

#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include <fstream>


Settings::Settings()
{
    std::ifstream options("../options.json");
    rapidjson::IStreamWrapper isw(options);

    doc.ParseStream(isw);
    if (doc.HasParseError())
    {
        FMT::error("Error parsin JSON\n");
    }
}

uint16_t Settings::GetWidth()
{
    return doc["window-size"]["width"].GetInt();
}


uint16_t Settings::GetHeight()
{
    return doc["window-size"]["height"].GetInt();
}

std::string Settings::GetTitle()
{
    return doc["title"].GetString();
}

void Settings::SetWidth(uint16_t width)
{
    std::ofstream options("../options.json");
    rapidjson::OStreamWrapper osw(options);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);

    doc["window-size"]["width"].SetInt(width);
    doc.Accept(writer);
}

void Settings::SetHeight(uint16_t height)
{
    std::ofstream options("../options.json");
    rapidjson::OStreamWrapper osw(options);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);

    doc["window-size"]["height"].SetInt(height);
    doc.Accept(writer);
}

void Settings::SetTitle(std::string title)
{
    std::ofstream options("../options.json");
    rapidjson::OStreamWrapper osw(options);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
    
    rapidjson::Document::AllocatorType& alloc = doc.GetAllocator();
    if (doc.HasMember("title"))
    {
        doc["title"].SetString(title.c_str(), alloc);
    }
    doc.Accept(writer);
}

