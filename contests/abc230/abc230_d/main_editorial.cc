#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<pair<int, int>> v;
  rep(n) {
    ints(l, r);
    v.eb(r, l);
  }
  sort(all(v));
  int ans = 0;
  int last = 0;
  each(r, l, v) {
    if (last < l) {
      ++ans;
      last = r + d - 1;
    }
  }
  wt(ans);
}
