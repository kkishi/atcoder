#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, l);
  V<mint> dp(n + 1);
  dp[0] = 1;
  rep(i, n) {
    dp[i + 1] += dp[i];
    if (int j = i + 1 - l; j >= 0) dp[i + 1] += dp[j];
  }
  wt(dp[n]);
}
