#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int n = 400;
  VV<int> g(n);
  rep(i, 1, 200) g[0].pb(i);
  rep(i, 1, 399) rep(j, i + 1, 399) g[i].pb(j);
  rep(i, 200, 399) g[i].pb(399);
  V<pair<int, int>> e;
  rep(i, n) each(j, g[i]) e.eb(i, j);
  int m = sz(e);
  wt(n, m);
  each(i, j, e) wt(i + 1, j + 1);
}
