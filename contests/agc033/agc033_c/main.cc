#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

int diameter(const Graph<int>& g) {
  if (g.NumVertices() == 1) return 0;
  V<optional<int>> d1 = Dijkstra(g, 0);
  int m = 0, i;
  rep(j, sz(d1)) if (chmax(m, *d1[j])) i = j;
  V<optional<int>> d2 = Dijkstra(g, i);
  m = 0;
  rep(j, sz(d2)) chmax(m, *d2[j]);
  return m;
}

void Main() {
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  wt(diameter(g) % 3 == 1 ? "Second" : "First");
}
