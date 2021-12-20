#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n), b(n);
  cin >> a >> b;
  vector dp(1 << n, big);
  dp[0] = 0;
  rep(mask, 1 << n) {
    int D = dp[mask];
    if (D == big) continue;
    int i = popcount(mask);
    int not_used_left = 0;
    rep(j, n) {
      if (hasbit(mask, j)) continue;
      int X = abs(a[i] - b[j]) * x;
      int Y = not_used_left * y;
      chmin(dp[mask | (1 << j)], D + X + Y);
      ++not_used_left;
    }
  }
  wt(dp[(1 << n) - 1]);
}
