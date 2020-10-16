#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  mint ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += m * mint(m - 1).Pow(n - 1 - i) * mint::Comb(n - 1, i);
  }
  wt(ans);
}
