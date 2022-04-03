#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, s, t);
  WeightedGraph<int> gs(n), gt(n);
  rep(m) {
    ints(u, v, a, b);
    --u, --v;
    gs[u].eb(v, a);
    gs[v].eb(u, a);
    gt[u].eb(v, b);
    gt[v].eb(u, b);
  }
  V<optional<int>> ds = Dijkstra(gs, s - 1).dist;
  V<optional<int>> dt = Dijkstra(gt, t - 1).dist;
  V<int> ans(n);
  int mini = big;
  rrep(i, n) {
    chmin(mini, *ds[i] + *dt[i]);
    ans[i] = mini;
  }
  rep(i, n) wt(1000000000000000LL - ans[i]);
}
