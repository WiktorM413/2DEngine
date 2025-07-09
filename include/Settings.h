#pragma once

#include <cinttypes>
#include <fstream>

class Settings
{
private:
    std::ifstream options;
    
public:
    Settings();
    ~Settings();

    uint16_t GetWidth();
    uint16_t GetHeight();
    std::string GetTitle();
};
