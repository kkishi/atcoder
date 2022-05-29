#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector dp(2, vector(n + 2, big));
  dp[0][1] = 0;
  dp[1][1] = dp[1][2] = a[0];
  rep(i, 1, n) rep(j, 2) rep(k, 1, 3) chmin(dp[j][i + k], dp[j][i] + a[i]);
  wt(min(dp[0][n + 1], dp[1][n]));
}
