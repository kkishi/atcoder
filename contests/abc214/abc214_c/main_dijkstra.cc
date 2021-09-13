#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> s(n), t(n);
  cin >> s >> t;
  Graph<int> g(n + 1);
  rep(i, n) {
    g.AddEdge(n, i, t[i]);
    g.AddEdge(i, (i + 1) % n, s[i]);
  }
  auto d = Dijkstra(g, n).dist;
  rep(i, n) wt(*d[i]);
}
