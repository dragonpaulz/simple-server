#include <iostream>
#include <string>

#include "Byte.hpp"

using byte = handler::Byte;

byte::Byte(std::string hexStr)
{
    valid = (hexStr.size() == 2) && isHexChar(hexStr[0]) && isHexChar(hexStr[1]);
    
    len = valid ? std::stoi(hexStr, nullptr, 16) : 0;
}

bool byte::isHexChar(char c)
{
    return (c >= 65 && c <= 70) ||
        (c >= 97 && c <= 102) ||
        (c >= 48 && c <= 57);
}
