#include <iostream>
#include <valarray>
#include <string>

#include "handler.hpp"
#include "handler/Byte.hpp"
#include "handler/MsgLen.hpp"

const std::vector<uint8_t> handler::Data::helloBytes = std::vector<uint8_t>{uint8_t(240), uint8_t(16)}; // 0xE110
const std::vector<uint8_t> handler::Data::dataBytes = {uint8_t(218), uint8_t(122)}; // 0xDA7A
const std::vector<uint8_t> handler::Data::goodbyeBytes = {uint8_t(11), uint8_t(31)}; // 0x0B1E

const std::vector<char> handler::Data::helloChars = {'E', '1', '1', '0'};
const std::vector<char> handler::Data::dataChars = {'D', 'A', '7', 'A'};
const std::vector<char> handler::Data::goodbyeChars = {'0', 'B', '1', 'E'};

using byte = handler::Byte;

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

handler::Data handler::Data::Create(std::vector<char> in)
{
    if (in.size() < handler::Data::minChars)
    {
        return InvalidInput();
    }

    // 2 bytes is the equivalent of 4 char. Reads chars 0 to 3.
    std::vector<uint8_t> typeBytes(2);
    for (uint i = 0; i < 2; i++)
    {
        typeBytes[i] = 16*handler::Byte::HexCharToUint8(in[i*2]) + handler::Byte::HexCharToUint8(in[i*2+1]);
    }

    std::cout << "0: " << typeBytes[0] << " 1: " << typeBytes[1] << std::endl;
    types type = GetTypeFromBytes(typeBytes);

    if (type == types::unknown)
    {
        return InvalidInput();
    }

    // next four bytes are length, encoding 8 characters
    std::vector<char> lengthPortion(in[4], in[11]);
    MsgLen valueLen(lengthPortion);

    // next series of bytes are the message
    if (valueLen.isValid() && in.size() != handler::Data::minBytes + valueLen.getLen())
    {
        return InvalidInput();
    }

    std::string message = "";
    // for (int i = handler::Data::minBytes; i < handler::Data::minBytes + valueLen; i++)
    // {
    //     // write out message from bytes
    // }

    return Data(type, valueLen.getLen(), message);
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
