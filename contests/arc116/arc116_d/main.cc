#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  int N = 12;
  vector dp(N + 1, vector(m + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, N) {
    rep(j, m + 1) {
      if (dp[i][j] == 0) continue;
      rep(k, div_ceil(n, 2) + 1) {
        int nj = j + ((k * 2) << (N - 1 - i));
        if (nj <= m) {
          dp[i + 1][nj] += dp[i][j] * mint::Comb(n, k * 2);
        }
      }
    }
  }
  wt(dp[N][m]);
}
