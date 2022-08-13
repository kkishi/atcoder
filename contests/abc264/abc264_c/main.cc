#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(h1, w1);
    vector a(h1, vector(w1, int(0)));
    cin >> a;
    ints(h2, w2);
    vector b(h2, vector(w2, int(0)));
    cin >> b;
    rep(hm, 1 << h1) rep(wm, 1 << w1) {
      VV<int> c;
      rep(i, h1) if (!hasbit(hm, i)) {
        V<int> v;
        rep(j, w1) if (!hasbit(wm, j)) v.eb(a[i][j]);
        c.eb(v);
      }
      if (c == b) return true;
    }
    return false;
  }());
}
