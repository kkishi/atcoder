#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<bool> g(n, V<bool>(n));
  rep(m) {
    ints(x, y);
    --x, --y;
    g[x][y] = g[y][x] = true;
  }
  int ans = 0;
  rep(s, 1 << n) {
    bool ok = true;
    rep(i, n - 1)
        rep(j, i + 1, n) if (((s >> i) & 1) && ((s >> j) & 1) && !g[i][j]) ok =
            false;
    if (ok) chmax(ans, popcount(s));
  }
  wt(ans);
}
