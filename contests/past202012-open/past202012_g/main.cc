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
          rep(d, 4) {
            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, 1, 0, -1};
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (0 <= nr && nr < h && 0 <= nc && nc < w && rec(nr, nc, x)) {
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
