#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, p);
  V<mint> dp(n + 1);
  dp[1] = 1;
  mint two = mint(p) / 100;
  mint one = 1 - two;
  rep(i, 2, n + 1) dp[i] = 1 + two * dp[i - 2] + one * dp[i - 1];
  wt(dp[n]);
}
