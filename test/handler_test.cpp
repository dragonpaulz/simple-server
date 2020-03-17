#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/handler.hpp"
#include "../src/handler/TLVComponent/Type.hpp"

using data = handler::Data;
using typec = TLVComponent::Type;

TEST(Handler_test, E110_EmptyMsg)
{
    std::vector<char> emptyHello = {typec::helloChars[0], typec::helloChars[1], typec::helloChars[2],
        typec::helloChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};
    
    data out = data::Create(emptyHello);

    EXPECT_EQ(TLVComponent::Type::hello, out.msgType.getType());
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, DA7A_EmptyMsg)
{
    std::vector<char> emptyData = {typec::dataChars[0], typec::dataChars[1], typec::dataChars[2],
        typec::dataChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

    data out = data::Create(emptyData);

    EXPECT_EQ(TLVComponent::Type::data, out.msgType.getType());
    EXPECT_EQ(uint32_t(0), out.msgLen);
    EXPECT_TRUE(out.msg.empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, 0B1E_EmptyMsg)
{
    std::vector<char> emptyBye = {typec::byeChars[0], typec::byeChars[1], typec::byeChars[2],
        typec::byeChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

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
    std::vector<char> lenMismatch(data::minChars + 2, '0');
    lenMismatch[0] = typec::helloChars[0];
    lenMismatch[1] = typec::helloChars[1];
    lenMismatch[2] = typec::helloChars[2];
    lenMismatch[3] = typec::helloChars[3];

    data out = data::Create(lenMismatch);
    EXPECT_FALSE(out.getValid());
}

TEST(Handler_test, lengthGood_Valid)
{
    // assumes hello bytes is passing.
    std::vector<char> withMessage(data::minChars + 2, '0');
    withMessage[0] = typec::helloChars[0];
    withMessage[1] = typec::helloChars[1];
    withMessage[2] = typec::helloChars[2];
    withMessage[3] = typec::helloChars[3];

    withMessage[10] = '1';
    // value "00"

    data out = data::Create(withMessage);
    EXPECT_TRUE(out.getValid());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
