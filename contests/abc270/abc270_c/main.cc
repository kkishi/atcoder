#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, x, y);
  --x, --y;
  WeightedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].eb(v, 1);
    g[v].eb(u, 1);
  }
  auto res = Dijkstra(g, x);
  V<int> ans = res.Path(y);
  each(e, ans)++ e;
  wt(ans);
}
