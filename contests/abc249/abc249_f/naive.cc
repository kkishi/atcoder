#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> t(n), y(n);
  rep(i, n) cin >> t[i] >> y[i];
  int ans = -big;
  rep(mask, 1 << n) {
    if (popcount(mask) > k) continue;
    int x = 0;
    rep(i, n) if (!hasbit(mask, i)) {
      if (t[i] == 1) {
        x = y[i];
      } else {
        x += y[i];
      }
    }
    if (chmax(ans, x)) {
      dbg(bitset<5>(mask).to_string(), ans);
    }
  }
  wt(ans);
}
