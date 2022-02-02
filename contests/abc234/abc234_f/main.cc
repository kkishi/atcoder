#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(s);
  map<char, int> m;
  each(e, s)++ m[e];
  int n = sz(s);
  V<mint> dp(n + 1);
  dp[0] = 1;
  each(_, e, m) {
    V<mint> ndp(n + 1);
    rep(i, n + 1 - e) rep(j, e + 1) ndp[i + j] += dp[i] * mint::Comb(i + j, i);
    swap(dp, ndp);
  }
  wt(accumulate(all(dp), mint(0)) - 1);
}
