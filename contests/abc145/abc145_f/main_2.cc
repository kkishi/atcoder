#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

const int INF = 1LL << 60;

void Main() {
  ints(n, K);
  vector<int> h(n);
  cin >> h;

  h.pb(0);
  Compressor hc(h);
  int N = sz(hc.coord);

  vector dp(n + 1, vector(K + 1, vector(N, INF)));
  dp[0][0][0] = 0;
  rep(i, n) rep(j, K + 1) rep(k, N) {
    if (j < K) {
      chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
    }
    chmin(dp[i + 1][j][hc(h[i])], dp[i][j][k] + max(0LL, h[i] - hc.coord[k]));
  }
  int ans = INF;
  rep(i, K + 1) rep(j, N) chmin(ans, dp[n][i][j]);
  wt(ans);
}
