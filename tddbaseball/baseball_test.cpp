#include "baseball.cpp"

#include "gmock/gmock.h"

using namespace testing;

class BaseballFixture : public testing ::Test {
 public:
  Baseball game;
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


int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}