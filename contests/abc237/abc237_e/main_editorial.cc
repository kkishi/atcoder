#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> h(n);
  cin >> h;
  Graph<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    if (h[u] > h[v]) swap(u, v);
    g.AddEdge(v, u, 0);
    g.AddEdge(u, v, h[v] - h[u]);
  }
  auto dist = Dijkstra(g, 0).dist;
  int ans = -big;
  rep(i, n) chmax(ans, h[0] - h[i] - *dist[i]);
  wt(ans);
}
