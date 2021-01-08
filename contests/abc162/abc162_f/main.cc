#include <bits/stdc++.h>

#include "atcoder.h"

int dp[2 * 100000][2][3];

void Main() {
  ints(N);
  V<int> A(N);
  cin >> A;

  const int INF = 100000000000000000;
  rep(i, N) rep(j, 2) rep(k, 3) dp[i][j][k] = -INF;
  dp[0][0][1] = 0;
  dp[0][1][0] = A[0];
  int maxskip = even(N) ? 1 : 2;
  rep(i, 1, N) {
    rep(skipped, maxskip + 1) {
      // Previous one is taken, do not take.
      chmax(dp[i][0][skipped], dp[i - 1][1][skipped]);
      // Previous one is not taken, take.
      chmax(dp[i][1][skipped], dp[i - 1][0][skipped] + A[i]);
      if (skipped < maxskip) {
        // Previous one is not taken, do not take.
        chmax(dp[i][0][skipped + 1], dp[i - 1][0][skipped]);
      }
    }
  }
  int ans = -INF;
  rep(i, maxskip + 1) chmax(ans, dp[N - 1 - i][1][maxskip - i]);
  wt(ans);
}
