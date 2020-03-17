#include <vector>

#include "Type.hpp"

const std::vector<char> TLVComponent::Type::helloChars = {'E', '1', '1', '0'};
const std::vector<char> TLVComponent::Type::dataChars = {'D', 'A', '7', 'A'};
const std::vector<char> TLVComponent::Type::byeChars = {'0', 'B', '1', 'E'};

TLVComponent::Type::Type(std::vector<char> charType)
{
    _type = charType == helloChars ? types::hello :
        charType == dataChars ? types::data :
        charType == byeChars ? types::bye :
        types::unknown;
    _valid = _type != types::unknown;
}
