#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  int N = h + w - 1;
  vector dp(h + 1, vector(w + 1, vector(N + 1, int(-1))));
  dp[0][0][0] = 0;
  rep(r, h) rep(c, w) {
    rep(i, N) {
      if (dp[r][c][i] == -1) continue;
      chmax(dp[r + 1][c][i], dp[r][c][i]);
      chmax(dp[r + 1][c][i + 1], dp[r][c][i] + a[r][c]);
      chmax(dp[r][c + 1][i], dp[r][c][i]);
      chmax(dp[r][c + 1][i + 1], dp[r][c][i] + a[r][c]);
    }
  }
  V<int> ans(N + 1);
  rep(r, h + 1) rep(c, w + 1) rep(i, N + 1) chmax(ans[i], dp[r][c][i]);
  rep(i, N) wt(ans[i + 1]);
}
