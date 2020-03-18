#include <iostream>
#include <string>
#include <vector>

#include "Byte.hpp"

using byte = handler::Byte;

byte::Byte(std::string hexStr)
{
    valid = (hexStr.size() == 2) && isHexChar(hexStr[0]) && isHexChar(hexStr[1]);
    
    len = valid ? std::stoi(hexStr, nullptr, 16) : 0;
}

bool isUpperLetter(char c)
{
    return c >= 'A' && c <= 'F';
}

bool isLowerLetter(char c)
{
    return c >= 'a' && c <= 'f';
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// returns 0 for non-hex chars
uint8_t byte::HexCharToUint8(char c)
{
    return isUpperLetter(c) ? uint8_t(c - 'A' + 10) :
        isLowerLetter(c) ? uint8_t(c - 'a' + 10) :
        isDigit(c) ? uint8_t(c - '0') :
        0;
}

bool byte::isHexChar(char c)
{
    return isUpperLetter(c) ||
        isLowerLetter(c) ||
        isDigit(c);
}

bool byte::areHexChar(std::vector<char> chars)
{
    if (chars.size() < 1)
    {
        // special case. Not sure there's a right answer here
        return true;
    }

    bool valid = isHexChar(chars[0]);

    // start on second element
    for (uint i = 1; i < chars.size() && valid; i++)
    {
        valid &= isHexChar(chars[i]);
    }

    return valid;
}
