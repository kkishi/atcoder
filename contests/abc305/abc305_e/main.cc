#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, k);
  WeightedGraph<int> g(n + 1);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  rep(k) {
    ints(p, h);
    --p;
    g[n].eb(p, n - h);
  }
  auto d = Dijkstra(g, n).dist;
  V<int> ans;
  rep(i, n) if (d[i] && *d[i] <= n) ans.eb(i + 1);
  wt(sz(ans));
  wt(ans);
}
