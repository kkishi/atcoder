#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(H, W, n, h, w);
  vector a(H, vector(W, int(0)));
  cin >> a;
  int ah = H - h + 1;
  int aw = W - w + 1;
  vector ans(ah, vector(aw, int(0)));
  rep(i, n) {
    vector b(H, vector(W, int(0)));
    rep(r, H) rep(c, W) if (a[r][c] == i + 1) b[r][c] = 1;
    CumulativeSum2D s(b);
    int cnt = s.Get(H - 1, W - 1);
    rep(r, ah) rep(c, aw) {
      if (s.Get(r, c, r + h - 1, c + w - 1) < cnt) ++ans[r][c];
    }
  }
  each(e, ans) wt(e);
}
