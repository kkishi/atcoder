#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, q);
  VV<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<int> c(n);
  cin >> c;
  rep(q) {
    ints(k, x);
    --x;
    wt(c[x]);
    if (k == 1) {
      each(y, g[x]) c[y] = c[x];
    } else {
      ints(y);
      c[x] = y;
    }
  }
}
