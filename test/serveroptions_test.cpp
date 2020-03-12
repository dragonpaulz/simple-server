#include <algorithm>
#include <cstdint>
#include <string>
#include "gtest/gtest.h"

#include "../src/serveroptions.hpp"

TEST(ServerOption_Test, GoodData)
{
    char** args = new char*{"./program --port 755"};
    setup_server::Server_Options opts(3, args);

    EXPECT_EQ(uint16_t(755), opts.port);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}