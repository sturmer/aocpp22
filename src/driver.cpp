#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "day5.hpp"
#include "day6.hpp"

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
  CHECK(dev::ciccarelli::day6::solve("input/day06.sample.txt") == 7);
	CHECK(dev::ciccarelli::day6::findMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", MARKER_LENGTH) == 5);
	CHECK(dev::ciccarelli::day6::findMarker("nppdvjthqldpwncqszvftbrmjlhg", MARKER_LENGTH) == 6);
	CHECK(dev::ciccarelli::day6::findMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", MARKER_LENGTH) == 10);
	CHECK(dev::ciccarelli::day6::findMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", MARKER_LENGTH) == 11);

  CHECK(dev::ciccarelli::day6::solve("input/day06.txt") == 1140);
}

// TEST_CASE("part 2") {
//   CHECK(solvePartTwo("input/day06.sample.txt") == "MCD");
//   CHECK(solvePartTwo("input/day06.txt") == "MCD");
// }
