#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  a.erase(unique(all(a)), a.end());
  n = sz(a);
  wt(Fix([&](auto rec, int l, int r, int bit) {
    if (bit < 0) return 0;
    auto f = [&](int i) { return hasbit(a[i], bit); };
    if (f(l) == f(r - 1)) return rec(l, r, bit - 1);
    int m;
    rep(i, l + 1, r) if (f(i - 1) != f(i)) m = i;
    return (1 << bit) + min(rec(l, m, bit - 1), rec(m, r, bit - 1));
  })(0, n, 30));
}
