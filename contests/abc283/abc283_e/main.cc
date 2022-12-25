#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  auto check = [&](int r, int mask) {
    rep(c, w) {
      bool ok = false;
      each(nr, nc, adjacent(r, c)) if (inside(nr, nc, h, w)) {
        int x = a[r][c] ^ hasbit(mask, 1);
        int y = a[nr][nc] ^ hasbit(mask, (nr - r) + 1);
        if (x == y) ok = true;
      }
      if (!ok) return false;
    }
    return true;
  };
  vector dp(h, vector(1 << 2, big));
  rep(i, 2) dp[0][i << 1] = i;
  rep(r, 1, h) rep(mask, 1 << 3) if (check(r - 1, mask)) {
    int pmask = mask & ((1 << 2) - 1);
    int nmask = mask >> 1;
    chmin(dp[r][nmask], dp[r - 1][pmask] + (mask >> 2));
  }
  int ans = big;
  rep(mask, 1 << 2) if (check(h - 1, mask)) chmin(ans, dp[h - 1][mask]);
  if (ans == big) ans = -1;
  wt(ans);
}
