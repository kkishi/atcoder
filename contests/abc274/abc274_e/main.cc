#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n, m);
  int N = n + m;
  V<Point> v(N);
  cin >> v;

  vector dp(1 << N, vector(N, double(big)));
  rep(i, N) dp[1 << i][i] = v[i].Norm();

  double ans = big;
  for (int mask = 0; mask < (1 << N); ++mask) {
    for (int i = 0; i < N; ++i) {
      double speed = pow(2, popcount(mask >> n));
      if (popcount(mask & ((1 << n) - 1)) == n) {
        chmin(ans, dp[mask][i] + v[i].Norm() / speed);
      }
      if (!((mask >> i) & 1)) continue;
      for (int j = 0; j < N; ++j) {
        if ((mask >> j) & 1) continue;
        double& x = dp[mask | (1 << j)][j];
        double y = dp[mask][i] + (v[i] - v[j]).Norm() / speed;
        if (x > y) x = y;
      }
    }
  }
  wt(ans);
}
