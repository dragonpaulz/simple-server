#include "../src/handler/Byte.hpp"
#include "gtest/gtest.h"

using byte = handler::Byte;

TEST(Hex_test, Accepts_0_to_9)
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

TEST(Hex_test, Accepts_a_to_f)
{
    EXPECT_TRUE(byte::isHexChar('a'));
    EXPECT_TRUE(byte::isHexChar('b'));
    EXPECT_TRUE(byte::isHexChar('c'));
    EXPECT_TRUE(byte::isHexChar('d'));
    EXPECT_TRUE(byte::isHexChar('e'));
    EXPECT_TRUE(byte::isHexChar('f'));
}

TEST(Hex_test, Accepts_A_to_F)
{
    EXPECT_TRUE(byte::isHexChar('A'));
    EXPECT_TRUE(byte::isHexChar('B'));
    EXPECT_TRUE(byte::isHexChar('C'));
    EXPECT_TRUE(byte::isHexChar('D'));
    EXPECT_TRUE(byte::isHexChar('E'));
    EXPECT_TRUE(byte::isHexChar('F'));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
