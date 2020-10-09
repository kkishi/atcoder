#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> h(n);
  cin >> h;
  const int inf = numeric_limits<int>::max() / 10;
  V<int> dp(n, inf);
  dp[0] = 0;
  rep(i, 1, n) rep(j, k) {
    int l = i - 1 - j;
    if (l < 0) continue;
    chmin(dp[i], dp[l] + abs(h[i] - h[l]));
  }
  wt(dp[n - 1]);
}
