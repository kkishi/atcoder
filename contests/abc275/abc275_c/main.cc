#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(9);
  cin >> s;
  int ans = 0;
  auto ok = [&](int r, int c) { return inside(r, c, 9, 9) && s[r][c] == '#'; };
  rep(i, 9) rep(j, 9) rep(k, 9) rep(l, 9) {
    if (i == k && j == l) continue;
    if (ok(i, j) && ok(k, l)) {
      int r = k - i;
      int c = l - j;
      int I = i;
      int J = j;
      bool ok2 = true;
      rep(i, 4) {
        if (!ok(I, J)) ok2 = false;
        I += r;
        J += c;
        int nr = c;
        int nc = -r;
        r = nr;
        c = nc;
      }
      if (ok2) ++ans;
    }
  }
  wt(ans / 4);
}
