#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  vector dp(62, vector(61, vector(61, mint(0))));
  dp[0][0][0] = 1;
  rep(i, 60) rep(j, 60) rep(k, 60) {
    mint d = dp[i][j][k] / 5;
    if (d == 0) continue;
    dp[i + 1][j][k] += d;
    dp[i][j + 1][k] += d;
    dp[i + 2][j][k] += d;
    dp[i][j][k + 1] += d;
    dp[i + 1][j + 1][k] += d;
  }
  ints(n);
  int i = 0, j = 0, k = 0;
  while (n % 2 == 0) ++i, n /= 2;
  while (n % 3 == 0) ++j, n /= 3;
  while (n % 5 == 0) ++k, n /= 5;
  if (n > 1) {
    wt(0);
  } else {
    wt(dp[i][j][k]);
  }
}
