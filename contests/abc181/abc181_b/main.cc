#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = 0;
  rep(i, n) {
    ans += b[i] * (b[i] + 1) / 2;
    ans -= a[i] * (a[i] - 1) / 2;
  }
  wt(ans);
}
