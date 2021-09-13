#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph<int> g(n + 1);
  rep(m) {
    ints(l, r, x);
    --l;
    // b[r] - b[l] <= r - l - x
    g.AddEdge(l, r, r - l - x);
  }
  rep(i, n) {
    // b[i+1] - b[i] <= 1
    g.AddEdge(i, i + 1, 1);
    // b[i] - b[i+1] <= 0
    g.AddEdge(i + 1, i, 0);
  }
  auto d = Dijkstra(g, 0).dist;
  V<int> ans(n);
  rep(i, n) ans[i] = 1 - (*d[i + 1] - *d[i]);
  wt(ans);
}
