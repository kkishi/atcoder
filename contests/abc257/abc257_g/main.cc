#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"
#include "z_algorithm.h"

void Main() {
  strings(s, t);
  string st = s + "$" + t;
  V<int> z = ZAlgorithm(st);
  int N = sz(t);
  WeightedGraph<int> g(N + 1);
  rep(i, N) g[i + 1].eb(i, 0);
  rep(i, N) g[i].eb(i + z[sz(s) + 1 + i], 1);
  auto d = Dijkstra(g, 0).dist;
  if (d[N]) {
    wt(*d[N]);
  } else {
    wt(-1);
  }
}
