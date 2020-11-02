#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;

  mint sum = 0;
  rep(i, n) sum += a[i];

  mint x = 1;
  V<int> b(n, 1);
  rep(i, k) {
    x *= sum;
    rep(j, n) b[j] *= a[j];
    mint y = 0;
    rep(j, n) y += b[j];
    wt(x + y);
  }
}
