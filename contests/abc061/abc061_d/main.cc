#include <bits/stdc++.h>

#include "atcoder.h"
#include "bellman_ford.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> a(m), b(m), c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
  }

  WeightedGraph<int> rg(n);
  rep(i, m) rg[b[i]].eb(a[i], 0);
  V<optional<int>> rd = Dijkstra(rg, n - 1).dist;

  WeightedGraph<int> g(n);
  rep(i, m) if (rd[b[i]]) g[a[i]].eb(b[i], -c[i]);

  if (auto [e, ok] = BellmanFord(g, 0); ok) {
    wt(-*e[n - 1]);
  } else {
    wt("inf");
  }
}
