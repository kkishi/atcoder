#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, m, t);
    V<int> a(n - 1);
    cin >> a;
    V<int> bonus(n);
    rep(m) {
      ints(x, y);
      bonus[x - 1] = y;
    }
    rep(i, n - 1) {
      t += bonus[i] - a[i];
      if (t <= 0) return false;
    }
    return true;
  }());
}
