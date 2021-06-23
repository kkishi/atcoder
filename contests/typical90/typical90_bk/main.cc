#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector p(h, vector(w, int(0)));
  cin >> p;
  int ans = -big;
  rep(mask, 1, 1 << h) {
    map<int, int> m;
    rep(i, w) {
      int v = -1;
      rep(j, h) if (hasbit(mask, j)) {
        if (v == -1) {
          v = p[j][i];
        } else if (v != p[j][i]) {
          v = -2;
        }
      }
      if (v != -2) ++m[v];
    }
    each(_, e, m) chmax(ans, e * popcount(mask));
  }
  wt(ans);
}
