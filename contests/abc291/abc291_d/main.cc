#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  vector a(n, vector(2, int(0)));
  rep(i, n) rep(j, 2) cin >> a[i][j];
  vector dp(n, vector(2, mint(0)));
  dp[0][0] = dp[0][1] = 1;
  rep(i, 1, n) rep(j, 2) rep(k, 2) {
    if (a[i - 1][j] != a[i][k]) dp[i][k] += dp[i - 1][j];
  }
  wt(accumulate(dp[n - 1]));
}
