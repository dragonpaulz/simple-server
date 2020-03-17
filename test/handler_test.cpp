#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/handler.hpp"
#include "../src/handler/TLVComponent/Type.hpp"

using data = handler::Data;

const std::string zeroLen = "000000";

TEST(Handler_test, E110_EmptyMsg)
{
    // std::vector<uint8_t> emptyHello = {data::helloBytes[0], data::helloBytes[1], uint8_t(0),
    //     uint8_t(0), uint8_t(0), uint8_t(0)};
    std::vector<char> emptyHello = {data::helloChars[0], data::helloChars[1], data::helloChars[2],
        data::helloChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};
    
    data out = data::Create(emptyHello);

    EXPECT_EQ(TLVComponent::Type::hello, out.msgType.getType());
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, DA7A_EmptyMsg)
{
    // std::vector<uint8_t> emptyData = {data::dataBytes[0], data::dataBytes[1], uint8_t(0),
    //     uint8_t(0), uint8_t(0), uint8_t(0)};
    std::vector<char> emptyData = {data::dataChars[0], data::dataChars[1], data::dataChars[2],
        data::dataChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

    data out = data::Create(emptyData);

    EXPECT_EQ(TLVComponent::Type::data, out.msgType.getType());
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, 0B1E_EmptyMsg)
{
    // std::vector<uint8_t> emptyBye = {data::goodbyeBytes[0], data::goodbyeBytes[1], uint8_t(0),
    //     uint8_t(0), uint8_t(0), uint8_t(0)};
    std::vector<char> emptyBye = {data::goodbyeChars[0], data::goodbyeChars[1], data::goodbyeChars[2],
        data::goodbyeChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

    data out = data::Create(emptyBye);

    EXPECT_EQ(TLVComponent::Type::bye, out.msgType.getType());
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, unknown_EmptyMsg_NotValid)
{
    std::vector<char> emptyUnknown (data::minChars, '0');

    data out = data::Create(emptyUnknown);
    EXPECT_FALSE(out.getValid());
}

TEST(Handler_test, lengthMismatch_NotValid)
{
    // assumes hello bytes is passing.
    std::vector<char> lenMismatch(data::minChars + 1, '0');
    lenMismatch[0] = data::helloChars[0];
    lenMismatch[1] = data::helloChars[1];
    lenMismatch[2] = data::helloChars[2];
    lenMismatch[3] = data::helloChars[3];

    data out = data::Create(lenMismatch);
    EXPECT_FALSE(out.getValid());
}

// TEST(Handler_test, contains_message_valid)
// {
//     // std::vector<uint8_t> helloWithMsg = {data::helloBytes[0], data::helloBytes[1], uint8_t(0),
//     //     uint8_t(0), uint8_t(0), uint8_t(1), uint8_t(1)};
//     std::vector<char> helloWithMsg = {data::helloChars[0], data::helloChars[1], data::helloChars[2],
//         data::helloChars[3], '0', '0', '0', '0', '0', '0', '0', '1', '0', '0'};

//     data out = data::Create(helloWithMsg);

//     EXPECT_TRUE(out.getValid());
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
