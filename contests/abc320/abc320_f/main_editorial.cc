// https://atcoder.jp/contests/abc320/tasks/abc320_f
#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h);
  V<int> x(n + 1);
  rep(i, n) cin >> x[i + 1];
  V<int> p(n), f(n);
  rep(i, 1, n) cin >> p[i] >> f[i];
  vector dp(h + 1, vector(h + 1, big));
  rep(i, h + 1) dp[h][i] = 0;
  rep(i, n) {
    int d = x[i + 1] - x[i];

    vector ndp(h + 1, vector(h + 1, big));
    rep(x, h + 1) {
      rep(y, h + 1) {
        if (dp[x][y] == big) continue;

        auto maybeUpdate = [&](int nx, int ny, int p) {
          if (nx >= 0 && ny <= h) {
            chmin(ndp[nx][ny], dp[x][y] + p);
          }
        };

        // Do not use
        maybeUpdate(x - d, y + d, 0);

        // Use in the first pass
        maybeUpdate(min(h, x + f[i]) - d, y + d, p[i]);

        // Use in the second pass
        if (y == h) {
          rep(j, min(f[i], h) + 1) maybeUpdate(x - d, h - j + d, p[i]);
        } else {
          if (y - f[i] >= 0) {
            maybeUpdate(x - d, y - f[i] + d, p[i]);
          }
        }
      }
    }
    swap(dp, ndp);
  }
  int ans = big;
  rep(i, h + 1) rep(j, i + 1) chmin(ans, dp[i][j]);
  if (ans == big) ans = -1;
  wt(ans);
}
