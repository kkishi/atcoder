#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long A[2 * 100000];
long long dp[2 * 100000][3];

void setmax(long long &best, long long cand) {
  if (best < cand) best = cand;
}

int main() {
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  const long long INF = 1e18;
  REP(i, N) REP(j, 3) dp[i][j] = -INF;
  dp[0][0] = A[0];
  dp[0][1] = 0;
  int maxskip = N % 2 + 1;
  for (int i = 1; i < N; ++i) {
    for (int skipped = 0; skipped <= maxskip; ++skipped) {
      bool put = (i + skipped) % 2 == 0;
      setmax(dp[i][skipped], dp[i - 1][skipped] + (put ? A[i] : 0));
      if (skipped < maxskip) {
        setmax(dp[i][skipped + 1], dp[i - 1][skipped]);
      }
    }
  }
  cout << dp[N - 1][maxskip] << endl;
}
