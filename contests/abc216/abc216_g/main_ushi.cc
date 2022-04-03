#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n + 1);
  rep(m) {
    ints(l, r, x);
    --l;
    // b[r] - b[l] <= r - l - x
    g[l].eb(r, r - l - x);
  }
  rep(i, n) {
    // b[i+1] - b[i] <= 1
    g[i].eb(i + 1, 1);
    // b[i] - b[i+1] <= 0
    g[i + 1].eb(i, 0);
  }
  auto d = Dijkstra(g, 0).dist;
  V<int> ans(n);
  rep(i, n) ans[i] = 1 - (*d[i + 1] - *d[i]);
  wt(ans);
}
