#include <bits/stdc++.h>

#include "atcoder.h"
#include "diameter.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  auto [d, a, b] = Diameter(g);
  V<int> path;
  Fix([&](auto rec, int node, int parent) -> bool {
    bool ok = node == b;
    each(child, _, g[node]) {
      if (child == parent) continue;
      if (rec(child, node)) ok = true;
    }
    if (ok) path.pb(node);
    return ok;
  })(a, -1);
  V<int> ans(n);
  int E = 1;
  rep(i, sz(path)) {
    ans[path[i]] = E;
    each(to, _, g[path[i]]) {
      if (i > 0 && to == path[i - 1]) continue;
      if (i < sz(path) - 1 && to == path[i + 1]) continue;
      Fix([&](auto rec, int node, int parent) -> void {
        ++E;
        ans[node] = E;
        each(to, _, g[node]) {
          if (to == parent) continue;
          rec(to, node);
        }
        ++E;
      })(to, path[i]);
    }
    ++E;
  }
  wt(ans);
}
