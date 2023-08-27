#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int N = 100001;
  V<int> dp(N, big);
  dp[0] = 0;
  int free = 0;
  int sum_z = 0;
  rep(n) {
    ints(x, y, z);
    sum_z += z;
    int cost = (y + 1 - x) / 2;
    if (cost <= 0) {
      free += z;
      continue;
    }
    rrep(i, N) {
      if (i + z < N) {
        chmin(dp[i + z], dp[i] + cost);
      }
    }
  }
  int target = (sum_z + 1) / 2;
  if (free >= target) {
    wt(0);
  } else {
    int ans = big;
    rep(i, target - free, N) chmin(ans, dp[i]);
    wt(ans);
  }
}
