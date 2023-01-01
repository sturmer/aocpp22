#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "day5.hpp"
#include "day6.hpp"
#include "day7.hpp"
#include "doctest.h"

using namespace dev::ciccarelli;
using namespace std;

TEST_CASE("day 5") {
  SUBCASE("part 1") {
    CHECK(day5::solve("input/day05.sample.txt") == "CMZ");
    CHECK(day5::solve("input/day05.txt") == "QGTHFZBHV");
  }

  SUBCASE("part 2") {
    CHECK(day5::solvePartTwo("input/day05.sample.txt") == "MCD");
    CHECK(day5::solvePartTwo("input/day05.txt") == "MGDMPSZTM");
  }
}

TEST_CASE("day 6") {
  SUBCASE("part 1") {
    const int MARKER_LENGTH = 4;
    CHECK(day6::solve("input/day06.sample.txt") == 7);
    CHECK(day6::findMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", MARKER_LENGTH) == 5);
    CHECK(day6::findMarker("nppdvjthqldpwncqszvftbrmjlhg", MARKER_LENGTH) == 6);
    CHECK(day6::findMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", MARKER_LENGTH) == 10);
    CHECK(day6::findMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", MARKER_LENGTH) == 11);

    CHECK(day6::solve("input/day06.txt") == 1140);
  }

  SUBCASE("part 2") {
    const int SEQ_LENGTH = 14;
    CHECK(day6::solvePartTwo("input/day06.sample.txt") == 19);
    CHECK(day6::findMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", SEQ_LENGTH) == 23);
    CHECK(day6::findMarker("nppdvjthqldpwncqszvftbrmjlhg", SEQ_LENGTH) == 23);
    CHECK(day6::findMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", SEQ_LENGTH) == 29);
    CHECK(day6::findMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", SEQ_LENGTH) == 26);

    CHECK(day6::solvePartTwo("input/day06.txt") == 3495);
  }
}

TEST_CASE("day 7") {
  SUBCASE("Sample") {
    auto lines = readInput("input/day07.sample.txt");
    Graph graph = day7::parseInstructions(lines);

    graph.computeDirSizes();
    // cout << "graph with correct sizes: " << graph << endl;
    CHECK(graph.size["/"] == 48381165);
    CHECK(graph.size["/-d"] == 24933642);
    CHECK(graph.size["/-a"] == 94853);
    CHECK(graph.size["/-a-e"] == 584);
  }

  SUBCASE("Real file") {
    auto lines = readInput("input/day07.txt");
    Graph graph = day7::parseInstructions(lines);

    CHECK(graph.visited.empty());
    graph.computeDirSizes();
    CHECK(graph.visited.size() == graph.adjList.size());

    // printContainer(graph.adjList["/"]);
    CHECK(graph.adjList["/"].size() == 5);

    // Key insight:
    // Search for `pfnglqgw`: it's repeated several times, which means:
    // labels are not unique in the graph :(

  }

  SUBCASE("part 1") {
    CHECK(day7::solve("input/day07.sample.txt") == 95437);
    CHECK(day7::solve("input/day07.txt") == 1084134);
  }

  SUBCASE("part 2") {
    CHECK(day7::solvePartTwo("input/day07.sample.txt") == 24933642);
    CHECK(day7::solvePartTwo("input/day07.txt") == 6183184);
  }
}
