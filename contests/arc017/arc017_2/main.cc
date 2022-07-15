#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  V<int> x;
  x.pb(0);
  rep(i, n - 1) if (a[i] >= a[i + 1]) x.pb(i + 1);
  x.pb(n);
  int ans = 0;
  rep(i, sz(x) - 1) ans += max(0, x[i + 1] - x[i] - k + 1);
  wt(ans);
}
