#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<double> dp(n + 1);
  rep(i, 1, n + 1) rep(j, 1, 7) dp[i] += max(j, dp[i - 1]) / 6.0;
  wt(dp[n]);
}
