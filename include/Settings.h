#pragma once

#include <cinttypes>
#include <string>
#include <fstream>

#include <rapidjson/document.h>

class Settings
{ 
private:
    rapidjson::Document doc;

public:
    Settings();
    uint16_t GetWidth();
    uint16_t GetHeight();
    std::string GetTitle();

    void SetWidth(uint16_t width);
    void SetHeight(uint16_t height);
    void SetTitle(std::string title);
};

