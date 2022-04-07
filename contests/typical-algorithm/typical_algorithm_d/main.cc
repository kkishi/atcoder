#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(u, v, c);
    g[u].eb(v, c);
  }
  wt(*Dijkstra(g, 0).dist[n - 1]);
}
