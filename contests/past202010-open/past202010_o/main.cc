#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n + 1);
  rep(i, n) g[i + 1].eb(i, 0);
  int y = 0;
  rep(i, n) {
    ints(a);
    g[i].eb(i + 1, a);
    y += a;
  }
  rep(m) {
    ints(l, r, c);
    g[l - 1].eb(r, c);
  }
  wt(y - *Dijkstra(g, 0).dist[n]);
}
