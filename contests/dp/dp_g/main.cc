#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(x, y);
    g[x - 1].eb(y - 1);
  }
  auto [ts, ok] = TopologicalSort(g);
  assert(ok);
  V<int> dp(n);
  rrep(i, n) each(to, g[ts[i]]) chmax(dp[ts[i]], dp[to] + 1);
  wt(max(dp));
}
