#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int ans = 0;
  rep(r, h - 1) rep(c, w - 1) {
    int cnt = 0;
    rep(dr, 2) rep(dc, 2) cnt += s[r + dr][c + dc] == '#';
    if (cnt == 1 || cnt == 3) ++ans;
  }
  wt(ans);
}
