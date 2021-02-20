#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int ans = big;
  rep(k, 1, n + 1) {
    vector dp(k + 1, vector(k, -1));
    dp[0][0] = 0;
    rep(i, n) rrep(used, k) rep(j, k) if (dp[used][j] >= 0) {
      chmax(dp[used + 1][(j + a[i]) % k], dp[used][j] + (j + a[i]) / k);
    }
    if (dp[k][x % k] >= 0) chmin(ans, (x / k) - dp[k][x % k]);
  }
  wt(ans);
}
