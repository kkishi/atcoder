#include <bits/stdc++.h>

#include "atcoder.h"

const int INF = 1LL << 60;

void Main() {
  ints(n, k);
  vector<int> h(n + 4);
  rep(i, n) cin >> h[i + 2];  // h[i + 2] = height at 0
  // left, mid, prev
  // dp[i + 1][j][k]
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(k + 1, vector<int>(4, INF)));
  dp[0][0][1] = 0;
  rep(i, n) {
    rep(d, 4) {
      int prev_height = d == 3 ? 0 : h[i + 2 - d];
      rep(e, 4) {
        int curr_height = e == 3 ? 0 : h[i + 3 - e];
        rep(j, k + 1) {
          int nj = j + (e == 1 ? 0 : 1);
          if (nj > k) continue;
          chmin(dp[i + 1][nj][e],
                dp[i][j][d] + max(0LL, curr_height - prev_height));
        }
      }
    }
  }
  int ans = INF;
  rep(i, k + 1) rep(j, 4) chmin(ans, dp[n][i][j]);
  wt(ans);
}
