#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dijkstra.h"
#include "graph.h"
#include "i128.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> e;
  V<int> v = {1, n};
  rep(m) {
    ints(a, b, c);
    e.eb(a, b, c);
    v.eb(a);
    v.eb(b);
  }
  Compressor cr(v);
  int N = sz(cr.coord);
  Graph<i128> g(N);
  rep(i, N - 1) {
    int d = cr.coord[i + 1] - cr.coord[i];
    g.AddEdge(i, i + 1, d);
    g.AddEdge(i + 1, i, d);
  }
  for (auto [a, b, c] : e) {
    g.AddEdge(cr(a), cr(b), c);
    g.AddEdge(cr(b), cr(a), c);
  }
  wt(*Dijkstra(g, 0).dist[N - 1]);
}
