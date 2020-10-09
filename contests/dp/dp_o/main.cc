#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n));
  cin >> a;
  VV<mint> dp(n + 1, V<mint>(1 << n));
  dp[0][0] = 1;
  rep(s, 1 << n) {
    int i = popcount(s);
    rep(j, n) if (int b = 1 << j; !(s & b) && a[i][j]) {
      dp[i + 1][s | b] += dp[i][s];
    }
  }
  wt(dp[n][(1 << n) - 1]);
}
