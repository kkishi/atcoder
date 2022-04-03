#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  V<optional<int>> df = Dijkstra(g, 0).dist, ds = Dijkstra(g, n - 1).dist;
  int f = 0;
  rep(i, n) f += (*df[i] <= *ds[i]) ? 1 : -1;
  wt(f > 0 ? "Fennec" : "Snuke");
}
