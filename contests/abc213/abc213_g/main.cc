#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(a, b);
    g[a - 1].pb(b - 1);
  }
  vector G(1 << n, mint(0));
  rep(mask, 1 << n) {
    int cnt = 0;
    rep(i, n) if (hasbit(mask, i)) each(j, g[i]) if (hasbit(mask, j))++ cnt;
    G[mask] = mint(2).Pow(cnt);
  }
  vector F(1 << n, mint(0));
  rep(mask, 1 << n) {
    F[mask] = G[mask];
    int i = __builtin_ctz(mask);
    for (int submask = (mask - 1) & mask; submask > 0;
         submask = (submask - 1) & mask) {
      if (hasbit(submask, i)) F[mask] -= F[submask] * G[mask ^ submask];
    }
  }
  V<mint> ans(n);
  rep(mask, 1 << n) rep(i, n) if (hasbit(mask, 0) && hasbit(mask, i)) ans[i] +=
      F[mask] * G[((1 << n) - 1) ^ mask];
  rep(i, 1, n) wt(ans[i]);
}
