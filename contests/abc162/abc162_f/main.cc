#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long A[2 * 100000];
long long dp[2 * 100000][2][3];

void setmax(long long &best, long long cand) {
  if (best < cand) best = cand;
}

int main() {
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  const long long INF = 100000000000000000;
  REP(i, N) REP(j, 2) REP(k, 3) dp[i][j][k] = -INF;
  dp[0][0][1] = 0;
  dp[0][1][0] = A[0];
  int maxskip = N % 2 == 0 ? 1 : 2;
  for (int i = 1; i < N; ++i) {
    for (int skipped = 0; skipped <= maxskip; ++skipped) {
      // Previous one is taken, do not take.
      setmax(dp[i][0][skipped], dp[i - 1][1][skipped]);
      // Previous one is not taken, take.
      setmax(dp[i][1][skipped], dp[i - 1][0][skipped] + A[i]);
      if (skipped < maxskip) {
        // Previous one is not taken, do not take.
        setmax(dp[i][0][skipped + 1], dp[i - 1][0][skipped]);
      }
    }
  }
  long long ans = -INF;
  for (int i = 0; i <= maxskip; ++i) {
    setmax(ans, dp[N - 1 - i][1][maxskip - i]);
  }
  cout << ans << endl;
}