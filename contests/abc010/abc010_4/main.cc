#include <bits/stdc++.h>

#include "atcoder.h"
#include "edmonds_karp.h"
#include "graph.h"

void Main() {
  ints(n, g, e);
  V<int> p(g);
  cin >> p;
  Graph<int> graph(n + 1);
  rep(e) {
    ints(a, b);
    graph.AddEdge(a, b, 1);
    graph.AddEdge(b, a, 1);
  }
  rep(i, g) graph.AddEdge(p[i], n, 1);
  wt(EdmondsKarp(graph, 0, n));
}
