#include <bits/stdc++.h>

#include "atcoder.h"
#include "travelling_salesperson_problem.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  vector dp(1 << n, vector(n, big));
  dp[1][0] = 0;
  TravellingSalespersonProblem(dp, a);
  int ans = big;
  rep(i, 1, n) chmin(ans, dp.back()[i] + a[i][0]);
  wt(ans);
}
