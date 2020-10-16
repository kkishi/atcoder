#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"

const int INF = 1LL << 60;

void Main() {
  ints(n, K);
  vector<int> h(n);
  cin >> h;

  h.push_back(0);
  vector<int> hc = Compress(h);

  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(K + 1, vector<int>(hc.size(), INF)));
  dp[0][0][0] = 0;
  rep(i, n) rep(j, K + 1) rep(k, hc.size()) {
    if (j < K) {
      chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
    }
    chmin(dp[i + 1][j][Uncompress(hc, h[i])],
          dp[i][j][k] + max(0LL, h[i] - hc[k]));
  }
  int ans = INF;
  rep(i, K + 1) rep(j, hc.size()) chmin(ans, dp[n][i][j]);
  wt(ans);
}
