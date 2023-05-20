#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  VV<int> s;
  WeightedGraph<int> g(m + n);
  rep(i, n) {
    ints(a);
    rep(a) {
      ints(x);
      --x;
      g[x].eb(m + i, 1);
      g[m + i].eb(x, 1);
    }
  }
  auto d = Dijkstra(g, 0).dist[m - 1];
  if (d) {
    wt((*d - 1) / 2);
  } else {
    wt(-1);
  }
}
