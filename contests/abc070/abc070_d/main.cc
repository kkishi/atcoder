#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  g.Read();
  ints(q, k);
  V<optional<int>> dist = Dijkstra(g, k - 1).dist;
  rep(q) {
    ints(x, y);
    wt(*dist[x - 1] + *dist[y - 1]);
  }
}
