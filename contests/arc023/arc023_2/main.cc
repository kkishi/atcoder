#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c, d);
  VV<int> a(r, V<int>(c));
  cin >> a;
  int ans = -big;
  rep(i, r) rep(j, c) if (i + j <= d && (d - (i + j)) % 2 == 0) {
    chmax(ans, a[i][j]);
  }
  wt(ans);
}
