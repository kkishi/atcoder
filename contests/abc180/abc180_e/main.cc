#include <bits/stdc++.h>

#include "atcoder.h"
#include "travelling_salesperson_problem.h"

void Main() {
  ints(n);
  V<int> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];
  vector dist(n, vector(n, big));
  rep(a, n) rep(b, n) dist[a][b] =
      abs(x[a] - x[b]) + abs(y[a] - y[b]) + max(0, z[b] - z[a]);
  vector dp(1 << n, vector(n, big));
  dp[1][0] = 0;
  TravellingSalespersonProblem(dp, dist);
  int ans = big;
  rep(i, n) chmin(ans, dp[(1 << n) - 1][i] + dist[i][0]);
  wt(ans);
}
