#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    V<pair<int, int>> v;
    rep(n) {
      ints(l, r);
      v.eb(r, l);
    }
    sort(v);
    Intervals is;
    bool ok = true;
    each(r, l, v) {
      int x = is.Mex(l - 1);
      if (r <= x) {
        ok = false;
        break;
      }
      is.Insert(x, x + 1);
    }
    wt(ok);
  }
}
