#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, K);
  vector a(h, vector(w, int(0)));
  cin >> a;

  int ans = big;
  each(e, a) each(A, e) {
    vector dp(h, vector(w, vector(K + 1, big)));
    if (a[0][0] >= A) dp[0][0][1] = a[0][0];
    if (a[0][0] <= A) dp[0][0][0] = 0;
    rep(i, h) rep(j, w) rep(k, K + 1) {
      if (dp[i][j][k] == big) continue;
      rep(d, 2) {
        int ni = i + (1 - d);
        int nj = j + d;
        if (ni == h || nj == w) continue;
        int na = a[ni][nj];
        if (na >= A) chmin(dp[ni][nj][k + 1], dp[i][j][k] + na);
        if (na <= A) chmin(dp[ni][nj][k], dp[i][j][k]);
      }
    }
    chmin(ans, dp[h - 1][w - 1][K]);
  }
  wt(ans);
}
