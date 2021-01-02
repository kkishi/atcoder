#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> h(n);
  cin >> h;
  V<int> dp(n, big);
  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);
  rep(i, 2, n) rep(j, 2) chmin(dp[i], dp[i - 1 - j] + abs(h[i] - h[i - 1 - j]));
  wt(dp[n - 1]);
}
