#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> dp(n + 1, -big);
  dp[0] = 0;
  rep(n) {
    ints(p);
    rrep(i, 1, n) if (dp[i - 1] != -big) chmax(dp[i], dp[i - 1] - p);
    rep(i, n - 1) if (dp[i + 1] != -big) chmax(dp[i], dp[i + 1] + p);
  }
  wt(dp[0]);
}
