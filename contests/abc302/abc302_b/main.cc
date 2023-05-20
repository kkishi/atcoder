#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  rep(i, h) rep(j, w) rep(dr, -1, 2) rep(dc, -1, 2) {
    if (dr == 0 && dc == 0) continue;
    string snuke = "snuke";
    V<pair<int, int>> ans;
    rep(k, sz(snuke)) {
      int r = i + dr * k;
      int c = j + dc * k;
      if (!inside(r, c, h, w) || (snuke[k] != s[r][c])) break;
      ans.eb(r, c);
    }
    if (sz(ans) == 5) {
      each(r, c, ans) wt(r + 1, c + 1);
      return;
    }
  }
}
