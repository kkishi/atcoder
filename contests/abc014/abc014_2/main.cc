#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) if ((x >> i) & 1) ans += a[i];
  wt(ans);
}
