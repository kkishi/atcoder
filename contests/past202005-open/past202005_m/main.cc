#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].eb(v, 1);
    g[v].eb(u, 1);
  }
  ints(s);
  --s;
  ints(k);
  V<int> t(k);
  cin >> t;
  each(ti, t)-- ti;
  V<int> init(k);
  vector dist(k, vector(k, int(0)));
  rep(i, k) {
    V<optional<int>> d = Dijkstra(g, t[i]).dist;
    init[i] = *d[s];
    rep(j, k) dist[i][j] = *d[t[j]];
  }
  vector dp(1 << k, vector(k, big));
  rep(i, k) dp[1 << i][i] = init[i];
  rep(s, 1 << k) {
    rep(i, k) {
      if (!hasbit(s, i)) continue;
      rep(j, k) {
        if (hasbit(s, j)) continue;
        chmin(dp[s | (1 << j)][j], dp[s][i] + dist[i][j]);
      }
    }
  }
  int ans = big;
  rep(i, k) chmin(ans, dp[(1 << k) - 1][i]);
  wt(ans);
}
