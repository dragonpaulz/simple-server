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
    EXPECT_EQ(uint8_t(0), byte::TwoHexToByte("00"));
    EXPECT_EQ(uint8_t(16), byte::TwoHexToByte("10"));
    EXPECT_EQ(UINT8_MAX, byte::TwoHexToByte("FF"));
}

TEST(Hex_Test, TwoHexToByte_BadData)
{
    EXPECT_EQ(uint8_t(0), byte::TwoHexToByte("F"));
    EXPECT_EQ(uint8_t(0), byte::TwoHexToByte("F00"));
    EXPECT_EQ(uint8_t(0), byte::TwoHexToByte("G0"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
