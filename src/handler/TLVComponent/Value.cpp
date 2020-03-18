#include <string>
#include <vector>

#include "Value.hpp"
#include "helper/Byte.hpp"

bool TLVComponent::Value::isValid()
{
    return _value.size() > 1 &&
        TLVhelper::Byte::areHexChar(_value) &&
        _value.size() % 2 == 0;
}
