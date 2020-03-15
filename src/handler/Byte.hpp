#ifndef handler_byte_hpp
#define handler_byte_hpp

#include <iostream>
#include <string>

namespace handler
{
    class Byte
    {
        public:
            // responsible for converting two hex characters to bytes. Returns 0 for invalid input
            static uint8_t TwoHexToByte(std::string hexStr);
            static bool isHexChar(char);
    };
}

#endif
