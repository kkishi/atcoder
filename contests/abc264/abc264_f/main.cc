#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<int> r(h), c(w);
  cin >> r >> c;
  V<string> a(h);
  cin >> a;
  vector dp(h, vector(w, array<array<int, 2>, 2>()));
  rep(i, h) rep(j, w) rep(k, 2) rep(l, 2) dp[i][j][k][l] = big;
  dp[0][0][0][0] = 0;
  dp[0][0][1][0] = r[0];
  dp[0][0][0][1] = c[0];
  dp[0][0][1][1] = r[0] + c[0];
  rep(i, h) rep(j, w) rep(R, 2) rep(C, 2) {
    char x = a[i][j] ^ R ^ C;
    if (i + 1 < h) {
      int NR = 0;
      int cost = 0;
      if (x != (a[i + 1][j] ^ C)) {
        NR = 1;
        cost = r[i + 1];
      }
      chmin(dp[i + 1][j][NR][C], dp[i][j][R][C] + cost);
    }
    if (j + 1 < w) {
      int NC = 0;
      int cost = 0;
      if (x != (a[i][j + 1] ^ R)) {
        NC = 1;
        cost += c[j + 1];
      }
      chmin(dp[i][j + 1][R][NC], dp[i][j][R][C] + cost);
    }
  }
  int ans = big;
  rep(i, 2) rep(j, 2) chmin(ans, dp[h - 1][w - 1][i][j]);
  wt(ans);
}
