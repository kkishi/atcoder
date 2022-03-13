#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int maxa = *max_element(all(a));
  sort(b, greater{});
  int ans = big;
  int damage = 0;
  rep(i, n + 1) {
    if (i) damage += b[i - 1];
    chmin(ans, i + div_ceil(max(0, h - damage), maxa));
  }
  wt(ans);
}
