#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  int r = n - k;
  for (int i = 1; i <= k; ++i) {
    if (i > r + 1) {
      wt(0);
    } else {
      wt(mint::Comb(k - 1, (i - 1)) * mint::Comb(r + 1, i));
    }
  }
}
