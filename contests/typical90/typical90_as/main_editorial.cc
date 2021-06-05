#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  V<int> set_d(1 << n, -big);
  rep(mask, 1, 1 << n) {
    if (popcount(mask) == 1) {
      set_d[mask] = 0;
      continue;
    }
    rep(i, n - 1) rep(j, i + 1, n) {
      if (hasbit(mask, i) && hasbit(mask, j)) {
        auto sq = [](int x) { return x * x; };
        chmax(set_d[mask], sq(x[i] - x[j]) + sq(y[i] - y[j]));
      }
    }
  }
  vector dp(1 << n, vector(k + 1, big));
  rep(mask, 1, 1 << n) rep(cnt, 1, k + 1) {
    if (cnt == 1) {
      dp[mask][cnt] = set_d[mask];
      continue;
    }
    dp[mask][cnt] = big;
    for (int mask_a = (mask - 1) & mask; mask_a > 0;
         mask_a = (mask_a - 1) & mask) {
      int mask_b = mask - mask_a;
      chmin(dp[mask][cnt], max(set_d[mask_a], dp[mask_b][cnt - 1]));
    }
  }
  wt(dp[(1 << n) - 1][k]);
}
