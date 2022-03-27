#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, K);
  V<int> a(n), b(n);
  cin >> a >> b;
  vector dp(n, vector(2, false));
  dp[0][0] = true;
  dp[0][1] = true;
  rep(i, 1, n) {
    rep(j, 2) if (dp[i - 1][j]) {
      rep(k, 2) {
        V<int>& p = (j == 0 ? a : b);
        V<int>& c = (k == 0 ? a : b);
        if (abs(p[i - 1] - c[i]) <= K) {
          dp[i][k] = true;
        }
      }
    }
  }
  wt(dp[n - 1][0] || dp[n - 1][1]);
}
