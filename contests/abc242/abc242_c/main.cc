#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  vector dp(n, vector(11, mint(0)));
  rep(i, 1, 10) dp[0][i] = 1;
  rep(i, 1, n) rep(j, 1, 10) rep(k, -1, 2) dp[i][j + k] += dp[i - 1][j];
  mint ans = 0;
  rep(i, 1, 10) ans += dp[n - 1][i];
  wt(ans);
}
