#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<mint> dp(10);
  dp[a[0]] = 1;
  rep(i, 1, n) {
    V<mint> ndp(10);
    rep(j, 10) {
      ndp[(j + a[i]) % 10] += dp[j];
      ndp[(j * a[i]) % 10] += dp[j];
    }
    swap(dp, ndp);
  }
  each(e, dp) wt(e);
}
