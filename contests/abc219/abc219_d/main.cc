#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector dp(x + 1, vector(y + 1, big));
  dp[0][0] = 0;
  rep(i, n) {
    vector ndp = dp;
    rep(j, x + 1) rep(k, y + 1) {
      chmin(ndp[min(x, j + a[i])][min(y, k + b[i])], dp[j][k] + 1);
    }
    swap(dp, ndp);
  }
  int ans = dp[x][y];
  if (ans == big) ans = -1;
  wt(ans);
}
