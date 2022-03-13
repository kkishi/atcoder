#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> c;
  rep(i, 1, (1 << n)) {
    ints(x);
    c.eb(x, i);
  }
  sort(c);
  V<int> base;
  int ans = 0;
  each(x, y, c) {
    each(e, base) chmin(y, y ^ e);
    if (y > 0) {
      ans += x;
      base.pb(y);
    }
  }
  wt(ans);
}
