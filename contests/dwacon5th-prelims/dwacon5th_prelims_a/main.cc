#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(all(a), 0LL);
  int ans, diff = numeric_limits<int>::max();
  rep(i, n) if (chmin(diff, abs(sum - a[i] * n))) ans = i;
  wt(ans);
}
