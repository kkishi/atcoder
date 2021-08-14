#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(s);
  int n = sz(s);
  vector next(n + 2, vector(26, int(-1)));
  rrep(i, n) {
    next[i] = next[i + 1];
    next[i][s[i] - 'a'] = i;
  }
  vector dp(n + 2, mint(0));
  dp[0] = 1;
  mint ans = 0;
  rep(i, n) {
    rep(j, 26) {
      int k = next[(i == 0 ? 0 : i + 1)][j];
      if (k >= 0) dp[k + 1] += dp[i];
    }
  }
  rep(i, n) ans += dp[i + 1];
  wt(ans);
}
