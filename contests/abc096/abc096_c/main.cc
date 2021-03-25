#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  rep(r, h) cin >> s[r];
  VV<bool> b(h + 2, V<bool>(w + 2));
  rep(r, h) rep(c, w) b[r + 1][c + 1] = s[r][c] == '#';
  rep(r, h) rep(c, w) if (b[r + 1][c + 1]) {
    bool ok = false;
    each(nr, nc, adjacent(r + 1, c + 1)) if (b[nr][nc]) ok = true;
    if (!ok) {
      wt("No");
      return;
    }
  }
  wt("Yes");
}
