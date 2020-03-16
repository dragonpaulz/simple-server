#include "Byte.hpp"
#include "MsgLen.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

const unsigned int handler::MsgLen::nChar = 8;

const unsigned int handler::MsgLen::nBytes = nChar/2;

handler::MsgLen::MsgLen(std::vector<char> lenChars)
{
    bool validSoFar = lenChars.size() == handler::MsgLen::nChar;
    std::vector<handler::Byte> nums(nChar);
    for (int i = (nChar -1); i >= 0; i -= 2)
    {
        int thisByte = (i-1)/2;
        std::string s = {lenChars[i], lenChars[i-1]};
        handler::Byte newByte(s);
        nums[thisByte] = newByte;
    }

    len = 0;
    for (unsigned int j = 0; j < nBytes; j++)
    {
        validSoFar &= nums[j].isValid();
        len += uint(nums[j].getLen());
    }

    valid = validSoFar;
}
