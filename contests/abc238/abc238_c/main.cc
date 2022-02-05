#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  mint ans = mint(n) * (n + 1) / 2;
  for (int t = 1; t <= n; t *= 10) {
    ans -= (t - 1) * mint(min(n - t + 1, 9 * t));
  }
  wt(ans);
}
