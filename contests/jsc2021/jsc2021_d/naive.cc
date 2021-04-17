#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, p);
  V<mint> dp(p);
  rep(i, 1, p) dp[i] = 1;
  rep(n - 1) {
    V<mint> ndp(p);
    rep(i, 1, p) rep(j, 1, p) ndp[(i + j) % p] += dp[i];
    swap(dp, ndp);
    dbg(dp);
  }
  mint ans = accumulate(all(dp), mint(0)) - dp[0];
  wt(ans);
}
