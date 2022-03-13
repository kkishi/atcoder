#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, K);
  V<int> w(n);
  cin >> w;
  mint s = accumulate(w);

  vector dp(K + 1, vector(n + 1, vector(n + 1, mint(0))));
  dp[0][0][0] = 1;
  rep(i, K + 1) rep(j, n) rep(k, n) rep(l, K + 1 - i) {
    dp[i + l][j + 1][k + (l > 0)] +=
        dp[i][j][k] / mint::Fact(l) * (w[j] / s).Pow(l);
  }
  wt(dp[K][n][m] * mint::Fact(K));
}
