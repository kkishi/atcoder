#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(K);
  ints(d);
  vector dp(sz(K) + 1, vector(2, vector(d, mint(0))));
  dp[0][0][0] = 1;
  rep(i, sz(K)) rep(j, 2) rep(k, d) rep(l, 10) {
    int m = (k + l) % d;
    int n = K[i] - '0';
    int o = j ? 1 : l < n ? 1 : l == n ? 0 : -1;
    if (o == -1) continue;
    dp[i + 1][o][m] += dp[i][j][k];
  }
  mint ans = -1;
  rep(i, 2) ans += dp[sz(K)][i][0];
  wt(ans);
}
