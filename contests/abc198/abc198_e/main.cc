#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  map<int, int> seen;
  V<bool> ans(n);
  Fix([&](auto rec, int node, int parent) -> void {
    if (seen[c[node]] == 0) {
      ans[node] = true;
    }
    ++seen[c[node]];
    each(child, g[node]) {
      if (child == parent) continue;
      rec(child, node);
    }
    --seen[c[node]];
  })(0, -1);
  rep(i, n) if (ans[i]) wt(i + 1);
}
