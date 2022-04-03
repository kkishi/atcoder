#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dijkstra.h"
#include "graph.h"

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
  WeightedGraph<int> g(N);
  rep(i, N - 1) {
    int d = cr.coord[i + 1] - cr.coord[i];
    g[i].eb(i + 1, d);
    g[i + 1].eb(i, d);
  }
  for (auto [a, b, c] : e) {
    g[cr(a)].eb(cr(b), c);
    g[cr(b)].eb(cr(a), c);
  }
  wt(*Dijkstra(g, 0).dist[N - 1]);
}
