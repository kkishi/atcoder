#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w, n);
  V<pair<int, int>> p(n);
  cin >> p;
  p.eb(h, w);
  sort(p);
  V<mint> dp(n + 1);
  rep(i, n + 1) {
    auto [ri, ci] = p[i];
    auto f = [&](int dr, int dc) { return mint::Comb(dr + dc, dr); };
    dp[i] = f(ri - 1, ci - 1);
    rep(j, i) {
      auto [rj, cj] = p[j];
      dp[i] -= dp[j] * f(ri - rj, ci - cj);
    }
  }
  wt(dp[n]);
}
