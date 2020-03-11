#include <cstdint>
#include <gtest/gtest.h>

#include "../src/serveroptions.hpp"

uint16_t ServerOptionsPortNumberHelper(char arguments[])
{
    char** args = new char*{arguments};
    setup_server::Server_Options opts(args);
    return opts.port;
}

TEST(ServerOption_Test, GoodData) 
{
    EXPECT_EQ(uint16_t(755), ServerOptionsPortNumberHelper("./program --port 755"));
    EXPECT_EQ(setup_server::Server_Options::defaultPort, ServerOptionsPortNumberHelper("./program"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}