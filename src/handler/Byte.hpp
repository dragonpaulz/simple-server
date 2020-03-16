#ifndef handler_byte_hpp
#define handler_byte_hpp

#include <string>

namespace handler
{
    class Byte
    {
        public:
            Byte() {};
            Byte(std::string);

            static bool isHexChar(char);

            uint8_t getLen() { return len; };
            bool isValid() { return valid; };

        private:
            bool valid;
            uint8_t len;
    };
}

#endif
