#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t);
  vector<pair<int, int>> f(n);
  rep(i, n) cin >> f[i].first >> f[i].second;
  sort(f);
  vector<int> dp(t + 3001);
  int ans = 0;
  rep(i, n) {
    rrep(j, t) {
      dp[j + f[i].first] = max(dp[j + f[i].first], dp[j] + f[i].second);
      chmax(ans, dp[j + f[i].first]);
    }
  }
  wt(ans);
}
