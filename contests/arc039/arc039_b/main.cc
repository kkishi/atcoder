#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  if (k < n) {
    // Stars and bars
    wt(mint::Comb(n + k - 1, n - 1));
  } else {
    wt(mint::Comb(n, k % n));
  }
}
