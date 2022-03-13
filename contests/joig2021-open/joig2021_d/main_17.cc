#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, d);
  V<pair<int, int>> xv(n);
  cin >> xv;
  sort(xv);
  V<int> x(n), v(n);
  rep(i, n) tie(x[i], v[i]) = xv[i];
  vector dp(n + 1, vector(m + 1, -big));
  rep(i, n) {
    dp[i + 1][1] = v[i];
    rep(j, i) {
      rep(k, min(m + 1, j + 2)) {
        if (x[i] - x[j] >= d) {
          chmax(dp[i + 1][k + 1], min(dp[j + 1][k], v[i]));
        }
      }
    }
  }
  int ans = -big;
  rep(i, n) chmax(ans, dp[i + 1][m]);
  if (ans == -big) ans = -1;
  wt(ans);
}
