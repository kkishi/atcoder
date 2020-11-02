#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(x, y);
  if ((x + y) % 3) {
    wt(0);
    return;
  }
  int n = (2 * y - x) / 3;
  int m = (2 * x - y) / 3;
  if (n < 0 || m < 0) {
    wt(0);
    return;
  }
  wt(mint::Comb(n + m, m));
}
