#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> a(2, V<int>(n));
  cin >> a;
  VV<int> dp(3, V<int>(n + 1));
  rep(i, 2) rep(j, n) dp[i + 1][j + 1] =
      max(dp[i][j + 1], dp[i + 1][j]) + a[i][j];
  wt(dp[2][n]);
}
