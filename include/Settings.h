#pragma once

#include <cinttypes>
#include <string>
#include <fstream>

#include <rapidjson/document.h>

class Settings
{ 
private:
    static rapidjson::Document doc;

public:
    static void Initialize();
    static uint16_t GetWidth();
    static uint16_t GetHeight();
    static std::string GetTitle();

    static void SetWidth(uint16_t width);
    static void SetHeight(uint16_t height);
    static void SetTitle(std::string title);
};

