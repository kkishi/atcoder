#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int ans = 0;
  rep(r, h - 1) rep(c, w - 1) {
    int cnt = 0;
    rep(dr, 2) rep(dc, 2) {
      int nr = r + dr;
      int nc = c + dc;
      cnt += s[nr][nc] == '#';
    }
    dbg(r, c, cnt);
    if (cnt == 4 || cnt == 0) continue;
    if (cnt != 2) ++ans;
  }
  wt(ans);
}
