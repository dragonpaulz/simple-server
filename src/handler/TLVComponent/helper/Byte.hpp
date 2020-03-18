#ifndef handler_byte_hpp
#define handler_byte_hpp

#include <string>
#include <vector>

namespace TLVhelper
{
    class Byte
    {
        public:
            Byte() {};
            Byte(std::string);

            static bool isHexChar(char);
            static bool areHexChar(std::vector<char>);
            static uint8_t HexCharToUint8(char);

            uint8_t getLen() { return len; };
            bool isValid() { return valid; };

        private:
            bool valid;
            uint8_t len;
    };
}

#endif
