#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<bool> xy(n, V<bool>(n));
  rep(m) {
    ints(x, y);
    xy[x - 1][y - 1] = true;
  }
  V<int> dp((1 << n) + 1);
  dp[0] = 1;
  rep(s, 1 << n) {
    rep(i, n) {
      if (hasbit(s, i)) continue;
      bool ok = true;
      rep(j, n) if (hasbit(s, j) && xy[i][j]) ok = false;
      if (!ok) continue;
      dp[s | (1 << i)] += dp[s];
    }
  }
  wt(dp[(1 << n) - 1]);
}
