#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  vector a(n, vector(n, 0));
  cin >> a;
  VV<mint> dp(n, V<mint>(n));
  rep(i, n) dp[i][i] = 1;
  V<int> op;
  while (k) {
    if (k & 1) {
      op.pb(0);
      --k;
    } else {
      op.pb(1);
      k /= 2;
    }
  }
  rrep(i, sz(op)) {
    VV<mint> ndp(n, V<mint>(n));
    if (op[i] == 0) {
      rep(i, n) rep(j, n) if (a[i][j]) rep(k, n) ndp[i][k] += dp[j][k];
      --k;
    } else {
      rep(i, n) rep(j, n) rep(k, n) ndp[i][k] += dp[i][j] * dp[j][k];
      k /= 2;
    }
    swap(dp, ndp);
  }
  mint ans = 0;
  rep(i, n) rep(j, n) ans += dp[i][j];
  wt(ans);
}
