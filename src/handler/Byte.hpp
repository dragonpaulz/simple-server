#ifndef handler_byte_hpp
#define handler_byte_hpp

#include <string>

namespace handler
{
    class Byte
    {
        public:
            // responsible for converting two hex characters to bytes. Returns 0 for invalid input
            Byte(std::string);
            // Byte(char big, char small);

            // Byte(bool, uint8_t);

            static bool isHexChar(char);

            uint8_t getLen() { return len; };
            bool isValid() { return valid; };

        private:
            bool valid;
            uint8_t len;
    };
}

#endif
