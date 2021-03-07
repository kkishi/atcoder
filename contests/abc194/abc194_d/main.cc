#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<double> dp(n + 1);
  rrep(i, n) dp[i] = double(n) / (n - i) + dp[i + 1];
  wt(dp[1]);
}
