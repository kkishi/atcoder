#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  mint ans = 0;
  rep(k, 1, n * n + 1) {
    vector dp(n, vector(n, mint(0)));
    rep(i, n) rep(j, n) {
      if (a[i][j] == k) {
        ++dp[i][j];
        ans += dp[i][j];
      }
      if (i + 1 < n) dp[i + 1][j] += dp[i][j];
      if (j + 1 < n) dp[i][j + 1] += dp[i][j];
    }
  }
  wt(ans);
}
