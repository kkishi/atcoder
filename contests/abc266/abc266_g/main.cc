// This doesn't AC yet.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(r, g, b, k);
  int n = r + g + b;
  auto f = [&](int k) -> mint {
    int rem = n - 2 * k;
    int R = r - k;
    int G = g - k;
    if (R < 0 || G < 0) return 0;
    return mint::Comb(rem + k, k) * mint::Comb(rem, R) * mint::Comb(rem - R, G);
  };
  int mi = min(r, g);
  V<mint> dp(mi + 1);
  rrep(i, mi + 1) {
    mint x = f(i);
    rep(j, i + 1, mi + 1) x -= dp[j] * mint::Comb(j, i);
    dp[i] = x;
  }
  wt(dp[k]);
}
