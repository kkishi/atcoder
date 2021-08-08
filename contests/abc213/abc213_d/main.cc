#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  each(e, g) sort(all(e));
  V<int> ans;
  Fix([&](auto rec, int node, int parent) -> void {
    ans.pb(node + 1);
    each(c, g[node]) {
      if (c != parent) {
        rec(c, node);
      }
    }
    if (parent != -1) ans.pb(parent + 1);
  })(0, -1);
  wt(ans);
}
