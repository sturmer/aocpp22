#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "day5.hpp"
#include "day6.hpp"
#include "doctest.h"

using namespace dev::ciccarelli;

TEST_CASE("part 1") {
  CHECK(day5::solve("input/day05.sample.txt") == "CMZ");
  CHECK(day5::solve("input/day05.txt") == "QGTHFZBHV");
}

TEST_CASE("part 2") {
  CHECK(day5::solvePartTwo("input/day05.sample.txt") == "MCD");
  CHECK(day5::solvePartTwo("input/day05.txt") == "MGDMPSZTM");
}

TEST_CASE("part 1") {
  const int MARKER_LENGTH = 4;
  CHECK(day6::solve("input/day06.sample.txt") == 7);
  CHECK(day6::findMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", MARKER_LENGTH) == 5);
  CHECK(day6::findMarker("nppdvjthqldpwncqszvftbrmjlhg", MARKER_LENGTH) == 6);
  CHECK(day6::findMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", MARKER_LENGTH) == 10);
  CHECK(day6::findMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", MARKER_LENGTH) == 11);

  CHECK(day6::solve("input/day06.txt") == 1140);
}

TEST_CASE("part 2") {
  const int SEQ_LENGTH = 14;
  CHECK(day6::solvePartTwo("input/day06.sample.txt") == 19);
  CHECK(day6::findMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", SEQ_LENGTH) == 23);
  CHECK(day6::findMarker("nppdvjthqldpwncqszvftbrmjlhg", SEQ_LENGTH) == 23);
  CHECK(day6::findMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", SEQ_LENGTH) == 29);
  CHECK(day6::findMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", SEQ_LENGTH) == 26);

  CHECK(day6::solvePartTwo("input/day06.txt") == 3495);
}
