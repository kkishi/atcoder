#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<pair<int, int>> v(n);
  rep(m) {
    ints(x, y, z);
    v[x - 1].eb(y, z);
  }
  vector dp(n + 1, vector(1 << n, int(0)));
  dp[0][0] = 1;
  rep(i, n) rep(mask, 1 << n) if (dp[i][mask]) rep(j, n) if (!hasbit(mask, j)) {
    int nmask = mask | (1 << j);
    V<int> cnt(19);
    rep(i, 1, n + 1) {
      cnt[i] = cnt[i - 1];
      if (hasbit(nmask, i - 1)) ++cnt[i];
    }
    bool ok = true;
    each(y, z, v[i]) {
      if (cnt[y] > z) ok = false;
    }
    if (ok) {
      dp[i + 1][nmask] += dp[i][mask];
    }
  }
  wt(dp[n][(1 << n) - 1]);
}
