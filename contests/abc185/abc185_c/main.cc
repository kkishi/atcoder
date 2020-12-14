#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l);
  vector dp(l + 1, vector(13, optional<int>()));
  wt(Fix([&](auto rec, int x, int n) -> int {
    if (x < n) return 0;
    if (n == 1) return 1;
    auto& d = dp[x][n];
    if (!d) {
      d = 0;
      rep(y, 1, x)* d += rec(x - y, n - 1);
    }
    return *d;
  })(l, 12));
}
