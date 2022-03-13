#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  strings(s);
  vector dp(n, vector(n, mint(0)));
  dp[0][0] = 1;
  rep(i, 1, n) {
    V<mint> cum = dp[i - 1];
    if (s[i - 1] == '<') {
      rep(j, i) cum[j + 1] += cum[j];
    } else {
      rrep(j, i) cum[j] += cum[j + 1];
    }
    rep(j, i + 1) {
      if (s[i - 1] == '<') {
        if (j > 0) dp[i][j] += cum[j - 1];
        // rep(k, j) dp[i][j] += dp[i - 1][k];
      } else {
        dp[i][j] += cum[j] - cum[i];
        // rep(k, j + 1, i + 1) dp[i][j] += dp[i - 1][k - 1];
      }
    }
  }
  wt(accumulate(dp[n - 1]));
}
