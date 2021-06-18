#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m, k);
  if (n > m + k) {
    wt(0);
  } else {
    wt(mint::Comb(n + m, n) - mint::Comb(n + m, n - k - 1));
  }
}
