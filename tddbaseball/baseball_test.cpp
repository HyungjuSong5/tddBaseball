#include "baseball.cpp"

#include "gmock/gmock.h"

using namespace testing;

TEST(BASEBALLGame, ThrowExceptionWhenInputLengthIsUnmatched) {
  Baseball game;
  EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BASEBALLGame, ThrowExceptionWhenInvalidChar) {
  Baseball game;
  EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}