#include <bits/stdc++.h>

#include "atcoder.h"

const int INF = 1LL << 60;

void Main() {
  int n, K;
  cin >> n >> K;
  vector<int> h(n + 1);
  rep(i, n) cin >> h[i + 1];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) rep(j, n) rep(k, i) {
      chmin(dp[i][j + 1], dp[k][j] + max(0LL, h[i] - h[k]));
    }
  int ans = INF;
  rep(i, n + 1) chmin(ans, dp[i][n - K]);
  cout << ans << endl;
}
