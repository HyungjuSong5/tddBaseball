#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
 public:
  void guess(const string& input) {
	  throw length_error("Must be three letter.");
  }
};