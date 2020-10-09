#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<double> p(n);
  cin >> p;
  vector dp(n + 1, vector(n + 1, double(0)));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, n) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  }
  double ans = 0;
  rep(i, n / 2 + 1) ans += dp[n][n - i];
  cout << fixed << setprecision(20);
  wt(ans);
}
