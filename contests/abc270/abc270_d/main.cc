#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(k);
  cin >> a;
  V<pair<int, int>> dp(n + 1);
  rep(i, n + 1) {
    int X = 0;
    int Y = i;
    each(e, a) if (e <= i) {
      auto [x, y] = dp[i - e];
      y += e;
      if (y > X) {
        X = y;
        Y = x;
      }
    }
    dp[i] = {X, Y};
  }
  wt(dp[n].first);
}
