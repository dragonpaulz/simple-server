#include <cstddef>
#include <string>

#include "handler.hpp"

// When a stream of bytes come in, this is the code that interprets the data, and returns a string of bytes
std::string HandleData::DataHandler::ReadBytes(std::byte[])
{
    return "";
}

// Writes the bytes out to the proper location, terminal for example
void WriteBytes(std::string)
{
    return;
}
