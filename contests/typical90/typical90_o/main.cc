#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  rep(k, 1, n + 1) {
    mint ans = 0;
    for (int i = 1; i + (i - 1) * (k - 1) <= n; ++i) {
      ans += mint::Comb(n - (i - 1) * k + (i - 1), i);
    }
    wt(ans);
  }
}
