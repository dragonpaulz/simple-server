#ifndef handler_hpp_
#define handler_hpp_

#include <string>

namespace HandleData
{
    class DataHandler{
        // Takes bytes of an unspecified length, and returns a string to interpret data
        std::string ReadBytes(std::uint8_t[]);
        // Write out bytes to a specified stream
        void WriteBytes(std::string);
    };
}

#endif