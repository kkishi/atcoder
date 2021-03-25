#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;
  int cnt = 0;
  each(x, s) each(y, x) cnt += y == '.';
  int ans = 0;
  rep(r, n) rep(c, m) if (s[r][c] == '#') {
    s[r][c] = '.';
    vector v(n, vector(m, false));
    if (Fix([&](auto rec, int r, int c) -> int {
          v[r][c] = true;
          int ret = 1;
          each(nr, nc, adjacent(r, c)) {
            if (inside(nr, nc, n, m) && s[nr][nc] == '.' && !v[nr][nc]) {
              ret += rec(nr, nc);
            }
          }
          return ret;
        })(r, c) == cnt + 1) {
      ++ans;
    }
    s[r][c] = '#';
  }
  wt(ans);
}
