#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  vector dp(n + 1, vector(m + 1, mint(0)));
  rep(i, n) rep(j, m) {
    if (i == 0) {
      dp[i + 1][j] = 1;
    } else {
      rep(k, j + 1, m + 1) if (j % 3 != k % 3) dp[i + 1][k] += dp[i][j];
    }
  }
  wt(accumulate(dp[n]));
}
