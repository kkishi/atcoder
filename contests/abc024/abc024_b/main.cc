#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n - 1) ans += min(t, a[i + 1] - a[i]);
  wt(ans + t);
}
