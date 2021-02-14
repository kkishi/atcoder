#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<bool> x(l + 1);
  rep(n) {
    ints(xi);
    x[xi] = true;
  }
  ints(t1, t2, t3);
  V<int> dp(l + 10, big);
  dp[0] = 0;
  rep(i, l) {
    chmin(dp[i + 1], dp[i] + t1 + x[i + 1] * t3);
    chmin(dp[i + 2], dp[i] + t1 + t2 + x[i + 2] * t3);
    chmin(dp[i + 4], dp[i] + t1 + t2 * 3 + x[i + 4] * t3);
    if (i + 3 >= l) {
      int d = l - i;
      // 0.5 * t1 + (d - 0.5) * t2
      // (t1 / 2) + (d * 2 - 1) * (t2 / 2)
      chmin(dp[l], dp[i] + (t1 / 2) + (d * 2 - 1) * (t2 / 2));
    }
  }
  wt(dp[l]);
}
