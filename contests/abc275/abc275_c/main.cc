#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_geometry.h"

void Main() {
  V<string> s(9);
  cin >> s;
  int ans = 0;
  auto ok = [&](int r, int c) { return inside(r, c, 9, 9) && s[r][c] == '#'; };
  rep(i, 9) rep(j, 9) rep(di, -8, 9) rep(dj, -8, 9) {
    if (di == 0 && dj == 0) continue;
    Point p = {i, j};
    Point d = {di, dj};
    bool ok2 = true;
    rep(4) {
      if (!ok(p.x(), p.y())) ok2 = false;
      p += d;
      d = Rot90(d);
    }
    if (ok2) ++ans;
  }
  wt(ans / 4);
}
