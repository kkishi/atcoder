#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];
  auto dist = [&](int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]) + max(0, z[b] - z[a]);
  };
  int inf = numeric_limits<int>::max() / 10;
  int ans = inf;
  vector dp(1 << n, vector(n, inf));
  dp[1][0] = 0;
  rep(s, 1 << n) rep(i, n) if (hasbit(s, i)) rep(j, n) if (!hasbit(s, j)) {
    chmin(dp[s | (1 << j)][j], dp[s][i] + dist(i, j));
  }
  rep(i, n) chmin(ans, dp[(1 << n) - 1][i] + dist(i, 0));
  wt(ans);
}
