#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c, d);
  vector a(r, V<int>(c));
  cin >> a;
  int ans = -big;
  rep(i, r) rep(j, c) if (i + j <= d && even(d - (i + j))) {
    chmax(ans, a[i][j]);
  }
  wt(ans);
}
