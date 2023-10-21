#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> d(n);
  cin >> d;
  ints(l0, c0, k0, l1, c1, k1);
  vector dp(n + 1, vector(k0 + 1, big));
  dp[0][0] = 0;
  rep(i, n) rep(j, k0 + 1) rep(k, j, k0 + 1) {
    int rem = d[i] - (k - j) * l0;
    int x = dp[i][j] + div_ceil(max(0, rem), l1);
    if (x <= k1) {
      chmin(dp[i + 1][k], x);
    }
  }
  int ans = big;
  rep(i, k0 + 1) if (dp[n][i] < big) chmin(ans, c0 * i + c1 * dp[n][i]);
  if (ans == big) ans = -1;
  wt(ans);
}
