#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  mint ans = 0;
  rep(i, 60) {
    int ones = 0;
    rep(j, n) if ((a[j] >> i) & 1)++ ones;
    ans += ones * (n - ones) * mint(2).Pow(i);
  }
  wt(ans);
}
