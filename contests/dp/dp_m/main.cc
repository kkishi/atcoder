#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  vector dp(n, vector(k + 1, mint(0)));
  vector sdp(n, vector(k + 1, mint(0)));
  rep(i, k + 1) dp[0][i] = i <= a[0];
  sdp[0][0] = dp[0][0];
  rep(i, 1, k + 1) sdp[0][i] = sdp[0][i - 1] + dp[0][i];
  rep(i, 1, n) {
    rep(j, k + 1) {
      int l = j - a[i] - 1;
      dp[i][j] += sdp[i - 1][j] - (l >= 0 ? sdp[i - 1][l] : 0);
    }
    sdp[i][0] = dp[i][0];
    rep(j, 1, k + 1) sdp[i][j] = sdp[i][j - 1] + dp[i][j];
  }
  wt(dp[n - 1][k]);
}
