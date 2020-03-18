#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/setup/setup_helper/serveroptions.hpp"

TEST(ServerOption_Test, GoodData)
{
    setup::Server_Options opts(uint16_t(755));

    EXPECT_EQ(uint16_t(755), opts.getPort());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
