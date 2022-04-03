#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n + 1);
  rep(n - 1) {
    ints(a, b, c);
    g[a].eb(b, c);
    g[b].eb(a, c);
  }
  ints(q, k);
  V<optional<int>> dist = Dijkstra(g, k).dist;
  rep(q) {
    ints(x, y);
    wt(*dist[x] + *dist[y]);
  }
}
