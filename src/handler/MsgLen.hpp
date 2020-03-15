#ifndef handler_MsgLen_hpp
#define handler_MsgLen_hpp

#include <vector>

namespace handler
{
    class MsgLen
    {
        public:
            const static uint nChar = 8;
            const static uint nBytes = nChar/2;

            MsgLen(std::vector<char>);

            uint getLen();
            bool isValid();
        private:
            // MsgLen(bool) exists for invalid input
            // MsgLen(bool);
            uint len;
            bool valid;
    };
}

#endif
