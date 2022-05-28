#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  if (k == 0) {
    wt(mint(m).Pow(n));
    return;
  }
  V<mint> dp(m + 1);
  rep(i, 1, m + 1) dp[i] = 1;
  rep(n - 1) {
    V<mint> ldp = dp, rdp = dp;
    rep(i, 2, m + 1) ldp[i] += ldp[i - 1];
    rrep(i, 1, m) rdp[i] += rdp[i + 1];
    V<mint> ndp(m + 1);
    rep(i, 1, m + 1) {
      if (i - k >= 1) ndp[i] += ldp[i - k];
      if (i + k <= m) ndp[i] += rdp[i + k];
    }
    swap(dp, ndp);
  }
  wt(accumulate(dp));
}
