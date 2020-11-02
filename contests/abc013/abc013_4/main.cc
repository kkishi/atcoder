#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, d);
  V<int> ord(n);
  iota(all(ord), 0);
  rep(m) {
    ints(a);
    swap(ord[a - 1], ord[a]);
  }
  VV<int> ordn(40, V<int>(n));
  ordn[0] = ord;
  rep(i, 1, 40) rep(j, n) ordn[i][j] = ordn[i - 1][ordn[i - 1][j]];
  V<int> ans(n);
  iota(all(ans), 0);
  rep(i, 40) if ((d >> i) & 1) rep(j, n) ans[j] = ordn[i][ans[j]];
  V<int> rans(n);
  rep(i, n) rans[ans[i]] = i;
  rep(i, n) wt(rans[i] + 1);
}
