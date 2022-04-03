#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n + 1);
  rep(m) {
    ints(a, b);
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  optional<int> d = Dijkstra(g, 1).dist[n];
  wt((d && d == 2) ? "POSSIBLE" : "IMPOSSIBLE");
}
