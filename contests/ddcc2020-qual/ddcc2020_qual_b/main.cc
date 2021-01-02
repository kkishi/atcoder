#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int tot = accumulate(all(a), 0LL);
  int sum = 0;
  int ans = big;
  rep(i, n) {
    sum += a[i];
    chmin(ans, abs(sum - (tot - sum)));
  }
  wt(ans);
}
