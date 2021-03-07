#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = big;
  rep(i, n) rep(j, n) {
    int x = i == j ? a[i] + b[j] : max(a[i], b[j]);
    chmin(ans, x);
  }
  wt(ans);
}
