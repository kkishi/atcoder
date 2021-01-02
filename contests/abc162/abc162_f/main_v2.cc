#include <bits/stdc++.h>

#include "atcoder.h"

long long A[2 * 100000];
long long dp[2 * 100000][3];

void Main() {
  int N;
  cin >> N;
  rep(i, N) cin >> A[i];

  const long long INF = 1e18;
  rep(i, N) rep(j, 3) dp[i][j] = -INF;
  dp[0][0] = A[0];
  dp[0][1] = 0;
  int maxskip = N % 2 + 1;
  for (int i = 1; i < N; ++i) {
    for (int skipped = 0; skipped <= maxskip; ++skipped) {
      bool put = even(i + skipped);
      chmax(dp[i][skipped], dp[i - 1][skipped] + (put ? A[i] : 0));
      if (skipped < maxskip) {
        chmax(dp[i][skipped + 1], dp[i - 1][skipped]);
      }
    }
  }
  cout << dp[N - 1][maxskip] << endl;
}
