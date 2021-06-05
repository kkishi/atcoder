#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, b, k);
  V<int> c(k);
  cin >> c;
  vector dp(61, vector(b, mint(0)));
  rep(i, k)++ dp[0][c[i] % b];
  V<int> pow10(61);  // pow10[i] = 10^(2^i)
  pow10[0] = 10 % b;
  rep(i, 60) pow10[i + 1] = pow10[i] * pow10[i] % b;
  rep(i, 60) rep(r1, b) rep(r2, b) {
    dp[i + 1][(r1 * pow10[i] + r2) % b] += dp[i][r1] * dp[i][r2];
  }
  vector dp2(b, mint(0));
  dp2[0] = 1;
  rep(i, 61) if (hasbit(n, i)) {
    vector ndp(b, mint(0));
    rep(r1, b) rep(r2, b) {
      ndp[(r1 * pow10[i] + r2) % b] += dp2[r1] * dp[i][r2];
    }
    swap(dp2, ndp);
  }
  wt(dp2[0]);
}
