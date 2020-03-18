#include <string>
#include <vector>

#include "../src/handler/TLVComponent/Value.hpp"
#include "gtest/gtest.h"

TEST(value_test, to_string_one_byte)
{
    std::vector<char> value1Chars{'0', '1'};
    std::string value1Str = "0x01";
    TLVComponent::Value value1(value1Chars);

    EXPECT_EQ(value1Str, value1.to_string());
}

TEST(value_test, to_string_two_bytes)
{
    std::vector<char> value2Chars{'0', '1', '0', '2'};
    std::string value2Str = "0x01 0x02";
    TLVComponent::Value value2(value2Chars);

    EXPECT_EQ(value2Str, value2.to_string());
}

TEST(value_test, to_string_three_bytes)
{
    std::vector<char> value3Chars{'A', '0', 'B', '5', 'F', 'D'};
    std::string value3Str = "0xA0 0xB5 0xFD";
    TLVComponent::Value value3(value3Chars);

    EXPECT_EQ(value3Str, value3.to_string());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}