#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, z);
  wt([&]() -> int {
    auto between = [](int a, int b, int c) {
      if (a > b) swap(a, b);
      return a < c && c < b;
    };
    if (!between(0, x, y)) return x;
    if (between(0, z, y)) return -1;
    return abs(z) + abs(z - x);
  }());
}
