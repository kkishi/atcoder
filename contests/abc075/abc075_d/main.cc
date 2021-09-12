#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(N, K);
  V<int> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];

  Compressor cx(x), cy(y);

  VV<bool> p(N, V<bool>(N));
  rep(i, N) p[cx(x[i])][cy(y[i])] = true;

  VV<int> dp(N + 1, V<int>(N + 1));
  rep(i, N) rep(j, N) {
    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + p[i][j];
  }

  int ans = numeric_limits<int>::max();
  rep(i, N) rep(j, N) rep(k, i + 1, N + 1) rep(l, j + 1, N + 1) {
    if (dp[k][l] - dp[i][l] - dp[k][j] + dp[i][j] >= K) {
      chmin(ans,
            (cx.coord[k - 1] - cx.coord[i]) * (cy.coord[l - 1] - cy.coord[j]));
    }
  }
  wt(ans);
}
