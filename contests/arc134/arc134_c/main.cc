#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int s = accumulate(a) - a[0];
  mint x = 1;
  rep(i, 1, n) x *= mint::CombSlow(a[i] + k - 1, k - 1);
  wt(x * mint::CombSlow(a[0] - s - k + (k - 1), k - 1));
}
