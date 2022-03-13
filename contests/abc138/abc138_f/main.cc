#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(l, r);
  auto f = [](int x) {
    V<int> v;
    while (x) {
      v.eb(x & 1);
      x >>= 1;
    }
    return v;
  };
  V<int> L = f(l), R = f(r);
  int n = sz(R);
  while (sz(L) < n) L.eb(0);
  reverse(L);
  reverse(R);
  vector dp(n + 1, vector(2, vector(2, mint(0))));
  bool seen_L_1 = false;
  rep(i, n) {
    rep(y_lt_r, 2) rep(x_gt_l, 2) rep(y, 2) rep(x, y + 1) {
      if (!y_lt_r && y > R[i]) continue;
      if (!x_gt_l && x < L[i]) continue;
      dp[i + 1][y_lt_r | (y < R[i])][x_gt_l | (x > L[i])] +=
          dp[i][y_lt_r][x_gt_l];
    }
    if ((i > 0 || R[i] == 1) && !seen_L_1) {
      dp[i + 1][i > 0][L[i] == 0] += 1;
    }
    if (L[i] == 1) seen_L_1 = true;
  }
  mint ans = 0;
  rep(i, 2) rep(j, 2) ans += dp[n][i][j];
  wt(ans);
}
