#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, x, y, z);
  mint ans = 0;
  rep(i, n + 1) {
    int a = i + abs(z);
    if (!even(a)) continue;
    mint Z = mint::Comb(i, a / 2);
    int j = n - i;
    int x2 = abs(x - y);
    int b = j + x2;
    if (!even(b)) continue;
    int y2 = abs(x + y);
    int c = j + y2;
    if (!even(c)) continue;
    mint XY = mint::Comb(j, b / 2) * mint::Comb(j, c / 2);
    ans += Z * XY * mint::Comb(n, i);
  }
  wt(ans);
}
