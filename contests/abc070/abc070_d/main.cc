#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph<int> g(n + 1);
  rep(n - 1) {
    ints(a, b, c);
    g.AddEdge(a, b, c);
    g.AddEdge(b, a, c);
  }
  ints(q, k);
  V<optional<int>> dist = Dijkstra(g, k);
  rep(q) {
    ints(x, y);
    wt(*dist[x] + *dist[y]);
  }
}
