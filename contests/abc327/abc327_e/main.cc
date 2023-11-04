#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  vector dp(n + 1, double(0));
  rep(i, n) rrep(j, i + 1) chmax(dp[j + 1], dp[j] * 0.9 + p[i]);
  double ans = -big;
  double q = 0;
  rep(i, 1, n + 1) {
    q = q * 0.9 + 1;
    chmax(ans, dp[i] / q - 1200 / sqrt(i));
  }
  wt(ans);
}
