#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = big;
  rep(init_same, 2) {
    vector dp(n, vector(2, big));
    if (init_same) {
      dp[0][1] = a[0];
    } else {
      dp[0][0] = 0;
    }
    rep(i, 1, n) rep(prev_same, 2) rep(curr_same, 2) {
      int cost = 0;
      if (prev_same == curr_same) cost += b[i - 1];
      if (curr_same) cost += a[i];
      if (i == n - 1 && init_same == curr_same) cost += b[i];
      chmin(dp[i][curr_same], dp[i - 1][prev_same] + cost);
    }
    each(e, dp[n - 1]) chmin(ans, e);
  }
  wt(ans);
}
