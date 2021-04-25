#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k, q);
  VV<int> p(2);
  rep(n) {
    ints(pi, t);
    p[t].pb(pi);
  }
  each(e, p) sort(all(e));
  VV<int> sp(2);
  rep(i, 2) {
    sp[i].resize(sz(p[i]) + 1);
    rep(j, sz(p[i])) sp[i][j + 1] = sp[i][j] + p[i][j];
  }
  int ans = big;
  rep(i, m + 1) {
    int j = m - i;
    if (sz(sp[0]) <= i || sz(sp[1]) <= j) continue;
    chmin(ans, sp[0][i] + sp[1][j] + div_ceil(j, k) * q);
  }
  wt(ans);
}
