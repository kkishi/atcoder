#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(r, g, b, k, x, y, z);
  if (max({r, g, b}) <= 5 && k <= min(5, r + g + b)) {
    mint ans = 0;
    rep(R, r + 1) rep(G, g + 1) rep(B, b + 1) {
      if (R + G <= x && G + B <= y && B + R <= z && R + G + B == k) {
        ans += mint::Comb(r, R) * mint::Comb(g, G) * mint::Comb(b, B);
      }
    }
    wt(ans);
  } else if (max({r, g, b}) <= 3000 && k <= min(3000, r + g + b)) {
    mint ans = 0;
    rep(R, r + 1) rep(G, g + 1) {
      int B = k - (R + G);
      if (B < 0) continue;
      if (R + G <= x && G + B <= y && B + R <= z && R + G + B == k) {
        ans += mint::Comb(r, R) * mint::Comb(g, G) * mint::Comb(b, B);
      }
    }
    wt(ans);
  }
}
