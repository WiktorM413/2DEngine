#pragma once

#include <string>

class FMT
{
public:
    void info(std::string message);
    void warn(std::string message);
    void error(std::string message);
};
