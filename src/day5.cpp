#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <array>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>

#include "common.hpp"
#include "doctest.h"

using namespace std;
using namespace dev::ciccarelli;

tuple<vector<string>, vector<string>::const_iterator> parsePiles(const vector<string>& lines) {
  vector<string>::const_iterator line = lines.cbegin();

  // This contains the lines as they are
  vector<string> rawPiles = {};

  while (*line != "" && !lines.empty()) {
    // cout << "line: '" << *line << "'\n";

    rawPiles.push_back(*line);
    line++;
  }

  const string lastLine = *(rawPiles.cend() - 1);

  // FIXME This is brittle. A space after the last digit (stack label) breaks everything.
  auto splits = split(lastLine, " ");
  // for (auto s : splits)
  //   cout << "split: " << s << endl;

  const int numPiles = stoi(splits[splits.size() - 1]);

  // cout << "We're dealing with " << numPiles << " piles\n";

  vector<string> piles(numPiles);
  for (int j = 0; j < rawPiles.size() - 1; j++) {  // skip pile labels
    const string& rawPile = rawPiles[j];
    for (int i = 1; i < rawPile.length(); i = i + 4) {
      char label = rawPile[i];
      int pileNo = i / 4;
      if (label != ' ')
        piles[pileNo].push_back(label);
    }
  }

  return {piles, line + 1};
}

vector<array<int, 3>> parseInstructions(const vector<string>& instructions,
                                        vector<string>::const_iterator cur_line) {
  const string delimiter(" ");
  vector<array<int, 3>> parsedInstructions;

  while (cur_line != instructions.cend() && !instructions.empty()) {
    auto splits = split(*cur_line, " ");
    int howMany = stoi(splits[1]);
    int from = stoi(splits[3]);
    int to = stoi(splits[5]);

    // cout << "Move " << howMany << " From " << from << " To " << to << "\n";

    parsedInstructions.push_back({howMany, from, to});
    cur_line++;
  }

  return parsedInstructions;
}

string solve(const string& filename) {
  auto lines = readInput(filename);
  auto [piles, line] = parsePiles(lines);

  // for (auto pile : piles)
  //   cout << "pile: " << pile << endl;

  auto instructions = parseInstructions(lines, line);
  for (auto instruction : instructions) {
    const int howMany = instruction[0];
    const int fromPileIdx = instruction[1] - 1;
    const int toPileIdx = instruction[2] - 1;
    for (int i = 0; i < howMany; i++) {
      piles[toPileIdx].insert(piles[toPileIdx].begin(), piles[fromPileIdx].front());
      piles[fromPileIdx].erase(piles[fromPileIdx].begin());
    }

    // cout << "executing <" << instruction[0] << ", " << instruction[1] << ", " << instruction[2] << ">:\n";
    // for (auto pile : piles)
    //   cout << "pile: " << pile << endl;
  }

  string tops;
  for (auto p : piles)
    tops += p.front();

  return tops;
}

string solvePartTwo(const string& filename) {
  auto lines = readInput(filename);
  auto [piles, line] = parsePiles(lines);

  // for (auto pile : piles)
    // cout << "pile: " << pile << endl;

  auto instructions = parseInstructions(lines, line);
  for (auto instruction : instructions) {
    const int howMany = instruction[0];
    const int fromPileIdx = instruction[1] - 1;
    const int toPileIdx = instruction[2] - 1;

    // cout << "about to process the tmpPIile (howMany: " << howMany << ", fromPileIdx: " << fromPileIdx << ", toPileIdx: " << toPileIdx << ")\n";
    vector<char> tmpPile;
    for (int i = 0; i < howMany; i++) {
      tmpPile.push_back(piles[fromPileIdx].front());

      // printContainer(tmpPile, "temp pile (pushed): ");

      // cout << "to-erase pile (before): " << piles[fromPileIdx] << endl;
      piles[fromPileIdx].erase(piles[fromPileIdx].begin());
      // cout << "erased (after)" << piles[fromPileIdx] << endl;
    }

    // printContainer(tmpPile, "temp pile: ");

    // cout << "to pile (before): " << piles[toPileIdx] << endl;
    for (auto x = tmpPile.rbegin(); x != tmpPile.rend(); x++)
      piles[toPileIdx].insert(piles[toPileIdx].begin(), *x);
    // cout << "to pile (after): " << piles[toPileIdx] << endl;

    // cout << "executing <" << instruction[0] << ", " << instruction[1] << ", " << instruction[2] << ">:\n";
    // for (auto pile : piles)
    //   cout << "pile: " << pile << endl;
  }

  string tops;
  for (auto p : piles)
    tops += p.front();

  return tops;
}

// TEST_CASE("part 1") {
//   CHECK(solve("input/day05.sample.txt") == "CMZ");
//   CHECK(solve("input/day05.txt") == "QGTHFZBHV");
// }

TEST_CASE("part 2") {
  CHECK(solvePartTwo("input/day05.sample.txt") == "MCD");
  CHECK(solvePartTwo("input/day05.txt") == "MCD");
}
