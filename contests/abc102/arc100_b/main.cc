#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  V<int> l(n);
  rep(i, n) l[i] = a[i] + (i > 0 ? l[i - 1] : 0);
  V<int> r(n);
  rrep(i, n) r[i] = a[i] + (i < n - 1 ? r[i + 1] : 0);

  int ans = big;
  rep(i, 1, n - 2) {
    int ls = l[i];
    int li = BinarySearch<int>(0, i, [&](int i) { return l[i] <= ls / 2; });
    int rs = r[i + 1];
    int ri =
        BinarySearch<int>(n - 1, i + 1, [&](int i) { return r[i] <= rs / 2; });
    rep(ld, -1, 2) rep(rd, -1, 2) {
      int lid = li + ld, rid = ri + rd;
      if (lid < 0 || i <= lid || rid <= i + 1 || n - 1 < rid) continue;
      int l1 = l[lid], l2 = ls - l1;
      int r1 = r[rid], r2 = rs - r1;
      chmin(ans, max({l1, l2, r1, r2}) - min({l1, l2, r1, r2}));
    }
  }
  wt(ans);
}
