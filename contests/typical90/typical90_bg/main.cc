#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, q);
  VV<int> g(n);
  rep(m) {
    ints(x, y);
    g[x - 1].pb(y - 1);
  }
  V<pair<int, int>> Q;
  rep(q) {
    ints(a, b);
    Q.eb(a - 1, b - 1);
  }
  rep(i, div_ceil(q, 64)) {
    V<bitset<64>> dp(n);
    int J = min(64, q - i * 64);
    rep(j, J) dp[Q[i * 64 + j].second][j] = 1;
    rrep(u, n) each(v, g[u]) dp[u] |= dp[v];
    rep(j, J) wt(bool(dp[Q[i * 64 + j].first][j]));
  }
}
