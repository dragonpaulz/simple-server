#include <vector>

#include "../src/handler/TLVComponent/Type.hpp"
#include "gtest/gtest.h"

using typec = TLVComponent::Type;

TEST(TLVtype_test, hello)
{
    std::vector<char> helloType(typec::helloChars[0], typec::helloChars[3]);
    typec out(helloType);

    ASSERT_EQ(typec::hello, out.getType());
    ASSERT_TRUE(out.isValid());
}

TEST(TLVtype_test, data)
{
    std::vector<char> dataType(typec::dataChars[0], typec::dataChars[3]);
    typec out(dataType);

    ASSERT_EQ(typec::data, out.getType());
    ASSERT_TRUE(out.isValid());
}

TEST(TLVtype_test, bye)
{
    std::vector<char> byeType(typec::byeChars[0], typec::byeChars[3]);
    typec out(byeType);

    ASSERT_EQ(typec::bye, out.getType());
    ASSERT_TRUE(out.isValid());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
