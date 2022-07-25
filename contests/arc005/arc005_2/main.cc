#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  --x, --y;
  strings(w);
  V<string> c(9);
  cin >> c;
  string ans;
  rep(4) {
    ans += c[y][x];
    auto d = [](char c) -> pair<int, int> {
      if (c == 'R') return {+1, 0};
      if (c == 'L') return {-1, 0};
      if (c == 'U') return {0, -1};
      if (c == 'D') return {0, +1};
      assert(false);
    };
    each(e, w) {
      auto [dx, dy] = d(e);
      if (!inside(x + dx, y + dy, 9, 9)) {
        if (e == 'R' || e == 'L') e = 'L' + 'R' - e;
        if (e == 'U' || e == 'D') e = 'U' + 'D' - e;
      }
    }
    each(e, w) {
      auto [dx, dy] = d(e);
      x += dx;
      y += dy;
    }
  }
  wt(ans);
}
