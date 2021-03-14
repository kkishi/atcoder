#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  mint sum = 0;
  vector dp(m + 1, vector(n + 1, vector(2, mint(0))));
  rep(mi, 1, m + 1) {
    auto& DP = dp[mi];
    DP[0][0] = 1;
    rep(i, n) {
      DP[i + 1][0] = DP[i][0] * (m - 1) + DP[i][1] * (mi - 1);
      DP[i + 1][1] = DP[i][0] + DP[i][1] * (m - mi + 1);
      dbg(mi, i, DP[i + 1]);
    }
  }

  rep(i, n - 1) rep(j, i + 1, n) {
    int r = n - 1 - j;
    int mid = j - i - 1;
    mint s = 0;
    for (int k = 1; k <= m; ++k) {
      mint x = mint(m - k + 1).Pow(mid);
      dbg(i, j, k, x);
      s += dp[k][i][0] * x;
    }
    sum += mint(m).Pow(r) * s;
  }
  mint tot = mint(m).Pow(n) * n;
  dbg(tot, sum);
  wt(tot - sum);
}
