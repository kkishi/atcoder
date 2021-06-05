#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  strings(s);
  string atcoder = "atcoder";
  V<mint> dp(sz(atcoder) + 1);
  dp[0] = 1;
  rep(i, n) {
    V<mint> ndp = dp;
    rep(j, sz(atcoder)) {
      if (s[i] == atcoder[j]) {
        ndp[j + 1] += dp[j];
      }
    }
    swap(dp, ndp);
  }
  wt(dp[sz(atcoder)]);
}
