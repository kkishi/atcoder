#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);

  // p[i] = m^i
  V<mint> p(n + 1);
  p[0] = 1;
  rep(i, n) p[i + 1] = p[i] * m;

  mint sum = 0;
  rep(M, 1, m + 1) rep(l, 2, n + 1) {
    sum += p[n - l] * (n - l + 1) * mint(m - M).Pow(l - 2);
  }
  wt(p[n] * n - sum);
}
