#include "../src/handler/Byte.hpp"
#include "gtest/gtest.h"

using byte = handler::Byte;

TEST(Hex_test, isHexChar_Accepts_0_to_9)
{
    EXPECT_TRUE(byte::isHexChar('0'));
    EXPECT_TRUE(byte::isHexChar('1'));
    EXPECT_TRUE(byte::isHexChar('2'));
    EXPECT_TRUE(byte::isHexChar('3'));
    EXPECT_TRUE(byte::isHexChar('4'));
    EXPECT_TRUE(byte::isHexChar('5'));
    EXPECT_TRUE(byte::isHexChar('6'));
    EXPECT_TRUE(byte::isHexChar('7'));
    EXPECT_TRUE(byte::isHexChar('8'));
    EXPECT_TRUE(byte::isHexChar('9'));
}

TEST(Hex_test, isHexChar_Accepts_a_to_f)
{
    EXPECT_TRUE(byte::isHexChar('a'));
    EXPECT_TRUE(byte::isHexChar('b'));
    EXPECT_TRUE(byte::isHexChar('c'));
    EXPECT_TRUE(byte::isHexChar('d'));
    EXPECT_TRUE(byte::isHexChar('e'));
    EXPECT_TRUE(byte::isHexChar('f'));
}

TEST(Hex_test, isHexChar_Accepts_A_to_F)
{
    EXPECT_TRUE(byte::isHexChar('A'));
    EXPECT_TRUE(byte::isHexChar('B'));
    EXPECT_TRUE(byte::isHexChar('C'));
    EXPECT_TRUE(byte::isHexChar('D'));
    EXPECT_TRUE(byte::isHexChar('E'));
    EXPECT_TRUE(byte::isHexChar('F'));
}

TEST(Hex_test, isHexChar_Rejects_NonHex)
{
    EXPECT_FALSE(byte::isHexChar('G'));
    EXPECT_FALSE(byte::isHexChar('g'));
    EXPECT_FALSE(byte::isHexChar('Z'));
    EXPECT_FALSE(byte::isHexChar('z'));
    EXPECT_FALSE(byte::isHexChar('?'));
    EXPECT_FALSE(byte::isHexChar('-'));
    EXPECT_FALSE(byte::isHexChar(':'));
    EXPECT_FALSE(byte::isHexChar('/'));
    EXPECT_FALSE(byte::isHexChar('@'));
    EXPECT_FALSE(byte::isHexChar('`'));
}

TEST(Hex_Test, TwoHexToByte_HexStr)
{
    byte zero("00");
    byte one("01");
    byte sixteen("10");
    byte max("FF");

    EXPECT_EQ(uint8_t(0), zero.getLen());
    EXPECT_EQ(uint8_t(1), one.getLen());
    EXPECT_EQ(uint8_t(16), sixteen.getLen());
    EXPECT_EQ(UINT8_MAX, max.getLen());

    EXPECT_TRUE(zero.isValid());
    EXPECT_TRUE(one.isValid());
    EXPECT_TRUE(sixteen.isValid());
    EXPECT_TRUE(max.isValid());
}

TEST(Hex_Test, TwoHexToByte_BadData)
{
    byte singleChar("F");
    EXPECT_EQ(uint8_t(0), singleChar.getLen());
    EXPECT_FALSE(singleChar.isValid());

    byte threeChar("FOO");
    EXPECT_EQ(uint8_t(0), threeChar.getLen());
    EXPECT_FALSE(threeChar.isValid());

    byte invalidHex("G0");
    EXPECT_EQ(uint8_t(0), invalidHex.getLen());
    EXPECT_FALSE(invalidHex.isValid());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
