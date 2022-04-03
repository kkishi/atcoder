#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> p(n - 1);
  cin >> p;
  Graph g(n);
  rep(i, n - 1) g[p[i] - 1].eb(i + 1);
  VV<tuple<int, int>> qs(n);
  ints(q);
  rep(i, q) {
    ints(u, d);
    qs[u - 1].eb(i, d);
  }
  V<int> ans(q);
  V<int> depth_cnt(n);
  Fix([&](auto rec, int node, int depth) -> void {
    each(i, d, qs[node]) ans[i] -= depth_cnt[d];
    depth_cnt[depth]++;
    each(e, g.Edges(node)) rec(e.to, depth + 1);
    each(i, d, qs[node]) ans[i] += depth_cnt[d];
  })(0, 0);
  each(e, ans) wt(e);
}
