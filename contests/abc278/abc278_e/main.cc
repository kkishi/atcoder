#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(H, W, n, h, w);
  vector a(H, vector(W, int(0)));
  cin >> a;
  V<int> cnt(n + 1);
  int uniq = 0;
  auto add = [&](int x) {
    if (cnt[x] == 0) ++uniq;
    ++cnt[x];
  };
  auto rem = [&](int x) {
    --cnt[x];
    if (cnt[x] == 0) --uniq;
  };
  each(e, a) each(e, e) add(e);
  vector ans(H - h + 1, vector(W - w + 1, int(0)));
  rep(r, H - h + 1) {
    int c = 0;
    auto A = [&](int R, int C) { return a[r + R][c + C]; };
    rep(R, h) rep(C, w) rem(A(R, C));
    while (true) {
      ans[r][c] = uniq;
      if (c + 1 == W - w + 1) {
        rep(R, h) rep(C, w) add(A(R, C));
        break;
      }
      rep(R, h) {
        add(A(R, 0));
        rem(A(R, w));
      }
      ++c;
    }
  }
  each(e, ans) wt(e);
}
