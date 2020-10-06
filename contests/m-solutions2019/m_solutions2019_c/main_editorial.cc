#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, a, b, c);
  mint A = 0;
  mint B = 0;
  mint pa = a / mint(a + b);
  mint pb = b / mint(a + b);
  rep(i, n) {
    A += pa.Pow(n) * pb.Pow(i) * mint::Comb(n - 1 + i, i) * (n + i);
    B += pb.Pow(n) * pa.Pow(i) * mint::Comb(n - 1 + i, i) * (n + i);
  }
  wt((A + B) * 100 / mint(100 - c));
}
