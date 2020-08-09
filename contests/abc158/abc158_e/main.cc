#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll dp[2][10000];

int main() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  dbg(S);
  ll ans = 0;
  rep(i, N) {
    int curr = i % 2;
    int prev = 1 - curr;
    memset(dp[curr], 0, sizeof(dp[curr]));
    int d = S[i] - '0';
    dbg(d, P);
    dp[curr][d % P]++;
    rep(j, P) { dp[curr][(j * 10 + d) % P] += dp[prev][j]; }
    dbg(i, curr, prev);
    rep(j, P) dbg(j, dp[curr][j]);
    ans += dp[curr][0];
  }
  cout << ans << endl;
}
