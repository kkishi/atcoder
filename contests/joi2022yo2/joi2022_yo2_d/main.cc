#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  vector dp(n * 2, vector(k, int(0)));
  dp[1][1] = a[0];
  rep(i, 1, n) rep(j, 1, k) {
    chmax(dp[i + 1][min(j + 1, k - 1)], dp[i][j]);
    chmax(dp[i - j + k][k - j], dp[i][j] + a[i]);
  }
  int ans = 0;
  each(e, dp) each(f, e) chmax(ans, f);
  wt(ans);
}
