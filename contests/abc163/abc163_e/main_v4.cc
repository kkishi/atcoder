#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long A[2000];

long long absolute(long long x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

long long dp[2000][2001];

int main() {
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  vector<pair<long long, int>> v;
  REP(i, N) v.push_back({-A[i], i});
  sort(v.begin(), v.end());

  dp[0][0] = -v[0].first * (N - 1 - v[0].second);
  dp[0][1] = -v[0].first * v[0].second;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      // right
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + -v[i].first * (N - 1 - (i - j) -
                                                             v[i].second));
      // left
      dp[i][j + 1] = max(
          dp[i][j + 1], dp[i - 1][j] + -v[i].first * absolute(v[i].second - j));
    }
  }
  long long ans = 0;
  REP(i, N + 1) if (ans < dp[N - 1][i]) ans = dp[N - 1][i];
  cout << ans << endl;
}
