#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = big;
  int s = 0;
  rep(i, min(n, x)) {
    s += a[i] + b[i];
    chmin(ans, s + (x - i - 1) * b[i]);
  }
  wt(ans);
}
