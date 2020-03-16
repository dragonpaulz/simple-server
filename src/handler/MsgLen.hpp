#ifndef handler_MsgLen_hpp
#define handler_MsgLen_hpp

#include <cstdint>
#include <vector>

namespace handler
{
    class MsgLen
    {
        public:
            const static unsigned int nChar;
            const static unsigned int nBytes;

            MsgLen(std::vector<char>);

            unsigned int getLen() {return len;}
            bool isValid() {return valid;}
        private:
            // MsgLen(bool) exists for invalid input
            // MsgLen(bool);
            unsigned int len;
            bool valid;
    };
}

#endif
