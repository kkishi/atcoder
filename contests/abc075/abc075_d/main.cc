#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"

void Main() {
  ints(N, K);
  V<int> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];

  V<int> cx = Compress(x), cy = Compress(y);

  VV<bool> p(N, V<bool>(N));
  rep(i, N) p[Uncompress(cx, x[i])][Uncompress(cy, y[i])] = true;

  VV<int> dp(N + 1, V<int>(N + 1));
  rep(i, N) rep(j, N) {
    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + p[i][j];
  }

  int ans = big;
  rep(i, N) rep(j, N) rep(k, i + 1, N + 1) rep(l, j + 1, N + 1) {
    if (dp[k][l] - dp[i][l] - dp[k][j] + dp[i][j] >= K) {
      chmin(ans, (cx[k - 1] - cx[i]) * (cy[l - 1] - cy[j]));
    }
  }
  wt(ans);
}
