#include "../src/handler/MsgLen.hpp"
#include "gtest/gtest.h"

using msglen = handler::MsgLen;

TEST(msglen_test, constructor)
{
    std::vector<char> zeroLen(msglen::nChar, '0');
    msglen::MsgLen out(zeroLen);

    EXPECT_EQ(uint(0), out.getLen());
    EXPECT_EQ(true, out.isValid());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
