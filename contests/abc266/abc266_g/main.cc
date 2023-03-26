#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(r, g, b, k);
  int x = k;
  r -= k;
  g -= k;
  auto f = mint::Fact;
  mint ans = f(r + b + x) / (f(r) * f(b) * f(x));
  ans *= mint::Comb(b + x + g, g);
  wt(ans);
}
