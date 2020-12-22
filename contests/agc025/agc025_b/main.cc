#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, a, b, k);
  mint ans = 0;
  rep(i, n + 1) {
    int x = k - a * i;
    if (x >= 0 && x % b == 0) {
      int j = x / b;
      if (j <= n) {
        ans += mint::Comb(n, i) * mint::Comb(n, j);
      }
    }
  }
  wt(ans);
}
