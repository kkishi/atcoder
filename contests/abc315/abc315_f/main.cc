#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<double> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  double inf = numeric_limits<double>::max();
  int N = 30;
  vector dp(n, vector(N, inf));
  dp[0][0] = 0;
  rep(i, 1, n) rep(c, N) rep(pi, max(0, i - N - 1 + c), i) {
    double d = hypot(abs(x[i] - x[pi]), abs(y[i] - y[pi]));
    chmin(dp[i][c + i - pi - 1], dp[pi][c] + d);
  }
  double ans = inf;
  rep(i, N) chmin(ans, dp[n - 1][i] + (i == 0 ? 0 : (int(1) << (i - 1))));
  wt(ans);
}
