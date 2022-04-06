#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, a, b, c);
  mint ans = 0;
  mint A = 1, B = 1, C = 1;
  rep(i, n + 1) {
    mint x = A * B * C * mint::Comb(n, i);
    if (!even(n - i)) x = -x;
    ans += x;
    A = A * 2 - mint::Comb(i, a);
    B = B * 2 - mint::Comb(i, b);
    C = C * 2 - mint::Comb(i, c);
  }
  wt(ans);
}
