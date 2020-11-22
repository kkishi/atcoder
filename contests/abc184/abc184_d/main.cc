#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  vector dp(101, vector(101, vector(101, optional<double>())));
  wt(Fix([&](auto rec, int x, int y, int z) -> double {
    if (max({x, y, z}) == 100) return 0;
    auto& d = dp[x][y][z];
    if (!d) {
      double tot = x + y + z;
      d = 1;
      *d += x / tot * rec(x + 1, y, z);
      *d += y / tot * rec(x, y + 1, z);
      *d += z / tot * rec(x, y, z + 1);
    }
    return *d;
  })(a, b, c));
}
