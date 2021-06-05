#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<int> c;
  rep(i, n) {
    c.pb(b[i]);
    c.pb(a[i] - b[i]);
  }
  sort(all(c), greater{});
  int ans = 0;
  rep(i, k) ans += c[i];
  wt(ans);
}
