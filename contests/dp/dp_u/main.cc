#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n));
  cin >> a;
  V<optional<int>> dp(1 << n);
  auto bit = [](int s, int i) { return (s >> i) & 1; };
  wt(Fix([&](auto rec, int s) -> int {
    auto& d = dp[s];
    if (!d) {
      d = 0;
      rep(i, 1, n) rep(j, i) if (bit(s, i) && bit(s, j))* d += a[i][j];
      for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
        chmax(*d, rec(t) + rec(s ^ t));
      }
    }
    return *d;
  })((1 << n) - 1));
}
