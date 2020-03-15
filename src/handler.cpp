#include <valarray>
#include <string>

#include "handler.hpp"

const std::vector<uint8_t> handler::Data::helloBytes = std::vector<uint8_t>{uint8_t(240), uint8_t(16)}; // 0xE110
const std::vector<uint8_t> handler::Data::dataBytes = {uint8_t(218), uint8_t(122)}; // 0xDA7A
const std::vector<uint8_t> handler::Data::goodbyeBytes = {uint8_t(11), uint8_t(31)}; // 0x0B1E

handler::Data::Data(bool isValid)
{
    _valid = isValid;
};

handler::Data::Data(handler::Data::types type, int len, std::string message)
{
    msgType = type;
    msgLen = len;
    msg = message;
    _valid = true;
}

handler::Data handler::Data::Create(std::vector<uint8_t> in)
{
    if (in.size() < handler::Data::minBytes)
    {
        return InvalidInput();
    }

    // first two bytes are type
    std::vector<uint8_t> typeBytes(startType+typeLen);
    for (uint i = startType; i < startType + typeLen; i++)
    {
        typeBytes[i-startType] = in[i];
    }

    types type = GetTypeFromBytes(typeBytes);

    if (type == types::unknown)
    {
        return InvalidInput();
    }

    // next four bytes are length
    int valueLen = 0;

    // next series of bytes are the message
    if (in.size() != handler::Data::minBytes + valueLen)
    {
        return InvalidInput();
    }

    std::string message = "";
    // for (int i = handler::Data::minBytes; i < handler::Data::minBytes + valueLen; i++)
    // {
    //     // write out message from bytes
    // }

    return Data(type, valueLen, message);
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

handler::Data::types handler::Data::GetTypeFromBytes(std::vector<uint8_t> typeBytes)
{
    if (typeBytes ==  helloBytes)
    {
        return types::hello;
    }
    else if (typeBytes == dataBytes)
    {
        return types::data;
    }
    else if (typeBytes == goodbyeBytes)
    {
        return types::goodbye;
    }
    else
    {
        return types::unknown;
    }
}
