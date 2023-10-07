#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, x);
  vector dp(x + 1, mint(0));
  dp[0] = 1;
  V<int> t(n);
  cin >> t;
  mint y = 1 / mint(n);
  mint ans = 0;
  rep(i, x + 1) {
    if (i + t[0] > x) {
      ans += dp[i] * y;
    }
    rep(j, n) {
      if (i + t[j] <= x) {
        dp[i + t[j]] += dp[i] * y;
      }
    }
  }
  wt(ans);
}
