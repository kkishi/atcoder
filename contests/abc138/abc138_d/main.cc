#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  VV<int> g(n);
  rep(i, n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  V<int> xs(n);
  rep(q) {
    ints(p, x);
    xs[p - 1] += x;
  }
  V<int> ans(n);
  Fix([&](auto dfs, int x, int node, int parent) -> void {
    x += xs[node];
    ans[node] = x;
    for (int child : g[node]) {
      if (child == parent) continue;
      dfs(x, child, node);
    }
  })(0, 0, -1);
  wt(ans);
}
