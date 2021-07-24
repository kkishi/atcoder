#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(s);
  int n = sz(s);
  string c = "chokudai";
  int m = sz(c);
  vector dp(n + 1, vector(m + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    dp[i + 1] = dp[i];
    rep(j, m) {
      if (s[i] == c[j]) {
        dp[i + 1][j + 1] += dp[i][j];
      }
    }
  }
  wt(dp[n][m]);
}
