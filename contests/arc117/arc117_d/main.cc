#include <bits/stdc++.h>

#include "atcoder.h"
#include "diameter.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  auto [d, a, b] = Diameter(g);
  V<int> path;
  Fix([&](auto rec, int node, int parent) -> bool {
    bool ok = node == b;
    each(e, g.Edges(node)) {
      if (e.to == parent) continue;
      if (rec(e.to, node)) ok = true;
    }
    if (ok) path.pb(node);
    return ok;
  })(a, -1);
  V<int> ans(n);
  int E = 1;
  rep(i, sz(path)) {
    ans[path[i]] = E;
    each(e, g.Edges(path[i])) {
      if (i > 0 && e.to == path[i - 1]) continue;
      if (i < sz(path) - 1 && e.to == path[i + 1]) continue;
      Fix([&](auto rec, int node, int parent) -> void {
        ++E;
        ans[node] = E;
        each(e, g.Edges(node)) {
          if (e.to == parent) continue;
          rec(e.to, node);
        }
        ++E;
      })(e.to, path[i]);
    }
    ++E;
  }
  wt(ans);
}
