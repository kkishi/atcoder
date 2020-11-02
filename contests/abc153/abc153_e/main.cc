#include <bits/stdc++.h>

#include "atcoder.h"

const int INF = 1LL << 50;
int A[1000], B[1000];
int dp[20001];

void Main() {
  ints(H, N);
  rep(i, N) cin >> A[i] >> B[i];
  rep(i, 20000 + 1) dp[i] = INF;
  dp[0] = 0;
  int ans = INF;
  for (int i = 0; i <= H; ++i) {
    rep(n, N) {
      int j = i + A[n];
      chmin(dp[j], dp[i] + B[n]);
      if (j >= H) chmin(ans, dp[j]);
    }
  }
  wt(ans);
}
