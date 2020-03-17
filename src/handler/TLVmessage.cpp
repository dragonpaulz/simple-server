#include <iostream>
#include <valarray>
#include <string>

#include "TLVmessage.hpp"
#include "Byte.hpp"
#include "TLVComponent/Length.hpp"
#include "TLVComponent/Type.hpp"
#include "TLVComponent/Value.hpp"

using byte = handler::Byte;

handler::TLVmessage::TLVmessage(bool isValid)
{
    _valid = isValid;
};

handler::TLVmessage::TLVmessage(TLVComponent::Type type, int len, std::string message)
{
    msgType = type;
    msgLen = len;
    msg = message;
    _valid = true;
}

handler::TLVmessage handler::TLVmessage::Create(std::vector<char> in)
{
    if (in.size() < handler::TLVmessage::minChars)
    {
        return InvalidInput();
    }

    // TODO: use iterators constructor
    std::vector<char> typeSection{in[0], in[1], in[2], in[3]};

    TLVComponent::Type msgType(typeSection);

    if (!msgType.isValid())
    {
        return InvalidInput();
    }

    // next four bytes are length, encoding 8 characters
    // TODO: use iterators constructor
    std::vector<char> lengthPortion{in[4], in[5], in[6], in[7], in[8], in[9], in[10], in[11]};
    TLVComponent::Length valueLen(lengthPortion);

    // for (uint i = 0; i < lengthPortion.size(); i++ )
    // {
    //     std::cout << lengthPortion[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "is Valid: " << valueLen.isValid() << " len " << valueLen.getLen() << " size " << in.size() << std::endl;

    // next series of bytes are the message
    if (!valueLen.isValid() 
        // || (in.size() != handler::TLVmessage::minChars + (valueLen.getLen()*2))
        )
    {
        return InvalidInput();
    }

    std::vector<char> val(in.begin() + 12, in.end());
    TLVComponent::Value actualValue(val);

    std::cout << "len: " << valueLen.getLen() << " valid:" << valueLen.isValid();
    std::cout << " actualValue: " << std::endl;

    for (uint i = 0; i < actualValue.value.size(); i++)
    {
        std::cout << actualValue.value[i] << ", ";
    }
    std::cout << std::endl;

    if (!ValueIsOfLen(valueLen, actualValue))
    {
        return InvalidInput();
    }

    std::string message = "";

    return TLVmessage(msgType, valueLen.getLen(), message);
}

// Writes the bytes out to the proper location, terminal for example
void WriteBytes(std::string)
{
    return;
}

bool handler::TLVmessage::ValueIsOfLen(TLVComponent::Length len, TLVComponent::Value val)
{
    return len.getLen() * 2 == val.value.size();
}
