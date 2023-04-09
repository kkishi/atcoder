#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(h, w, k);
  auto C = [&](int r, int c) { return mint::Comb(r * c, k); };
  mint ans = 0;
  rep(i, h) rep(j, w) {
    mint A = C(h, w);
    int t = i, b = h - 1 - i;
    int l = j, r = w - 1 - j;
    mint ng = C(h, l) + C(h, r) + C(w, t) + C(w, b);
    ng -= C(t, l) + C(t, r) + C(b, l) + C(b, r);
    ans += (A - ng) / A;
  }
  wt(ans);
}
