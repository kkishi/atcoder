#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  set<pair<int, int>> bad;
  rep(i, n) rep(j, i + 1, n) bad.emplace(i, j);
  rep(m) {
    V<int> a(n);
    cin >> a;
    each(e, a)-- e;
    rep(i, n - 1) {
      int x = a[i];
      int y = a[i + 1];
      if (x > y) swap(x, y);
      bad.erase({x, y});
    }
  }
  wt(sz(bad));
}
