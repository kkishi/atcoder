#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n);
  VV<int> a(n);
  rep(i, n) {
    cin >> c[i];
    a[i].resize(c[i]);
    cin >> a[i];
  }
  ints(x);
  int mi = big;
  rep(i, n) each(e, a[i]) if (e == x) chmin(mi, c[i]);
  V<int> ans;
  rep(i, n) each(e, a[i]) if (e == x && c[i] == mi) ans.eb(i + 1);
  sort(ans);
  wt(sz(ans));
  wt(ans);
}
