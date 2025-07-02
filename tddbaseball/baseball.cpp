#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct GuessResult {
  bool solved;
  int strikes;
  int balls;
};

class Baseball {
 public:
  explicit Baseball(const string& question) : question(question) {}

  GuessResult guess(const string& guessNumber) {
    assertIllegalArgument(guessNumber);
    checktheresult(guessNumber);
    return checktheresult(guessNumber);
  }

  GuessResult checktheresult(const string& guessNumber) {
    vector<int> seqNum = {0, 1, 2};
    GuessResult result = {false, 0, 0};

    for (auto pos = seqNum.begin(); pos != seqNum.end();) {
      if (question[*pos] == guessNumber[*pos]) {
        result.strikes++;
        pos = seqNum.erase(pos);
      } else
        pos++;
    }
    if (seqNum.empty()) {
      result.solved = true;
      return result;
    }
    for (auto pos1 = seqNum.begin(); pos1 != seqNum.end(); ++pos1) {
      for (auto pos2 = seqNum.begin(); pos2 != seqNum.end(); ++pos2) {
        if (question[*pos2] == guessNumber[*pos1]) {
          result.balls++;
        }
      }
    }
    return result;
  }

  void assertIllegalArgument(const std::string& guessNumber) {
    if (guessNumber.length() != 3) {
      throw length_error("Must be three letter.");
    }

    for (char ch : guessNumber) {
      if (ch >= '0' && ch <= '9') continue;
      throw invalid_argument("Must be number");
    }

    if (isDuplicatedNumber(guessNumber)) {
      throw invalid_argument("Must not have the same number");
    }
  }

  bool isDuplicatedNumber(const std::string& guessNumber) {
    return (guessNumber[0] == guessNumber[1] ||
            guessNumber[1] == guessNumber[2] ||
            guessNumber[0] == guessNumber[2]);
  }

 private:
  string question;
};