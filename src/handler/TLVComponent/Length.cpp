#include "helper/Byte.hpp"
#include "Length.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

const unsigned int TLVComponent::Length::nChar = 8;

const unsigned int TLVComponent::Length::nBytes = nChar/2;

TLVComponent::Length::Length(std::vector<char> lenChars)
{
    bool validSoFar = lenChars.size() == TLVComponent::Length::nChar;
    std::vector<TLVhelper::Byte> nums(nChar);
    for (int i = (nChar -1); i >= 0; i -= 2)
    {
        int thisByte = (i-1)/2;
        std::string s = {lenChars[i-1], lenChars[i]};
        TLVhelper::Byte newByte(s);
        nums[thisByte] = newByte;
    }

    lenBytes = 0;
    for (unsigned int j = 0; j < nBytes; j++)
    {
        validSoFar &= nums[j].isValid();
        lenBytes += uint(nums[j].getLen());
    }

    valid = validSoFar;
}
