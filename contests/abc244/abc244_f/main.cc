#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector dp(n, vector(1 << n, big));
  rep(i, n) dp[i][1 << i] = 1;
  while (true) {
    bool updated = false;
    rep(i, n) rep(mask, 1 << n) {
      int x = dp[i][mask];
      if (x == big) continue;
      each(ni, g[i]) {
        if (chmin(dp[ni][mask ^ (1 << ni)], x + 1)) {
          updated = true;
        }
      }
    }
    if (!updated) break;
  }
  V<int> ans(1 << n, big);
  ans[0] = 0;
  rep(i, n) rep(j, 1 << n) chmin(ans[j], dp[i][j]);
  wt(accumulate(ans));
}
