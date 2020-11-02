#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, W);
  V<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  int w0 = w[0];
  rep(i, n) w[i] -= w0;
  VV<int> dp(n + 1, V<int>(n * 3 + 1, -1));
  dp[0][0] = 0;
  rep(i, n) rrep(used, n) for (int j = sz(dp[used]) - 1; j - w[i] >= 0; --j) {
    int d = dp[used][j - w[i]];
    if (d != -1) chmax(dp[used + 1][j], d + v[i]);
  }
  int ans = 0;
  rep(used, n + 1) for (int i = 0; i + used * w0 <= W && i <= used * 3; ++i) {
    chmax(ans, dp[used][i]);
  }
  wt(ans);
}
