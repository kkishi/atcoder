#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;

  V<int> gt(n);
  rep(i, n) rep(j, n) if (a[j] > a[i])++ gt[i];

  mint ans = 0;
  rep(i, 0, n) {
    mint x = 0;
    rep(j, i) if (a[j] > a[i])++ x;
    ans += x * k + gt[i] * mint(k) * mint(k - 1) / 2;
  }
  wt(ans);
}
