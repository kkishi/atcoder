#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v;
  rep(S, 1, 1 << 10) {
    int x = 0;
    rep(i, 10) if (hasbit(S, i)) {
      x *= 10;
      x += (9 - i);
    }
    v.eb(x);
  }
  sort(v);
  ints(k);
  wt(v[k]);
}
