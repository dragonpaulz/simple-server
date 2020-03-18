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

handler::TLVmessage::TLVmessage(std::vector<char> in)
{
    _valid = in.size() >= handler::TLVmessage::minChars;

    TLVComponent::Type* msgType;

    if (_valid)
    {
        std::cout << "in first block" << std::endl;
        // TODO: use iterators constructor
        std::vector<char> typeSection {in[0], in[1], in[2], in[3]};

        msgType = new TLVComponent::Type(typeSection);
        std::cout << "type: " << msgType->getType() << std::endl;
    }
    else
    {
        msgType = new TLVComponent::Type();
    }
    
    _valid &= msgType->isValid();


    TLVComponent::Length* valueLen;
    TLVComponent::Value* actualValue;

    if (_valid)
    {
        std::cout << "in second block" << std::endl;
        // TODO: use iterators constructor
        std::vector<char> lengthPortion{in[4], in[5], in[6], in[7], in[8], in[9], in[10], in[11]};
        valueLen = new TLVComponent::Length(lengthPortion);

        std::vector<char> val(in.begin() + 12, in.end());
        actualValue = new TLVComponent::Value(val);
    }
    else
    {
        valueLen = new TLVComponent::Length();
        actualValue = new TLVComponent::Value();
    }
    

    _valid &= ValueIsOfLen(*valueLen, *actualValue);
    std::cout << "type: " << msgType->getType() << std::endl;

    _type = *msgType;
    _len = *valueLen;
    _value = *actualValue;
}

// Writes the bytes out to the proper location, terminal for example
void WriteBytes(std::string)
{
    return;
}

bool handler::TLVmessage::ValueIsOfLen(TLVComponent::Length len, TLVComponent::Value val)
{
    return len.getLen() * 2 == val.getValue().size();
}
