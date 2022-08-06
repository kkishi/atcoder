#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  V<int> dp(3, big);
  dp[0] = 0;
  rep(i, n) {
    V<int> ndp(3);
    ndp[0] = dp[0] + l;
    ndp[1] = min(dp[0], dp[1]) + a[i];
    ndp[2] = min(dp) + r;
    swap(dp, ndp);
  }
  wt(min(dp));
}
