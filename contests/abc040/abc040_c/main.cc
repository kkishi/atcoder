#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> dp(n, big);
  dp[0] = 0;
  rep(i, n) rep(j, i - 2, i) if (j >= 0) {
    chmin(dp[i], dp[j] + abs(a[i] - a[j]));
  }
  wt(dp[n - 1]);
}
