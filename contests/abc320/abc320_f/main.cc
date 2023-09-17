#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h);
  V<int> x(n + 1);
  rep(i, n) cin >> x[i + 1];
  vector dp(h + 1, vector(h + 1, big));
  rep(i, h + 1) dp[h][i] = 0;
  rep(i, n - 1) {
    ints(p, f);
    chmin(f, h);
    int d = x[i + 1] - x[i];
    vector ndp(h + 1, vector(h + 1, big));
    rep(x, h + 1) {
      int nx = x - d;
      if (nx < 0) continue;
      rep(y, h + 1) {
        int ny = y + d;
        if (ny > h) continue;
        if (dp[x][y] == big) continue;

        // Do not use
        chmin(ndp[nx][ny], dp[x][y]);

        // Use in the first pass
        chmin(ndp[min(h, nx + f)][ny], dp[x][y] + p);

        // Use in the second pass
        if (ny == h) {
          rep(i, f + 1) chmin(ndp[nx][h - i], dp[x][y] + p);
        } else {
          if (ny - f >= 0) {
            chmin(ndp[nx][ny - f], dp[x][y] + p);
          }
        }
      }
    }
    swap(dp, ndp);
  }
  int d = x[n] - x[n - 1];
  int ans = big;
  rep(x, d * 2, h + 1) chmin(ans, dp[x][x - d * 2]);
  if (ans == big) ans = -1;
  wt(ans);
}
