#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, x, y);
  V<string> s(h);
  cin >> s;
  --x, --y;
  each(dr, dc, adjacent(0, 0)) {
    int r = x, c = y;
    while (inside(r, c, h, w) && s[r][c] != '#') {
      s[r][c] = ' ';
      r += dr;
      c += dc;
    }
  }
  int ans = 0;
  each(e, s) each(c, e) if (c == ' ')++ ans;
  wt(ans);
}
