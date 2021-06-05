#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(K);
  vector dp(K + 100, vector(9, mint(0)));
  dp[0][0] = 1;
  rep(i, K) rep(j, 9) rep(k, 1, 10) dp[i + k][(j * 10 + k) % 9] += dp[i][j];
  wt(dp[K][0]);
}
