#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  vector dp(n, vector(2, mint(0)));
  dp[0][1] = m;
  rep(i, 1, n) {
    dp[i][0] += dp[i - 1][0] * (m - 2) + dp[i - 1][1] * (m - 1);
    dp[i][1] += dp[i - 1][0];
  }
  wt(dp[n - 1][0]);
}
