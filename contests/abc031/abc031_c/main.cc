#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = numeric_limits<int>::min();
  rep(ti, n) {
    int x;
    int maxi = numeric_limits<int>::min();
    rep(ai, n) if (ai != ti) {
      int i = ti, j = ai;
      if (i > j) swap(i, j);
      int ts = 0, as = 0;
      rep(k, i, j + 1)(((k - i) & 1) ? as : ts) += a[k];
      if (chmax(maxi, as)) {
        x = ts;
      }
    }
    chmax(ans, x);
  }
  wt(ans);
}
