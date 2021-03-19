#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string v = to_string(n);
  each(e, v) e -= '0';
  int N = sz(v);
  vector dp(N + 1, vector(2, vector(10, int(0))));
  dp[0][0][0] = 1;
  rep(i, N) rep(less, 2) rep(one, 10) rep(j, 10) {
    if (!less && j > v[i]) continue;
    dp[i + 1][less | (j < v[i])][one + (j == 1)] += dp[i][less][one];
  }
  int ans = 0;
  rep(i, 2) rep(j, 10) ans += dp[N][i][j] * j;
  wt(ans);
}
