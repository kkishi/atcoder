#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) if (hasbit(x, i)) ans += a[i];
  wt(ans);
}
