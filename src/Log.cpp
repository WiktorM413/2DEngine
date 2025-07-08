#include "../include/Log.h"

#include <string>
#include <iostream>

static void FMT::info(std::string message)
{
    std::cout << message << std::endl;    
}

static void FMT::warn(std::string message)
{
    std::cerr << message << std::endl;
    std::cin.ignore();
}

static void FMT::error(std::string message)
{
    std::cout << message << std::endl;
    std::exit(1);
}
