#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;

  const int N = 40;
  vector cnt(N, vector(2, int(0)));
  rep(i, n) rep(j, N)++ cnt[j][hasbit(a[i], j)];

  V<int> v(N);
  rrep(i, N) {
    v[i] = k & 1;
    k >>= 1;
  }

  vector dp(N + 1, vector(2, -big));
  dp[0][0] = 0;
  rep(i, N) rep(isless, 2) rep(j, 2) {
    if (!isless && j > v[i]) continue;
    chmax(dp[i + 1][isless | (j < v[i])],
          (dp[i][isless] << 1) + cnt[(N - 1) - i][1 - j]);
  }
  int ans = -big;
  rep(i, 2) chmax(ans, dp[N][i]);
  wt(ans);
}
