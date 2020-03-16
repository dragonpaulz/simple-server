#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/handler.hpp"

using data = handler::Data;

const std::string zeroLen = "000000";

TEST(Handler_test, E110_EmptyMsg)
{
    std::vector<uint8_t> emptyHello = {data::helloBytes[0], data::helloBytes[1], uint8_t(0),
        uint8_t(0), uint8_t(0), uint8_t(0)};
    
    data out = data::Create(emptyHello);

    EXPECT_EQ(data::types::hello, out.msgType);
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, DA7A_EmptyMsg)
{
    std::vector<uint8_t> emptyData = {data::dataBytes[0], data::dataBytes[1], uint8_t(0),
        uint8_t(0), uint8_t(0), uint8_t(0)};

    data out = data::Create(emptyData);

    EXPECT_EQ(data::types::data, out.msgType);
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, 0B1E_EmptyMsg)
{
    std::vector<uint8_t> emptyBye = {data::goodbyeBytes[0], data::goodbyeBytes[1], uint8_t(0),
        uint8_t(0), uint8_t(0), uint8_t(0)};

    data out = data::Create(emptyBye);

    EXPECT_EQ(data::types::goodbye, out.msgType);
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, unknown_EmptyMsg_NotValid)
{
    std::vector<uint8_t> emptyUnknown (data::minBytes, uint8_t(0));

    data out = data::Create(emptyUnknown);
    EXPECT_FALSE(out.getValid());
}

TEST(Handler_test, lengthMismatch_NotValid)
{
    // assumes hello bytes is passing.
    std::vector<uint8_t> lenMismatch(data::minBytes + 1, 0);
    lenMismatch[0] = data::helloBytes[0];
    lenMismatch[1] = data::helloBytes[1];

    data out = data::Create(lenMismatch);
    EXPECT_FALSE(out.getValid());
}

// not yet ready
// TEST(Handler_test, contains_message_valid)
// {
//     std::vector<uint8_t> helloWithMsg = {data::helloBytes[0], data::helloBytes[1], uint8_t(0),
//         uint8_t(0), uint8_t(0), uint8_t(1), uint8_t(1)};

//     data out = data::Create(helloWithMsg);

//     EXPECT_TRUE(out.getValid());
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
