#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  sort(all(a));

  mint ans = 0;
  rep(i, n - (k - 1)) ans -= a[i] * mint::Comb(n - 1 - i, k - 1);
  for (int i = n - 1; i >= (k - 1); --i) {
    ans += a[i] * mint::Comb(i, k - 1);
  }
  wt(ans);
}
