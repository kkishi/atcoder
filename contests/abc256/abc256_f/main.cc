#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  BIT<mint> i2(n), i1(n), i0(n);
  auto set = [&](int i) {
    // Use mint(i) to avoid the overflow.
    i2.Set(i, mint(i) * i * a[i]);
    i1.Set(i, i * a[i]);
    i0.Set(i, a[i]);
  };
  rep(i, n) set(i);
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x, v);
      --x;
      a[x] = v;
      set(x);
    } else {
      ints(x);
      --x;
      wt(i2.Sum(x) / 2 - i1.Sum(x) * (2 * x + 3) / 2 +
         i0.Sum(x) * (x + 1) * (x + 2) / 2);
    }
  }
}
