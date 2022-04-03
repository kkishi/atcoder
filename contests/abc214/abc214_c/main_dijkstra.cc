#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> s(n), t(n);
  cin >> s >> t;
  WeightedGraph<int> g(n + 1);
  rep(i, n) {
    g[n].eb(i, t[i]);
    g[i].eb((i + 1) % n, s[i]);
  }
  auto d = Dijkstra(g, n).dist;
  rep(i, n) wt(*d[i]);
}
