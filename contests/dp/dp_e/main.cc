#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, W);
  V<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  int inf = numeric_limits<int>::max() / 10;
  V<int> dp(100001, inf);
  dp[0] = 0;
  rep(i, n) rrep(j, 100001 - v[i]) if (dp[j] != -1) {
    chmin(dp[j + v[i]], dp[j] + w[i]);
  }
  int ans = 0;
  rep(i, 100001) if (dp[i] <= W) chmax(ans, i);
  wt(ans);
}
