#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> d(n);
  cin >> d;

  int N = 100000;
  V<int> dn(N + 1);
  for (int di : d) ++dn[di];

  V<mint> dp(N * 2 + 1);
  dp[1] = 1;
  mint ans = 0;
  rep(I, 4) {
    V<mint> ndp(N * 2 + 1);
    mint x = 0;
    rep(i, N + 1) {
      x += dp[i];
      ndp[i * 2] += x * dn[i];
      if (I == 3) ans += x * dn[i];
    }
    dp = ndp;
  }
  wt(ans);
}
