#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n));
  cin >> a;
  V<int> dp(1 << n);
  rep(s, 1 << n) {
    rep(i, 1, n) rep(j, i) if ((s >> i) & (s >> j) & 1) dp[s] += a[i][j];
    for (int t = s; t > 0; t = (t - 1) & s) chmax(dp[s], dp[t] + dp[s - t]);
  }
  wt(dp[(1 << n) - 1]);
}
