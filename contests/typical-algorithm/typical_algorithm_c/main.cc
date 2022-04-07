#include <bits/stdc++.h>

#include "atcoder.h"
#include "travelling_salesperson_problem.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  VV<optional<int>> dp = TravellingSalespersonProblem(a);
  int ans = big;
  rep(i, 1, n) chmin(ans, *dp[(1 << n) - 1][i] + a[i][0]);
  wt(ans);
}
