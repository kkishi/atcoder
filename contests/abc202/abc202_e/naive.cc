#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n - 1);
  cin >> p;
  VV<int> g(n);
  rep(i, n - 1) { g[p[i] - 1].pb(i + 1); }
  ints(q);
  rep(q) {
    ints(u, d);
    --u;
    int ans = 0;
    Fix([&](auto rec, int node, int parent, bool ok, int depth) -> void {
      ok = ok || node == u;
      if (ok && depth == d) ++ans;
      each(child, g[node]) { rec(child, node, ok, depth + 1); }
    })(0, -1, false, 0);
    wt(ans);
  }
}
