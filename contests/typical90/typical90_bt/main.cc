#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> C(h);
  cin >> C;
  int ans = 0;
  rep(i, h) rep(j, w) {
    vector seen(h, vector(w, false));
    Fix([&](auto rec, int r, int c, int depth) -> void {
      if (C[r][c] == '#') return;
      if (seen[r][c]) {
        if (r == i && c == j) chmax(ans, depth);
        return;
      }
      seen[r][c] = true;
      each(nr, nc, adjacent(r, c)) if (inside(nr, nc, h, w)) {
        rec(nr, nc, depth + 1);
      }
      seen[r][c] = false;
    })(i, j, 0);
  }
  if (ans <= 2) ans = -1;
  wt(ans);
}
