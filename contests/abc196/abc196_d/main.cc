#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, a, b);
  int ans = 0;
  vector g(h, vector(w, false));
  Fix([&](auto rec, int ra, int rb) -> void {
    if (ra == 0 && rb == 0) {
      ++ans;
      return;
    }
    rep(i, h) rep(j, w) if (!g[i][j]) {
      g[i][j] = true;
      if (ra > 0) {
        // vertical
        if (i + 1 < h && !g[i + 1][j]) {
          g[i + 1][j] = true;
          rec(ra - 1, rb);
          g[i + 1][j] = false;
        }
        // horizontal
        if (j + 1 < w && !g[i][j + 1]) {
          g[i][j + 1] = true;
          rec(ra - 1, rb);
          g[i][j + 1] = false;
        }
      }
      if (rb > 0) {
        rec(ra, rb - 1);
      }
      g[i][j] = false;
      return;
    }
  })(a, b);
  wt(ans);
}
