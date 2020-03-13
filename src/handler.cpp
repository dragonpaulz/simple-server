#include <string>

#include "handler.hpp"

const std::vector<uint8_t> handler::Data::hello = std::vector<uint8_t>{uint8_t(240), uint8_t(16)}; // 0xE110
const std::vector<uint8_t> handler::Data::data = {uint8_t(218), uint8_t(122)}; // 0xDA7A
const std::vector<uint8_t> handler::Data::goodbye = {uint8_t(11), uint8_t(31)}; // 0x0B1E

handler::Data::Data handler::Data::Create(std::vector<uint8_t> in)
{
    for (int i = 0; i < in.size(); i++)
    {

    }
}

// When a stream of bytes come in, this is the code that interprets the data, and returns a string of bytes
std::string handler::Data::ReadBytes()
{
    return "";
}

// Writes the bytes out to the proper location, terminal for example
void WriteBytes(std::string)
{
    return;
}
