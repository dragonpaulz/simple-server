#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/handler.hpp"

using data = handler::Data;

TEST(Handler_test, E110_EmptyMsg)
{
    std::vector<uint8_t> emptyHello = {data::helloBytes[0], data::helloBytes[1], uint8_t(0),
        uint8_t(0), uint8_t(0), uint8_t(0)};
    
    data out = data::Create(emptyHello);

    EXPECT_EQ(data::types::hello, out.msgType);
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
}

TEST(Handler_test, DA7A_EmptyMsg)
{
    std::vector<uint8_t> emptyData = {data::dataBytes[0], data::dataBytes[1], uint8_t(0),
        uint8_t(0), uint8_t(0), uint8_t(0)};

    data out = data::Create(emptyData);

    EXPECT_EQ(data::types::data, out.msgType);
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
