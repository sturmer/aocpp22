#include "day6.hpp"

#include <iostream>
#include <string>
#include <unordered_set>

#include "common.hpp"

using namespace std;

namespace dev {
namespace ciccarelli {
namespace day6 {

unordered_set<char> histogram(const string& buf) {
  unordered_set<char> hist;

  for (auto c : buf)
    hist.insert(c);

  return hist;
}

int solve(const string& filename) {
  auto lines = readInput(filename);
  // cout << "line from file: " << lines[0] << endl;

  return findMarker(lines[0], 4);
}

int findMarker(const string& buf, const int sequence_length) {
  string marker;

  for (int i = 0; i < buf.length(); ++i) {
    if (marker.length() >= sequence_length)
      marker.erase(0, 1);

    marker += buf[i];

    // cout << "marker: " << marker << endl;

    const auto h = histogram(marker);
    if (h.size() == sequence_length) {
      // cout << "i: " << i << endl;
      return i + 1;
    }
  }
  return -1;
}

}  // namespace day6
}  // namespace ciccarelli
}  // namespace dev
