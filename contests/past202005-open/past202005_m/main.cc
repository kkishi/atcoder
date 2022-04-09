#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"
#include "travelling_salesperson_problem.h"

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

  vector dp(1 << k, vector(k, big));
  vector dist(k, vector(k, int(0)));
  rep(i, k) {
    V<optional<int>> d = Dijkstra(g, t[i]).dist;
    dp[1 << i][i] = *d[s];
    rep(j, k) dist[i][j] = *d[t[j]];
  }
  TravellingSalespersonProblem(dp, dist);

  wt(min(dp.back()));
}
