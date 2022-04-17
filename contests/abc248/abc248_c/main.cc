#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, K);
  vector dp(n + 1, vector(K + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, K + 1) {
      rep(k, 1, m + 1) {
        if (j + k <= K) dp[i + 1][j + k] += dp[i][j];
      }
    }
  }
  wt(accumulate(dp[n]));
}
