#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);

  auto f = [&](auto& dp, int l) {
    rep(i, k) {
      dp[i + 1][1] = dp[i][0];
      dp[i + 1][0] = dp[i][0] * (l - 2) + dp[i][1] * (l - 1);
    }
  };

  vector xdp(k + 1, array<mint, 2>());
  xdp[0][x1 == x2] = 1;
  f(xdp, h);

  vector ydp(k + 1, array<mint, 2>());
  ydp[0][y1 == y2] = 1;
  f(ydp, w);

  mint ans = 0;
  rep(xs, k + 1) {
    int ys = k - xs;
    ans += xdp[xs][1] * ydp[ys][1] * mint::Comb(k, xs);
  }
  wt(ans);
}
