#include "../src/handler/TLVComponent/Length.hpp"
#include "gtest/gtest.h"

using msglen = TLVComponent::Length;

TEST(msglen_test, constructor_zerolength)
{
    std::vector<char> zeroLen(msglen::nChar, '0');
    msglen out(zeroLen);

    EXPECT_EQ(uint(0), out.getLen());
    EXPECT_TRUE(out.isValid());
}

TEST(msglen_test, constructor_WithLength)
{
    // assumes length of nChar >=2
    std::vector<char> oneLen(msglen::nChar, '0');
    oneLen[msglen::nChar -1] = '1';
    msglen out1(oneLen);

    std::vector<char> sixteenLen(msglen::nChar, '0');
    sixteenLen[msglen::nChar - 2] = '1';
    msglen out16(sixteenLen);

    EXPECT_EQ(uint(1), out1.getLen());
    EXPECT_EQ(uint(16), out16.getLen());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
