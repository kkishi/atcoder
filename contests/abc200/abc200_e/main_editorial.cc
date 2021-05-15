#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector dp(4, vector(4 * n + 1, int(0)));
  dp[0][0] = 1;
  rep(i, 3) {
    rep(j, 3 * n + 1) {
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + n + 1] -= dp[i][j];
    }
    rep(j, 3 * n) dp[i + 1][j + 1] += dp[i + 1][j];
  }
  int x = 3;
  while (true) {
    int cnt = dp[3][x];
    if (cnt >= k) break;
    k -= cnt;
    ++x;
  }
  dbg(x, k);
  int I = 1;
  chmax(I, x - 2 * n);
  dbg(I);
  while (true) {
    int cnt;
    {
      int J = 1;
      int K = x - (I + J);
      dbg(J, K);
      if (K > n) {
        J += K - n;
        K = n;
      }
      cnt = (K - J) + 1;
    }
    if (cnt >= k) break;
    k -= cnt;
    ++I;
  }
  int J = 1;
  int K = x - (I + J);
  if (K > n) {
    J += K - n;
    K = n;
  }
  J += k - 1;
  K -= k - 1;
  wt(I, J, K);
}
