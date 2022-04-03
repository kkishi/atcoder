#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, q, k);
  WeightedGraph<int> g(n);
  V<int> a(k);
  cin >> a;
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].eb(v, 1);
    g[v].eb(u, 1);
  }
  V<Result<int>> res;
  each(e, a) res.eb(Dijkstra(g, e - 1));
  rep(q) {
    int ans = big;
    ints(s, t);
    each(e, res) chmin(ans, *e.dist[s - 1] + *e.dist[t - 1]);
    wt(ans);
  }
}
