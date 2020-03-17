#ifndef handler_MsgLen_hpp
#define handler_MsgLen_hpp

#include <cstdint>
#include <vector>

namespace TLVComponent
{
    class Length
    {
        public:
            const static unsigned int nChar;
            const static unsigned int nBytes;

            Length(std::vector<char>);

            // Length of value in bytes.
            unsigned int getLen() {return lenBytes;}
            // whether the input was valid or not
            bool isValid() {return valid;}
        private:
            unsigned int lenBytes;
            bool valid;
    };
}

#endif
