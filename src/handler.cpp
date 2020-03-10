#include <cstddef>
#include <string>

#include "handler.hpp"

// When a stream of bytes come in, this is the code that interprets the data, and returns a string of bytes
std::string HandleData::DataHandler::ReadBytes(std::byte[])
{
    return "";
}
