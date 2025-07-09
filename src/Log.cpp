#include "../include/Log.h"

#include <string>
#include <iostream>

void FMT::info(std::string message)
{
    std::cout << message << std::endl;    
}

void FMT::warn(std::string message)
{
    std::cerr << message << std::endl;
    std::cin.ignore();
}

void FMT::error(std::string message)
{
    std::cout << message << std::endl;
    std::exit(1);
}
