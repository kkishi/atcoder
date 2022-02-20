#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<int> l(n), r(n);
  Fix([&](auto rec, int node, int parent, int offset) -> int {
    l[node] = offset;
    bool first = true;
    each(child, g[node]) if (child != parent) {
      if (first) {
        first = false;
      } else {
        ++offset;
      }
      offset = rec(child, node, offset);
    }
    r[node] = offset;
    return offset;
  })(0, -1, 0);
  rep(i, n) wt(l[i] + 1, r[i] + 1);
}
