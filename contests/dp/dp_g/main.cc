#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(x, y);
    g.AddEdge(x - 1, y - 1);
  }
  auto [ts, ok] = TopologicalSort(g);
  assert(ok);
  V<int> dp(n);
  rrep(i, n) for (const auto& e : g.Edges(ts[i]))
      chmax(dp[e.from], dp[e.to] + 1);
  wt(max(dp));
}
