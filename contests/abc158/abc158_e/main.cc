#include <bits/stdc++.h>

#include "atcoder.h"

int dp[2][10000];

void Main() {
  ints(N, P);
  strings(S);
  int ans = 0;
  rep(i, N) {
    int curr = i % 2;
    int prev = 1 - curr;
    memset(dp[curr], 0, sizeof(dp[curr]));
    int d = S[i] - '0';
    dp[curr][d % P]++;
    rep(j, P) dp[curr][(j * 10 + d) % P] += dp[prev][j];
    rep(j, P) dbg(j, dp[curr][j]);
    ans += dp[curr][0];
  }
  wt(ans);
}
