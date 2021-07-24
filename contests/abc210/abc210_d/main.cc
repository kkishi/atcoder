#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, c);
  vector a(h, vector(w, int(0)));
  cin >> a;

  int ans = big;
  rep(2) {
    vector dp(h + 1, vector(w + 1, big));
    rep(i, h) rep(j, w) {
      chmin(ans, dp[i][j] + a[i][j]);
      chmin(dp[i][j], a[i][j]);
      chmin(dp[i + 1][j], dp[i][j] + c);
      chmin(dp[i][j + 1], dp[i][j] + c);
    }
    each(e, a) reverse(all(e));
  }
  wt(ans);
}
