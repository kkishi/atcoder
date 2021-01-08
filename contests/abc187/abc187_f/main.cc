#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector g(n, V<bool>(n));
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a][b] = g[b][a] = true;
  }
  V<int> dp(1 << n, big);
  rep(s, 1 << n) {
    bool ok = true;
    rep(i, n - 1) if (hasbit(s, i))
        rep(j, i + 1, n) if (hasbit(s, j)) if (!g[i][j]) ok = false;
    if (ok) {
      dp[s] = 1;
    } else {
      for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
        chmin(dp[s], dp[t] + dp[s ^ t]);
      }
    }
  }
  wt(dp[(1 << n) - 1]);
}
