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
            static Byte TwoHexToByte(std::string hexStr);
            static bool isHexChar(char);

            uint8_t getLen() { return len; };
            bool isValid() { return valid; };
        private:
            Byte(bool, uint8_t);

            bool valid;
            uint8_t len;
    };
}

#endif