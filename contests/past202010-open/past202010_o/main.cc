#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph<int> g(n + 1);
  rep(i, n) g.AddEdge(i + 1, i, 0);
  int y = 0;
  rep(i, n) {
    ints(a);
    g.AddEdge(i, i + 1, a);
    y += a;
  }
  rep(m) {
    ints(l, r, c);
    g.AddEdge(l - 1, r, c);
  }
  wt(y - *Dijkstra(g, 0).dist[n]);
}
