#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  vector dp(n + 1, vector(n + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) rep(j, n) dp[i + 1][j + 1] =
      dp[i][j] + max(0, j + 1 - i / m) * dp[i][j + 1];
  rep(i, n) wt(dp[n][i + 1]);
}
