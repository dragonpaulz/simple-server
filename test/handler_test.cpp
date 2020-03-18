#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/handler/TLVmessage.hpp"
#include "../src/handler/TLVComponent/Type.hpp"

using message = handler::TLVmessage;
using typec = TLVComponent::Type;

TEST(Handler_test, E110_EmptyMsg)
{
    std::vector<char> emptyHello = {typec::helloChars[0], typec::helloChars[1], typec::helloChars[2],
        typec::helloChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};
    
    message out(emptyHello);

    EXPECT_EQ(TLVComponent::Type::hello, out.getMsgType().getType());
    EXPECT_EQ(uint32_t(0), out.getMsgLength().getLen());
    EXPECT_TRUE(out.getMsgValue().getValue().empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, DA7A_EmptyMsg)
{
    std::vector<char> emptyData = {typec::dataChars[0], typec::dataChars[1], typec::dataChars[2],
        typec::dataChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

    message out(emptyData);

    EXPECT_EQ(TLVComponent::Type::data, out.getMsgType().getType());
    EXPECT_EQ(uint32_t(0), out.getMsgLength().getLen());
    EXPECT_TRUE(out.getMsgValue().getValue().empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, 0B1E_EmptyMsg)
{
    std::vector<char> emptyBye = {typec::byeChars[0], typec::byeChars[1], typec::byeChars[2],
        typec::byeChars[3], '0', '0', '0', '0', '0', '0', '0', '0'};

    message out(emptyBye);

    EXPECT_EQ(TLVComponent::Type::bye, out.getMsgType().getType());
    EXPECT_EQ(uint32_t(0), out.getMsgLength().getLen());
    EXPECT_TRUE(out.getMsgValue().getValue().empty());
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_test, unknown_EmptyMsg_NotValid)
{
    std::vector<char> emptyUnknown (message::minChars, '0');

    message out(emptyUnknown);
    EXPECT_FALSE(out.getValid());
}

TEST(Handler_test, lengthMismatch_NotValid)
{
    // assumes hello bytes is passing.
    std::vector<char> lenMismatch(message::minChars + 2, '0');
    lenMismatch[0] = typec::helloChars[0];
    lenMismatch[1] = typec::helloChars[1];
    lenMismatch[2] = typec::helloChars[2];
    lenMismatch[3] = typec::helloChars[3];

    message out(lenMismatch);
    EXPECT_FALSE(out.getValid());
}

TEST(Handler_test, lengthGood_Valid)
{
    // assumes hello bytes is passing.
    std::vector<char> withMessage(message::minChars + 2, '0');
    withMessage[0] = typec::helloChars[0];
    withMessage[1] = typec::helloChars[1];
    withMessage[2] = typec::helloChars[2];
    withMessage[3] = typec::helloChars[3];

    withMessage[11] = '1';
    // value "00"

    message out(withMessage);
    EXPECT_TRUE(out.getValid());
}

TEST(Handler_unittest_ValueIsOfLen, length_and_valuelength_match)
{
    std::vector<char> len1(TLVComponent::Length::nChar, '0');
    len1[TLVComponent::Length::nChar - 1] = '1';
    TLVComponent::Length length1(len1);

    std::vector<char> valueLen1Byte(2, '0');
    TLVComponent::Value value1Byte(valueLen1Byte);

    bool out = message::ValueIsOfLen(length1, valueLen1Byte);
    EXPECT_TRUE(out);
}

TEST(Handler_unittest_ValueIsOfLen, length_and_valuelength_donotmatch)
{
    std::vector<char> len1(TLVComponent::Length::nChar, '0');
    len1[TLVComponent::Length::nChar - 1] = '1';
    TLVComponent::Length length1(len1);

    std::vector<char> valueLen1Byte(4, '0');
    TLVComponent::Value value1Byte(valueLen1Byte);

    bool out = message::ValueIsOfLen(length1, valueLen1Byte);
    EXPECT_FALSE(out);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
