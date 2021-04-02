#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<int> c(n), d(n);
  cin >> c >> d;
  vector dp(n + 1, vector(n + 1, big));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, n) {
      {
        int nj = j + (s[i] == '(' ? 1 : -1);
        if (nj >= 0) chmin(dp[i + 1][nj], dp[i][j]);
      }
      {
        int nj = j + (s[i] == '(' ? -1 : 1);
        if (nj >= 0) chmin(dp[i + 1][nj], dp[i][j] + c[i]);
      }
      chmin(dp[i + 1][j], dp[i][j] + d[i]);
    }
  }
  wt(dp[n][0]);
}
