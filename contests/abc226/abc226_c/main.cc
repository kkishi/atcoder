#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n);
  VV<int> g(n);
  rep(i, n) {
    cin >> t[i];
    ints(k);
    rep(k) {
      ints(a);
      --a;
      g[i].pb(a);
    }
  }
  V<bool> seen(n);
  Fix([&](auto rec, int node, int parent) -> void {
    if (seen[node]) return;
    seen[node] = true;
    each(child, g[node]) if (child != parent) rec(child, node);
  })(n - 1, -1);
  int ans = 0;
  rep(i, n) if (seen[i]) ans += t[i];
  wt(ans);
}
