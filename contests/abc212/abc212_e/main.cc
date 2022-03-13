#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  VV<int> g(n);
  rep(i, n) g[i].pb(i);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<mint> dp(n);
  dp[0] = 1;
  rep(k) {
    V<mint> ndp(n);
    mint sum = accumulate(dp);
    rep(i, n) {
      mint sub = 0;
      each(e, g[i]) sub += dp[e];
      ndp[i] = sum - sub;
    }
    swap(dp, ndp);
  }
  wt(dp[0]);
}
