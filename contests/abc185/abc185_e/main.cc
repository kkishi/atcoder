#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  vector dp(n + 1, vector(m + 1, big));
  dp[0][0] = 0;
  rep(i, m) dp[0][i + 1] = i + 1;
  rep(i, n) dp[i + 1][0] = i + 1;
  rep(i, n) rep(j, m) {
    int& d = dp[i + 1][j + 1];
    chmin(d, dp[i][j] + (a[i] != b[j]));
    chmin(d, dp[i][j + 1] + 1);
    chmin(d, dp[i + 1][j] + 1);
  }
  wt(dp[n][m]);
}
