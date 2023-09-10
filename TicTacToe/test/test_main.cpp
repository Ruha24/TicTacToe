#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../include/Player.h"

using namespace testing;


TEST(PlayerTest, ConstructorTest) {
    std::string playerName = "Alice";
    Player player(playerName);
    EXPECT_EQ(player.getName(), playerName);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
