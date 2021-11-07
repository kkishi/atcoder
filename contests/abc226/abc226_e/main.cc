#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

mint Solve(const VV<int>& g) {
  int n = sz(g);
  mint ans = 1;
  V<bool> seen(n);
  rep(i, n) if (!seen[i]) {
    set<int> nodes;
    set<pair<int, int>> edges;
    Fix([&](auto rec, int node, int parent) {
      if (seen[node]) return;
      seen[node] = true;
      nodes.insert(node);
      each(child, g[node]) if (child != parent) {
        pair<int, int> e{node, child};
        if (e.first > e.second) swap(e.first, e.second);
        edges.insert(e);
        rec(child, node);
      }
    })(i, -1);
    if (sz(nodes) != sz(edges)) return 0;
    ans *= 2;
  }
  return ans;
}

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  wt(Solve(g));
}
