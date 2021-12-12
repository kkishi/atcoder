#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  wt([&]() {
    ints(n, m);
    VV<int> g(n);
    DisjointSet ds(n);
    rep(m) {
      ints(a, b);
      --a, --b;
      g[a].pb(b);
      g[b].pb(a);
      if (ds.Same(a, b)) return false;
      ds.Union(a, b);
    }
    rep(i, n) if (sz(g[i]) > 2) return false;
    return true;
  }());
}
