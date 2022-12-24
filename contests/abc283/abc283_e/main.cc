#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  auto check = [&](int c, const VV<int>& st) {
    each(nr, nc,
         adjacent(0, c)) if (inside(nr, nc, 2, w) && st[0][c] == st[nr][nc]) {
      return true;
    }
    return false;
  };
  vector dp(h, vector(1 << 2, big));
  rep(mask, 1 << 2) {
    vector st(2, vector(w, int(0)));
    rep(i, 2) rep(j, w) st[i][j] = a[i][j] ^ hasbit(mask, i);
    bool ok = true;
    rep(i, w) if (!check(i, st)) ok = false;
    if (ok) dp[1][mask] = popcount(mask);
  }
  rep(r, 2, h) {
    rep(mask, 1 << 3) {
      int pmask = mask & 3;
      int nmask = mask >> 1;
      if (dp[r - 1][pmask] < big) {
        vector st(3, vector(w, int(0)));
        rep(i, 3) rep(j, w) { st[i][j] = a[r - 2 + i][j] ^ hasbit(mask, i); }

        auto check = [&](int c, const VV<int>& st) {
          each(nr, nc, adjacent(1, c)) if (inside(nr, nc, 3, w) &&
                                           st[1][c] == st[nr][nc]) {
            return true;
          }
          return false;
        };

        bool ok = true;
        rep(i, w) if (!check(i, st)) ok = false;
        if (ok) chmin(dp[r][nmask], dp[r - 1][pmask] + (mask >> 2));
      }
    }
  }
  int ans = big;
  rep(mask, 1 << 2) if (dp[h - 1][mask] != big) {
    auto check = [&](int c, const VV<int>& st) {
      each(nr, nc,
           adjacent(1, c)) if (inside(nr, nc, 2, w) && st[1][c] == st[nr][nc]) {
        return true;
      }
      return false;
    };
    vector st(2, vector(w, int(0)));
    rep(i, 2) rep(j, w) st[i][j] = a[h - 2 + i][j] ^ hasbit(mask, i);
    bool ok = true;
    rep(i, w) if (!check(i, st)) ok = false;
    if (ok) chmin(ans, dp[h - 1][mask]);
  }
  if (ans == big) ans = -1;
  wt(ans);
}
