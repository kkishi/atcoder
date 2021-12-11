#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, q, k);
  Graph<int> g(n);
  V<int> a(k);
  cin >> a;
  rep(m) {
    ints(u, v);
    --u, --v;
    g.AddEdge(u, v, 1);
    g.AddEdge(v, u, 1);
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
