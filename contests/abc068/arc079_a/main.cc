#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  Graph<int> g(n + 1);
  rep(m) {
    ints(a, b);
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  optional<int> d = Dijkstra(g, 1)[n];
  wt((d && d == 2) ? "POSSIBLE" : "IMPOSSIBLE");
}
