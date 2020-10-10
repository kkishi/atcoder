#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Solve() {
  ints(n, a, b);
  if (a + b > n) {
    wt(0);
    return;
  }
  mint A = n - a + 1, B = n - b + 1;
  mint tot = A * A * B * B;
  mint X = min(a, b) - 1;
  mint Y = n + 1 - (a + b - 1);
  mint Z = (X * Y + X * (X - 1) / 2) * 2;
  mint W = mint(n + 1 - max(a, b)) * (abs(a - b) + 1);
  mint C = Z + W;
  wt(tot - C * C);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
