#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int tot = 0;
  each(si, s) each(c, si) tot += c == '#';
  rep(i, h) rep(j, w) {
    if (Fix([&](auto rec, int r, int c, int x) -> bool {
          char& d = s[r][c];
          if (d != '#') return false;
          d = '.';
          ++x;
          if (x == tot) {
            wt(tot);
            wt(r + 1, c + 1);
            return true;
          }
          each(nr, nc, adjacent(r, c)) {
            if (inside(nr, nc, h, w) && rec(nr, nc, x)) {
              wt(r + 1, c + 1);
              return true;
            }
          }
          d = '#';
          return false;
        })(i, j, 0))
      return;
  }
}
