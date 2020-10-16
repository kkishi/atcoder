#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> x(n);
  cin >> x;
  int ans = 0;
  rep(i, n) ans += min(x[i], k - x[i]) * 2;
  wt(ans);
}
