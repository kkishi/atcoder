#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int dp[87];
  dp[0] = 2;
  dp[1] = 1;
  rep(i, 2, 87) dp[i] = dp[i - 1] + dp[i - 2];
  ints(n);
  wt(dp[n]);
}
