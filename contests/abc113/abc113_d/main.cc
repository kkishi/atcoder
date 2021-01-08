#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w, k);
  vector<vector<mint>> dp(h + 1, vector<mint>(w));
  dp[0][0] = 1;
  rep(i, h) rep(s, 1 << (w - 1)) {
    auto connected = [&s](int x) { return hasbit(s, x); };
    bool ok = true;
    rep(j, w - 2) if (connected(j) && connected(j + 1)) ok = false;
    if (!ok) continue;
    vector<mint> tmp = dp[i];
    rep(j, w - 1) if (connected(j)) swap(tmp[j], tmp[j + 1]);
    rep(j, w) dp[i + 1][j] += tmp[j];
  }
  wt(dp[h][k - 1]);
}
