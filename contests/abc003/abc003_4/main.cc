#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(r, c, x, y, d, l);
  auto f = [&](int i, int j) -> mint {
    if (i <= 0 || j <= 0) return 0;
    if (i * j < d + l) return 0;
    return mint::Comb(i * j, d) * mint::Comb(i * j - d, l);
  };
  mint ans = 0;
  rep(u, 2) rep(d, 2) rep(l, 2) rep(r, 2) {
    mint sign = even(u + d + l + r) ? 1 : -1;
    ans += f(x - u - d, y - l - r) * sign;
  }
  wt(ans * (r - x + 1) * (c - y + 1));
}
