#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(n - 1 + m) {
    ints(a, b);
    g[a - 1].eb(b - 1);
  }
  auto [ts, ok] = TopologicalSort(g);
  assert(ok);
  V<int> p(n, -1);
  rrep(i, n) {
    each(to, g[ts[i]]) {
      if (p[to] == -1) {
        p[to] = ts[i];
      }
    }
  }
  rep(i, n) wt(p[i] + 1);
}
