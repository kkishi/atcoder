#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  V<int> v(m);
  rep(i, 1, n + 1)++ v[i % m];
  vector dp(n + 1, mint(0));
  dp[0] = 1;
  each(e, v) {
    vector ndp(n + 1, mint(0));
    rep(i, n + 1) {
      if (dp[i] == 0) continue;
      for (int g = max(0, e - i); g <= e; ++g) {
        ndp[i + g] += dp[i] * mint::Perm(i, e - g) * mint::Comb(e, g);
      }
    }
    swap(dp, ndp);
  }
  rep(i, n) wt(dp[i + 1]);
}
