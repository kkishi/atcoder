#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  a.erase(unique(all(a)), a.end());
  n = sz(a);

  int ans = big;
  each(e, a) {
    int l = 0, r = n;
    int y = 0;
    rrep(i, 30) {
      int L = a[l];
      int lv = hasbit(L, i);
      int R = a[r - 1];
      int rv = hasbit(R, i);
      int v = 0;
      if (lv == rv) {
        v = lv;
      } else {
        int m =
            BinarySearch<int>(l, r, [&](int x) { return !hasbit(a[x], i); }) +
            1;
        int ev = hasbit(e, i);
        if (ev == 0) {
          v = 1;
          r = m;
        } else {
          v = 0;
          l = m;
        }
      }
      y |= v << i;
    }
    chmin(ans, e ^ y);
  }
  wt(ans);
}
