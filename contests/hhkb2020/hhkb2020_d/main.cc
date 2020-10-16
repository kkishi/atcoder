#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Solve() {
  ints(n, a, b);
  auto sq = [](mint x) { return x * x; };
  mint A = n - a + 1, B = n - b + 1;
  wt(sq(A) * sq(B) - sq(A * B - 2 * mint::CombSlow(n - (a + b) + 2, 2)));
}

void Main() {
  ints(t);
  rep(t) Solve();
}
