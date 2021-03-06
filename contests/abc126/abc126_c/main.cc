#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<double> dp(max(k, n) + 1);
  for (int i = max(k, n); i >= 1; --i) {
    if (i >= k) {
      dp[i] = 1;
    } else {
      int ii = i + i;
      dp[i] = (ii >= k ? 1 : dp[ii]) / 2;
    }
  }
  double p = 0;
  for (int i = 1; i <= n; ++i) {
    p += dp[i] / n;
  }
  wt(p);
}
