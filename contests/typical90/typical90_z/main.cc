#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  VV<int> ans(2);
  Fix([&](auto rec, int node, int parent, int color) -> void {
    ans[color].pb(node + 1);
    each(child, g[node]) {
      if (child == parent) continue;
      rec(child, node, 1 - color);
    }
  })(0, -1, 0);
  if (sz(ans[0]) < sz(ans[1])) swap(ans[0], ans[1]);
  ans[0].resize(n / 2);
  wt(ans[0]);
}
