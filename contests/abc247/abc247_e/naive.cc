#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) rep(j, i + 1, n + 1) {
    int ma = -big, mi = big;
    rep(k, i, j) {
      chmax(ma, a[k]);
      chmin(mi, a[k]);
    }
    if (mi == y && ma == x) ++ans;
  }
  wt(ans);
}
