#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  auto f = [&](int ini, const V<int>& v) {
    set<int> dp;
    dp.insert(ini);
    each(e, v) {
      set<int> ndp;
      each(f, dp) {
        ndp.insert(f - e);
        ndp.insert(f + e);
      }
      swap(dp, ndp);
    }
    return dp;
  };
  V<int> e, o;
  rep(i, 1, n)(even(i) ? e : o).eb(a[i]);
  wt(f(a[0], e).count(x) && f(0, o).count(y));
}
