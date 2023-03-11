#include <bits/stdc++.h>

#include "atcoder.h"
#include "convex_hull_trick.h"

void Main() {
  ints(n, c);
  V<int> h(n);
  cin >> h;
  V<int> dp(n);
  MinMonotoneConvexHullTrick cht;
  // dp[i] = min(dp[j] + (h[i] - h[j])^2 + c)
  //       = min(-2 * h[j] * h[i] + dp[j] + h[j]^2) + h[i]^2 + c
  rep(i, 1, n) {
    cht.Add(-2 * h[i - 1], dp[i - 1] + h[i - 1] * h[i - 1]);
    dp[i] = cht.Get(h[i]) + h[i] * h[i] + c;
  }
  wt(dp[n - 1]);
}
