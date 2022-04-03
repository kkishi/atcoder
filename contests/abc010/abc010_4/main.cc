#include <bits/stdc++.h>

#include "atcoder.h"
#include "edmonds_karp.h"
#include "graph.h"

void Main() {
  ints(n, g, e);
  V<int> p(g);
  cin >> p;
  WeightedGraph<int> graph(n + 1);
  rep(e) {
    ints(a, b);
    graph[a].eb(b, 1);
    graph[b].eb(a, 1);
  }
  rep(i, g) graph[p[i]].eb(n, 1);
  wt(EdmondsKarp(graph, 0, n));
}
