#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, k);
  vector<string> c(h);
  cin >> c;
  int ans = 0;
  rep(hs, 1 << h) rep(ws, 1 << w) {
    int black = 0;
    rep(i, h) rep(j, w) {
      bool red = hasbit(hs, i) || hasbit(ws, j);
      if (c[i][j] == '#' && !red) ++black;
    }
    if (black == k) ++ans;
  }
  wt(ans);
}
