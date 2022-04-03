#include <bits/stdc++.h>

#include "atcoder.h"
#include "euler_tour.h"
#include "segment_tree.h"

void Main() {
  ints(n);
  V<int> p(n - 1);
  cin >> p;
  Graph g(n);
  rep(i, n - 1) g[p[i] - 1].eb(i + 1);
  auto [in, out] = EulerTour(g);
  VV<int> depth_idx(n);
  Fix([&](auto rec, int node, int depth) -> void {
    depth_idx[depth].pb(node);
    each(to, g[node]) rec(to, depth + 1);
  })(0, 0);
  ints(q);
  VV<tuple<int, int>> depth_qs(n);
  rep(i, q) {
    ints(u, d);
    depth_qs[d].eb(i, u - 1);
  }
  SegmentTree<int> tree(n, [](int a, int b) { return a + b; });
  V<int> ans(q);
  rep(depth, n) {
    each(idx, depth_idx[depth]) tree.Set(in[idx], 1);
    each(i, u, depth_qs[depth]) ans[i] = tree.Aggregate(in[u], out[u]);
    each(idx, depth_idx[depth]) tree.Set(in[idx], 0);
  }
  each(e, ans) wt(e);
}
