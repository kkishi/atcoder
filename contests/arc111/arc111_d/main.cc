#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> v(m);
  cin >> v;
  each(a, b, v)-- a, --b;
  VV<int> g(n);
  each(a, b, v) {
    g[a].pb(b);
    g[b].pb(a);
  }
  V<int> c(n);
  cin >> c;

  V<int> idx(n);
  iota(all(idx), 0);
  sort(idx, [&](int i, int j) { return c[i] < c[j]; });

  set<pair<int, int>> dir;
  each(i, idx) {
    each(j, g[i]) {
      if (c[i] < c[j]) dir.insert({j, i});
      if (c[i] > c[j]) dir.insert({i, j});
    }
  }
  rep(i, n) Fix([&](auto rec, int n, int p) -> void {
    each(c, g[n]) if (c != p) {
      if (dir.count({n, c}) || dir.count({c, n})) continue;
      dir.insert({n, c});
      rec(c, n);
    }
  })(i, -1);

  each(a, b, v) wt(dir.count({a, b}) ? "->" : "<-");
}
