#include "baseball.cpp"

#include "gmock/gmock.h"

using namespace testing;

class BaseballFixture : public testing ::Test {
 public:
  Baseball game{"123"};
  void assertIllegalArgument(string guessNumber) {
    try {
      game.guess(guessNumber);
      FAIL();
    } catch (exception e) {
      // pass
    }
  }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
  assertIllegalArgument("12");
  assertIllegalArgument("12s");
  assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
  GuessResult result = game.guess("123");

  EXPECT_TRUE(result.solved);
  EXPECT_EQ(3, result.strikes);
  EXPECT_EQ(0, result.balls);
}


TEST_F(BaseballFixture, TwoStrikeNoBall) {
  GuessResult result = game.guess("124");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(2, result.strikes);
  EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, OneStrikeTwoBall) {
  GuessResult result = game.guess("321");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(1, result.strikes);
  EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, OneStrikOneBall) {
  GuessResult result = game.guess("135");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(1, result.strikes);
  EXPECT_EQ(1, result.balls);
}

TEST_F(BaseballFixture, OneStrikNoBall) {
  GuessResult result = game.guess("185");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(1, result.strikes);
  EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, NoStrikeTwoBall) {
  GuessResult result = game.guess("241");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(0, result.strikes);
  EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, NoStrikeOneBall) {
  GuessResult result = game.guess("451");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(0, result.strikes);
  EXPECT_EQ(1, result.balls);
}
TEST_F(BaseballFixture, NoStrikeNoBall) {
  GuessResult result = game.guess("456");

  EXPECT_FALSE(result.solved);
  EXPECT_EQ(0, result.strikes);
  EXPECT_EQ(0, result.balls);
}

int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}