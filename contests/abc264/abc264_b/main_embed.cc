#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> g{
      // clang-format off
      {"###############"},
      {"#.............#"},
      {"#.###########.#"},
      {"#.#.........#.#"},
      {"#.#.#######.#.#"},
      {"#.#.#.....#.#.#"},
      {"#.#.#.###.#.#.#"},
      {"#.#.#.#.#.#.#.#"},
      {"#.#.#.###.#.#.#"},
      {"#.#.#.....#.#.#"},
      {"#.#.#######.#.#"},
      {"#.#.........#.#"},
      {"#.###########.#"},
      {"#.............#"},
      {"###############"},
      // clang-format on
  };
  ints(r, c);
  wt(g[r - 1][c - 1] == '#' ? "black" : "white");
}