#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

long long A[2 * 100000];
long long dp[2 * 100000][2][3];

int main() {
  int N;
  cin >> N;
  rep(i, N) cin >> A[i];

  const long long INF = 100000000000000000;
  rep(i, N) rep(j, 2) rep(k, 3) dp[i][j][k] = -INF;
  dp[0][0][1] = 0;
  dp[0][1][0] = A[0];
  int maxskip = N % 2 == 0 ? 1 : 2;
  for (int i = 1; i < N; ++i) {
    for (int skipped = 0; skipped <= maxskip; ++skipped) {
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
  long long ans = -INF;
  for (int i = 0; i <= maxskip; ++i) {
    chmax(ans, dp[N - 1 - i][1][maxskip - i]);
  }
  cout << ans << endl;
}
