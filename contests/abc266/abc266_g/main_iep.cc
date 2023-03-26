#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(r, g, b, k);
  mint ans = 0;
  int x = k;
  r -= k;
  g -= k;
  rep(i, 0, min(r, g) + 1) {
    int y = i;
    int R = r - i;
    int G = g - i;
    auto f = mint::Fact;
    mint cnt = f(R + G + b + x + y) / (f(R) * f(G) * f(b) * f(x) * f(y));
    if (!even(i)) cnt = -cnt;
    ans += cnt;
  }
  wt(ans);
}
