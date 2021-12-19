#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n), b(n);
  cin >> a >> b;
  vector dp(n + 1, vector(1 << n, big));
  dp[0][0] = 0;
  rep(i, n) rep(mask, 1 << n) {
    if (popcount(mask) != i) continue;
    int D = dp[i][mask];
    if (D == big) continue;
    int not_used_left = 0;
    rep(j, n) {
      if (hasbit(mask, j)) continue;
      int X = abs(a[i] - b[j]) * x;
      int Y = not_used_left * y;
      chmin(dp[i + 1][mask | (1 << j)], D + X + Y);
      ++not_used_left;
    }
  }
  wt(dp[n][(1 << n) - 1]);
}
