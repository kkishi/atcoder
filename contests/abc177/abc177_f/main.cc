#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<int> a(h), b(h);
  rep(i, h) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }
  int inf = numeric_limits<int>::max() / 10;
  VV<int> dp(2, V<int>(w, inf));
  rep(i, w) dp[0][i] = 0;
  rep(i, h) {
    rep(j, w) dp[1][j] = inf;
    rep(j, w) if (j < a[i] || b[i] < j) chmin(dp[1][j], dp[0][j] + 1);
    rep(j, w - 1) chmin(dp[1][j + 1], dp[1][j] + 1);
    int ans = inf;
    rep(j, w) chmin(ans, dp[1][j]);
    wt(ans == inf ? -1 : ans);
    swap(dp[0], dp[1]);
  }
}
