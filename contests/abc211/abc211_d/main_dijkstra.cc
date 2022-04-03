#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  auto dist = Dijkstra(g, 0);
  V<tuple<int, int, int>> v;
  rep(i, n) each(e, g.Edges(i)) {
    auto a = dist[i];
    auto b = dist[e.to];
    if (a && b && *a + 1 == *b) {
      v.eb(*a, i, e.to);
    }
  }
  sort(v);
  vector dp(n, mint(0));
  dp[0] = 1;
  for (auto [_, i, j] : v) dp[j] += dp[i];
  wt(dp[n - 1]);
}
