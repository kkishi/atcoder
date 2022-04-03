#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> h(n);
  cin >> h;
  WeightedGraph<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    if (h[u] > h[v]) swap(u, v);
    g[v].eb(u, 0);
    g[u].eb(v, h[v] - h[u]);
  }
  auto dist = Dijkstra(g, 0).dist;
  int ans = -big;
  rep(i, n) chmax(ans, h[0] - h[i] - *dist[i]);
  wt(ans);
}
