#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector dp(100, -big);
  dp[0] = 0;
  rep(n) {
    ints(p, u);
    vector ndp = dp;
    rep(i, 100) {
      int x = i + p;
      chmax(ndp[x % 100], dp[i] + u + x / 100 * 20 - p);
    }
    swap(ndp, dp);
  }
  wt(max(dp));
}
