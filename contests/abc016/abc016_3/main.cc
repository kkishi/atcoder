#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<bool> g(n, V<bool>(n));
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a][b] = g[b][a] = true;
  }
  rep(i, n) {
    set<int> s;
    rep(j, n) if (g[i][j]) rep(k, n) if (g[j][k]) s.insert(k);
    s.erase(i);
    rep(j, n) if (g[i][j]) s.erase(j);
    wt(sz(s));
  }
}
