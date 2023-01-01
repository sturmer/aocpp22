#include "common.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "doctest.h"

using namespace std;

namespace dev {
namespace ciccarelli {

vector<string> readInput(const string& filename) {
  ifstream file(filename);
  string line;
  vector<string> file_contents;

  while (getline(file, line)) {
    file_contents.push_back(line);
  }

  // for (auto line : file_contents)
  // 	cout << line << endl;

  return file_contents;
}

vector<string> split(const string& s, const string& delimiter) {
  if (s.empty())
    return {};

  vector<string> res = {};
  size_t old_pos = 0;
  size_t new_pos = s.find(delimiter);

  string token;

  while (new_pos != string::npos) {
    token = s.substr(old_pos, new_pos - old_pos);
    if (!token.empty())
      res.push_back(token);

    old_pos = new_pos + 1;
    new_pos = s.find(delimiter, new_pos + 1);
    // cout << "old_pos: " << old_pos << ", new_pos: " << new_pos << "\n";
  }

  res.push_back(s.substr(old_pos, string::npos));

  return res;
}

string join(const vector<string>& s, const string& delimiter) {
  ostringstream oss;

  if (s.size() <= 1) {
    return s[0];
  }

  for (int i = 0; i < s.size() - 1; i++) {
    oss << s[i] << delimiter;
  }
  oss << s[s.size() - 1];

  return oss.str();
}

// FIXME
string chomp(const string& s) {
  string o = s;

  size_t left_pos = 0;
  size_t right_pos = 0;
  auto beg = o.begin();

  int i = 0;
  while (isblank(*beg)) {
    beg++;
    i++;
  }

  auto end = o.end() - 1;
  int j = o.length();
  while (isblank(*end)) {
    end--;
    j--;
  }

  cout << "i: " << i << ", j: " << j << ", res: '" << o.substr(i, j) << "'" << endl;

  if (i < j)
    return o.substr(i, j - 1);
  else
    return s;
}

TEST_CASE("can split string") {
  string s = "move 11 from 3 to 4";
  vector<string> splits = split(s, " ");
  CHECK(splits.size() == 6);
  CHECK(splits[0] == "move");
  CHECK(splits[1] == "11");
  CHECK(splits[2] == "from");
  CHECK(splits[3] == "3");
  CHECK(splits[4] == "to");
  CHECK(splits[5] == "4");
}

TEST_CASE("can join strings") {
  vector<string> vs;
  vs.push_back("a");
  vs.push_back("b");
  vs.push_back("c");

  CHECK(join(vs, "/") == "a/b/c");

  SUBCASE("only 2 strings") {
    vector<string> vs;
    vs.push_back("a");
    vs.push_back("b");
    CHECK(join(vs, "/") == "a/b");
  }
}

// FIXME:
// TEST_CASE("can chomp strings") {
//   CHECK(chomp(" 1 2 3 4   5  6   7  ") == "1 2 3 4   5  6   7");
//   CHECK(chomp("1 2 3 4   5  6   7") == "1 2 3 4   5  6   7");
//   CHECK(chomp(" ") == "");
//   CHECK(chomp("  ") == "");
//   CHECK(chomp("  1") == "1");
//   CHECK(chomp("1  ") == "1");
// }

}  // namespace ciccarelli
}  // namespace dev
