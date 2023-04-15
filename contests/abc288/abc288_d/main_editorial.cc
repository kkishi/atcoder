#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, k);
  V<int> a(n + 2);
  rep(i, n) cin >> a[i + 1];
  V<int> b(n + 1);
  rep(i, n + 1) b[i] = a[i + 1] - a[i];

  V<CumulativeSum1D<int>> cs;
  rep(i, k) {
    V<int> v;
    for (int j = i; j < sz(b); j += k) v.eb(b[j]);
    cs.eb(CumulativeSum1D(v));
  }

  ints(q);
  rep(q) {
    ints(l, r);

    bool ok = true;
    rep(i, k) {
      // l - 1 <= i + j * k <= r
      // L <= j <= R
      int L = div_ceil(l - 1 - i, k);
      int R = div_floor(r - i, k);
      int sum = L > R ? 0 : cs[i].Get(L, R);
      if (i == (l - 1) % k) sum += a[l - 1];
      if (i == r % k) sum -= a[r + 1];
      if (sum != 0) ok = false;
    }
    wt(ok);
  }
}
