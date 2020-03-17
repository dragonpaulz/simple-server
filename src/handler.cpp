#include <iostream>
#include <valarray>
#include <string>

#include "handler.hpp"
#include "handler/Byte.hpp"
#include "handler/MsgLen.hpp"
#include "handler/TLVComponent/Type.hpp"

using byte = handler::Byte;

handler::Data::Data(bool isValid)
{
    _valid = isValid;
};

handler::Data::Data(TLVComponent::Type type, int len, std::string message)
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

    // this could be done better with iterators
    std::vector<char> typeSection{in[0], in[1], in[2], in[3]};

    TLVComponent::Type msgType(typeSection);

    if (!msgType.isValid())
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

    return Data(msgType, valueLen.getLen(), message);
}

// Writes the bytes out to the proper location, terminal for example
void WriteBytes(std::string)
{
    return;
}
