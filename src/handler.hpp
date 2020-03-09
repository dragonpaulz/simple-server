#ifndef handler_hpp_
#define handler_hpp_

#include <cstddef>

namespace handleData
{
    class DataHandler{
        // Takes bytes of an unspecified length, and writes them out
        void ReadBytes(std::byte[]);
    };
}

#endif