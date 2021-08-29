#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(n - 1 + m) {
    ints(a, b);
    g.AddEdge(a - 1, b - 1);
  }
  auto [ts, ok] = TopologicalSort(g);
  assert(ok);
  V<int> p(n, -1);
  rrep(i, n) {
    for (const auto& e : g.Edges(ts[i])) {
      if (p[e.to] == -1) {
        p[e.to] = ts[i];
      }
    }
  }
  rep(i, n) wt(p[i] + 1);
}
