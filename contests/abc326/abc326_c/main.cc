#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  sort(a);
  int r = 0;
  int ans = -big;
  rep(l, n) {
    while (r < n && (a[r] - a[l]) < m) ++r;
    chmax(ans, r - l);
  }
  wt(ans);
}
