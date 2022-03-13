#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  cin >> a;
  a.pb(0);
  a.pb(n + 1);
  sort(a);
  int mini = n;
  rep(i, sz(a) - 1) {
    int d = a[i + 1] - a[i] - 1;
    if (d > 0) chmin(mini, d);
  }
  int ans = 0;
  rep(i, sz(a) - 1) {
    int d = a[i + 1] - a[i] - 1;
    if (d > 0) ans += div_ceil(d, mini);
  }
  wt(ans);
}
