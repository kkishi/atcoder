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
  const int B = 1024;
  rep(i, div_ceil(q, B)) {
    V<bitset<B>> dp(n);
    int J = min(B, q - i * B);
    rep(j, J) dp[Q[i * B + j].second][j] = 1;
    rrep(u, n) each(v, g[u]) dp[u] |= dp[v];
    rep(j, J) wt(bool(dp[Q[i * B + j].first][j]));
  }
}
