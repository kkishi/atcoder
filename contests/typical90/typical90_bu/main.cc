#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<char> c(n);
  cin >> c;
  Graph g(n);
  g.Read();
  wt(Fix([&](auto rec, int node, int parent) -> V<mint> {
    V<mint> dp(4);
    dp[1 << (c[node] == 'a' ? 0 : 1)] = 1;
    each(child, g[node]) if (child != parent) {
      V<mint> cdp = rec(child, node);
      V<mint> ndp(4);
      // Connect
      rep(mask1, 1, 1 << 2) rep(mask2, 1, 1 << 2) {
        ndp[mask1 | mask2] += dp[mask1] * cdp[mask2];
      }
      // Don't connect
      rep(mask, 1, 1 << 2) ndp[mask] += dp[mask] * cdp[3];
      dp = ndp;
    }
    return dp;
  })(0, -1)[3]);
}
