#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, s, t);
  Graph<int> gs(n), gt(n);
  rep(m) {
    ints(u, v, a, b);
    --u, --v;
    gs.AddEdge(u, v, a);
    gs.AddEdge(v, u, a);
    gt.AddEdge(u, v, b);
    gt.AddEdge(v, u, b);
  }
  V<optional<int>> ds = Dijkstra(gs, s - 1);
  V<optional<int>> dt = Dijkstra(gt, t - 1);
  V<int> ans(n);
  int mini = numeric_limits<int>::max();
  rrep(i, n) {
    chmin(mini, *ds[i] + *dt[i]);
    ans[i] = mini;
  }
  rep(i, n) wt(1000000000000000LL - ans[i]);
}
