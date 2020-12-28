#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, n);
  V<int> t(n), h(n);
  rep(i, n) cin >> t[i] >> h[i];
  vector dp(x + y + 1, vector(x + 1, int(0)));
  rep(i, n) {
    rrep(j, x + y + 1 - t[i]) rrep(k, x) {
      chmax(dp[j + t[i]][k + 1], dp[j][k] + h[i]);
    }
  }
  int ans = 0;
  rep(i, x + y + 1) rep(j, x + 1) chmax(ans, dp[i][j]);
  wt(ans);
}
